#include "zoo.h"

/*********************************************************************
 * ** Function: Default constructor
 * ** Description: This function initializes values for the start of the game, and creates arrays of correct size
 * ** Parameters: None
 * ** Pre-Conditions: Whenever an object of type "Zoo" is created, the values are initialized to those in the constructor
 * ** Post-Conditions: None
 * *********************************************************************/

 Zoo::Zoo() {
 	bank_balance = 100000;
 	month = 0;
 	eat = 80;

 	sealionNum = 0;
 	sealionArrSize = 10;
 	sealionArr = new Sea_Lion[sealionArrSize];

 	tigerNum = 0;
 	tigerArrSize = 10;
 	tigerArr = new Tiger[tigerArrSize];

 	blackbearNum = 0;
 	blackbearArrSize = 10;
 	blackbearArr = new Black_Bear[blackbearArrSize];
 }

 /*********************************************************************
  * ** Function: Destructor
  * ** Description: Removes dynamically allocated memory from the heap
  * ** Parameters: None
  * ** Pre-Conditions: An object of type "Zoo" is created
  * ** Post-Conditions: Respective memory removed from heap from each array
  * *********************************************************************/

 Zoo::~Zoo() {
 	delete [] tigerArr;
 	delete [] blackbearArr;
 	delete [] sealionArr;
 }

/***************************************************************************************************************************************************************************************************************
  * ** Function: welcome
  * ** Description: displays welcome message
  * ** Parameters: None
  * ** Pre-Conditions: none
  * ** Post-Conditions: none
  * ************************************************************************************************************************************************************************************************************/

void Zoo::welcome() {
   cout << "\n---------------------------------------------------------------Ready to build the ultimate Zoo? Welcome to Zoo Tycoon!-----------------------------------------------------------------" << endl;
   cout << "\n                                             The goal of this game is to build your zoo empire while making sure you never go bankruput! " << endl;
   cout << "                                                 Throughout the game you will gain and/or loose money depending on a variety of factors. " << endl;
   cout << "                               You will start the game with $100,000 dollars in your bank, which you can use a portion of to purchase your first set of animals. " << endl;
   cout << "                            After your first purchase, the game will start incrementing in months, and each months a different series of events will occur in your zoo. " << endl;
   cout << "                                               It's up to you to keep your business running smoothly despite any bumps in the road! Good luck!" << endl;
   cout << "\n\nFor your first purchase, you are allowed to buy up to 2 adult animals (both must be of the same species). Here are your options: " << endl;
 }

 /*********************************************************************
  * ** Function: control
  * ** Description: Controls the function, ensures the game continues as long as the user has more than $0 in their bank
  * ** Parameters: None
  * ** Pre-Conditions: Bank > 0
  * ** Post-Conditions: None
  * *********************************************************************/

 int Zoo::control() {
 	while (bank_balance > 0) {
 		display_inventory();
 		make_purchase();
    choose_food();
 		generate_revenue();
 		age_animals();
 		month++;
 		// for valgrind purposes, cap month at 100
 		if (month == 100)
 			return 0;
 	}
 	cout << "\n\tYou ran out of money and your check bounced! The animals were sold, and the zoo was shut down. Congratulations, you're now bankrupt!" << endl;
 	return 0;
 }

 /*********************************************************************
  * ** Function: display_inventory
  * ** Description: Displays the current statistics of each month
  * ** Parameters: None
  * ** Pre-Conditions: None
  * ** Post-Conditions: None
  * *********************************************************************/

 void Zoo::display_inventory() {
 	cout << "---------------------------------------------" << endl;
 	cout << "Month: " << month << endl;
 	cout << "Current Bank Balance: " << bank_balance << endl;
 	cout << "\nInventory of Animals" << endl;
 	cout << "\tSea Lions: " << sealionNum << endl;
 	cout << "\tTigers: " << tigerNum << endl;
 	cout << "\tBlack Bears: " << blackbearNum << endl << endl;
 }

 /*********************************************************************
  * ** Function: choose_food
  * ** Description: allows user to choose feed type
  * ** Parameters: None
  * ** Pre-Conditions: animals in inventory
  * ** Post-Conditions: redirected to random event generator
  * *********************************************************************/

 void Zoo::choose_food() {
   string s;
   int feed;
   cout << "Choose a type of feed for this month: (1) Regular (2) Premium (3) Cheap" << endl;
   "\nYour Selection: ";
   int feed1 = IntegerError(s, feed);
   switch (feed1) {
     case 1:
      regular_random();
      deduct_regular();
      break;
     case 2:
      premium_random();
      deduct_premium();
      break;
     case 3:
      cheap_random();
      deduct_cheap();
      break;
   }
 }

 /*********************************************************************
  * ** Function: x_random
  * ** Description: Selects an event at random between random sickness, birth, boom, or none
       in varying probabilities depending on feed type
  * ** Parameters: none
  * ** Pre-Conditions: specified feed type
  * ** Post-Conditions: random event generated
  * *********************************************************************/

 void Zoo::regular_random() {
  srand(time(NULL));
  int random;
  random = rand() % 4;
  cout << "\nRANDOM EVENT"<< endl;
  switch (random) {
    case 0: random_sickness();
      break;
    case 1: random_birth();
      break;
    case 2: random_boom();
      break;
    case 3:
      cout << "No special event occured this month!" << endl;
      break;
  }
 }

