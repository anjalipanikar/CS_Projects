#include <iostream>
#include "gold.h"

/*********************************************************************
 * ** Function: percept() & event()
 * ** Description: these functions display the percept and return a letter for event type
 * ** Parameters: virutal percept() and event() functions
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

string Gold::percept() {
  cout << "You see a glimmer nearby." << endl;
}

string Gold::event() {
   return "G";
}
