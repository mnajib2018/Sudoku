#include <iostream>
#include "sudokuboard.h"
using namespace std;

//constructor
sudokuboard::sudokuboard(string newboard[9]){

  //copy all strings from the string array in sboard
  for( int i =0; i < 9; i++)
    {
      sboard[i] = newboard[i];
    }

}

// places char n at position r,c
void sudokuboard::place(size_t r,size_t c ,char n){

  sboard[r][c] = n ;

} 

//return char at location row r and col c  
char sudokuboard::get(size_t r,size_t c) const{

  return sboard[r][c];

} 
 
// replace char at row r and col c with '_'
void sudokuboard::remove(size_t r,size_t c){

  sboard[r][c] = '_';

}

// Bool function to return true if four conditions are met
bool sudokuboard::canplace(char num, size_t r, size_t c) const
{

  //checks if num is present anywhere in same col
  for( int col= 0; col < 9 ; col++)
    {

      if( sboard[r][col] == num)
	return false;

    } 

  // checks if num is present in same row
  for ( int row = 0; row < 9; row++)
    {

      if(sboard[row][c] == num)
        return false;

    }

  // row_one for first row position of 3x3 box
  int row_one = (r/3)*3;

  // col_one for first col position of 3x3 box
  int col_one = (c/3)*3;
 
  //two for loops loop through each position in 3x3 box
  for(int i= row_one ; i < row_one + 3 ; i++)
    for(int j = col_one ; j < col_one + 3; j++)
    {
      //return false if num already in 3x3 box
      if(sboard[i][j] == num)
	return false;
    }

  // position at (r,c) already has a num return false
  if(sboard[r][c] != '_')
    return false; 
 
  // return true if all conditions met or false not returned yet
  return true;

}

//print sudokuboard to cout
void  sudokuboard::print() const{

  //each string holds a row
  //print each row in one line
  for(int i=0; i < 9; i++)
    {
      cout<< sboard[i] << endl;      
    }

}

//return true if all places filled in board
bool sudokuboard::solved() const {

  // loop through all values 
  // return false if board not filled completely

  for( int i=0; i < 9; i++)
    {
      for( int j=0; j < 9; j++)
        {
	  if(sboard[i][j] ==  '_')
	    return false;
	}
    }

  return true;
}

//find row, col of most constrained square
//return false if square not found
//out_r, out_c passed by reference
bool  sudokuboard::constrained(size_t & out_r, size_t & out_c) 
{ 

  //total stores total possible values for each square
  size_t total = 0;

  //min possible values after looping through all locations
  size_t min = 10;

  //loop through all locations
  for(size_t i =0; i < 9; i++ )
    {
      for (size_t j =0; j < 9; j++)
	{
          //set total to zero before every location
	  total = 0;

          //check for all possible values
          //increment total if num can be placed

	  for (char num ='1'; num <= '9'; num++)
	    {
	      if(canplace(num , i , j ))
		{
		  total++;
		}
	    }

          //if total is lower than or equal to min for a square 
          //store that square location in out_r, out_c

	  if(total <= min && total != 0)
	    {
              out_r = i; out_c = j;
	      min = total;
	    } 
	}
    }  
 
  //if min is unchanged, square not found
  if(min == 10)
        return false;

  else
        return true;
   
}
