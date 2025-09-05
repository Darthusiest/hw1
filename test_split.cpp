/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using std::cout;
using std::endl;

void printlist(Node* list);

int main(int argc, char* argv[])
{
  Node* in = new Node(1, nullptr);
  Node* odds = nullptr;
  Node* evens = nullptr;

  in->next = new Node(2, nullptr);
  in->next->next = new Node(3, nullptr);
  in->next->next->next = new Node(4, nullptr);

  split(in, odds, evens);

  cout << "Odds: ";
  printlist(odds);

  cout << "Evens: ";
  printlist(evens);

  cout << "in: ";
  printlist(in);

  return 0;
}

void printlist(Node* list){
  Node* cur = list;
  while(cur){
    cout << cur->value << ", ";
    cur = cur->next;
  }
  cout << endl;
}
