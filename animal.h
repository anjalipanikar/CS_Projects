#ifndef ANIMAL_H
#define ANIMAL_H


class Animal {
    private:
      int cost;
      int age;
      int num_babies;
      int food_cost;
      int revenue;

    public:
		  Animal();
		  int get_cost() const;
		  int get_age() const;
		  int get_num_babies() const;
		  int get_food_cost() const;
		  int get_revenue() const;
		  void set_cost(int);
		  void set_age(int);
      void set_num_babies(int);
		  void set_food_cost(int);
		  void set_revenue(int);
};

#endif
