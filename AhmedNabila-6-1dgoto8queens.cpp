#include <iostream>
using namespace std;

int main() {
   // Initialize the board to 0
   int q[8] = {};

   // Starts in the , 1st column, and place a queen there
   int c = 0;

nextCol:
   // Moves to the next column
   c++;
   // inside the if(you have passed the last column)
   if (c==8){
      goto print;
   }


   // Move to one before the first row
   q[c] = -1;

nextRow:
   // Moves to the next row
   q[c]++;
   //if (you have passed the end of the column)
   if (q[c]==8){
      goto backtrack;
   }

   // If there is a queen in the same row (to the left), goto nextRow
   for (int i=0;i<=c-1;i++){
      //if (there is a queen on that square)

      if (q[i] == q[c]){

         goto nextRow;
      }
   }
   // If there is a queen in the upper-left diagonal, goto nextRow
      //for (int i = 1; ...; i++)
   for (int i=1;i<=c;i++){
         // Ends the loop when you are above or left of the chessboard
      //if (there is a queen i spots above and left of the current square)
      if (q[c-i]== q[c]-i){

         goto nextRow;
      }
   }

   // If there is a queen in the lower-left diagonal, goto nextRow
     // for (int i = 1; ...; i++)
   for (int i=1;i<=c;i++) {
   // Ends the loop when you are below or left of the chessboard
      //if (there is a queen i spots below and left of the current square)
      if (q[c-i]== q[c]+i){
         goto nextRow;
      }
   }

   // Places a queen in the current square (2D version only)
   goto nextCol;

backtrack:
   c-=1; // Moves to the previous column
   //if (you have moved to the left of the chessboard)
   if (c<0){
      return 0;
   }
  goto nextRow;
      //exit the program

print:
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions<< ":\n";

   for(int i=0;i<8;i++){
         cout<< q[i];
    }

   cout<<endl;
   goto backtrack;
}
