#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   // Reuse the ok function from your 1D 8 queens program.
  // Returns true if the queen in column c is ok
   for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

// This function should return the number of solutions for the given board size (you don't need to print the solutions).
int nqueens(int n) {
  int *q = new int[n];// Dynamically declare an array of size n and initialize the first element to 0.
   // Reuse the code from your 1D 8 queens program to find the solutions (you may have to make changes).
  q[0] = 0;   // Initialize the array to 0.
  int c = 0;       // Start on the first column
  int counter=0;
   while (c >= 0) {// End the loop if you backtrack from the first column
      c++;
      if (c == n) { // If you are in the last column, print and backtrack
         counter++;
         --c;
      }
      else                  // Otherwise, move to one before the first row of the next column
         q[c] = -1;
      while (c >= 0) {
         ++q[c];            // Move to the next row
         if (q[c] == n)     // If you have passed the end of the column, backtrack
            --c;
         else if (ok(q, c)) break;
         else continue;
      }


   }

    delete []q;  // Delete the array.
      return counter;// Return the number of solutions.
}
int main() {
   int n = 12;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}

