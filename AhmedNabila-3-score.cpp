#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   while (true) {
   string outcome;
   cout << "Enter the race outcome in uppercase or enter  done to quit"<< endl;  // If the user entered "done", exit the program.
      cin >> outcome;
if (outcome == "done") {
 return 0;}

      int numTeams = 0;  // The number of teams
      int players  = 0; //players per team
      double scores[26] = {0}; // scores[i] keeps track    of the total score of team i
      int counts[26] = {0}; // counts[i] keeps track of the number of runners on team i

      for ( int i = 0; i < outcome.length(); i++)
      {
         counts[outcome[i]- 'A']++;
      }
       bool canContinue = true;

        for (int i = 0; i<26; i++)
         if (counts [i]!= 0){
            numTeams++;
         }
         cout<<"the number of teams is "<<numTeams<<endl;
            // Print the number of teams

            for (int i = 0; i<26; i++){

               if ( counts[i] !=0 && players == 0){
                  players = counts[i];
               }
                  if (counts[i] !=0 && players !=0){
                     if (counts [i] != players)
                     {   cout << "error"<< endl; // If the teams do not all have the same number of runners, PrintS an error message and ask for input again (goes back to the beginning of the loop)
                        canContinue= false;
                     }
                  }
            }
                     if (canContinue ==true){
                     cout<<"The number of players per team is "<<players<<endl;
                     // Prints the number of runners on each team
                     cout<<"Team"<<"  "<<"Score"<<endl;
                        int temp=25;
                           for ( int i = 0; i < outcome.length(); i++){
                              scores[outcome[i]- 'A'] += i+1;
                              if(temp>scores[i] && scores[i] !=0)
                              {   temp=i;
                              }
                           }

                                 for ( int i = 0; i < 26; i++){
                                    if ( scores[i] != 0){
                                       scores[i]= scores[i]/players;
                                       cout<<(char)(i+65)<<" "<<scores[i]<<endl;
                                    }
                                 }
                                    cout<<"The winning team is team "<<(char)(temp+65)<<" with the score of "<<scores[temp]<<endl;
                     }




      // For each letter from A-Z,
         // If that team participated,
            // Print the name of the team and its average score
            // Also keep track of which team(s) has the best score
      // Print the name of the winning team and its average score (if it's a tie, you may either pick one arbitrarily or print all of the winners)
}

return 0;
}


