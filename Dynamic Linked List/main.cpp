#include <iostream>
#include <stdlib.h>
#include "linked_list.h"

int main() {

  cout << "Would you like to run the (1) int or (2) unsigned int version of this program?" << endl;
  cout << "Enter the number of your preferred option: ";
  int version;
  cin >> version;

  if (version == 1) {
    Linked_List<int> l;
    l.interface();
  } else {
    Linked_List<unsigned int> l;
    l.interface();
    l.clear();
  }
  
return 0;
}
