/* 
	V1 changed the structs to classes
    V2 created public and private class members
    V3 added constructors
    V4 changed .notations to getters and setters
    V5 added additional rooms, verbs, and nouns
    V6 converted arrays to vectors
    v7 added rest and get verbs(get kinda words)

*/


#include <iostream>
#include <string>
#include <vector>
#include <cctype>   // used for tupper

using namespace std;

enum en_DIRS {NORTH, EAST, SOUTH, WEST};
enum en_ROOMS {OUTSKIRTS, BERG, VALLEY, TEMPLE, STABLES, GATES, STOREROOM, FOUNTAINHEAD, GARDEN, POND, CASTLE, BASEMENT, WELL, PAGODA, SHRINE, ARENA, ESTATE, VILLAGE, CATACOMBS, TOWER, BARRACKS, MERCHANT,FARMLAND, FOREST, GRAVEYARD, BRIDGE, CLIFFS, KITCHEN, BATHROOM, LAKE};    // CHANGED ALL ROOMS
enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, FIGHT, LOOK, REST, STORE};    
enum en_NOUNS {STORE_DOOR, SHURIKEN, FLAME_VENT, FIRECRACKERS, SEN, RICE, FUSHIGIRI, GOURD, AXE, BALLOONS, SUGAR, CLOAK, DAGGER, RING, SPEAR, ASH};   

const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 30;
const int VERBS = 10;
const int NOUNS = 16;

bool debug = true;

class words {
private:
    string word;
    int code;
public:
    words(string ThisWord, int ThisCode)
    {
        word = ThisWord;
        code = ThisCode;
    }
    string GetWord()
    {
        return word;
    }
    void SetWord(string sWord)
    {
        word = sWord;
    }
    int GetCode()
    {
        return code;
    }
    void SetCode(int cde)
    {
        code = cde;
    }
};

class room {
private:
    string description;
    int exits_to_room[DIRS];
public:
    // Constructor
    room(string desc, int NORTH, int EAST, int SOUTH, int WEST)
    {
        description = desc;
        exits_to_room[0] = NORTH;
        exits_to_room[1] = EAST;
        exits_to_room[2] = SOUTH;
        exits_to_room[3] = WEST;
    };
    // Getters
    string GetDesc()
    {
        return description;
    }
    int GetExits(int dir)
    {
        return exits_to_room[dir];
    }
    // Setters
    void SetDesc(string desc)
    {
        description = desc;
    }
    void SetExits(int dir, int room){
        exits_to_room[dir] = room;
    }

};
class noun {
private:
    string word;
    string description;
    int code;
    int location;
    bool can_carry;
public:
    
    // Constructor
    noun(string GivenWord, int GivenCode, string GivenDesc, int loc, bool carry)
    {
        word = GivenWord;
        code = GivenCode;
        description = GivenDesc;
        location = loc;
        can_carry = carry;
    };
    // Getters for the private 
    string GetDesc()
    {
        return description;
    }
    string GetWord()
    {
        return word;
    }
    int GetCode()
    {
        return code;
    }
    int GetLoc()
    {
        return location;
    }
    bool GetCarry()
    {
        return can_carry;  
    }
    // Setters
    void SetDesc(string desc)
    {
        description = desc;
    }
    void SetWord(string wrd)
    {
        word = wrd;
    }
    void SetCode(int cde)
    {
        code = cde;
    }
    void SetLoc(int loc)
    {
        location = loc;
    }
    void SetCarry(bool carry)
    {
        can_carry = carry;
    }
};

