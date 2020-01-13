#include <iostream>
#include "room.h"


/*********************************************************************
 * ** Function: Room::x
 * ** Description: these functions initialize, get, and return the event pointer
 * ** Parameters: none
 * ** Pre-Conditions: existing event pointer
 * ** Post-Conditions: None
 * *********************************************************************/

Room::Room() {
  this -> event = NULL;
}

Event* Room::get_event() {
  return this->event;
}

void Room::set_event(Event& event) {
  this->event = &event;
}
