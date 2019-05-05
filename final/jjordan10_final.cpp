/* 
	V1 changing the structs to classes

*/


#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

enum en_DIRS {NORTH, EAST, SOUTH, WEST};
enum en_ROOMS {OUTSKIRTS, BERG, VALLEY, TEMPLE, STABLES, GATE, STOREROOM, FOUNTAINHEAD, GARDEN, POND, CASTLE};
enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK};
enum en_NOUNS {STORE_DOOR, SHURIKEN, FLAME_VENT, FIRECRACKERS, SEN, RICE};

const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 11;
const int VERBS = 8;
const int NOUNS = 6;

//--------------
//--------------

class words{
	public:
		void set_directions(words *dir);
        void set_verbs(words *vbs);
        words(){
            string word ="";
            code = 0;
        };
        words(string wrd, int cde){
            word = wrd;
            code = cde;
        };
        string GetWord(){
            return word;
        };
        void SetWord(string sWord){
            word = sWord;
        };
        int GetCode(){
            return code;
        };
        void SetCode(int cde){
            code = cde;
        };
         string word;
    // private:
        // string word;
        int code;
    
};

class rooms {
    public:
		void set_rooms(rooms *rms);
		rooms();

        string GetDesc(){
            return description;
        };
        void SetDescription(string desc){
            description = desc;
        };
        int GetDirs(){
            return exits_to_room[DIRS];
        };
        void SetDirs(int exits){
            exits_to_room[DIRS] = exits;
        };
	// private:
        string description;
        int exits_to_room[DIRS];
};
class nouns {
    public:
		void set_nouns(nouns *nns);
        nouns(){
            
        };
        string word;
        int code;
        int location;
	// private:
        string word;
        string description;
        int code;
        int location;
        bool can_carry;
    
};


// class verbs {
// 	public:
// 		void set_verbs(words *vbs);
// 		verbs(){
// 			word = "";
// 			code = 0;
// 		};
// 		verbs(string wrd, int cde){
// 			word = wrd;
// 			code = cde;
// 		};
// 		string GetVerb(){
// 			return word;
// 		};
// 		void SetVerb(string sVerb){
// 			word = sVerb;
// 		};
// 		int GetCode(){
// 			return code;
// 		}
// 		void SetCode(int cde){
// 			code = cde;
// 		}
// 	private:
// 		string word;
// 		int code;

// };




