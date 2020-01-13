#include "tiger.h"

/*********************************************************************
 * ** Function: Tiger()
 * ** Description: This class inherits type "Animal" and instead of using a parametized constructor, it uses the mutators to
 * 		set the values of the Animal class for the species.
 * ** Parameters: None
 * ** Pre-Conditions: An object of type Tiger is created
 * ** Post-Conditions: None
 * *********************************************************************/
Tiger::Tiger() {
    set_cost(12000);
    set_age(0);
    set_num_babies(3);
    set_food_cost(5);
    set_revenue(1200);
}
