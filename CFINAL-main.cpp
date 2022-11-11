#include <iostream>

#include <string>

#include <vector>

#include <stdlib.h>

#include <cctype>

using namespace std;

enum en_DIRS {
NORTH,
EAST,
SOUTH,
WEST
}; //Directions

enum en_ROOMS {
SECRET_PASSAGE,
LIBRARY,
THRONE_ROOM,
KINGS_CHAMBERS,
CASTLE,
BARRACKS,
ARMORY,
STORE_ROOM,
RED_PORTAL,
PIG_PEN,
GARDEN,
VILLAGE,
HORSE_STABLES,
RIVERBED,
FOREST,
PLAINS,
DESERT,
DESERT_OASIS,
ANCIENT_RUINS,
FIELDS,
HELL,
PALACE,
BLUE_PORTAL,
LOBBY,
PORTAL_ROOM,
GREAT_BEYOND,
TAVERN,
GAMBLING_TABLE,
YELLOW_PORTAL,
VOID,
CORRIDOR
}; // Different discoverable rooms

enum en_VERBS {
GET,
HIT,
PET,
GO,
DROP,
USE,
OPEN,
CLOSE,
EXAMINE,
INVENTORY,
LOOK
};

//Added code
enum en_NOUNS {
STORE_DOOR,
MAGIC_ORB,
SWORD,
ROULETTE,
MONEY,
HORSE,
FISHROD,
KEY,
TREASURE_CHEST,
SKULL,
TRASH_CAN,
CORPSE,
DOG,
CAT,
BUNNY,
PIG,
};


const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 31;
const int VERBS = 12;

// Added code 
const int NOUNS = 17;

class words
{
  public:
  
  string word;
  int code;
  
  words() 
    { 
        word = " ";
        code = 0;
    } 
};

class room {
  public:
  string description;
  int exits_to_room[DIRS];
  room()
  {
    description = " ";
  }

  room(string desc)
  {
    description = desc;
  }
};


// Added code 
class noun
{
  
  public:
  
  string word;
  string description;
  int code;
  int location;
  bool can_attack;

  noun()
  {
    word=" ";
    description = " ";
    code = 0;
    location = 0;
    can_attack = false;
  }

  noun(string w, string d, int c, int l, bool cc)
  {
    word=w;
    description = d;
    code = c;
    location = l;
    can_attack = cc;
  }

};

