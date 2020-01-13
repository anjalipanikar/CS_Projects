#ifndef LINKED_LIST_H
#define LINKED_LIST_H

using namespace std;

template <class T>
class Node {
  public:
    T data;
    Node<T>* next;
    Node() {
      next = NULL;
    }
    ~Node() {}
};

template <class T>
class Linked_List {
  private:
    unsigned int length;
    Node<T>* headptr;
  public:
    Linked_List<T>() {
      length = 0;
      headptr = NULL;
    }
    void print();
    int get_length();
    unsigned int push_front(T val);
    unsigned int push_back(T val);
    unsigned int insert(T val, unsigned int index);
    Node<T>* merge(Node<T>* a, Node<T>* b);
    void merge_sort(Node<T>** a);
    void sort_ascending();
    void swap(Node<T>**, Node<T>*, Node<T>*, Node<T>*);
    Node<T>* select(Node<T>*);
    void sort_descending();
    bool is_prime(T num);
    void interface();
    void clear();
    ~Linked_List<T>() {
      clear();
    }

};

#endif
