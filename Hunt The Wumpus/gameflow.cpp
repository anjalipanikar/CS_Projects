#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include "wumpus.h"
#include "room.h"
#include "event.h"
#include "pit.h"
#include "bat.h"
#include "wumpus.h"
#include "gold.h"
#include "hunter.h"

using namespace std;

/*********************************************************************
 * ** Function: display_cave
 * ** Description: displays cave contents
 * ** Pre-Conditions: filled cave
 * ** Post-Conditions: None
 * *********************************************************************/

void display_cave(vector < vector< Room > > &cave, int size, string mode, Hunter& hunter) {
  for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "+---";
        }
        cout << "+" << endl << "|";
        for (int j = 0; j < size; j++) {

          //for regular mode
          if (mode == "false") {
            if (hunter.x == i && hunter.y == j) {
                cout << " " << "*" << " ";
            } else {
              cout << "   ";
            }
              cout << "|";
          }

          //for debug mode
          if (mode == "true") {
            if (hunter.x == i && hunter.y == j) {
              cout << " " << "*" << " ";
            } else if (cave[i][j].get_event()->event() != " ") {
              cout << " " << cave[i][j].get_event()->event() << " ";
            } else {
              cout << "   ";
            }
            cout << "|";
          }
        }
        cout << endl;
      }


      for (int i = 0; i < size; i++) {
          cout << "+---";
      }
      cout << "+";
      cout << endl;
}

