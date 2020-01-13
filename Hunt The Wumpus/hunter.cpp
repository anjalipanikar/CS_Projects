#include <iostream>
#include "hunter.h"

using namespace std;

/*********************************************************************
 * ** Function: event()
 * ** Description: these functions return specific event charachters
 * ** Parameters: virtual event function
 * ** Pre-Conditions: None
 * ** Post-Conditions: None
 * *********************************************************************/

string HunterStart::event(){
  return "S";
}

string Fill::event() {
  return " ";
}
