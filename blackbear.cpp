#include "blackbear.h"

/*********************************************************************
 * ** Function: Black_Bear()
 * ** Description: This class inherits type "Animal" and instead of using a parametized constructor, it uses the mutators to
 * 		set the values of the Animal class for the species.
 * ** Parameters: None
 * ** Pre-Conditions: An object of type Black_Bear is created
 * ** Post-Conditions: None
 * *********************************************************************/
Black_Bear::Black_Bear() {
    set_cost(5000);
    set_age(0);
    set_num_babies(2);
    set_food_cost(3);
    set_revenue(500);
}
