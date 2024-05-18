/*
                          Deep-First Search in n-queen Problem
Deep-First Search is a method that is used to work on a tree data structure. It begins by selecting a path 
and thoroughly examining it, then moves on to the next way until all paths are completed. It can be used in a 
variety of development or problem-solving situations, such as maze development and Sudoku. Underneath the 
n-queen problem investigated in this code is also a Deep-First-Search algorithm (DFS). The problem is to focus 
on dealing with N queens on an N x N chessboard, and any two queens should not attack each other. As a result, 
the solution to the problem demands that two queens not be located in the same row, column, or diagonal. Some 
functions are created to check all directions to determine whether there might be an already-located queen or 
not. These functions are called inside the main part of the code to work together with the algorithm. The Deep 
First Search algorithm (DFS) produces queens in all boxes in a column. After that, it starts to control them all. 
If a queen encounters another queen in the searched column, it stops to inspect that column and moves on to the 
next column. It then proceeds to control the following column using the same method. When the algorithm identifies 
an appropriate spot for a queen, it shows 1, which represents a queen; otherwise, it displays 0, which represents 
a space. If the algorithm is right, the chess board with the outcome is written out. If not, the error message is 
displayed on the screen.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>

#define GAP " "
#define Q 4
/*
The name of the function: Print_chessboard()

Function description: The function is responsible for printing a chess board. 1 represents a queen and 0 represents an empty place.

Input: There are one input in this function. 
1. board[Q][Q] : this is an array to define chess board. 

Output: It prints out the chess board on the screen.

Function process: The Print_chessboard() function works on displaying a chess board using a matrix. Firstly, the function 
uses two loops to check every single row and column in the matrix. After that, if it finds an element that is 1, it prints '1' 
in that location. Otherwise, it prints '0'. 
*/
void Print_chessboard(int board[Q][Q])
{
  for(int i=0; i < Q; i++)
  {
    for(int j=0; j < Q; j++)
    {
      if (board[i][j] == 1)
        std::cout << GAP << "1";
      else
        std::cout<< GAP << "0";
    }
    std::cout << std::endl;
  }
}
/*
The name of the function: check_diagL()

Function description: The function checks if a queen is placed in the upper-left and lower-right diognal locations to be able 
to not put two queens in the same direction.

Input: There are three inputs in this function. 
1. board[Q][Q] : this is an array to define chess board. 
2. row: an integer equal to the row in which the queen is located
3. column: an integer corresponding to the coulmn where the queen is placed

Output: the function returns true or false 

Function process: The check_diagL() function's goal is to check rows and columns in the upper-left and lower-right directions 
of the located queen. In loops, i and j variables were equivalent to columns and rows. Then they both starts to check the 
locations at the same time. If, in the checking process, the function finds a 1 (queen), it returns false. If it does not find 
any queens, it returns true. 
*/
bool check_diagL(int row, int column, int board[Q][Q])
{
  for(int i = row, j = column; (i < Q) && (j < Q); i++, j++)
  {
    if(board[i][j] == 1)
      return false; // false, since the queen is there 
    // access the queen's location that might exist
  }

  for(int i = row, j = column; (i >= 0) && (j >= 0); i--, j--)
  {
    if(board[i][j] == 1)
      return false; 
  }
  return true;
}
/*
The name of the function: check_diagR()

Function description: The function checks if a queen is placed in the upper-right and lower-left diognal locations 
to be able to not put two queens in the same direction.

Input: There are three inputs in this function. 
1. board[Q][Q] : this is an array to define chess board. 
2. row: an integer equal to the row in which the queen is located
3. column: an integer corresponding to the coulmn where the queen is placed

Output: the function returns true or false 

Function process: The check diagR() method examines the rows and columns in the upper-right and lower-left directions of 
the found queen. In loops, the variables I and j represented columns and rows, respectively. Then they both begin to search 
for destinations at the same time. If the function discovers a 1 (queen) throughout the checking procedure, it returns false. 
If no queens are found, it returns true.
*/
bool check_diagR(int row, int column, int board[Q][Q])
{
  for(int i = row, j = column; (i >= 0) && (j < Q); i--, j++)
  {
    if(board[i][j] == 1)
      return false;
  }

  for(int i = row, j = column; (i < Q) && (j >= 0); i++, j--)
  {
    if(board[i][j] == 1)
      return false;
  }
  return true;
}
/*
The name of the function: check_row()

Function description: The function checks if a queen is placed in a row.

Input: There are two inputs in this function. 
1. board[Q][Q] : this is an array to define chess board. 
2. row: an integer equal to the row in which the queen is located

Output: the function returns true or false 

Function process: This function checks every single box in a row. If it finds a queen, it returns a false; if there are no queens, 
it returns true to say that this row does not contain any queen. 
*/
bool check_row(int row, int board[Q][Q])
{
  for(int i = 0; i < Q; i++) // i = column
  {
    if(board[row][i] == 1)
      return false;
  }
  return true;
}
/*
The name of the function: check_column()

Function description: The function checks if a queen is placed in a column.

Input: There are two inputs in this function. 
1. board[Q][Q] : this is an array to define chess board. 
2. column: an integer equal to the position of the queen in the column

Output: the function returns true or false 

Function process: This function checks each and every box in a column. If it discovers a queen, it returns false; if there 
are no queens, it returns true, indicating that this row has no queens.
*/
bool check_column(int column, int board[Q][Q])
{
  for(int i = 0; i < Q; i++)
  {
    if(board[i][column] == 1) // i = row
      return false;
  }
  return true;
}
/*
The name of the function: is_safe()

Function description: The function checks if a queen placed in a row, column or diognal ways in the chess board. 

Input: There are three inputs in this function. 
1. board[Q][Q] : this is an array to define chess board. 
2. row: an integer equal to the row in which the queen is located
3. column: an integer corresponding to the coulmn where the queen is placed

Output: the function returns true or false 

Function process: The is_sate() function's aim is to call the check_row(), the check_column(), the check_diagL() and 
the check_diagR(), which are responsibility of checking positions that are not threatening located queen. If all positions 
are safe for the located queen, it returns true. Otherwise, it returns false.
*/
bool is_safe(int board[Q][Q], int row, int column)
{
  return check_row(row, board) && check_column(column, board) && check_diagL(row, column, board) && check_diagR(row, column, board);
}
/*
The name of the function: SolveProblem()

Function description: This is the main function of whole code. Basically, in this function, it is supposed to solve the 
problem with N number of queens in NXN chess board.

Input: There are two inputs in this function. 
1. board[Q][Q] : this is an array to define chess board. 
2. column: an integer corresponding to the coulmn where the queen is placed

Output: the function returns true or false 

Function process: The function visit all possible locations to put a queen and then calls is_safe() function to check row, 
column and diaognal to find a already located queen or not. board[i][column] == 1 records the position of queen in the board 
array. Otherwise, it put 0 to this location. It does the same process to the next column as well. 
*/
bool SolveNQueen(int board[Q][Q], int column)
{
 if (column == Q)
 {
   return true;
 }

  for(int i=0; i < Q; i++) // visits all possible locations to put a queen
  {
    if(is_safe(board, i, column)) // checks all directions to find a queen already located
    {
      board[i][column] = 1;
      
      if(SolveNQueen(board, column+1)) // does the same thing in next location
      {
        return true;
      }
      board[i][column] = 0;
    }
  }
  return false;
}
/*
The name of the function: DisplayResult()

Function description: It displays the result on the chess board. 

Input: There are two inputs in this function. 
1. board[Q][Q] : this is an array to define chess board. 
2. column: an integer corresponding to the coulmn where the queen is placed

Output: the function returns nothing

Function process: This function display the result to the screen. It checks if the SolveProblem() is true, it prints the 
result with the result. Otherwise, it just prints an error message. 
*/
void DisplayResult()
{
  int board[Q][Q];
  int column = 0;

  if (true == SolveNQueen(board, column))
  {
    Print_chessboard(board);
  }
  else
  {
    std::cout << "No solution exists!" << std::endl;
  }
}

int main() {
  DisplayResult();
return 0;
}
