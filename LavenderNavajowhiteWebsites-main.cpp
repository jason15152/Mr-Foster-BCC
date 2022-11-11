#include <iostream>
#include <vector>
using namespace std;
int main() {
	  
		vector<string> names;
    vector<string>::iterator iter;

		string playerInput;

		do 
    {
			// list names

			// give the player their options
			// get player input
      cout << "Would you like to add,change,remove, or show names?" << endl << "Example input:(add,change,show,remove):" << endl;
      cin >> playerInput;
			
      
			
      if(playerInput == "add")// if(add name)
      {
        cout << "Okay what name would you like to add?" << endl;
        cin >> playerInput;

        names.push_back(playerInput);// add name to vector
        cout << "Added!" << endl;

      }
      else if(playerInput == "change")// else if(change name)
      {
        cout << "Okay what name would you like to change?" << endl;// what name to change?
        cin >> playerInput; // get input from player
       
       
       
        for(iter = names.begin(); iter != names.end(); iter++) 
        {
          if (*iter == playerInput)
          {
            
            cout << "What would you like to change " << playerInput << " to?" << endl;// change name to what?
            cin >> playerInput;// get input from player
            
            cout << *iter << " was changed to " << playerInput << "." << endl;
            *iter = playerInput;// old name = new name
            break;
          }
        }
      }
      else if(playerInput == "remove")// else if(remove name)
      {
        cout << "Okay what name would you like to delete?" << endl;// what name to remove?
        cin >> playerInput;// get input from player
        for(iter = names.begin(); iter != names.end(); iter++) {
          if (*iter == playerInput)
          {
            names.erase(iter);// remove name
            cout << *iter << " was deleted." <<endl;
            break;
          }
        }
      }
      else if(playerInput == "show")// else if(show names)
      {
        cout << "Current Names: " <<endl;
        sort(names.begin(), names.end());// sort names
        for(iter = names.begin(); iter != names.end(); iter++) // for loop to show every name
        {
          cout << *iter << endl;// use iterators and dereference operator
        }
      }
      else if(playerInput == "quit")// else if(quit)
      {
        cout <<"Quitting... " << endl;
        break;// break out of loop
      }
      else// else
      {
        cout<< "That isn't any of the available options! Try again!" << endl;// that's not one of the options!
      }

		} while(playerInput != "Quit" || playerInput != "quit");
		
    // thank player
    cout << "Thank you for playing!" << endl;
		// end game
    cout << "Fin." << endl;
	}