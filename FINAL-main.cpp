#include <iostream>

#include <string>

#include <vector>

#include <cctype>

using namespace std;

enum Directions {
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
CASINO,
GAMBLING_TABLE,
YELLOW_PORTAL,
VOID,
CORRIDOR
}; // Different discoverable rooms

enum en_VERBS {
GET,
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
MAGNET,
METER,
ROULETTE,
MONEY,
FISHROD,
COBALT_DOOR,
IRON_DOOR,
WOODEN_DOOR,
TREASURE_CHEST,
SKULL,
TRASH_CAN,
CORPSE,
DOG,
CAT,
BUNNY
};

const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 30;
const int VERBS = 8;

// Added code 
const int NOUNS = 16;

class words
{
  public:
  string word;
  int code;
};

class room {
  public:
  string description;
  int exits_to_room[DIRS];
};

// Added code 
class noun
{
  public:
  string word;
  string description;
  int code;
  int location;
  bool can_carry;
};

void set_rooms(room * rms) 
{
  rms[LOBBY].description.assign("spawning lobby");
  rms[LOBBY].exits_to_room[NORTH] = PORTAL_ROOM;
  rms[LOBBY].exits_to_room[EAST] = NONE;
  rms[LOBBY].exits_to_room[SOUTH] = CASINO;
  rms[LOBBY].exits_to_room[WEST] = NONE;

  rms[CASINO].description.assign("state of the art casino");
  rms[CASINO].exits_to_room[NORTH] = LOBBY;
  rms[CASINO].exits_to_room[EAST] = NONE;
  rms[CASINO].exits_to_room[SOUTH] = GAMBLING_TABLE;
  rms[CASINO].exits_to_room[WEST] = NONE;

  rms[GAMBLING_TABLE].description.assign("a decrepit gambling table"); // find money here
  rms[GAMBLING_TABLE].exits_to_room[NORTH] = CASINO;
  rms[GAMBLING_TABLE].exits_to_room[EAST] = NONE;
  rms[GAMBLING_TABLE].exits_to_room[SOUTH] = NONE;
  rms[GAMBLING_TABLE].exits_to_room[WEST] = NONE;

  rms[PORTAL_ROOM].description.assign("convenient portal room");
  rms[PORTAL_ROOM].exits_to_room[NORTH] = FOREST;
  rms[PORTAL_ROOM].exits_to_room[EAST] = NONE;
  rms[PORTAL_ROOM].exits_to_room[SOUTH] = LOBBY;
  rms[PORTAL_ROOM].exits_to_room[WEST] = BLUE_PORTAL;

  rms[BLUE_PORTAL].description.assign("a shimmering blue portal");
  rms[BLUE_PORTAL].exits_to_room[NORTH] = HELL;
  rms[BLUE_PORTAL].exits_to_room[EAST] = PORTAL_ROOM;
  rms[BLUE_PORTAL].exits_to_room[SOUTH] = NONE;
  rms[BLUE_PORTAL].exits_to_room[WEST] = NONE;

  rms[HELL].description.assign("depths of hell");
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

  rms[DESERT_OASIS].description.assign("deserted desert");
  rms[DESERT_OASIS].exits_to_room[NORTH] = NONE;
  rms[DESERT_OASIS].exits_to_room[EAST] = ANCIENT_RUINS;
  rms[DESERT_OASIS].exits_to_room[SOUTH] = NONE;
  rms[DESERT_OASIS].exits_to_room[WEST] = DESERT;

  rms[STORE_ROOM].description.assign("cluttered storeroom");
  rms[STORE_ROOM].exits_to_room[NORTH] = NONE;
  rms[STORE_ROOM].exits_to_room[EAST] = CORRIDOR;
  rms[STORE_ROOM].exits_to_room[SOUTH] = NONE;
  rms[STORE_ROOM].exits_to_room[WEST] = RED_PORTAL;

  rms[RED_PORTAL].description.assign("shimmering red portal");
  rms[RED_PORTAL].exits_to_room[NORTH] = NONE;
  rms[RED_PORTAL].exits_to_room[EAST] = CORRIDOR;
  rms[RED_PORTAL].exits_to_room[SOUTH] = NONE;
  rms[RED_PORTAL].exits_to_room[WEST] = ANCIENT_RUINS;

  rms[CORRIDOR].description.assign("a dark corridor");
  rms[CORRIDOR].exits_to_room[NORTH] = NONE;
  rms[CORRIDOR].exits_to_room[EAST] = CASTLE;
  rms[CORRIDOR].exits_to_room[SOUTH] = NONE;
  rms[CORRIDOR].exits_to_room[WEST] = STORE_ROOM;

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

  rms[BARRACKS].description.assign("prominent castle");
  rms[BARRACKS].exits_to_room[NORTH] = NONE;
  rms[BARRACKS].exits_to_room[EAST] = ARMORY;
  rms[BARRACKS].exits_to_room[SOUTH] = NONE;
  rms[BARRACKS].exits_to_room[WEST] = CASTLE;
 
  rms[ARMORY].description.assign("twinkling armory");
  rms[ARMORY].exits_to_room[NORTH] = NONE;
  rms[ARMORY].exits_to_room[EAST] = NONE;
  rms[ARMORY].exits_to_room[SOUTH] = NONE;
  rms[ARMORY].exits_to_room[WEST] = BARRACKS;

  rms[CASTLE].description.assign("intimidating throne room");
  rms[CASTLE].exits_to_room[NORTH] = LIBRARY;
  rms[CASTLE].exits_to_room[EAST] = KINGS_CHAMBERS;
  rms[CASTLE].exits_to_room[SOUTH] = CASTLE;
  rms[CASTLE].exits_to_room[WEST] = NONE;

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

  rms[HORSE_STABLES].description.assign("smelly horse stable");
  rms[HORSE_STABLES].exits_to_room[NORTH] = NONE;
  rms[HORSE_STABLES].exits_to_room[EAST] = NONE;
  rms[HORSE_STABLES].exits_to_room[SOUTH] = NONE;
  rms[HORSE_STABLES].exits_to_room[WEST] = VILLAGE;
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
  //enum en_NOUNS {STORE_DOOR, MAGNET, METER, ROULETTE, MONEY, FISHROD};
  nns[STORE_DOOR].word = "DOOR";
  nns[STORE_DOOR].code = STORE_DOOR;
  nns[STORE_DOOR].description = "a closed store room door"; 
  nns[STORE_DOOR].can_carry = false; 
  nns[STORE_DOOR].location = STORE_ROOM; 
  nns[MAGNET].word = "MAGNET"; 
  nns[MAGNET].code = MAGNET; 
  nns[MAGNET] .description = "a magnet"; 
  nns[MAGNET].can_carry = true; 
  nns[MAGNET].location = NONE; 
  nns[METER].word = "METER"; 
  nns[METER]. code = METER; 
  nns[METER]. description = "a bale of hay"; 
  nns[METER].can_carry = false; 
  nns[METER].location = HORSE_STABLES; 
  nns[ROULETTE].word = "ROULETTE"; 
  nns[ROULETTE]. code = ROULETTE; 
  nns[ROULETTE].description = "a roulette wheel"; 
  nns[ROULETTE].can_carry = false;
  nns[ROULETTE].location = GAMBLING_TABLE;
  nns[MONEY].word = "MONEY";
  nns[MONEY].code = MONEY;
  nns[MONEY].description = "some money";
  nns[MONEY].can_carry = true;
  nns[MONEY].location = NONE;
  nns[FISHROD].word = "ROD";
  nns[FISHROD].code = FISHROD;
  nns[FISHROD].description = "a fishing rod";
  nns[FISHROD].can_carry = false;
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
  static bool door_state = false; // false is a closed door. 
  int i;
  for (i = 0; i < DIRS; i++)
  {
    if (wd1 ==dir[i].word)
    {
      if (rms[loc].exits_to_room[dir[i].code] != NONE)
      {
        loc = rms[loc].exits_to_room[dir[i].code]; cout << "I am now in a " << rms[loc].description << "." << endl; // Added code, A special case for the corridor STORE_ROOM door. 
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

  if (VERB_ACTION == LOOK)
  {
    look_around(loc, rms, dir, /* Added parameter nns */ nns);
    return true;
  }

  // Added code 11 Actions for usage of VERB OPEN \
  if(VERB_ACTION == OPEN)
  {
    if (NOUN_MATCH == STORE_DOOR)
    {
      if (loc == CORRIDOR || loc == STORE_ROOM)
      {
        if (door_state == false)
        {
          door_state = true;
          rms[CORRIDOR].exits_to_room[EAST] = STORE_ROOM;
          rms[STORE_ROOM].exits_to_room[WEST] = CORRIDOR;
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
    else
    {
      cout << "Opening that is not possible." << endl;
      return true;
    }
  }
  return false;
}

int main()
{
  cout<<"Hi there";
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
    cout << "what shall I do? ";
    getline(cin, command);

    word_1.clear(); 
    word_2.clear();

    section_command(command, word_1, word_2);

    if (word_1 != "QUIT")
    {
      parser(location, word_1, word_2, directions, verbs, rooms, /* Added parameter */ nouns);
    }
  }
  return 0;
}