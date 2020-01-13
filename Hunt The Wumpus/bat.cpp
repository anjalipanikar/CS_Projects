#include <iostream>
#include "bat.h"

using namespace std;

/*********************************************************************
 * ** Function: percept() & event()
 * ** Description: these functions display the percept and return a letter for event type
 * ** Parameters: virutal percept() and event() functions
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

string Bat::percept() {
  cout << "You hear wings flapping." << endl;
}

string Bat::event() {
  return "B";
}