void set_rooms(room * rms) 
{
  rms[LOBBY].description.assign("lobby of some sort");
  rms[LOBBY].exits_to_room[NORTH] = PORTAL_ROOM;
  rms[LOBBY].exits_to_room[EAST] = NONE;
  rms[LOBBY].exits_to_room[SOUTH] = TAVERN;
  rms[LOBBY].exits_to_room[WEST] = NONE;

  rms[TAVERN].description.assign("wonky old tavern");
  rms[TAVERN].exits_to_room[NORTH] = LOBBY;
  rms[TAVERN].exits_to_room[EAST] = NONE;
  rms[TAVERN].exits_to_room[SOUTH] = GAMBLING_TABLE;
  rms[TAVERN].exits_to_room[WEST] = NONE;

  rms[GAMBLING_TABLE].description.assign("decrepit gambling table"); // find money here
  rms[GAMBLING_TABLE].exits_to_room[NORTH] = TAVERN;
  rms[GAMBLING_TABLE].exits_to_room[EAST] = NONE;
  rms[GAMBLING_TABLE].exits_to_room[SOUTH] = NONE;
  rms[GAMBLING_TABLE].exits_to_room[WEST] = NONE;

  rms[PORTAL_ROOM].description.assign("convenient portal room");
  rms[PORTAL_ROOM].exits_to_room[NORTH] = FOREST;
  rms[PORTAL_ROOM].exits_to_room[EAST] = YELLOW_PORTAL;
  rms[PORTAL_ROOM].exits_to_room[SOUTH] = LOBBY;
  rms[PORTAL_ROOM].exits_to_room[WEST] = BLUE_PORTAL;

  rms[BLUE_PORTAL].description.assign("shimmering blue portal");
  rms[BLUE_PORTAL].exits_to_room[NORTH] = NONE;
  rms[BLUE_PORTAL].exits_to_room[EAST] = PORTAL_ROOM;
  rms[BLUE_PORTAL].exits_to_room[SOUTH] = NONE;
  rms[BLUE_PORTAL].exits_to_room[WEST] = NONE;

  rms[HELL].description.assign("area called the depths of hell");
  rms[HELL].exits_to_room[NORTH] = NONE;
  rms[HELL].exits_to_room[EAST] = NONE;
  rms[HELL].exits_to_room[SOUTH] = NONE;
  rms[HELL].exits_to_room[WEST] = FIELDS;

  rms[FIELDS].description.assign("fields of punishment");
  rms[FIELDS].exits_to_room[NORTH] = NONE;
  rms[FIELDS].exits_to_room[EAST] = HELL;
  rms[FIELDS].exits_to_room[SOUTH] = PALACE;
  rms[FIELDS].exits_to_room[WEST] = NONE;

  rms[PALACE].description.assign("palace of hades");
  rms[PALACE].exits_to_room[NORTH] = FIELDS;
  rms[PALACE].exits_to_room[EAST] = BLUE_PORTAL;
  rms[PALACE].exits_to_room[SOUTH] = NONE;
  rms[PALACE].exits_to_room[WEST] = NONE;

  rms[FOREST].description.assign("great green forest");
  rms[FOREST].exits_to_room[NORTH] = RIVERBED;
  rms[FOREST].exits_to_room[EAST] = PLAINS;
  rms[FOREST].exits_to_room[SOUTH] = PORTAL_ROOM;
  rms[FOREST].exits_to_room[WEST] = NONE;

  rms[PLAINS].description.assign("vast far-reaching plain");
  rms[PLAINS].exits_to_room[NORTH] = VILLAGE;
  rms[PLAINS].exits_to_room[EAST] = DESERT;
  rms[PLAINS].exits_to_room[SOUTH] = NONE;
  rms[PLAINS].exits_to_room[WEST] = FOREST;

  rms[DESERT].description.assign("deserted desert");
  rms[DESERT].exits_to_room[NORTH] = NONE;
  rms[DESERT].exits_to_room[EAST] = DESERT_OASIS;
  rms[DESERT].exits_to_room[SOUTH] = NONE;
  rms[DESERT].exits_to_room[WEST] = PLAINS;

  rms[DESERT_OASIS].description.assign("deserted desert oasis");
  rms[DESERT_OASIS].exits_to_room[NORTH] = NONE;
  rms[DESERT_OASIS].exits_to_room[EAST] = ANCIENT_RUINS;
  rms[DESERT_OASIS].exits_to_room[SOUTH] = NONE;
  rms[DESERT_OASIS].exits_to_room[WEST] = DESERT;

  rms[STORE_ROOM].description.assign("cluttered storeroom");
  rms[STORE_ROOM].exits_to_room[NORTH] = RED_PORTAL;
  rms[STORE_ROOM].exits_to_room[EAST] = CORRIDOR;
  rms[STORE_ROOM].exits_to_room[SOUTH] = NONE;
  rms[STORE_ROOM].exits_to_room[WEST] = NONE;

  rms[RED_PORTAL].description.assign("shimmering red portal");
  rms[RED_PORTAL].exits_to_room[NORTH] = NONE;
  rms[RED_PORTAL].exits_to_room[EAST] = STORE_ROOM;
  rms[RED_PORTAL].exits_to_room[SOUTH] = NONE;
  rms[RED_PORTAL].exits_to_room[WEST] = NONE;

  rms[CORRIDOR].description.assign("dark corridor");
  rms[CORRIDOR].exits_to_room[NORTH] = NONE;
  rms[CORRIDOR].exits_to_room[EAST] = CASTLE;
  rms[CORRIDOR].exits_to_room[SOUTH] = NONE;
  rms[CORRIDOR].exits_to_room[WEST] = NONE;

  rms[RIVERBED].description.assign("tranquil riverbed");
  rms[RIVERBED].exits_to_room[NORTH] = GARDEN;
  rms[RIVERBED].exits_to_room[EAST] = NONE;
  rms[RIVERBED].exits_to_room[SOUTH] = FOREST;
  rms[RIVERBED].exits_to_room[WEST] = NONE;

  rms[GARDEN].description.assign("bountiful garden");
  rms[GARDEN].exits_to_room[NORTH] = NONE;
  rms[GARDEN].exits_to_room[EAST] = VILLAGE;
  rms[GARDEN].exits_to_room[SOUTH] = RIVERBED;
  rms[GARDEN].exits_to_room[WEST] = PIG_PEN;

  rms[PIG_PEN].description.assign("disgusting pig pen");
  rms[PIG_PEN].exits_to_room[NORTH] = NONE;
  rms[PIG_PEN].exits_to_room[EAST] = GARDEN;
  rms[PIG_PEN].exits_to_room[SOUTH] = NONE;
  rms[PIG_PEN].exits_to_room[WEST] = NONE;

  rms[VILLAGE].description.assign("quiet little village");
  rms[VILLAGE].exits_to_room[NORTH] = CASTLE;
  rms[VILLAGE].exits_to_room[EAST] = HORSE_STABLES;
  rms[VILLAGE].exits_to_room[SOUTH] = PLAINS;
  rms[VILLAGE].exits_to_room[WEST] = GARDEN;

  rms[CASTLE].description.assign("prominent castle");
  rms[CASTLE].exits_to_room[NORTH] = THRONE_ROOM;
  rms[CASTLE].exits_to_room[EAST] = BARRACKS;
  rms[CASTLE].exits_to_room[SOUTH] = VILLAGE;
  rms[CASTLE].exits_to_room[WEST] = CORRIDOR;

  rms[BARRACKS].description.assign("bustling barracks");
  rms[BARRACKS].exits_to_room[NORTH] = NONE;
  rms[BARRACKS].exits_to_room[EAST] = ARMORY;
  rms[BARRACKS].exits_to_room[SOUTH] = NONE;
  rms[BARRACKS].exits_to_room[WEST] = CASTLE;
 
  rms[ARMORY].description.assign("twinkling armory");
  rms[ARMORY].exits_to_room[NORTH] = NONE;
  rms[ARMORY].exits_to_room[EAST] = NONE;
  rms[ARMORY].exits_to_room[SOUTH] = NONE;
  rms[ARMORY].exits_to_room[WEST] = BARRACKS;

  rms[THRONE_ROOM].description.assign("intimidating throne room");
  rms[THRONE_ROOM].exits_to_room[NORTH] = LIBRARY;
  rms[THRONE_ROOM].exits_to_room[EAST] = KINGS_CHAMBERS;
  rms[THRONE_ROOM].exits_to_room[SOUTH] = CASTLE;
  rms[THRONE_ROOM].exits_to_room[WEST] = NONE;

  rms[KINGS_CHAMBERS].description.assign("eloquent kingly chambers");
  rms[KINGS_CHAMBERS].exits_to_room[NORTH] = NONE;
  rms[KINGS_CHAMBERS].exits_to_room[EAST] = NONE;
  rms[KINGS_CHAMBERS].exits_to_room[SOUTH] = NONE;
  rms[KINGS_CHAMBERS].exits_to_room[WEST] = THRONE_ROOM;

  rms[LIBRARY].description.assign("ancient and vast library");
  rms[LIBRARY].exits_to_room[NORTH] = NONE;
  rms[LIBRARY].exits_to_room[EAST] = NONE;
  rms[LIBRARY].exits_to_room[SOUTH] = THRONE_ROOM;
  rms[LIBRARY].exits_to_room[WEST] = SECRET_PASSAGE;

  rms[SECRET_PASSAGE].description.assign("ancient passageway");
  rms[SECRET_PASSAGE].exits_to_room[NORTH] = NONE;
  rms[SECRET_PASSAGE].exits_to_room[EAST] = LIBRARY;
  rms[SECRET_PASSAGE].exits_to_room[SOUTH] = NONE;
  rms[SECRET_PASSAGE].exits_to_room[WEST] = RIVERBED;

  rms[ANCIENT_RUINS].description.assign("ancient ruin");
  rms[ANCIENT_RUINS].exits_to_room[NORTH] = NONE;
  rms[ANCIENT_RUINS].exits_to_room[EAST] = NONE;
  rms[ANCIENT_RUINS].exits_to_room[SOUTH] = VOID;
  rms[ANCIENT_RUINS].exits_to_room[WEST] = DESERT_OASIS;

  rms[HORSE_STABLES].description.assign("smelly horse stable");
  rms[HORSE_STABLES].exits_to_room[NORTH] = NONE;
  rms[HORSE_STABLES].exits_to_room[EAST] = NONE;
  rms[HORSE_STABLES].exits_to_room[SOUTH] = NONE;
  rms[HORSE_STABLES].exits_to_room[WEST] = VILLAGE;

  rms[YELLOW_PORTAL].description.assign("shimmering yellow portal");
  rms[YELLOW_PORTAL].exits_to_room[NORTH] = NONE;
  rms[YELLOW_PORTAL].exits_to_room[EAST] = NONE;
  rms[YELLOW_PORTAL].exits_to_room[SOUTH] = NONE;
  rms[YELLOW_PORTAL].exits_to_room[WEST] = PORTAL_ROOM;

  rms[GREAT_BEYOND].description.assign("realm of the great beyond");
  rms[GREAT_BEYOND].exits_to_room[NORTH] = NONE;
  rms[GREAT_BEYOND].exits_to_room[EAST] = VOID;
  rms[GREAT_BEYOND].exits_to_room[SOUTH] = NONE;
  rms[GREAT_BEYOND].exits_to_room[WEST] = YELLOW_PORTAL;

  rms[VOID].description.assign("void");
  rms[VOID].exits_to_room[NORTH] = ANCIENT_RUINS;
  rms[VOID].exits_to_room[EAST] = NONE;
  rms[VOID].exits_to_room[SOUTH] = NONE;
  rms[VOID].exits_to_room[WEST] = GREAT_BEYOND;
}

