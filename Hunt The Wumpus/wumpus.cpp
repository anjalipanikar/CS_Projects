#include <iostream>
#include "wumpus.h"

/*********************************************************************
 * ** Function: percept() & event()
 * ** Description: these functions display the percept and return a letter for event type
 * ** Parameters: virutal percept() and event() functions
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

string Wumpus::percept() {
  cout << "You smell a terrible stench." << endl;
}

string Wumpus::event() {
   return "W";
}
