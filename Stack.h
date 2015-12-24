//Muhammad Najib
//Stack.h
//Header file for Stack Data Structure
#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

//node to create a linked list
struct node{
 
  // data stores values of row and col
  int data;
  // next is pointer to next node
  node* next;

};


class stack{

 public:

  //constructor
  stack();

  //push item on top of stack
  void push(const int  & item);

  //remove top of stack
  void pop();

  //return top of stack
  int  top() const;

  //return true if stack empty
  bool empty () const;
 
 private:

  //node pointer to top node of stack
  node * _top;

};

#endif
