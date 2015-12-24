#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H
#include <iostream>
using namespace std;

class sudokuboard {

 public:

  //constructor  
  sudokuboard(string newboard[]);

  //place char n at row r and col c
  void place(size_t r, size_t c, char n);

  //return char at row r and col c
  char get(size_t r,size_t c) const;

  //replace char at row r and col c with '_'
  void remove(size_t r,size_t c);

  // return true if num can be placed
  // at row r and col c 
  bool canplace(char num, size_t r, size_t c) const;
  
  //print the sudoku board
  void print() const;

  //return true if all the places in board have been filled
  bool solved() const;

  //return true if most constrained square found
  //store location of that square in out_r & out_c
  bool  constrained(size_t & out_r, size_t & out_c);

 private:

  //string array of nine strings to hold sudokuboard values
  string sboard[9];

};

#endif