void set_directions(words * dir)
{
  dir[NORTH].code = NORTH;
  dir[NORTH].word = "NORTH";
  dir[EAST].code = EAST;
  dir[EAST].word = "EAST";
  dir[SOUTH].code = SOUTH;
  dir[SOUTH].word = "SOUTH";
  dir[WEST].code = WEST;
  dir[WEST].word = "WEST";
}

void set_verbs(words * vbs)
{
  vbs[GET].code = GET;
  vbs[GET].word = "GET";

  vbs[GO].code = GO;
  vbs[GO].word = "GO";

  vbs[HIT].code = HIT;
  vbs[HIT].word = "HIT";

  vbs[PET].code = PET;
  vbs[PET].word = "PET";

  vbs[DROP].code = DROP;
  vbs[DROP].word = "DROP";

  vbs[USE].code = USE;
  vbs[USE].word = "USE";
  vbs[OPEN].code = OPEN;
  vbs[OPEN].word = "OPEN";
  vbs[CLOSE].code = CLOSE;
  vbs[CLOSE].word = "CLOSE";
  vbs[EXAMINE].code = EXAMINE;
  vbs[EXAMINE].word = "EXAMINE";
  vbs[INVENTORY].code = INVENTORY;
  vbs[INVENTORY].word = "INVENTORY";
  vbs[LOOK].code = LOOK;
  vbs[LOOK].word = "LOOK";
}

