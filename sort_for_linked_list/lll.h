#include <iostream>
struct node {
  int data;
  node *next;
  node(int inData);
};

class List {
private:
  node *head;

public:
  List();
  ~List();
  void push(int inData);
  void insert_sorted(int inData);
  void sort();
  void swap(node *a, node *b);
  void print();
};
