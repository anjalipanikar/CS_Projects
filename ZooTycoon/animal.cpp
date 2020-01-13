#include "animal.h"

/*********************************************************************
 * ** Function: Animal()
 * ** Description: Default Constructor. Initializes values to zero
 * ** Parameters: None
 * ** Pre-Conditions: Object of type "Animal" or object of something that inherits type "Animal" will call this constructor
 * ** Post-Conditions: An object of type "Animal" or an object of something that inherits type "Animal" will possess values of this animal constructor
 * *********************************************************************/
Animal::Animal() {
    cost = 0;
    age = 0;
    num_babies = 0;
    food_cost = 0;
    revenue = 0;
}

/*********************************************************************
 * ** Function: Accessors / Getters
 * ** Description: These functions obtain values from the private member variables of class Animal.
 * ** Parameters: None
 * ** Pre-Conditions: An object of type Animal is created
 * ** Post-Conditions: Private member variables from this class can be obtained from other classes (if desired)
 * *********************************************************************/

int Animal::get_cost() const {
    return cost;
}
int Animal::get_age() const {
    return age;
}
int Animal::get_num_babies() const {
    return num_babies;
}
int Animal::get_food_cost() const {
    return food_cost;
}
int Animal::get_revenue() const {
    return revenue;
}

/*********************************************************************
 * ** Function: Mutators/ Setters
 * ** Description: These functions set values of private member variables of type Animal when the class is inherited
 * ** Parameters: These functions take in their respective member variable and set the variable of that object to the argument
 * ** Pre-Conditions: An object of type "Animal" or an object inherting class Animal is created and needed to alter the initialized values of the constructor
 * ** Post-Conditions: These values can be manipulated (more specifically, when cost, age, num_babies, food_cost, revenue need to be changed for different species);
 * *********************************************************************/
void Animal::set_cost(int cost) {
    this->cost = cost;
}
void Animal::set_age(int age) {
    this->age = age;
}
void Animal::set_num_babies(int num_babies) {
    this->num_babies = num_babies;
}
void Animal::set_food_cost(int food_cost) {
    this->food_cost = food_cost;
}
void Animal::set_revenue(int revenue) {
    this->revenue = revenue;
}
