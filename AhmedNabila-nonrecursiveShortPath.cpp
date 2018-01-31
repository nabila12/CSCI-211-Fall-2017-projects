#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
int path[NUM_COLS];

// Calculates the cost of every square and fills in the cost matrix.
void calculateCosts() {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};

   static int cost[NUM_ROWS][NUM_COLS]=     {{3,0,0,0,0,0},
                                             {6,0,0,0,0,0},
                                             {5,0,0,0,0,0},
                                             {8,0,0,0,0,0},
                                             {3,0,0,0,0,0}};
   // Copy the leftmost column of the weight matrix to the cost matrix, and initialize the leftmost column of the path matrix.

   // For each remaining column,
   for(int i=1; i<NUM_COLS;i++ ){
     for(int j= 0; j<NUM_ROWS;j++){

   int up = weight[j][i]+ cost[(j+4)%5][i-1];
   int left = weight[j][i]+cost[j][i-1];
   int down = weight[j][i]+cost[(j+1)%5][i-1];// Calculate the cost of each square in the column (non-recursively),

   int a = min(min(up,left), down);
   cost[j][i]=a;

      }
    }
    int minRow=0;
    int minCost = cost[0][NUM_COLS-1];
    for(int r=1;r<NUM_ROWS;r++){

      if(cost[r][NUM_COLS-1]<minCost){
        minRow=r;
        minCost = cost[r][NUM_COLS-1];
      }
    }

    path[NUM_COLS-1]= minRow;

for(int c= NUM_COLS-2;c>=0;c--){
  int up= cost[(minRow +4)%5][c];
  int left = cost[minRow][c];
  int down = cost[(minRow+1)%5][c];

  int tempCost =up, tempRow = ((minRow + 4)%5);
  if (tempCost>left){
    tempCost=left;
    tempRow=minRow;
  }
  if (tempCost>down){
    tempCost=down;
    tempRow=(minRow+1)%5;
  }
  minRow=tempRow;
  path[c]=minRow;
}
cout << "The length of the shortest path is " << minCost;
   cout << ".\nThe rows of the path from left to right are " ;
   for(int c=0;c<NUM_COLS;c++){
     cout<<path[c]<<"";
   }
   cout<<"."<<endl;


}

int main() {
   calculateCosts();

   return 0;
}