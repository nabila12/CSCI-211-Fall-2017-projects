#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
   for(int i =0; i <c-1;i++) //each i from 0 to c-1
      if (q[i]==q[c])//there is a conflict between the queens in columns i and c
         return false;
   return true;
}

void print(int q[]) {
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ": ";
   		for(int i=0; i<8; i++){
   			cout<<q[i];
		   }
   // Print the array
   cout << "\n";
}

int main() {
   int q[8] = {};   // Initialize the array to 0.
   int c=0;  // Start in the 1st row, 1st column
   while (c >= 0) {
    // End the loop if you backtrack from the first column
      	c++;// Move to the next column
     if(c==8){// If you have passed the last column,
     		print(int q[]);
		  	c-=1;} // Call the print function and backtrack
      else{q[c]= -1;
	   }// Otherwise, move to one before the first row
  
      while (c >= 0) {
         // Move to the next row
         // If you have passed the end of the column, backtrack
         // Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
         return true;
      }
   }
   return 0;
}