void Zoo::premium_random() {
  srand(time(NULL));
  int random;
  random = rand() % 7;
  cout << "\nRANDOM EVENT"<< endl;
  switch (random) {
    case 0: random_sickness();
      break;
    case 1: random_birth();
      break;
    case 2: random_birth();
      break;
    case 3: random_boom();
      break;
    case 4: random_boom();
      break;
    case 5:
      cout << "No special event occured this month!" << endl;
      break;
    case 6:
      cout << "No special event occured this month!" << endl;
      break;
  }
}

void Zoo::cheap_random() {
 srand(time(NULL));
 int random;
 random = rand() % 5;
 cout << "\nRANDOM EVENT"<< endl;
 switch (random) {
   case 0: random_sickness();
     break;
   case 1: random_sickness();
     break;
   case 2: random_birth();
     break;
   case 3: random_boom();
     break;
   case 4:
     cout << "No special event occured this month!" << endl;
     break;
 }
}

/*********************************************************************
 * ** Function: deduct_x
 * ** Description: deducts feeding cost from bank depending on feed type
 * ** Parameters: none
 * ** Pre-Conditions: specified feed type
 * ** Post-Conditions: feed cost deducted
 * *********************************************************************/

void Zoo::deduct_regular() {
  int food_per_month = 0;
  food_per_month = ((tigerNum * tigerArr[0].get_food_cost() * eat) +
      (blackbearNum * blackbearArr[0].get_food_cost() * eat) +
      (sealionNum * sealionArr[0].get_food_cost() * eat));
  cout << "\nFood cost from month " << month << " is: " << food_per_month << endl;
  bank_balance -= food_per_month;
  srand(time(NULL));
  eat = eat * (float((rand() % 40) + 80) / 100);  // random float 0.80 to 1.20 algorithm
  if (eat < 10)
    eat = 10;
}

void Zoo::deduct_premium() {
  int food_per_month = 0;
  food_per_month = ((tigerNum * tigerArr[0].get_food_cost() * eat) +
      (blackbearNum * blackbearArr[0].get_food_cost() * eat) +
      (sealionNum * sealionArr[0].get_food_cost() * eat));
  food_per_month = (food_per_month * 2);
  cout << "\nFood cost from month " << month << " is: " << food_per_month << endl;
  bank_balance -= food_per_month;
  srand(time(NULL));
  eat = eat * (float((rand() % 40) + 80) / 100);  // random float 0.80 to 1.20 algorithm
  if (eat < 10)
    eat = 10;
}