// Added code 
void set_nouns(noun *nns)
{
  //STORE_DOOR,MAGIC_ORB,SWORD,ROULETTE,MONEY,FISHROD,KEY,TREASURE_CHEST,SKULL,TRASH_CAN,CORPSE,DOG,CAT,BUNNY,PIG,};
  nns[STORE_DOOR].word = "DOOR";
  nns[STORE_DOOR].code = STORE_DOOR;
  nns[STORE_DOOR].description = "a closed store room door"; 
  nns[STORE_DOOR].can_attack = false; 
  nns[STORE_DOOR].location = CORRIDOR; 

  nns[SKULL].word = "SKULL";
  nns[SKULL].code = SKULL;
  nns[SKULL].description = "a gnarly skull"; 
  nns[SKULL].can_attack = false; 
  nns[SKULL].location = NONE; 

  nns[CORPSE].word = "CORPSE";
  nns[CORPSE].code = CORPSE;
  nns[CORPSE].description = "a very old corpse"; 
  nns[CORPSE].can_attack = false; 
  nns[CORPSE].location = ANCIENT_RUINS; 

  nns[HORSE].word = "HORSE";
  nns[HORSE].code = HORSE;
  nns[HORSE].description = "a very giddy horse"; 
  nns[HORSE].can_attack = false; 
  nns[HORSE].location = HORSE_STABLES; 

  nns[STORE_DOOR].word = "DOOR";
  nns[STORE_DOOR].code = STORE_DOOR;
  nns[STORE_DOOR].description = "a closed store room door"; 
  nns[STORE_DOOR].can_attack = false; 
  nns[STORE_DOOR].location = CORRIDOR; 

  nns[KEY].word = "KEY";
  nns[KEY].code = KEY;
  nns[KEY].description = "a key to the storeroom"; 
  nns[KEY].can_attack = false; 
  nns[KEY].location = KINGS_CHAMBERS; 

  nns[MAGIC_ORB].word = "ORB"; 
  nns[MAGIC_ORB].code = MAGIC_ORB; 
  nns[MAGIC_ORB] .description = "a magic orb, capable of opening portals!"; 
  nns[MAGIC_ORB].can_attack = false; 
  nns[MAGIC_ORB].location = LIBRARY;

  nns[SWORD].word = "SWORD"; 
  nns[SWORD].code = SWORD; 
  nns[SWORD] .description = "a sword"; 
  nns[SWORD].can_attack = false; 
  nns[SWORD].location = ARMORY;

  nns[PIG].word = "PIG"; 
  nns[PIG].code = PIG; 
  nns[PIG] .description = "a big ol' piggy"; 
  nns[PIG].can_attack = false; 
  nns[PIG].location = PIG_PEN;

  nns[BUNNY].word = "BUNNY"; 
  nns[BUNNY].code = BUNNY; 
  nns[BUNNY] .description = "a small bunny"; 
  nns[BUNNY].can_attack = true; 
  nns[BUNNY].location = GARDEN;

  nns[ROULETTE].word = "ROULETTE"; 
  nns[ROULETTE]. code = ROULETTE; 
  nns[ROULETTE].description = "a roulette wheel"; 
  nns[ROULETTE].can_attack = false;
  nns[ROULETTE].location = GAMBLING_TABLE;

  nns[MONEY].word = "MONEY";
  nns[MONEY].code = MONEY;
  nns[MONEY].description = "some money";
  nns[MONEY].can_attack = true;
  nns[MONEY].location = NONE;

  nns[FISHROD].word = "ROD";
  nns[FISHROD].code = FISHROD;
  nns[FISHROD].description = "a fishing rod";
  nns[FISHROD].can_attack = false;
  nns[FISHROD].location = RIVERBED;
}

