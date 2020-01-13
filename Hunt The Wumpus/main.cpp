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
#include "gold.h"
#include "hunter.h"
#include "gameflow.h"

/******************************************************
** Program: main.cpp
** Author: Geethanjali Panikar
** Date: 11/15/2019
** Description: A terminal based simulation of the game Hunt The Wumpus
** Input: 3 command line arguments
** Output: Game Flow
******************************************************/

using namespace std;

int main (int argc, char** argv) {

  int size = atoi(argv[1]);
  string mode = argv[2];
  validate(size);

  vector<vector <Room> > cave(size);
    for (int i = 0; i < size; i++) {
      cave[i] = vector<Room> (size);
  }

  Fill f;
  Bat b;
  Pit p;
  Wumpus w;
  Gold g;
  Hunter hunter;
  HunterStart s;

  set_all(cave, size, b, p, w, g, f, hunter, s);
  play(cave, size, b, p, w, g, f, hunter, s, mode);

return 0;
}