void rooms::set_rooms(rooms *rms)
{
    rms[OUTSKIRTS].description.assign("Ashina Outskirts");
    rms[OUTSKIRTS].exits_to_room[NORTH] = NONE;
    rms[OUTSKIRTS].exits_to_room[EAST] = NONE;
    rms[OUTSKIRTS].exits_to_room[SOUTH] = VALLEY;
    rms[OUTSKIRTS].exits_to_room[WEST] = NONE;

    rms[BERG].description.assign("Undead Berg");
    rms[BERG].exits_to_room[NORTH] = NONE;
    rms[BERG].exits_to_room[EAST] = NONE;
    rms[BERG].exits_to_room[SOUTH] = TEMPLE;
    rms[BERG].exits_to_room[WEST] = NONE;

    rms[VALLEY].description.assign("Unseen Valley");
    rms[VALLEY].exits_to_room[NORTH] = OUTSKIRTS;
    rms[VALLEY].exits_to_room[EAST] = TEMPLE;
    rms[VALLEY].exits_to_room[SOUTH] = NONE;
    rms[VALLEY].exits_to_room[WEST] = NONE;

    rms[TEMPLE].description.assign("Dilapidated Temple");
    rms[TEMPLE].exits_to_room[NORTH] = BERG;
    rms[TEMPLE].exits_to_room[EAST] = STABLES;
    rms[TEMPLE].exits_to_room[SOUTH] = GATE;
    rms[TEMPLE].exits_to_room[WEST] = VALLEY;

    rms[STABLES].description.assign("Stables");
    rms[STABLES].exits_to_room[NORTH] = NONE;
    rms[STABLES].exits_to_room[EAST] = NONE;
    rms[STABLES].exits_to_room[SOUTH] = NONE;
    rms[STABLES].exits_to_room[WEST] = TEMPLE;

    rms[GATE].description.assign("Castle Gate");
    rms[GATE].exits_to_room[NORTH] = TEMPLE;
    rms[GATE].exits_to_room[EAST] = NONE;
    rms[GATE].exits_to_room[SOUTH] = GARDEN;
    rms[GATE].exits_to_room[WEST] = NONE;

    rms[STOREROOM].description.assign("Store Room");
    rms[STOREROOM].exits_to_room[NORTH] = NONE;
    rms[STOREROOM].exits_to_room[EAST] = NONE;
    rms[STOREROOM].exits_to_room[SOUTH] = NONE;
    rms[STOREROOM].exits_to_room[WEST] = NONE;

    rms[FOUNTAINHEAD].description.assign("Fountainhead");
    rms[FOUNTAINHEAD].exits_to_room[NORTH] = NONE;
    rms[FOUNTAINHEAD].exits_to_room[EAST] = GARDEN;
    rms[FOUNTAINHEAD].exits_to_room[SOUTH] = CASTLE;
    rms[FOUNTAINHEAD].exits_to_room[WEST] = NONE;

    rms[GARDEN].description.assign("tranquil garden");
    rms[GARDEN].exits_to_room[NORTH] = GATE;
    rms[GARDEN].exits_to_room[EAST] = POND;
    rms[GARDEN].exits_to_room[SOUTH] = NONE;
    rms[GARDEN].exits_to_room[WEST] = FOUNTAINHEAD;

    rms[POND].description.assign("Coy Pond");
    rms[POND].exits_to_room[NORTH] = NONE;
    rms[POND].exits_to_room[EAST] = NONE;
    rms[POND].exits_to_room[SOUTH] = NONE;
    rms[POND].exits_to_room[WEST] = GARDEN;

    rms[CASTLE].description.assign("Ashina Castle");
    rms[CASTLE].exits_to_room[NORTH] = FOUNTAINHEAD;
    rms[CASTLE].exits_to_room[EAST] = NONE;
    rms[CASTLE].exits_to_room[SOUTH] = NONE;
    rms[CASTLE].exits_to_room[WEST] = NONE;
}
void words::set_directions(words *dir)
{
	// REPLACE ACCESS .notations with SETTERS
    dir[NORTH].code = NORTH;
    dir[NORTH].word = "NORTH";
    dir[EAST].code = EAST;
    dir[EAST].word = "EAST";
    dir[SOUTH].code = SOUTH;
    dir[SOUTH].word = "SOUTH";
    dir[WEST].code = WEST;
    dir[WEST].word = "WEST";
}
void words::set_verbs(words *vbs)
{
	//REPLACE ACCESS .notations with SETTERS
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
void nouns::set_nouns(nouns *nns)
{
	//REPLACE ACCESS .notations with SETTERS
    nns[STORE_DOOR].word = "DOOR";
    nns[STORE_DOOR].code = STORE_DOOR;
    nns[STORE_DOOR].description = "The gate is closed from this side";
    nns[STORE_DOOR].can_carry = false;
    nns[STORE_DOOR].location = GATE;
    nns[SHURIKEN].word = "SHURIKEN";
    nns[SHURIKEN].code = SHURIKEN;
    nns[SHURIKEN].description = "Shinobis shuriken";
    nns[SHURIKEN].can_carry = true;
    nns[SHURIKEN].location = OUTSKIRTS;
    nns[FLAME_VENT].word = "FLAME_VENT";
    nns[FLAME_VENT].code = FLAME_VENT;
    nns[FLAME_VENT].description = "Flame vent";
    nns[FLAME_VENT].can_carry = true;
    nns[FLAME_VENT].location = VALLEY;
    nns[FIRECRACKERS].word = "FIRECRACKERS";
    nns[FIRECRACKERS].code = FIRECRACKERS;
    nns[FIRECRACKERS].description = "Roberts firecrackers";
    nns[FIRECRACKERS].can_carry = true;
    nns[FIRECRACKERS].location = BERG;
    nns[SEN].word = "SEN";
    nns[SEN].code = SEN;
    nns[SEN].description = "some money";
    nns[SEN].can_carry = true;
    nns[SEN].location = NONE;
    nns[RICE].word = "RICE";
    nns[RICE].code = RICE;
    nns[RICE].description = "a serving of delicious rice";
    nns[RICE].can_carry = true;
    nns[RICE].location = OUTSKIRTS;
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
    if(words.size() == 0){
        cout << "No command given" << endl;
    }
    if(words.size() == 1){
        wd1 = words.at(0);
    }
    if(words.size() == 2)
    {
        wd1 = words.at(0);
        wd2 = words.at(1);
    }
    if(words.size() > 2){
        cout << "Command too long. Only type one or two words (direction or verb and noun)" << endl;
    }
}
void look_around(int loc, rooms *rms, words *dir, nouns *nns)
{
                                                                                        //CONTAINS ACCESS .notation REPLACE WIHT GETTERS/SETTERS
    int i;
    
    cout << "I am in a " << rms[loc].GetDesc() << "." << endl;       
	//ACCESS .notation was used
    for(i = 0; i < DIRS; i++)
    {
        if(rms[loc].exits_to_room[i] != NONE)      
		 //ACCESS .notation was used
        {
            cout << "There is an exit " << dir[i].word << " to a " << rms[rms[loc].exits_to_room[i]].GetDesc() << "." << endl; 
			//ACCESS .notation was used
        }
    }

    //The look command should check which objects (nouns) are in the current room and report them to the player
    for(i = 0; i < NOUNS; i++)
    {
        if(nns[i].location == loc)                                                     //ACCESS .notation was used
        {
            cout << "I see " << nns[i].description << "." << endl;                          //ACCESS .notation was used
        }
    }
}
bool parser(int &loc, string wd1, string wd2, words *dir, words *vbs, rooms *rms, nouns *nns)
{
    static bool door_state = false; //Door is closed by default
    int i;

    for(i = 0; i < DIRS; i++)
    {
        if(wd1 == dir[i].word)
        {
            if(rms[loc].exits_to_room[dir[i].code] != NONE)
            {
                loc = rms[loc].exits_to_room[dir[i].code];
                cout << "I am now in a " << rms[loc].description << "." << endl;
                // A special case for the corridor storeroom door.
                if(loc == STOREROOM || loc == GATE)
				{
                    nns[STORE_DOOR].location = loc;
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
        if(wd1 == vbs[i].word)
        {
            VERB_ACTION = vbs[i].code;
            break;
        }
    }

    if(wd2 != "")
    {
        for(i = 0; i < NOUNS; i++)
        {
            if(wd2 == nns[i].word)
            {
                NOUN_MATCH = nns[i].code;
                break;
            }
        }
    }

    if(VERB_ACTION == LOOK)
    {
        look_around(loc, rms, dir, nns);
        return true;
    }

    if(VERB_ACTION == OPEN)
    {
        if(NOUN_MATCH == STORE_DOOR)
        {
            if(loc == GATE || loc == STOREROOM)
            {
                if(door_state == false)
                {
                    door_state = true;
                    rms[GATE].exits_to_room[EAST] = STOREROOM;
                    rms[STOREROOM].exits_to_room[WEST] = GATE;
                    nns[STORE_DOOR].description.clear();
                    nns[STORE_DOOR].description.assign("an open store room door");
                    cout << "I have opened the door." << endl;
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

    // enum en_DIRS {NORTH, EAST, SOUTH, WEST};
    // enum en_ROOMS {OUTSKIRTS, BERG, VALLEY, TEMPLE, STABLES, GATE, STOREROOM, FOUNTAINHEAD, GARDEN, POND, CASTLE};
    // enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK};
    // enum en_NOUNS {STORE_DOOR, SHURIKEN, FLAME_VENT, FIRECRACKERS, SEN, RICE};
    string command;
    string word_1;
    string word_2;

    rooms rooms[ROOMS];
    set_rooms(rooms);

    words directions[DIRS];
    set_directions(directions);

    words verbs[VERBS];
    set_verbs(verbs);

    noun nouns[NOUNS];
    set_nouns(nouns);

    int location = VALLEY;

    while(word_1 != "QUIT")
    {
        command.clear();
        cout << "What would you like to do? ";
        getline(cin, command);

        word_1.clear();
        word_2.clear();

        section_command(command, word_1, word_2);

        if(word_1 != "QUIT")
            parser(location, word_1, word_2, directions, verbs, rooms, nouns);
    }
    return 0;

}