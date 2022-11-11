#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Health = 30;
int totalTreasure = 0;

void Story() {
  cout << "You wake up..." << endl;
  cout << "You have " << Health << " health."<< endl;
}

char AskYesNo(string question) {
  char answer;
  cout << question << endl;
  cin >> answer;
  return answer;
}

int RollDie(int sides)
{
  
  int randomSide = rand() % sides + 1;
  return randomSide;
}

void Ending()
{
  cout << "You return home with " << totalTreasure << " treasure!" << endl;
}

void Adventure()
{
  cout << "Let's go adventuring!" << endl;

  cout << "A monster appears, and begins to attack you when you try to steal it's treasure!" << endl;
  int enemyAttack = RollDie(6);
  int playerBlock = RollDie(6);
  int playerTreasure = RollDie(50);
  if(enemyAttack <= playerBlock)
  {
    cout << "You have successfully blocked!" << endl;
    Health -= 1;
    totalTreasure += playerTreasure;
    cout << "You lose 1 hp and gain " << playerTreasure << " treasure!" << endl;
    cout << "Your health is now " << Health << " and you have " << totalTreasure << " treasure."<<endl;
  }
  else if (enemyAttack > playerBlock)
  {
    Health = Health - enemyAttack;
    cout << "Your health is now " << Health << " and you have " << totalTreasure << " treasure." << endl;
  }
}

int main() {
  Story();
  bool looping = true;
  srand(time(0));
  do
  {
  char answer = AskYesNo("Will you go adventuring?(y/n)");
  if(answer == 'y' || answer =='Y')
  {
    Adventure();
  }
  else if(answer == 'n'|| answer == 'N')
  {
    Ending();
    looping=false;
  }
  }while(looping !=false || Health > 0);

}