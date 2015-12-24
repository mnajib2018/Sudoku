/*#######################################################
# Sudoku.cc                                             #
# Muhammad Najib                                        #
# Project 3 Solve Sudokuboard                           #
# Feb 20, 2015                                          #
# Program solves a sudokuboard by repeatedly finding    #
# the most constrained square and inserting minimum     #
# value.It stores location of filled squares in a stack #
# to go back to previous locations as necessary.        #
#######################################################*/

#include <iostream>
#include "sudokuboard.h"
#include "stack.h"
#include <string.h>
using namespace std;

//solveboard returns true if board solved 
//uses while and for loop to repeatedly
//find the right value to enter
bool solveboard(sudokuboard & boardone)
{

 char digit;

 // stack to store all constrained row and col
 stack positions;

 //to store the row, col found by constrained function
 size_t out_r , out_c; 

 // bool to find if constrained square found or not
 bool placed;  

 // while loop runs until board is solved
 while(!boardone.solved())
 {
   // constrained returns true or false 
   //out_r, out_c get back most constrained square
   placed =  boardone.constrained(out_r,out_c);

  
   if(placed){
     for(char num = '1'; num <= '9'; num++)
     {
	 if(boardone.canplace(num, out_r, out_c))
         {
	   boardone.place(out_r, out_c, num);
	   positions.push(out_r);
	   positions.push(out_c);
     	   placed = true;
	   // break;
	 }
     }
   }
   
   // this loop if constrained square not found
 while(!placed){

     size_t  col = positions.top();positions.pop();
     size_t  row = positions.top();positions.pop();

     //get digit from that location and then remove it
     digit = boardone.get(row, col); 
     boardone.remove(row, col);
 
     //if all num tried start over for that square
     if(digit == '9') 
	digit = '0';
     //else check square for next digit 
      else
         digit++;

      boardone.print();cout<<endl;
     for(; digit <= '9'; digit++)
       {
       if(boardone.canplace(digit,row,col)){
	 // if(placed == false){
	   boardone.place(row, col, digit);
	   positions.push(row);
	   positions.push(col);
	   placed = true; 
	   // }
       }
     }
   }
 
 }
 //if board is solved return true, else false
 if(boardone.solved())
   return true;
 else  
   return false;

}



int main()
{

  //string array to store board values
  string newboard[9];
  
  // for each loop we take the whole row from input
  for(int i =0; i<9; i++)
    {
      cin>> newboard[i];
    }
  
  // initialize board object and pass the newboard array
  sudokuboard boardone(newboard);
 
  //if soveboard returns true print board or print not solved
  if(solveboard(boardone))
    boardone.print();

  else
    cout<<"not solved";
}
