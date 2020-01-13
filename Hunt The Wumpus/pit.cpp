#include <iostream>
#include "pit.h"

/*********************************************************************
 * ** Function: percept() & event()
 * ** Description: these functions display the percept and return a letter for event type
 * ** Parameters: virutal percept() and event() functions
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

string Pit::percept() {
  cout << "You feel a breeze." << endl;
}

string Pit::event() {
  return "P";
}
