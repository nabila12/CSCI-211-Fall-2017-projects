#include <iostream>
using namespace std;
#include <cmath>

//Write a program to find the first perfect square(i*i) whose last two digitsare both odd.


int main(){

for(int i=1; i<=50; i++){
  int a= i*i;
  cout <<a<<endl;
  cout<<a%10<<endl;
  cout<< ((a/10)%10)<<endl;
      if ((((a/10)%10)%2) != 0 && (a%10)%2 !=0)         { cout<< "Number is found";}

  }
  cout << "Number is not found"<<endl;

return 0;


}
