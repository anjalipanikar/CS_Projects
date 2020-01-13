#ifndef ZOO_H
#define ZOO_H
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "tiger.h"
#include "sealion.h"
#include "blackbear.h"

using namespace std;

class Zoo {
	private:
		float eat;
		int bank_balance;
		int month;
		Tiger * tigerArr;
		Sea_Lion * sealionArr;
		Black_Bear * blackbearArr;
		int tigerNum;
		int sealionNum;
		int blackbearNum;
		int tigerArrSize;
		int sealionArrSize;
		int blackbearArrSize;
	public:
		Zoo();
		~Zoo();
    void welcome();
		int control();
		void display_inventory();
		void make_purchase();
		void generate_revenue();
		void choose_food();
		void regular_random();
		void deduct_regular();
		void premium_random();
		void deduct_premium();
		void cheap_random();
		void deduct_cheap();
		void age_animals();
		bool adult_exists(int);
		int random_sickness();
		int random_birth();
		void add_babies(int);
		void random_boom();
		void tigerArrPushback(int);
		void blackbearArrPushback(int);
		void sealionArrPushback(int);
		int IntegerError(string, int&);
		void tiger_new_array();
		void blackbear_new_array();
		void sealion_new_array();
		void bought_tiger();
		void bought_blackbear();
		void bought_sealion();

};

#endif
