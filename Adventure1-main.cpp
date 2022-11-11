//Jason Kurtz
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  //welcome player
  cout << "Welcome to the game!" << endl;
  cout << "You encounter an unknown monster while venturing in a deep dark cave." << endl << endl;
//set up the game
int health = 10;
int counter = 0;
//seed the random number generator
srand(time(0));
while (health > 0 && counter <=(rand() % 4))
{
  srand(time(0));
  counter +=1;
  cout << "The monster moves in to attack you!" << endl;
  int attack = rand() % 4;
  int block = rand() % 4;
  if (block>=attack){
    cout << "You successfully blocked the monsters attack! Great job!" << endl;
  }
  else
  {
    health -= attack;
    cout << "The monster got you, your health is now ";
    cout << health;
    cout << " out of 10!" << endl;
  }
}

if(health > 0)
{
  cout << "Congrats! You survived long enough to get away from the monster!" << endl;
}
else
{
  cout << "Oh no! The monster got you and now you're dead!!"<<endl;
}
}