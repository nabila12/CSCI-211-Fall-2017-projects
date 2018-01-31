#include <iostream>
using namespace std;

int main() {
   // Initialize the board to 0
   int q[8][8] = {};

   // Starts in the 1st row, 1st column, and place a queen there
   int r = 0, c = 0;
   q[r][c] = 1;

nextCol:
   // Moves to the next column
   c++;
   // inside the if(you have passed the last column)
   if (c==8){
      goto print;
   }


   // Move to one before the first row
   r = -1;

nextRow:
   // Moves to the next row
   r++;
   //if (you have passed the end of the column)
   if (r==8){
      goto backtrack;
   }

   // If there is a queen in the same row (to the left), goto nextRow
   for (int i=0;i<=c-1;i++){
      //if (there is a queen on that square)

      if (q[r][i] ==1){

         goto nextRow;
      }
   }
   // If there is a queen in the upper-left diagonal, goto nextRow
      //for (int i = 1; ...; i++)
   for (int i = 1; (r-i>=0) && (c-i>=0); i++){
         // Ends the loop when you are above or left of the chessboard
      //if (there is a queen i spots above and left of the current square)
      if (q[r-i][c-i] ==1){

         goto nextRow;
      }
   }

   // If there is a queen in the lower-left diagonal, goto nextRow
     // for (int i = 1; ...; i++)
   for (int i = 1; (r+i<8) && (c-i>=0); i++) {
   // Ends the loop when you are below or left of the chessboard
      //if (there is a queen i spots below and left of the current square)
      if (q[r+i][c-i] ==1){
         goto nextRow;
      }
   }

   // Places a queen in the current square (2D version only)
   q[r][c] =1;
   goto nextCol;

backtrack:
   c-=1; // Moves to the previous column
   //if (you have moved to the left of the chessboard)
   if (c<0){
      return 0;
   }
      //exit the program
   for(int i=0;i<8;i++){
      if(q[i][c] ==1){
         q[i][c] =0; // Removes the queen from the current square
         r=i; // Finds a the square in the column with a queen in it and sets r to the row number of that square
         goto nextRow;
      }
   }



print:
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions<< ":\n";

   for(int i=0;i<8;i++){
      cout<<endl;
      for(int j=0; j<8;j++){
      // a nested loop to print the chessboard
         cout<< q[i][j];
      }
   }
   cout<<endl;
   goto backtrack;
}
