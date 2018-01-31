#include <iostream>

using namespace std;

//Stable marriage - the goal is to match each man with a woman while avoiding instabilities


bool ok(int q[],int c){
  static int mp[3][3] = { {0,2,1}, // Man#0's preferences
                        {0,2,1}, // Man#1's preferences
                        {1,2,0}}; // Man#2's preferences
  static int wp[3][3] = { {2,1,0}, // Woman#0's preferences
                        {0,1,2}, // Woman#1's preferences
                        {2,0,1}}; // Woman#2's preferences
    for(int i=0;i<c;i++){
      if(q[i] == q[c]){//checks that Man#i and Man#c are not married to the same women
        return false ;
      }

      if( (mp[c][q[c]]> mp[c][q[i]] && wp[q[i]][c]<wp[q[i]][i]) ||
        (wp[q[c]][c] > wp[q[c]][i] && mp[i][q[c]]<mp[i][q[i]])) //Man#i and man#c's wife both likes each other more than their own spouse or woman#i and woman#c's husband both likes each other more than their own spouse.
        return false;
    }return true;
}

void print(int q[]) {
   static int solution = 0;
   cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
   for (int i = 0; i < 3; ++i)
      cout << i << "\t" << q[i] << "\n";
   cout << "\n";

}
int main(){

  int q[3] = {0};   // Initialize the array to 0.
   int c=0;  // Start in the 1st row, 1st column
   while (c >= 0) {
    // End the loop if you backtrack from the first column
      	c++;// Move to the next column
     if(c==3){// If you have passed the last column,
     		print(q);
        c--;// Call the print function and backtrack
     }
         else{q[c]= -1;
         }// Otherwise, move to one before the first row

      while (c >= 0) {
         q[c]++;// Move to the next row
         if(q[c]>=3){
            c--;
         }else{
            if(ok( q, c)){
                 break; // Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
               }
            }
         }
      }
      return 0;
}


