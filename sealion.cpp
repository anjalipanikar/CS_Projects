#include "sealion.h"

/*********************************************************************
 * ** Function: Sea_Lion()
 * ** Description: This class inherits type "Animal" and instead of using a parametized constructor, it uses the mutators to
 * 		set the values of the Animal class for the species.
 * ** Parameters: None
 * ** Pre-Conditions: An object of type Sea_Lion is created
 * ** Post-Conditions: None
 * *********************************************************************/
Sea_Lion::Sea_Lion() {
    set_cost(700);
    set_age(0);
    set_num_babies(1);
    set_food_cost(1);
    set_revenue(140);
}