class verb {
private:
    string word;
    int code;
public:
    verb(string GivenWord, int GivenCode)
    {
        word = GivenWord;
        code = GivenCode;
    }
    string GetWord()
    {
        return word;
    }
    void SetWord(string wrd)
    {
        word = wrd;
    }
    int GetCode()
    {
        return code;
    }
    void SetCode(int cde)
    {
        code = cde;
    }

};
// Replaced room *rms with the vector<room>&rms
void set_rooms(vector<room>&rms)
{
    rms.push_back(room("OUTSKIRTS", CLIFFS, NONE, FOREST, POND));
    rms.push_back(room("BERG", STOREROOM, GATES, KITCHEN, NONE));
    rms.push_back(room("VALLEY", GRAVEYARD, TEMPLE, NONE, NONE));
    rms.push_back(room("TEMPLE", GARDEN, BASEMENT, BATHROOM, VALLEY));
    rms.push_back(room("STABLES", NONE, NONE, NONE, STOREROOM));
    rms.push_back(room("GATES", CASTLE, POND, GARDEN, BERG));
    rms.push_back(room("STOREROOM", SHRINE, STABLES, BERG, NONE));
    rms.push_back(room("FOUNTAINHEAD", NONE, PAGODA, NONE, CASTLE));
    rms.push_back(room("GARDEN", GATES, NONE, TEMPLE, NONE));
    rms.push_back(room("POND", FOUNTAINHEAD, OUTSKIRTS, NONE, GATES));
    rms.push_back(room("CASTLE", CATACOMBS, FOUNTAINHEAD, GATES, TOWER));
    rms.push_back(room("BASEMENT", WELL, NONE, NONE, TEMPLE));
    rms.push_back(room("WELL", MERCHANT, NONE, BASEMENT, GARDEN));
    rms.push_back(room("PAGODA", NONE, NONE, CLIFFS, FOUNTAINHEAD));
    rms.push_back(room("SHRINE", ESTATE, NONE, NONE, NONE));
    rms.push_back(room("ARENA", POND, NONE, MERCHANT, KITCHEN));
    rms.push_back(room("ESTATE", NONE, TOWER, SHRINE, NONE));
    rms.push_back(room("VILLAGE", FOREST, NONE, FARMLAND, NONE));
    rms.push_back(room("CATACOMBS", NONE, NONE, CASTLE, NONE));
    rms.push_back(room("TOWER", NONE, CASTLE, NONE, ESTATE));
    rms.push_back(room("BARRACKS", KITCHEN, MERCHANT, BARRACKS, NONE));
    rms.push_back(room("MERCHANT", ARENA, VILLAGE, WELL, BARRACKS));
    rms.push_back(room("FARMLAND", VILLAGE, NONE, NONE, NONE));
    rms.push_back(room("FOREST", OUTSKIRTS, NONE, VILLAGE, NONE));
    rms.push_back(room("GRAVEYARD", BARRACKS, NONE, VALLEY, NONE));
    rms.push_back(room("BRIDGE", CASTLE, NONE, GATES, NONE));
    rms.push_back(room("CLIFFS", PAGODA, NONE, NONE, NONE));
    rms.push_back(room("KITCHEN", BERG, ARENA, BARRACKS, NONE));
    rms.push_back(room("BATHROOM", TEMPLE, NONE, NONE, NONE));
    rms.push_back(room("LAKE", VALLEY, NONE, NONE, NONE));
}
void set_directions(vector<words>&dir)
{
    dir.push_back(words("NORTH", NORTH));
    dir.push_back(words("EAST", EAST));
    dir.push_back(words("SOUTH", SOUTH));
    dir.push_back(words("WEST", WEST));
}
void set_verbs(vector<verb>&vbs)
{
    vbs.push_back(verb("GET", GET));
    vbs.push_back(verb("DROP", DROP));
    vbs.push_back(verb("USE", USE));
    vbs.push_back(verb("OPEN", OPEN));
    vbs.push_back(verb("CLOSE", CLOSE));
    vbs.push_back(verb("EXAMINE", EXAMINE));
    vbs.push_back(verb("FIGHT", FIGHT));
    vbs.push_back(verb("LOOK", LOOK));
    vbs.push_back(verb("REST", REST));
    vbs.push_back(verb("STORE", STORE));
}
void set_nouns(vector<noun>&nns)
{
    nns.push_back(noun("STORE_DOOR", STORE_DOOR, "door to the closet", STOREROOM, false));
    nns.push_back(noun("SHURIKEN", SHURIKEN, "Shinobis Shuriken", OUTSKIRTS, true));
    nns.push_back(noun("FLAME_VENT", FLAME_VENT, "Flame Vent", VALLEY, true));
    nns.push_back(noun("FIRECRACKERS", FIRECRACKERS, "Robertos Firecrackers", BERG, true));
    nns.push_back(noun("SEN", SEN, "some money", TEMPLE, true));
    nns.push_back(noun("RICE", RICE, "a serving of delicious rice", KITCHEN, true));
    nns.push_back(noun("FUSHIGIRI", FUSHIGIRI, "the Mortal Blade", BARRACKS, true));
    nns.push_back(noun("GOURD", GOURD, "a healing gourd", TEMPLE, true));
    nns.push_back(noun("AXE", AXE, "Heavy axe", STABLES, true));
    nns.push_back(noun("BALLOONS", BALLOONS, "Mibu Spirit Balloons", GARDEN, true));
    nns.push_back(noun("SUGAR", SUGAR, "Gachin Sugar for stealth", POND, true));
    nns.push_back(noun("CLOAK", CLOAK, "Traveling cloak", VILLAGE, true));
    nns.push_back(noun("DAGGER", DAGGER, "a deadly sidearm", STOREROOM, true));
    nns.push_back(noun("RING", RING, "Ring of the Illusory Halls", FOUNTAINHEAD, true));
    nns.push_back(noun("SPEAR", SPEAR, "Folding Spear", ARENA, true));
    nns.push_back(noun("ASH", ASH, "Bundle of Ash", GRAVEYARD, true));
}
void section_command(string Cmd, string &wd1, string &wd2)
{
    string sub_str;
    vector<string> words;
    char search = ' ';
    size_t i, j;

    for( i = 0; i < Cmd.size(); i++)
    {
        if(Cmd.at(i) != search)
        {
            sub_str.insert(sub_str.end(), Cmd.at(i));
        }
        if(i == Cmd.size() - 1)
        {
            words.push_back(sub_str);
            sub_str.clear();
        }
        if(Cmd.at(i) == search)
        {
            words.push_back(sub_str);
            sub_str.clear();
        }
    }
    for(i = words.size() - 1; i > 0; i--)
    {
        if(words.at(i) == "")
		{
            words.erase(words.begin() + i);
		}
	}
    for(i = 0; i < words.size(); i++)
    {
        for(j = 0; j < words.at(i).size(); j++)
        {
            if(islower(words.at(i).at(j)))
			{
                words.at(i).at(j) = toupper(words.at(i).at(j));
			}
        }
    }
    if(words.size() == 0)
    {
        cout << "No command given" << endl;
    }
    if(words.size() == 1)
    {
        wd1 = words.at(0);
    }
    if(words.size() == 2)
    {
        wd1 = words.at(0);
        wd2 = words.at(1);
    }
    if(words.size() > 2)
    {
        cout << "Command too long. Only type one or two words (direction or verb and noun)" << endl;
    }
}
void get(int loc, vector<noun>&nns)
{
    vector<string> inventory;

    for(int i = 0; i < NOUNS; i++)
    {
        if(nns[i].GetLoc() == loc)
        {
            inventory.push_back(nns[i].GetDesc());
        }
    }

    cout << "Your items:\n";
	for (unsigned int i = 0; i < inventory.size(); ++i)
	{
		cout << inventory[i] << endl;
	}
}
void rest(int loc, vector<room>&rms){
    string input;

    cout << "So you want to take a break and rest for a while?" << "\nAre you sure you want to stop while you're at the " << rms[loc].GetDesc() << "?\n";
    cin >> input;

    if(input == "yes" || input == "Yes" || input == "yeah" || input == "Yeah")
    {
        cout << "\nAs you wish, stopping to reflect can be more helpful than one might assume.\n" << "How long would you like to rest?\n";
        cin >> input;
        cout << "Okay then, I'll wake you up then. Have a good rest\n";
    }
}
void look_around(int loc, vector<room>&rms, vector<words>&dir, vector<noun>&nns)
{
    int i;
    
    cout << "You have entered the " << rms[loc].GetDesc() << "." << endl;       
	
    for(i = 0; i < DIRS; i++)
    {
        if(rms[loc].GetExits(i) != NONE)      
        {                                                                       
            cout << "There is an exit " << dir[i].GetWord() << " to a " << rms[rms[loc].GetExits(i)].GetDesc() << "." << endl; 
        }
    }
    //The look command should check which objects (nouns) are in the current room and report them to the player
    for(i = 0; i < NOUNS; i++)
    {
        if(nns[i].GetLoc() == loc)   
        {
            cout << "You see " << nns[i].GetDesc() << " in the area." << endl;  
        }
    }
}
bool parser(int &loc, string wd1, string wd2, vector<words>&dir, vector<verb>&vbs, vector<room>&rms, vector<noun>&nns)
{
    static bool door_state = false; //Door is closed by default
    int i;

    for(i = 0; i < DIRS; i++)
    {
        if(wd1 == dir[i].GetWord())
        {
            if(rms[loc].GetExits(dir[i].GetCode()) != NONE)
            {
                loc = rms[loc].GetExits(dir[i].GetCode());
                cout << "You am now in the " << rms[loc].GetDesc() << "." << endl;

                // A special case for the corridor storeroom door.
                if(loc == STOREROOM)
				{
                    nns[STORE_DOOR].SetLoc(loc);
                    cout << "To open the closet door, type in 'open store_door'.\n";
                    return true;
				}
            }
            else
            {
                cout << "No exit that way" << endl;
                return true;
            }    
        }
    }

    int NOUN_MATCH = NONE;
    int VERB_ACTION = NONE;

    for(i = 0; i < VERBS; i++)
    {
        if(wd1 == vbs[i].GetWord())
        {
            VERB_ACTION = vbs[i].GetCode();
            break;
        }
    }
    // if word2 is not an empty string
    if(wd2 != "")
    {
        // loop through nouns
        for(i = 0; i < NOUNS; i++)
        {
            if(wd2 == nns[i].GetWord())
            {
                NOUN_MATCH = nns[i].GetCode();
                break;
            }
        }
    }

    if(VERB_ACTION == LOOK)
    {
        look_around(loc, rms, dir, nns);
        return true;
    }
    if(VERB_ACTION == GET)
    {
        get(loc, nns);
        return true;
    }
    if(VERB_ACTION == REST)
    {
        rest(loc, rms);
        return true;
    }

    if(VERB_ACTION == OPEN)
    {
        if(NOUN_MATCH == STORE_DOOR)
        {
            if(loc == STOREROOM)
            {
                if(door_state == false)
                { 
                    door_state = true;
                    nns[STORE_DOOR].SetDesc("");
                    nns[STORE_DOOR].SetDesc("an open store room door");
                    cout << "I have opened the door.\n Yay!!" << endl;
                    return true;
                }
                else if(door_state == true)
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
    if(VERB_ACTION == NONE)
    {
        cout << "No valid command entered." << endl;
        return true;
    }
    return false;
}

int main()
{
    string command;
    string word_1;
    string word_2;

    vector<room> rooms;
    set_rooms(rooms);

    vector<words> directions;
    set_directions(directions);
	
    vector<verb> verbs;
    set_verbs(verbs);

    vector<noun> nouns;
    set_nouns(nouns);

    int location = TEMPLE;

    cout << "\nWelcome to the final adventure for this semester! I'm glad we were all able to make it through!\n" << "To start off with, you are in the temple to the south just outside of the castle. Feel free to explore and see what you can find.\n" << "Your options are 'look' 'open' 'rest' 'get' or you can type a cardinal direction.\n";

    while(word_1 != "QUIT")
    {
        command.clear();
        cout << "\nWhat would you like to do?\n";
        getline(cin, command);

        word_1.clear();
        word_2.clear();

        section_command(command, word_1, word_2);

        if(word_1 != "QUIT")
            parser(location, word_1, word_2, directions, verbs, rooms, nouns);
  }
  return 0;
}

