#include <iostream>
#include <stdlib.h>
#include <string>
#include "linked_list.h"

using namespace std;


/*********************************************************************
 * Function: print()
 * Description: follows each node pointer, then retrieves data value from
   nodes and prints to screen
 * Parameters: none
 * Pre-Conditions: an existing linked list
 * Post-Conditions: none
 * *********************************************************************/

template<class T>
void Linked_List<T>::print() {
  Node<T>* temp = headptr;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

/*********************************************************************
 * Function: get_length()
 * Description: retrieves private length variable from class and returns
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: none
 * *********************************************************************/

template<class T>
int Linked_List<T>::get_length() {
  return this->length;
}

/*********************************************************************
 * Function: push_front(T)
 * Description: adds a node at the front of the linked list
 * Parameters: value of type "Template"
 * Pre-Conditions: an existing linked list
 * Post-Conditions: new linked list with added node
 * *********************************************************************/

template<class T>
unsigned int Linked_List<T>::push_front(T n) {
Node<T>* new_node = new Node<T>;
new_node->data = n;
new_node->next = headptr;
headptr = new_node;
length++;
return length;
}

/*********************************************************************
 * Function: push_back(T)
 * Description: adds a node at the back of the linked list
 * Parameters: value of type "Template"
 * Pre-Conditions: an existing linked list
 * Post-Conditions: new linked list with added node
 * *********************************************************************/

template<class T>
unsigned int Linked_List<T>::push_back(T n) {
Node<T>* last = new Node<T>;
  last->data = n;
  last->next = NULL;
  if (headptr == NULL) {
    headptr = last;
    last = NULL;
  } else {
    Node<T>* temp = headptr;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = last;
      length++;
      return length;
    }
}

/*********************************************************************
 * Function: insert(T, unsigned int)
 * Description: adds a node at a user specified index
 * Parameters: value of type "Template", int index
 * Pre-Conditions: an existing linked list
 * Post-Conditions: new linked list with added node at user specified index
 * *********************************************************************/

template<class T>
unsigned int Linked_List<T>::insert(T val, unsigned int index) {
  Node<T>* node = new Node<T>;
   node->data = val;
   node->next = NULL;

   if (headptr == NULL) {
     if (index =! 0) {
      return length;
     } else {
      headptr = node;
     }
   }

   if (headptr != NULL && index == 0) {
     node->next = headptr;
     headptr = node;
     length++;
     return length;
   }

   Node<T>* current = headptr;
   Node<T>* previous = NULL;

   int i = 0;

   while (i < index) {
     previous = current;
     current = current->next;

     if (current == NULL) {
       break;
     }
      i++;
     }

     node->next = current;
     previous->next = node;

}

/**********************************************************************************
 * Function: swap(Node<T>**, Node<T>*, Node<T>*, Node<T>*)
 * Description: swaps pointer values of nodes for selection sort
 * Parameters: Double Node pointer to headptr, Node pointer to b, a, and previous a
 * Pre-Conditions: an existing linked list
 * Post-Conditions: Pointer positions of node a and b swapped
 * ********************************************************************************/

template<class T>
void Linked_List<T>::swap(Node<T>** headptr, Node<T>* b, Node<T>* a, Node<T>* prev_a) {
  Node<T>* temp;
  *headptr = a;
  prev_a->next = b;
  temp = a->next;
  a->next = b->next;
  b->next = temp;
}

/**********************************************************************************
 * Function: select(Node<T>*)
 * Description: recursively selects node pointer values to be swapped
 * Parameters: Node pointer to headptr
 * Pre-Conditions: an existing linked list
 * Post-Conditions: inserts paramters to swap() function
 * ********************************************************************************/

template<class T>
Node<T>* Linked_List<T>::select(Node<T>* headptr) {
  Node<T>* min = headptr;
  Node<T>* temp;
  Node<T>* before = NULL;

  if (headptr->next == NULL) {
    return headptr;
  }

  for (temp = headptr; temp->next != NULL; temp = temp->next) {
    if ((temp->next->data) > (min->data)) {
      min = temp->next;
      before = temp;
    }
  }

  if (min != headptr) {
    swap(&headptr, headptr, min, before);
    headptr->next = select(headptr->next);
  }
return headptr;
}

/*********************************************************************
 * Function: sort_descending()
 * Description: confirms that list is not empty, calls on select()
   function and passes through headptr
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: sorted list
 * ********************************************************************/

template<class T>
void Linked_List<T>::sort_descending() {
  if (headptr == NULL) {
    return;
  }

  headptr = select(headptr);
}

/*********************************************************************
 * Function: merge(Node<T>*, Node<T>*)
 * Description: recursivley merges pointer values until end of list is reached
 * Parameters: Node pointer to h1, Node pointer to h2
 * Pre-Conditions: an existing linked list
 * Post-Conditions: return temp & pointers merged
 * *********************************************************************/

template<class T>
Node<T>* Linked_List<T>::merge(Node<T>* h1, Node<T>* h2) {
   Node<T> *temp;

   if(h1 == NULL)
	return h2;

   if(h2 == NULL)
	return h1;

  if(h1->data > h2->data) {
      temp = h2;
      temp->next = merge(h1, h2->next);
    } else {
    temp = h1;
    temp->next = merge(h1->next, h2);
    }

    return temp;
}

/*********************************************************************
 * Function: merge(Node<T>**)
 * Description: recursivley merge sorts list
 * Parameters: Node double pointer to headptr
 * Pre-Conditions: an existing linked list
 * Post-Conditions: sorted liked list
 * *********************************************************************/

template<class T>
void Linked_List<T>::merge_sort(Node<T>** headptr) {
  Node<T>* first = *headptr;
  Node<T>* temp = *headptr;
  Node<T> *second;

  if(first == NULL || first->next == NULL){
    return;
  } else {
          while(first->next != NULL) {
      	 	first = first->next;
		if(first->next != NULL) {
	   		temp = temp->next;
	   		first = first->next;
		}
          }
	  second = temp->next;
	  temp->next = NULL;
	  first = *headptr;
  }
  merge_sort(&first);
  merge_sort(&second);
  *headptr = merge(first, second);
}

/********************************************************************************
 * Function: sort_ascending()
 * Description: calls on merge_sort() function and passes through headptr address
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: sorted list
 * *******************************************************************************/

template<class T>
void Linked_List<T>::sort_ascending() {
  merge_sort(&headptr);
}

/********************************************************************************
 * Function: is_prime()
 * Description: determines whether value is prime
 * Parameters: value of type "Template"
 * Pre-Conditions: none
 * Post-Conditions: returned boolean value
 * *******************************************************************************/

template<class T>
bool Linked_List<T>::is_prime(T n) {
int i;
bool isPrime = true;
	for (i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
		   isPrime = false;
		}
	}
  if (n == 1) {
    isPrime = false;
  }
return isPrime;
}

