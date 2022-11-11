#include <iostream>
using namespace std;

int main() {
  /*
    pseudocode for chapter 3 homework assignment

    create an array of strings with a size of 10.
    explain the story to the player, whatever story you wish to tell.
        the player starts with 3 items.
        over the course of several adventures, 
        1.  the player gains 3 items and has to name each of them.
            for example: BunnySword or FlameGuitar
             - because of cin limitations, the name can only be one word.
        2.  the player uses 1 item, making it go away.
        3. at each change in inventory - show the changes with a for loop that ignores strings that have "" no characters.
        
        For the final challenge, the player must give up their most treasured item to the bridge troll (or similar) to get past the bridge.
            The player will have to search for that item inside of a for loop.
*/
string inventory[] = {"","","","","","","","","",""};
int counter = 1;
cout << "You suddenly awaken in a camp next to a magical genie that will grant you three items of your choice: " << endl << endl;
cout << "You chose to wish for(one word names): " << endl;
for(int i = 1;i<=3;i++)
{
  cout << i << ": ";
  cin >> inventory[i];
}

cout << "Current inventory:" << endl;
for(int i= 1;i<=10;i++)
{
  if (inventory[i] != "")
  {
    cout << i << ": " << inventory[i] << endl;
  }
}

cout << "You feel the sudden desire to head home, so you begin to travel the land back to your village." << endl << endl;

do
{
  string answer;
  if (counter != 3)
  {
    cout << "You pass a person on your way home, you decide to give them one your items, you use: ";
  }
  else
  {
    cout << "You see a big troll on the bridge to your village, he asks you to pay the toll, you give him: ";
  }
  cin >> answer;

  if (answer == inventory[counter])
  {
     if (counter != 3)
     {
      cout << "You give them your " << inventory[counter] << " item, and they light up with extreme happiness." << endl <<endl;
      inventory[counter] = "";
      counter++;
      
      cout << "Current inventory:" << endl;
      for(int i= 1;i<=10;i++)
      {
        if (inventory[i] != "")
        {
          cout << i << ": " << inventory[i] << endl;
        }
      }
      cout << endl << endl;
     }
     else
     {
       cout << "You give the troll your final item, and he lets you pass" << endl << endl;
       counter++;
     }

  }
  else
  {
    cout << "Item not found in your inventory!" << endl << endl;
  }
} while(counter!=4);

cout << "You made it home safely and you live happily ever after!" << endl;

}