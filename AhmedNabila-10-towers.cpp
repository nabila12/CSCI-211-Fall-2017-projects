#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> t[3];
   int n;
   cout << "Please enter the number of rings to move: ";
   cin >> n;
   cout << endl;
   // The initial value of to depends on whether n is odd=1 or even =2
      int to;
      if(n%2==0){
            to=2;
      }else{
            to=1;
      }
   int from = 0, candidate = 1, move = 0;//candidate is the one that we are moving

   // Initialize the towers
   for(int i = n + 1; i >= 1; --i)
      t[0].push_back(i);
   t[1].push_back(n+1);
   t[2].push_back(n+1);

   while (t[1].size() < n+1) { // while t[1] does not contain all of the rings(nit full) there is till rings to transfer

      t[to].push_back(t[from].back());// get the last element from from and puch it to and remove it from from.
      t[from].pop_back();// takes out the ring from
      // Move the ring from the "from tower" to the "to tower" (first copy it, then delete it from the "from tower")
      cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower " << char(to+'A') << "\n";
if(n%2==1){// if there are an odd number of rings
      // from = the index of the tower with the smallest ring that has not just been moved: (to+1)%3 or (to+2)%3
         if (t[(to+1)%3].back() <t[(to+2)%3].back())
            from = (to+1)%3;
         else
            from = (to+2)%3;

         // candidate = the ring on top of the t[from] tower
         candidate = t[from].back();

         // to = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3
         // (compare the candidate with the ring on the closer tower; which tower is "closer" depends on whether n is odd or even)
         if (t[(from)%3].back() < t[(from+1)%3].back())
            to =(from +1)%3;
         else
            to =(from+2)%3;
    }
   else{// for even number
         // to = the index of the closest tower on which the candidate can be placed: (from+1)%3 or (from+2)%3
         // (compare the candidate with the ring on the closer tower; which tower is "closer" depends on whether n is odd or even)
         if (t[(to+1)%3].back() <t[(to+2)%3].back())
            from = (to+1)%3;
         else
            from = (to+2)%3;

         if (t[(from)%3].back() < t[(from+2)%3].back())
            to =(from +2)%3;
         else
            to =(from+1)%3;

         candidate = t[from].back();


      }

   }
    return 0;
}