void section_command(string Cmd, string & wd1, string & wd2)
{
  string sub_str;
  vector<string> words;
  char search = ' ';
  size_t i, j;

  for (i = 0; i < Cmd.size(); i++)
  {
    if (Cmd.at(i) != search)
    {
      sub_str.insert(sub_str.end(), Cmd.at(i));
    }

    if (i == Cmd.size() - 1)
    {
      words.push_back(sub_str);
      sub_str.clear();
    }

    if (Cmd.at(i) == search)
    {
      words.push_back(sub_str);
      sub_str.clear();
    }
  }   
  for (i = words.size() - 1; i > 0; i--)
  {
    if (words.at(i) == "")
    {
      words.erase(words.begin() + i);
    }
  }

  for (i = 0; i < words.size(); i++)
  {
    for (j = 0; j < words.at(i).size(); j++)
    {
      if (islower(words.at(i).at(j)))
      {
        words.at(i).at(j) = toupper(words.at(i).at(j));
      }
    }
  }

  if (words.size() == 0)
  {
    cout << "No command given" << endl;
  }

  if (words.size() == 1)
  {
    wd1 = words.at(0);
  }

  if (words.size() == 2)
  {
    wd1 = words.at(0);
    wd2 = words.at(1);
  }

  if(words.size() > 2)
  {
    cout << "Command too long. Only type one or two words (direction or verb and noun)" << endl;
  }
}