/********************************************************************************
 * Function: interface()
 * Description: displays user interface and calls all previously defined functions
 * Parameters: none
 * Pre-Conditions: none
 * Post-Conditions: user defined functionality
 * *******************************************************************************/

template<class T>
void Linked_List<T>::interface() {
int num_primes = 0;
char again;
char ans;
char sort;
do {
  do {
    cout << "Please enter a number: ";
    T num;
    cin >> num;
    bool prime = is_prime(num);
    if (prime) {
      num_primes++;
    }
    cout << "Would you like to add this number to:" << endl;
    cout << "\t(1) front of the linked list" << endl;
    cout << "\t(2) back of the linked list" << endl;
    cout << "\t(3) or at a specific index within the linked list?" << endl;
    cout << "Enter the number of your preferred option: ";
    int opt;
    cin >> opt;
    switch (opt) {
      case 1:
        push_front(num);
        break;
      case 2:
        push_back(num);
        break;
      case 3:
        cout << "At what integer index of the list would you like to insert your value? ";
        int index;
        cin >> index;
        insert(num, index);
        break;
    }
    cout << "Do you want to enter another number? (y or n): ";
    cin >> ans;
  } while (ans == 'y');

  cout << "Do you want to sort the list in ascending or descending order? (a or d): ";
  cin >> sort;
  if (sort == 'a') {
    sort_ascending();
    cout << "Your linked list is: ";
    print();
    cout << "You have " << num_primes << " prime number(s) in your list." << endl;
  } else {
    sort_descending();
    cout << "Your linked list is: ";
    print();
    cout << "You have " << num_primes << " prime number(s) in your list." << endl;
  }
  cout << "Do you want to do this again? (y or n): ";
  cin >> again;
} while (again == 'y');
  exit(EXIT_FAILURE);
}

/*********************************************************************
 * Function: clear()
 * Description: deletes all drynamic memory from linked list object
 * Parameters: none
 * Pre-Conditions: an existing linked list
 * Post-Conditions: none
 * *********************************************************************/

template<class T>
void Linked_List<T>::clear() {
Node<T>* to_delete = headptr;
while (to_delete != NULL) {
    Node<T>* next = to_delete->next;
    delete to_delete;
    to_delete = next;
  }
}

template class Linked_List<int>;
template class Linked_List<unsigned int>;
