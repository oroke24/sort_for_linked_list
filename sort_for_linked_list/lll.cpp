#include "lll.h"
node::node(int inData) { data = inData; }

/////////////////////////////////////////////////////////////
// BEGIN LIST METHODS

List::List() { head = nullptr; }
List::~List() {
  node *curr = head;
  while (head) {
    curr = head->next;
    delete head;
    head = curr;
  }
}

// Push function
void List::push(int inData) {
  node *temp = new node(inData);
  temp->next = head;
  head = temp;
}
//function to insert in sorted order
void List::insert_sorted(int inData){
  node * new_insertion_node = new node(inData);
  if(!head) head = new_insertion_node;
  else{
    node * prev = head;
    node * curr = head;
    while(curr && inData > curr->data){
       prev = curr; 
       curr = curr->next; 
    }
    prev->next = new_insertion_node;
    new_insertion_node->next = curr;
    
    
  }
}
// Sort function
void List::sort() {
  if (!head)
    std::cout << "empty, can't sort\n";
  else {
    node *i = head;
    while (i->next) {
      if (i->data > i->next->data) {
        node *j = i;
        while (j->next) {
          if (j->data > j->next->data) {
            swap(j, j->next);
          }
          j = j->next;
        }
        i = head;
      } else
        i = i->next;
    }
  }
}

// function to swap the data of two nodes
// IT DOES NOT SWAP THE ACTUAL POSTION OF THE NODE. THE 2 NODES TRADE DATA WITH
// EACHOTER.
void List::swap(node *a, node *b) {
  int placeHolder = a->data;
  a->data = b->data;
  b->data = placeHolder;
}
// function to print the list
void List::print() {
  if (!head)
    std::cout << "List empty.\n";
  else {
    node *curr = head;
    while (curr) {
      std::cout << curr->data;
      if (curr->next)
        std::cout << "->";
      curr = curr->next;
    }
    std::cout << std::endl;
  }
}