void Zoo::deduct_cheap() {
  int food_per_month = 0;
  food_per_month = ((tigerNum * tigerArr[0].get_food_cost() * eat) +
      (blackbearNum * blackbearArr[0].get_food_cost() * eat) +
      (sealionNum * sealionArr[0].get_food_cost() * eat));
  food_per_month = (food_per_month / 2);
  cout << "\nFood cost from month " << month << " is: " << food_per_month << endl;
  bank_balance -= food_per_month;
  srand(time(NULL));
  eat = eat * (float((rand() % 40) + 80) / 100);  // random float 0.80 to 1.20 algorithm
  if (eat < 10)
    eat = 10;
}


 /*********************************************************************
  * ** Function: make_purchase
  * ** Description: The user can choose to purchase a species
  * ** Parameters: None
  * ** Pre-Conditions: None
  * ** Post-Conditions: They will be asked how many to purchase, and will be set to age 48 months (4 years) upon purchase
  * *********************************************************************/

 void Zoo::make_purchase() {
 	string s;
 	int choice;
 	do {
    cout << "\n|| Animals For Sale || " << endl;
    cout << "\n1. Sea Lion" << endl;
    cout << "   \t- Base Price: $700 per Sea Lion" << endl;
    cout << "   \t- Monthly Birth Rate: 1 newborn per month" << endl;
    cout << "   \t- Monthly Feeding Cost: base" << endl;
    cout << "   \t- Monthly Revenue Generated: $140 per month" << endl;
    cout << " " << endl;
    cout << "2. Tiger" << endl;
    cout << "   \t- Base Price: $12,000 per Tiger" << endl;
    cout << "   \t- Monthly Birth Rate: 3 newborn per month" << endl;
    cout << "   \t- Monthly Feeding Cost: base x 5" << endl;
    cout << "   \t- Monthly Revenue Generated: $1200 per month" << endl;
    cout << " " << endl;
    cout << "3. Black Bears" << endl;
    cout << "   \t- Base Price: $5,000 per Black Bear" << endl;
    cout << "   \t- Monthly Birth Rate: 2 newborn per month" << endl;
    cout << "   \t- Monthly Feeding Cost: base x 3" << endl;
    cout << "   \t- Monthly Revenue Generated: $500 per month" << endl;
 		cout << "\nYour selection? (1, 2, 3, 4 for no purchase, or 5 to quit game): ";
 		IntegerError(s, choice);
  } while (!(choice > 0 && choice < 6));
 	    switch (choice) {
 		     case 1: bought_sealion();
 			     break;
 		     case 2: bought_tiger();
 			     break;
 		     case 3: bought_blackbear();
 			     break;
 		     case 4:
           break;
         case 5:
           exit(EXIT_FAILURE);
 	     }
 }

 /*********************************************************************
  * ** Function: New Array
  * ** Description: These functions double the size of the array for the respective species when the number of animals in each array
  * 		equals the size of the array. This ensures memory does not go out of bound and avoids segfault
  * ** Parameters: None
  * ** Pre-Conditions: When number of species is equal to the current array size, this function executes
  * ** Post-Conditions: New array created, of double size, with each element and index remaining the same
  * *********************************************************************/

 void Zoo::tiger_new_array() {
 	tigerArrSize = tigerArrSize * 2;
 	Tiger* temp = new Tiger[tigerArrSize];
 	for (int i = 0; i < tigerNum; i++) {
 		temp[i] = tigerArr[i];
 	}
 	delete[] tigerArr;
 	tigerArr = temp;
 }

 void Zoo::blackbear_new_array() {
 	blackbearArrSize = blackbearArrSize * 2;
 	Black_Bear* temp = new Black_Bear[blackbearArrSize];
 	for (int i = 0; i < blackbearNum; i++) {
 		temp[i] = blackbearArr[i];
 	}
 	delete [] blackbearArr;
 	blackbearArr = temp;
 }

 void Zoo::sealion_new_array() {
 	sealionArrSize = sealionArrSize * 2;
 	Sea_Lion* temp = new Sea_Lion[sealionArrSize];
 	for (int i = 0; i < sealionNum; i++) {
 		temp[i] = sealionArr[i];
 	}
 	delete [] sealionArr;
 	sealionArr = temp;
 }

 /*********************************************************************
  * ** Function: Bought <animal>
  * ** Description: These functions ask the user how many animals they would like to buy. If the number of animals is greater
  * 		than the current array size, a new array is created (dynamically) of double size. If they purchase an animal
  * 		the age is initializes to 4 years old (48 months)
  * ** Parameters: None
  * ** Pre-Conditions: User chooses to purchase (1) Sea Lion (2) Tiger (3) Black Bear.
  * ** Post-Conditions: The users zoo inventory now contains the animals they purchased. Their bank is deducted the correct cost
  * *********************************************************************/

  void Zoo::bought_tiger() {
  	string s;
  	int numToBuy;
  	do {
      cout << " " << endl;
  		cout << "\nWould you like to buy (1) or (2) tigers?"
  			"\nYour Selection: ";
  		IntegerError(s, numToBuy);
  	} while (!(numToBuy == 1 || numToBuy == 2));
  	     for (int i = 0; i < numToBuy; i++ ) {
  		       if (tigerNum == tigerArrSize)
  			        tiger_new_array();
  		          tigerArr[i].set_age(48);
  		          tigerNum++;
  		          bank_balance -= tigerArr[0].get_cost();
  	}
  }

  void Zoo::bought_blackbear() {
  	string s;
  	int numToBuy;
  	do {
      cout << " " << endl;
  		cout << "\nWould you like to buy (1) or (2) black bears?"
  			"\nYour Selection: ";
  		IntegerError(s, numToBuy);
  	} while (!(numToBuy == 1 || numToBuy == 2));
  	   for (int i = 0; i < numToBuy; i++ ) {
  		     if (blackbearNum == blackbearArrSize)
  			      blackbear_new_array();
  		        blackbearArr[i].set_age(48);
  		        blackbearNum++;
  		        bank_balance -= blackbearArr[0].get_cost();
  	   }
  }

  void Zoo::bought_sealion() {
  	string s;
  	int numToBuy;
  	do {
      cout << " " << endl;
  		cout << "\nWould you like to buy (1) or (2) Sea Lions?"
  			"\nYour Selection: ";
  		IntegerError(s, numToBuy);
  	} while (!(numToBuy == 1 || numToBuy == 2));
  	    for (int i = 0; i < numToBuy; i++ ) {
  		     if (sealionNum == sealionArrSize)
  			      sealion_new_array();
  		        sealionArr[i].set_age(48);
  		        sealionNum++;
  		        bank_balance -= sealionArr[0].get_cost();
  	    }
  }

  /*********************************************************************
   * ** Function: age_animal
   * ** Description: This function iterates through all current animals, on a weekly basis, and increases their age by one (+1 week to age)
   * ** Parameters: None
   * ** Pre-Conditions: Animals exist in the zoo
   * ** Post-Conditions: Existing animals have their age incremented by one
   * *********************************************************************/

   void Zoo::age_animals() {
   	// Tigers
   	for (int i = 0; i < tigerNum; i++) {
   		tigerArr[i].set_age(tigerArr[i].get_age() + 1);
   	}

   	// Black Bears
   	for (int i = 0; i < blackbearNum; i++) {
   		blackbearArr[i].set_age(blackbearArr[i].get_age() + 1);
   	}

   	// Sea Lions
   	for (int i = 0; i < sealionNum; i++) {
   		sealionArr[i].set_age(sealionArr[i].get_age() + 1);
   	}
   }

  /*********************************************************************
   * ** Function: generate_revenue
   * ** Description: Calculates revenue for each animal (different age means different revenue) and adds to users bank. Outputs value
   * ** Parameters: None
   * ** Pre-Conditions: User has animals in their inventory
   * ** Post-Conditions: Users bank now has more money
   * *********************************************************************/

   void Zoo::generate_revenue() {
   	int revenue_per_month = 0;
   	// Tigers
   	for (int i = 0; i < tigerNum; i++) {
   		if (tigerArr[i].get_age() < 6) {
   			bank_balance += 2400;
   			revenue_per_month += 2400;
   		}
   		else {
   			bank_balance += 1200;
   			revenue_per_month += 1200;
   		}
   	}

   	// Black Bears
   	for (int i = 0; i < blackbearNum; i++) {
   		if (blackbearArr[i].get_age() < 6) {
   			bank_balance += 1000;
   			revenue_per_month += 1000;
   		}
   		else {
   			bank_balance += 500;
   			revenue_per_month += 500;
   		}
   	}

   	// Sea Lions
   	for (int i = 0; i < sealionNum; i++) {
   		if (sealionArr[i].get_age() < 6) {
   			bank_balance += 280;
   			revenue_per_month += 280;
   		}
   		else {
   			bank_balance += 140;
   			revenue_per_month += 140;
   		}
   	}
   	cout << "Revenue from Month " << month << " is: " << revenue_per_month << endl;
   }


   /*********************************************************************
    * ** Function: <animal>ArrPushback
    * ** Description: These functions push back the array if an animal dies from some species.
    * ** Parameters: Random variable that indicates which species died
    * ** Pre-Conditions: Random species sickness event occurs, users bank does not have enough to heal animal
    * ** Post-Conditions: New array with index removed and array pushed back
    * *********************************************************************/

   void Zoo::tigerArrPushback(int randomVar) {
   	Tiger* temp = new Tiger[tigerArrSize];
   	for (int i = 0; i < tigerNum; i++) {
   		if (!(i == randomVar))
   			temp[i] = tigerArr[i];
   	}
   	delete [] tigerArr;
   	tigerArr = temp;
   	tigerNum = tigerNum - 1;
   }

   void Zoo::blackbearArrPushback(int randomVar) {
   	Black_Bear * temp = new Black_Bear[blackbearArrSize];
   	for (int i = 0; i < blackbearNum; i++) {
   		if (!(i == randomVar))
   			temp[i] = blackbearArr[i];
   	}
   	delete [] blackbearArr;
   	blackbearArr = temp;
   	blackbearNum = blackbearNum - 1;
   }

   void Zoo::sealionArrPushback(int randomVar) {
   	Sea_Lion * temp = new Sea_Lion[sealionArrSize];
   	for (int i = 0; i < sealionNum; i++) {
   		if (!(i == randomVar))
   			temp[i] = sealionArr[i];
   	}
   	delete [] sealionArr;
   	sealionArr = temp;
   	sealionNum = sealionNum - 1;
   }

   /*********************************************************************
    * ** Function: Random_sickness
    * ** Description: This function occurs at chance, it is a random event. It Sickens an animal at random. It then deducts the
    * 		users bank half the initial cost of the animal. If the user does not have enough money,
    * 		the animal dies. Array is pushed back for that index
    * ** Parameters: None
    * ** Pre-Conditions: Random_sickness occurs
    * ** Post-Conditions: Bank deducted or <animal>ArrPushback occurs
    * *********************************************************************/
   int Zoo::random_sickness() {
   	int randomVar;
   	do {
   	randomVar = rand() % 3; // this chooses a random species (3)
   	if (tigerNum == 0 && blackbearNum == 0 && sealionNum == 0)
   		return 1;
   	} while ((randomVar == 0 && tigerNum == 0) || (randomVar == 1 && blackbearNum == 0) || (randomVar == 2 && sealionNum == 0));

   	switch (randomVar) {
   		case 0: {
   				randomVar = rand() % tigerNum;
   				if (bank_balance > tigerArr[randomVar].get_cost()) {
   					bank_balance = bank_balance - (tigerArr[randomVar].get_cost() / 2);
   					cout << "A random sickness occured! In order to heal this animal, you were required to pay $" << (tigerArr[randomVar].get_cost() / 2)  << endl;
   				}
   				else {
   					cout << "A random sickness occured! You didn't have enough money to heal this animal and it passed away." << endl;
   					tigerArrPushback(randomVar);
   				}
   			}
   			break;

   		case 1: {
   				randomVar = rand() % blackbearNum;
   				if (bank_balance > blackbearArr[randomVar].get_cost()) {
   					bank_balance = bank_balance - (blackbearArr[randomVar].get_cost() / 2);
   					cout << "A random sickness occured! In order to heal this animal, you were required to pay $" << (blackbearArr[randomVar].get_cost() / 2)  << endl;
   				}
   				else {
   					cout << "A random sickness occured! You didn't have enough money to heal this animal and it passed away" << endl;
   					blackbearArrPushback(randomVar);
   				}
   			}
   			break;

   		case 2: {
   				randomVar = rand() % sealionNum;
   				if (bank_balance > sealionArr[randomVar].get_cost()) {
   					bank_balance = bank_balance - (sealionArr[randomVar].get_cost() / 2);
   					cout << "A random sickness occured! In order to heal this animal, you were required to pay $" << (sealionArr[randomVar].get_cost() / 2)  << endl;
   				}
   				else {
   					cout << "A random sickness occured! You didn't have enough money to heal this animal and it passed away" << endl;
   					sealionArrPushback(randomVar);
   				}
   			}
   			break;

   	}
   }

   /*********************************************************************
    * ** Function: Adult_exists
    * ** Description: After random_birth occurs, this function ensures there is an adult of the species that exists
    * 		that can give birth. If one does not exist, the random event is skipped for the week
    * ** Parameters: The species selected
    * ** Pre-Conditions: Random_birth occurs (1/4 probability)
    * ** Post-Conditions: New babies added to array of zoo
    * *********************************************************************/

   bool Zoo::adult_exists(int randomVar) {
   	// Tiger
   	if (randomVar == 0) {
   		for (int i = 0; i < tigerNum; i++)
   			if (tigerArr[i].get_age() >= 48)
   				return true;
   	}

   	// Black Bear
   	else if (randomVar == 1) {
   		for (int i = 0; i < blackbearNum; i++)
   			if (blackbearArr[i].get_age() >= 48)
   				return true;
   	}

   	// Sea Lion
   	else if (randomVar == 2) {
   		for (int i = 0; i < sealionNum; i++)
   			if (sealionArr[i].get_age() >= 104)
   				return true;

   	}
   	return false;
   }


   /*********************************************************************
    * ** Function: add_babies
    * ** Description: This function outputs added babies, checks array size to make sure there's room for them, initializes age
    * ** Parameters: Indicates the species selected at chance
    * ** Pre-Conditions: Random_birth selected (1/4 probability)
    * ** Post-Conditions: New species added to array. Potential for new array to have been created before species were added
    * *********************************************************************/

   void Zoo::add_babies(int randomVar) {
   	// Tigers
   	if (randomVar == 0) {
   		cout << "A random birth occured in the zoo! There are now " << tigerArr[0].get_num_babies() << " new baby Tigers!" << endl;
   		for (int i = 0; i < tigerArr[0].get_num_babies(); i++) {
   			if (tigerNum == tigerArrSize)
   				tiger_new_array();
   			  tigerArr[i].set_age(0);
   			  tigerNum++;
   		}
   	}

   	// Black Bears
   	if (randomVar == 1) {
   		cout << "A random birth occured in the zoo! There are now " << blackbearArr[0].get_num_babies() << " new baby Black Bears!" << endl;
   		for (int i = 0; i < blackbearArr[0].get_num_babies(); i++) {
   			if (blackbearNum == blackbearArrSize)
   				blackbear_new_array();
   			  blackbearArr[i].set_age(0);
   			  blackbearNum++;
   		}
   	}

   	// Sea Lions
   	if (randomVar == 2) {
   		cout << "A random birth occured in the zoo! There are now " << sealionArr[0].get_num_babies() << " new baby Sea Lions!" << endl;
   		for (int i = 0; i < sealionArr[0].get_num_babies(); i++) {
   			if (sealionNum == sealionArrSize)
   				sealion_new_array();
   			  sealionArr[i].set_age(0);
   			  sealionNum++;
   		}
   	}
   }

   /*********************************************************************
    * ** Function: Random_birth
    * ** Description: Users zoo, if it has adults of the specific species, contains new baby species starting at age zero
    * ** Parameters: None
    * ** Pre-Conditions: Random variable occurs in random_event (1/4 probability)
    * ** Post-Conditions: User now has the respective amount of babies of species added to their inventory
    * *********************************************************************/
   int Zoo::random_birth() {
   	int randomVar;
    bool check;
   	do {
        randomVar = rand() % 3; // this chooses a random species (3)
        if (tigerNum == 0 && blackbearNum == 0 && sealionNum == 0)
        return 1;
      } while ((randomVar == 0 && tigerNum == 0) || (randomVar == 1 && blackbearNum == 0) || (randomVar == 2 && sealionNum == 0));
   	    check = adult_exists(randomVar);
   	if (check == false)
   		return 1;
   	add_babies(randomVar);
   }

   /*********************************************************************
    * ** Function: Random Boom
    * ** Description: Random event (3) that appends the users bank with a random number (150-400) per number of sealions
    * ** Parameters: None
    * ** Pre-Conditions: Random variable occurs in random_event (1/4 probability)
    * ** Post-Conditions: Users bank now contains (150-400) * animal more money
    * *********************************************************************/
   void Zoo::random_boom() {
   	int randomInt = ((rand() % 400) + 300);
   	randomInt = (randomInt * sealionNum);
   	cout << "A random boom in the Zoo Attendance occured! You receieved a bonus of $" << randomInt << " from you Sea Lions." << endl;
   	bank_balance += randomInt;
   }

   /*********************************************************************
    * ** Function: IntegerEror
    * ** Description: This is an integer error checker
    * ** Parameters: String, Intgr
    * ** Pre-Conditions: User is required to enter an integer
    * ** Post-Conditions: Returns integer if they enter an integer, re-prompts input if they don't enter integer
    * *********************************************************************/
   int Zoo::IntegerError(string s, int& intgr) {
   	bool check = true;
   	do {
   		if (!check) {
   			cout << "Enter a valid Integer: ";
   		}
   		check = true;    // resets check boolean
   		getline(cin, s);

   		for (int i = 0; s[i]; i++) {
   			if (!isdigit(s[i])) {
   				check = false;
   			}
   		}
   	} while (!check); // atoi safe, checked before converted
   	intgr = atoi(s.c_str());
   	return intgr;
   }