/*********************************************************************
 * ** Function: set_x
 * ** Description: these functions randomly select an x and y coordinate to set events in
 * ** Parameters: cave, size, object
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

void set_bat(vector< vector< Room > > &cave, int size, Bat& b) {
  srand(time(NULL));
  int x_bat = rand() % size;
  int y_bat = rand() % size;
  bool check = false;
  while (check != true) {
    while (cave[x_bat][y_bat].get_event()->event() != " ") {
        x_bat = rand() % size;
        y_bat = rand() % size;
    }
    cave[y_bat][y_bat].set_event(b);
    check = true;
  }
}

void set_pit(vector< vector< Room > > &cave, int size, Pit& p) {
  srand(time(NULL));
  int x_pit = rand() % size;
  int y_pit = rand() % size;
  bool check = false;
  while (check != true) {
    while (cave[x_pit][y_pit].get_event()->event() != " ") {
        x_pit = rand() % size;
        y_pit = rand() % size;
    }
    cave[x_pit][y_pit].set_event(p);
    check = true;
  }
}

void set_wumpus(vector< vector< Room > > &cave, int size, Wumpus& w) {
  srand(time(NULL));
  int x_wumpus = rand() % size;
  int y_wumpus = rand() % size;
  bool check = false;
  while (check != true) {
    while (cave[x_wumpus][y_wumpus].get_event()->event() != " ") {
        x_wumpus = rand() % size;
        y_wumpus = rand() % size;
    }
    cave[x_wumpus][y_wumpus].set_event(w);
    check = true;
  }
}

void set_gold(vector< vector< Room > > &cave, int size, Gold& g) {
  srand(time(NULL));
  int x_gold = rand() % size;
  int y_gold = rand() % size;
  bool check = false;
  while (check != true) {
    while (cave[x_gold][y_gold].get_event()->event() != " ") {
        x_gold = rand() % size;
        y_gold = rand() % size;
    }
    cave[x_gold][y_gold].set_event(g);
    check = true;
  }
}

void set_hunter_start(vector< vector< Room > > &cave, int size, Hunter& hunter, HunterStart& s) {
  srand(time(NULL));
  hunter.count = 1;
  int x_start = rand() % size;
  int y_start = rand() % size;
  bool check = false;
  while (check != true) {
    while (cave[x_start][y_start].get_event()->event() != " ") {
        x_start = rand() % size;
        y_start = rand() % size;
    }
    cave[x_start][y_start].set_event(s);
    hunter.x = x_start;
    hunter.y = y_start;
    check = true;
  }
}

void set_empty(vector< vector< Room > > &cave, int size, Fill& f) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      cave[i][j].set_event(f);
    }
  }
}

void set_all(vector< vector< Room > > &cave, int size, Bat& b, Pit& p, Wumpus& w, Gold& g, Fill& f, Hunter& hunter, HunterStart& s) {
  set_empty(cave, size, f);
  set_bat(cave, size, b);
  set_pit(cave, size, p);
  set_wumpus(cave, size, w);
  set_gold(cave, size, g);
  set_hunter_start(cave, size, hunter, s);
}

/*********************************************************************
 * ** Function: is_player_alive
 * ** Description: these functions check to see if player is still alive in game
 * ** Parameters: cave vector, hunter
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

string is_player_alive(vector< vector< Room > > &cave, Hunter& hunter) {
    if (cave[hunter.x][hunter.y].get_event()->event() == "W") {
      return "death_by_wumpus";
    } else if (cave[hunter.x][hunter.y].get_event()->event() == "P") {
      return "death_by_pit";
    } else {
      return "alive";
    }
}

/*********************************************************************
 * ** Function: check_adjacent2
 * ** Description: these functions check adjacent rooms to sense an event
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

void check_adjacent2(vector< vector< Room > > &cave, int x, int y, Hunter& hunter) {
    if (cave[x][y].get_event()->event() == " ") {
      return;
    }
    if (cave[x][y].get_event()->event() == "W") {
      cout << "You smell a terrible stench nearby." << endl;
      return;
    }
    if (cave[x][y].get_event()->event() == "P") {
      cout << "You feel a breeze." << endl;
      return;
    }
    if (cave[x][y].get_event()->event() == "B") {
      cout << "You hear wings flapping." << endl;
      return;
    }
    if (cave[x][y].get_event()->event() == "G") {
      cout << "You see a glimmer nearby." << endl;
      return;
    }
}

/*********************************************************************
 * ** Function: check_event
 * ** Description: these functions check to see if player is in a room w/ an event
 * ** Parameters: cave vector, objects, size, mode
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

void check_event(vector< vector< Room > > &cave, int size, Bat& b, Pit& p, Wumpus& w, Gold& g, Fill& f, Hunter& hunter, HunterStart& s, string mode) {
  srand(time(NULL));
  //check room for gold
  if (cave[hunter.x][hunter.y].get_event()->event() == "G") {
    cout << "\nYou've found the gold! Quick, return back to your starting position to escape the cave with your treasure!" << endl;
  }

  if (cave[hunter.x][hunter.y].get_event()->event() == "B") {
    int x_rand = rand() % size;
    int y_rand = rand() % size;
    hunter.x = x_rand;
    hunter.y = y_rand;
    cout << "\nYou just entered the room with Bats! Your position was randomly displaced." << endl;
    display_cave(cave, size, mode, hunter);

  }

  if (cave[hunter.x][hunter.y].get_event()->event() == "S" && hunter.count == 2) {
    cout << "\nCongrats! you escaped the Wumpus' cave with the gold!" << endl;
    cout << "Would you like to play again? y/n " << endl;
    string ans;
    getline(cin, ans);
    if (ans == "n") {
      cout << "Thanks for playing!" << endl;
      exit (EXIT_FAILURE);
    }
    cout << "Would you like to restart the game with the same cave configuration (1) or a new one (2)?" << endl;
    getline(cin, ans);
    if (ans == "1") {
      //play(cave, size, b, p, w, g, hunter, s, mode);
    }
    if (ans == "2") {
      set_all(cave, size, b, p, w, g, f, hunter, s);
      //play(cave, size, b, p, w, g, hunter, s, mode);
    }
  }
}

/*********************************************************************
 * ** Function: check_adjacent1
 * ** Description: these functions aid in moving to the right rooms
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

void check_adjacent1(vector< vector< Room > > &cave, int size, string mode, Hunter& hunter) {

  bool moveUp = false, moveDown = false, moveLeft = false, moveRight = false;
  //find adjacent rooms
  int x_above = hunter.x - 1, y_above = hunter.y,
      x_below = hunter.x + 1, y_below = hunter.y,
      x_left = hunter.x, y_left = hunter.y - 1,
      x_right = hunter.x, y_right = hunter.y + 1;

  //check adjacent room validity
  if (x_above >=0 && x_above < size) {
    moveUp = true;
  }
  if (x_below >=0 && x_below < size) {
    moveDown = true;
  }
  if (y_left >=0 && y_left < size) {
    moveLeft = true;
  }
  if (y_right >=0 && y_right < size) {
    moveRight = true;
  }

  //check for percepts
  if (moveUp) {
    check_adjacent2(cave, x_above, y_above, hunter);
  }
  if (moveDown) {
    check_adjacent2(cave, x_below, y_below, hunter);
  }
  if (moveLeft) {
    check_adjacent2(cave, x_left, y_left, hunter);
  }
  if (moveRight) {
    check_adjacent2(cave, x_right, y_right, hunter);
  }
}

/*********************************************************************
 * ** Function: instructions
 * ** Description: these functions display the instructions for the player to make a move
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

void instructions(Hunter& hunter) {
  cout << "\n\nSelect any of the commands below to make your next move." << endl;
  cout << "\nCommands:" << endl;
  cout << "\tw (North)" << endl;
  cout << "\ts (South)" << endl;
  cout << "\td (East)" << endl;
  cout << "\ta (West)" << endl;
  cout << "\tw (North)" << endl;
  cout << "\tSpacebar + w, s, d, or a (Shoot Arrow + Direction)" << endl;
  cout << "\tq (Quit)" << endl;

  cout << "\nNumber of Arrows: " << hunter.num_arrows << endl;
  cout << "\nType your command ";
}

/*********************************************************************
 * ** Function: moves
 * ** Description: this function makes sure the players desired move is in bounds
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

void moves(Hunter& hunter, int size, string input) {
  if (input == "w") {
    while (hunter.x - 1 < 0) {
      cout << "You are trying to move out of bounds. Pick another direction" << endl;
      getline(cin, input);
      moves(hunter, size, input);
    }
    hunter.x = hunter.x - 1;
  }

  if (input == "s") {
    while (hunter.x + 1 > (size - 1)) {
      cout << "You are trying to move out of bounds. Pick another direction" << endl;
      getline(cin, input);
      moves(hunter, size, input);
    }
    hunter.x = hunter.x + 1;
  }

  if (input == "d") {
    while (hunter.y + 1 > (size - 1)) {
      cout << "You are trying to move out of bounds. Pick another direction" << endl;
      getline(cin, input);
      moves(hunter, size, input);
    }
    hunter.y = hunter.y + 1;
  }

  if (input == "a") {
    while (hunter.y - 1 < 0) {
      cout << "You are trying to move out of bounds. Pick another direction" << endl;
      getline(cin, input);
      moves(hunter, size, input);
    }
    hunter.y = hunter.y - 1;
  }
}

/*********************************************************************
 * ** Function: shoot_arrow
 * ** Description: these functions display the percept and return a letter for event type
 * ** Parameters: virutal percept() and event() functions
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

bool shoot_arrow(vector< vector< Room > > &cave, Hunter& hunter, int size, string input) {
  if (input == " ") {
    if (hunter.num_arrows == 0) {
      cout << "\nYou don't have enough arrows! Choose a different option" << endl;
      getline(cin, input);
    }
    cout << "\nIn which direction do you want to shoot? (w, s, d, a) " << endl;
    getline(cin, input);

    if (input == "w") {
      hunter.num_arrows = hunter.num_arrows - 1;
      if (cave[hunter.x - 1][hunter.y].get_event()->event() == "W") {
        cout << "\nYou killed the Wumpus!" << endl;
        return true;
      } else {
        cout << "No hit" << endl;
      }
    }

    if (input == "s") {
      hunter.num_arrows = hunter.num_arrows - 1;
      if (cave[hunter.x + 1][hunter.y].get_event()->event() == "W") {
        cout << "\nYou killed the Wumpus!" << endl;
        return true;
      } else {
        cout << "No hit" << endl;
      }
    }

    if (input == "d") {
      hunter.num_arrows = hunter.num_arrows - 1;
      if (cave[hunter.x][hunter.y + 1].get_event()->event() == "W") {
        cout << "\nYou killed the Wumpus!" << endl;
        return true;
      } else {
        cout << "No hit" << endl;
      }
    }

    if (input == "a") {
      hunter.num_arrows = hunter.num_arrows - 1;
      if (cave[hunter.x][hunter.y - 1].get_event()->event() == "W") {
        cout << "\nYou killed the Wumpus!" << endl;
        return true;
      } else {
        cout << "No hit" << endl;
      }
    }
  }
}

/*********************************************************************
 * ** Function: percept() & event()
 * ** Description: these functions display the percept and return a letter for event type
 * ** Parameters: virutal percept() and event() functions
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

bool player_status(vector< vector< Room > > &cave, Hunter& hunter, int size) {
  string input;
  getline(cin, input);
  moves(hunter, size, input);
  bool kill = shoot_arrow(cave, hunter, size, input);
  return kill;
}

/*********************************************************************
 * ** Function: percept() & event()
 * ** Description: these functions display the percept and return a letter for event type
 * ** Parameters: virutal percept() and event() functions
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

void play(vector< vector< Room > > &cave, int size, Bat& b, Pit& p, Wumpus& w, Gold& g, Fill& f, Hunter& hunter, HunterStart& s, string mode) {

string alive_message;
bool game_over = false;
hunter.num_arrows = 3;

//welcome messages
cout << "\nWelcome to the Dangerous World of Hunt the Wumpus" << endl;
cout << "Kill the Wumpus before it kills you!\n" << endl;

do {
    display_cave(cave, size, mode, hunter);
    alive_message = is_player_alive(cave, hunter);

    if (alive_message == "death_by_wumpus") {
      cout << "\nGame Over! You entered the Wumpus' room and got eaten!\n" << endl;
      game_over = true;
    }

    if (alive_message == "death_by_pit") {
      cout << "\nGame Over! You entered a room with a bottomless pit and fell to your demise!\n" << endl;
      game_over = true;
    }

    if (alive_message == "alive") {
      check_event(cave, size,b, p, w, g, f, hunter, s, mode);
      check_adjacent1(cave, size, mode, hunter);
      hunter.count = 2;
      instructions(hunter);
      if (!game_over) {
        game_over = player_status(cave, hunter, size);
      }
    }

} while (!game_over);

}

/*********************************************************************
 * ** Function: percept() & event()
 * ** Description: these functions display the percept and return a letter for event type
 * ** Parameters: virutal percept() and event() functions
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

void validate(int size) {
  if (size < 4) {
    cout << "Cave dimensions must be at least 4x4. Choose a larger number for 2nd argument." << endl;
    exit (EXIT_FAILURE);
  }
}
