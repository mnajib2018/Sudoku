//Muhammad Najib
//Stack.cc
//Stack.cc file defines the functions from header files

#include "stack.h"
#include <iostream>
#include <cassert>
using namespace std;

//constructor initializes _top
stack::stack()
{
  _top = NULL;
}

//push item on top of stack
//by creating new node and then 
//point _top to the new node
void stack::push(const int & item)
{

  node * p; p = new node;
  p -> data = item;
  p -> next = _top;
  _top = p;
 
}

//remove top of stack and
//point _top to next node
//by first creating new node
//and pointing it to next node
void stack::pop()
{

  assert(!empty());
  node * p; p = new node;
  p  = _top -> next;
  delete _top;
  _top = p;

}

//return value held at top of stack
int stack::top() const{

  return _top-> data;

}

//return true if stack is empty 
bool stack:: empty() const{

  return(_top == NULL);

}