void look_around(int loc, room * rms, words *dir, /* Added parameter */ noun * nns)
{
  int i;
  cout << "I am in a " << rms[loc].description << "." << endl;
  for (i = 0; i < DIRS; i++)
  if (rms[loc].exits_to_room[i] != NONE)
  cout << "There is an exit " << dir[i].word << " to a " << rms[rms[loc].exits_to_room[i]].description << "." << endl;
  // Added code 
  // The look command should check which objects (nouns) are in the current room and report them to the player. 
  for(i = 0; i < NOUNS; i++)
  {
    if (nns[i].location == loc)
    {
      cout << "I see " << nns[i].description << "." << endl;
    }
  }
}

bool parser(int & loc, string wd1, string wd2, words * dir, words * vbs, room  *rms, /* Added parameter */ noun * nns)
{
  // Added code 
  static bool door_state = false; // false if door is closed
  static bool key_state = false; // false if a key is on the ground
  static bool rod_state = false; // false if a rod is on the ground
  static bool orb_state = false; // false if a rod is on the ground
  static bool fish_state = false; // false if a fish has not been caught
  static bool red_state = false; // false if a fish has not been caught
  static bool blue_state = false; // false if a fish has not been caught
  static bool yellow_state = false; // false if a fish has not been caught
  static bool dirt_state = false; // false if the earth is untouched
  static bool sword_state = false; // false if the sword is untouched
  static int money_amount = 0;
  static bool gambling_state = false; // false if not gambling
  int i;



  // Added code 
  int NOUN_MATCH = NONE; 
  int VERB_ACTION = NONE;

  for (i = 0; i < VERBS; i++)
  {
    if (wd1 == vbs[i].word)
    {
      VERB_ACTION = vbs[i].code;
      break;
    }
  }


    for (i = 0; i < DIRS; i++)
  {
    if (wd2 ==dir[i].word)
    {
      if(VERB_ACTION == GO)
      {
        if (rms[loc].exits_to_room[dir[i].code] != NONE)
        {
          loc = rms[loc].exits_to_room[dir[i].code]; 
          cout << "I am now in a " << rms[loc].description << "." << endl; // Added code, A special case for the corridor STORE_ROOM door. 
          if(loc == STORE_ROOM || loc == CORRIDOR)
          {
            nns[STORE_DOOR].location = loc;
          }
          return true;
        }
        else
        {
          cout << "No exit that way." << endl;
          return true;
        }
      }
    }
  }
  // Added code 
  if(wd2 != "")
  {
    for (i = 0; i < NOUNS; i++)
    {
      if (wd2 == nns[i].word)
      {
        NOUN_MATCH = nns[i].code;
        break;
      }
    }
  }

  if (VERB_ACTION == NONE)
  {
    cout << "No valid command entered."<< endl;
    return true;
  }
  else if (VERB_ACTION == LOOK)
  {
    look_around(loc, rms, dir, /* Added parameter nns */ nns);
    return true;
  }
  else if (VERB_ACTION == HIT)
  {
    if(NOUN_MATCH == PIG)
    {
      if (loc == PIG_PEN)
      {
        if(sword_state == true)
        {
          cout << "I hit the pig, the pig bursts into pork chops! Yummy!" << endl;
          nns[PIG].location = NONE;

        }
        else
        {
          cout << "I hit the pig, the pig starts to cry... Why did I do something like that?" << endl;
        }
          
      }
      else
      {
        cout << "Nothing happens." << endl;
      }
    }
    else if(NOUN_MATCH == CORPSE)
    {
      if(loc == ANCIENT_RUINS)
      {
        cout << "I hit the corpse, causing all parts of the body except the skull to burst into white dust, strange." << endl;
        nns[CORPSE].location = NONE;
        nns[SKULL].location = ANCIENT_RUINS;
      }
      else
      {
        cout << "Nothing happens." << endl;
      }
    }
    else
    {
      cout << "Nothing to hit." << endl;
    }
    return true;
  }
  else if (VERB_ACTION == PET)
  {
    if(NOUN_MATCH == PIG)
    {
      if (loc == PIG_PEN)
      {
        cout << "I pet the pig, and the pig starts to cry... What is wrong with this pig?" << endl;
      }
      else
      {
        cout << "Nothing happens." << endl;
      }
    }
    else if(NOUN_MATCH == CORPSE)
    {
      if(loc == ANCIENT_RUINS)
      {
        cout << "I pet the corpse, and my hand smells like dead person now." << endl;
      }
      else
      {
        cout << "Nothing happens." << endl;
      }
    }
    else if(NOUN_MATCH == HORSE)
    {
      if(loc == HORSE_STABLES)
      {
        cout << "I pet the horse, and it shrugs and calms down." << endl;
        nns[HORSE].description = "a relatively calm horse";
      }
      else
      {
        cout << "Nothing happens." << endl;
      }
    }
    else if(NOUN_MATCH == BUNNY)
    {
      if (loc == GARDEN)
      {
        cout << "I pet the bunny, and he absolutely loves it!" << endl;
      }
      else
      {
        cout << "Nothing happens." << endl;
      }
    }
    else
    {
      cout << "Nothing to pet." << endl;
    }
    return true;
  }

  else if(VERB_ACTION == INVENTORY)
  {
    cout << "Current Inventory: " << endl <<endl;

    if(key_state == true)
    {
      cout << "-Key" << endl;
    }

    if(money_amount >0)
    {
      cout << "- "<< money_amount << " Gold" << endl;
    }
        
    if(fish_state == true)
    {
      cout << "-Fish" << endl;
    }

    if(sword_state == true)
    {
      cout << "-Sword" << endl;
    }

    if(rod_state == true)
    {
      cout << "-Rod" << endl;
    }
    if(orb_state == true)
    {
      cout << "-Orb" << endl;
    }
    
    if(orb_state != true && rod_state != true && key_state != true && fish_state != true && sword_state != true && money_amount <=0)
    {
      cout << "None" << endl;
    }
    return true;
  }
  // Added code 11 Actions for usage of VERB OPEN \
  else
  {
    if (VERB_ACTION == DROP)
    {
      if(key_state == true)
      {
        cout << "I dropped my key." << endl;
        nns[KEY].location= loc;
        key_state = false;
        return true;
      }
      
      if(rod_state == true)
      {
        cout << "I dropped my rod." << endl;
        nns[FISHROD].location= loc;
        rod_state = false;
        return true;
      }

      if(orb_state == true)
      {
        cout << "I dropped my orb." << endl;
        nns[MAGIC_ORB].location= loc;
        orb_state = false;
        return true;
      }

      if(sword_state == true)
      {
        cout << "I dropped my sword." << endl;
        nns[SWORD].location= loc;
        sword_state = false;
        return true;
      }
      
      if(orb_state != true && rod_state != true && key_state != true && sword_state != true)
      {
        cout <<"Nothing to drop!" << endl;
        return true;
      }
      
    }
    else if(VERB_ACTION == GET)
      {
        if (NOUN_MATCH == KEY && key_state == false && loc == nns[KEY].location)
        {
          cout << "Successfully picked up the key to the store room." << endl;
          nns[KEY].location= NONE;
          key_state = true;
        }
        else if (NOUN_MATCH == FISHROD && rod_state == false && loc == nns[FISHROD].location)
        {
          cout << "Successfully picked up the fishing rod." << endl;
          nns[FISHROD].location= NONE;
          rod_state = true;
        }
        else if (NOUN_MATCH == MAGIC_ORB && orb_state == false && loc == nns[MAGIC_ORB].location)
        {
          orb_state = true;
          cout << "Picked up a magical orb, maybe I should use this on portals?" << endl;
          nns[MAGIC_ORB].location= NONE;
        }
        else if (NOUN_MATCH == SWORD && sword_state == false && loc == nns[SWORD].location)
        {
          sword_state = true;
          cout << "Picked up sword, seems quite heavy." << endl;
          nns[SWORD].location= NONE;
        }
        else if (NOUN_MATCH == MONEY && loc == nns[MONEY].location)
        {
          nns[MONEY].location= NONE;
          cout << "PIcked up money, a nice gold piece." << endl;
          money_amount = money_amount + 1;
        }
        else
        {
          cout << "Nothing to get." << endl;
        }
      }
    else if(VERB_ACTION == USE)
      {
        if (NOUN_MATCH == KEY)
        {
          if (loc == CORRIDOR || loc == STORE_ROOM)
          {
            if (door_state == false && key_state != false)
            {
              door_state = true;
              rms[CORRIDOR].exits_to_room[WEST] = STORE_ROOM;
              rms[STORE_ROOM].exits_to_room[EAST] = CORRIDOR;
              nns[STORE_DOOR].description.clear();
              nns[STORE_DOOR].description.assign("an open store room door");
              cout << "I have opened the door." << endl;
              return true;
            }
            else if (door_state == true)
            {
              cout << "The door is already open." << endl;
              return true;
            }
          }
          else
          {
            cout << "There is no door to open here." << endl;
            return true;
          }
        }
        else if (NOUN_MATCH == FISHROD)
        {
          if (rod_state == true)
          {
            cout << "I cast my fishing rod onto the riverbed..(Press any key to continue)" << endl << endl;
            cin.ignore();
            cout << "I caught a fish!" << endl;
            fish_state = true;
            rod_state = false;
          }
        

        }
        else if (NOUN_MATCH == MAGIC_ORB)
          {
            if (orb_state == true)
            {
              if (loc == RED_PORTAL && red_state != true)
              {
                cout << "I use the magic orb, which opens the portal before me." << endl;
                red_state = true;
                rms[RED_PORTAL].exits_to_room[WEST] = ANCIENT_RUINS;
              }
              else if(loc == BLUE_PORTAL && blue_state != true)
              {
                cout << "I use the magic orb, which opens the portal before me." << endl;
                blue_state = true;
                rms[BLUE_PORTAL].exits_to_room[NORTH] = HELL;
              }
              else if(loc == YELLOW_PORTAL && yellow_state != true)
              {
                cout << "I use the magic orb, which opens the portal before me." << endl;
                yellow_state = true;
                rms[YELLOW_PORTAL].exits_to_room[EAST] = GREAT_BEYOND;
              }
              else
              {
                cout << "I use the magic orb, and nothing happens." << endl;
              }

              return true;
            }
          }
      }
    }
  return false;
  }

int main()
{
  string command;
  string word_1;
  string word_2;
  room rooms[ROOMS];
  set_rooms(rooms);
  words directions[DIRS];
  set_directions(directions);
  words verbs[VERBS];
  set_verbs(verbs);

  // Added code 
  noun nouns [NOUNS]; 
  set_nouns (nouns);

  int location = LOBBY;
  while (word_1 != "QUIT")
  {
    command.clear();
    cout << "what shall I do? "<< endl;
    getline(cin, command);

    word_1.clear(); 
    word_2.clear();
    

    section_command(command, word_1, word_2);

    if (word_1 != "QUIT")
    {
      parser(location, word_1, word_2, directions, verbs, rooms, /* Added parameter */nouns);
    }
  }
  return 0;
}