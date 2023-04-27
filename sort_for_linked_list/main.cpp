#include "lll.h"
#include <fstream>
#include <iostream>
using namespace std;
void fill_list(List &list) {
  ifstream file;
  file.open("numbers.txt");
  int data;
  cout << "Inserting sorted" << endl;
  while (!file.eof()) {
    file >> data;
    // this is the standard push onto stack
    // list.push(data);
    // below is the custom sort insert
    list.insert_sorted(data);

    file.peek();
  }
}

int main() {
  List list;
  cout << "Filling list from file!\n";
  fill_list(list);

  // cout << "Unsorted: \n";
  //  list.print();

  // cout << "Sorted: \n";
  //  list.sort();
  list.print();
}