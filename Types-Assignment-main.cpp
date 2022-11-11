#include <iostream>
using namespace std;

int main() {

  // 1. Variables
  int d = 1;
  float b = .30;
  string name = "Jason Kurtz";
  string fname = "";
  string lname = "";
  bool amICool = true;

//2. Modulus Operator
    if(d % 2 == 0)
    {
      // 3. Increment Operator
      d++;
      // 4. Decrement Operator
      d--;

      // 5. += and -=
      d+= 1;
      d-=1;
    }

// 6. Two inputs from player
    cout << "What's your first name?";
    cin>> fname;
    cout << "What's your last name?";
    cin>> lname;
// 7. Enumerators endless btw
do 
{
  cout << ("Hi there!");
} while(d == 1);

for(int i=1;i<40;i++)
{
  cout << "HEY!";
}

while(d == 1)
{
  cout << "Yo!";
}
// 8. Constants
  const bool COOLNESS= true;
}