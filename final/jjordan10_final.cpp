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
        //  string word;
    private:
        string word;
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
        int GetExits(){
            return exits_to_room[DIRS];
        };
        void SetExits(int exits){
            exits_to_room[DIRS] = exits;
        };
	private:
        string description;
        int exits_to_room[DIRS];
};
class nouns {
public:
    void set_nouns(nouns *nns);
    nouns();
    string GetDesc(){
        return description;
    };
    string GetWord(){
        return word;
    };
    int GetCode(){
        return code;
    };
    int GetLoc(){
        return location;
    };
    bool GetCarry(){
        return can_carry;  
    };
    void SetDescription(string desc){
        description = desc;
    };
    void SetWord(string wrd){
        word = wrd;
    };
    void SetCode(int cde){
        code = cde;
    };
    void SetLoc(int loc){
        location = loc;
    };
    void SetCarry(bool carry){
        can_carry = carry;
    };
private:
    string word;
    string description;
    int code;
    int location;
    bool can_carry;
};

class verbs {
	public:
		void set_verbs(words *vbs);
		verbs(){
			word = "";
			code = 0;
		};
		verbs(string wrd, int cde){
			word = wrd;
			code = cde;
		};
		string GetVerb(){
			return word;
		};
		void SetVerb(string sVerb){
			word = sVerb;
		};
		int GetCode(){
			return code;
		}
		void SetCode(int cde){
			code = cde;
		}
	private:
		string word;
		int code;

};

void rooms::set_rooms(rooms *rms)
{
	// enum en_ROOMS {OUTSKIRTS, BERG, VALLEY, TEMPLE, STABLES, GATE, STOREROOM, FOUNTAINHEAD, GARDEN, POND, CASTLE};
	// vector<string>vRooms);
	// 	vRooms.push_back("OUTSKIRTS");
	// 	vRooms.push_back("BERG");
	// 	vRooms.push_back("VALLEY");
	// 	vRooms.push_back("TEMPLE");
	// 	vRooms.push_back("STABLES");
	// 	vRooms.push_back("GATE");
	// 	vRooms.push_back("STOREROOM");
	// 	vRooms.push_back("FOUNTAINHEAD");
	// 	vRooms.push_back("GARDEN");
	// 	vRooms.push_back("POND");
	// 	vRooms.push_back("CASTLE");
	
	
    rms[OUTSKIRTS].SetDescription("Ashina Outskirts");
    rms[OUTSKIRTS].SetExits[EAST] = NONE;
    rms[OUTSKIRTS].SetExits[EAST] = NONE;
    rms[OUTSKIRTS].SetExits[SOUTH] = VALLEY;
    rms[OUTSKIRTS].SetExits[WEST] = NONE;

    rms[BERG].description.assign("Undead Berg");
    rms[BERG].SetExits[NORTH] = NONE;
    rms[BERG].SetExits[EAST] = NONE;
    rms[BERG].SetExits[SOUTH] = TEMPLE;
    rms[BERG].SetExits[WEST] = NONE;

    rms[VALLEY].description.assign("Unseen Valley");
    rms[VALLEY].SetExits[NORTH] = OUTSKIRTS;
    rms[VALLEY].SetExits[EAST] = TEMPLE;
    rms[VALLEY].SetExits[SOUTH] = NONE;
    rms[VALLEY].SetExits[WEST] = NONE;

    rms[TEMPLE].description.assign("Dilapidated Temple");
    rms[TEMPLE].SetExits[NORTH] = BERG;
    rms[TEMPLE].SetExits[EAST] = STABLES;
    rms[TEMPLE].SetExits[SOUTH] = GATE;
    rms[TEMPLE].SetExits[WEST] = VALLEY;

    rms[STABLES].description.assign("Stables");
    rms[STABLES].SetExits[NORTH] = NONE;
    rms[STABLES].SetExits[EAST] = NONE;
    rms[STABLES].SetExits[SOUTH] = NONE;
    rms[STABLES].SetExits[WEST] = TEMPLE;

    rms[GATE].description.assign("Castle Gate");
    rms[GATE].SetExits[NORTH] = TEMPLE;
    rms[GATE].SetExits[EAST] = NONE;
    rms[GATE].SetExits[SOUTH] = GARDEN;
    rms[GATE].SetExits[WEST] = NONE;

    rms[STOREROOM].description.assign("Store Room");
    rms[STOREROOM].SetExits[NORTH] = NONE;
    rms[STOREROOM].SetExits[EAST] = NONE;
    rms[STOREROOM].SetExits[SOUTH] = NONE;
    rms[STOREROOM].SetExits[WEST] = NONE;

    rms[FOUNTAINHEAD].description.assign("Fountainhead");
    rms[FOUNTAINHEAD].SetExits[NORTH] = NONE;
    rms[FOUNTAINHEAD].SetExits[EAST] = GARDEN;
    rms[FOUNTAINHEAD].SetExits[SOUTH] = CASTLE;
    rms[FOUNTAINHEAD].SetExits[WEST] = NONE;

    rms[GARDEN].description.assign("tranquil garden");
    rms[GARDEN].SetExits[NORTH] = GATE;
    rms[GARDEN].SetExits[EAST] = POND;
    rms[GARDEN].SetExits[SOUTH] = NONE;
    rms[GARDEN].SetExits[WEST] = FOUNTAINHEAD;

    rms[POND].description.assign("Coy Pond");
    rms[POND].SetExits[NORTH] = NONE;
    rms[POND].SetExits[EAST] = NONE;
    rms[POND].SetExits[SOUTH] = NONE;
    rms[POND].SetExits[WEST] = GARDEN;

    rms[CASTLE].description.assign("Ashina Castle");
    rms[CASTLE].SetExits[NORTH] = FOUNTAINHEAD;
    rms[CASTLE].SetExits[EAST] = NONE;
    rms[CASTLE].SetExits[SOUTH] = NONE;
    rms[CASTLE].SetExits[WEST] = NONE;
}
void words::set_directions(words *dir)
{
	// REPLACE ACCESS .notations with SETTERS
    dir[NORTH].SetCode(NORTH);
    dir[NORTH].SetWord("NORTH");
    dir[EAST].SetCode(EAST);
    dir[EAST].SetWord("EAST");
    dir[SOUTH].SetCode(SOUTH);
    dir[SOUTH].SetWord("SOUTH");
    dir[WEST].SetCode(WEST);
    dir[WEST].SetWord("WEST");
}
void words::set_verbs(words *vbs)
{
	//REPLACE ACCESS .notations with SETTERS
    vbs[GET].SetCode(GET);
    vbs[GET].SetWord("GET");
    vbs[DROP].SetCode(DROP);
    vbs[DROP].SetWord("DROP");
    vbs[USE].SetCode(USE);
    vbs[USE].SetWord("USE");
    vbs[OPEN].SetCode(OPEN);
    vbs[OPEN].SetWord("OPEN");
    vbs[CLOSE].SetCode(CLOSE);
    vbs[CLOSE].SetWord("CLOSE");
    vbs[EXAMINE].SetCode(EXAMINE);
    vbs[EXAMINE].SetWord("EXAMINE");
    vbs[INVENTORY].SetCode(INVENTORY);
    vbs[INVENTORY].SetWord("INVENTORY");
    vbs[LOOK].SetCode(LOOK);
    vbs[LOOK].SetWord("LOOK");
}
void nouns::set_nouns(nouns *nns)
{
	//REPLACE ACCESS .notations with SETTERS
    nns[STORE_DOOR].SetWord("DOOR");
    nns[STORE_DOOR].SetCode(STORE_DOOR);
    nns[STORE_DOOR].SetDescription("The gate is closed from this side");
    nns[STORE_DOOR].SetCarry(false);
    nns[STORE_DOOR].SetLoc(GATE);
    nns[SHURIKEN].SetWord("SHURIKEN");
    nns[SHURIKEN].SetCode(SHURIKEN);
    nns[SHURIKEN].SetDescription("Shinobis shuriken");
    nns[SHURIKEN].SetCarry(true);
    nns[SHURIKEN].SetLoc(OUTSKIRTS);
    nns[FLAME_VENT].SetWord("FLAME_VENT");
    nns[FLAME_VENT].SetCode(FLAME_VENT);
    nns[FLAME_VENT].SetDescription("Flame vent");
    nns[FLAME_VENT].SetCarry(true);
    nns[FLAME_VENT].SetLoc(VALLEY);
    nns[FIRECRACKERS].SetWord("FIRECRACKERS");
    nns[FIRECRACKERS].SetCode(FIRECRACKERS);
    nns[FIRECRACKERS].SetDescription("Roberts firecrackers");
    nns[FIRECRACKERS].SetCarry(true);
    nns[FIRECRACKERS].SetLoc(BERG);
    nns[SEN].SetWord("SEN");
    nns[SEN].SetCode(SEN);
    nns[SEN].SetDescription("some money");
    nns[SEN].SetCarry(true);
    nns[SEN].SetLoc(NONE);
    nns[RICE].SetWord("RICE");
    nns[RICE].SetCode(RICE);
    nns[RICE].SetDescription("a serving of delicious rice");
    nns[RICE].SetCarry(true);
    nns[RICE].SetLoc(OUTSKIRTS);
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
    int i;
    
    cout << "I am in a " << rms[loc].GetDesc() << "." << endl;       
	
    for(i = 0; i < DIRS; i++)
    {
        if(rms[loc].GetExits()[&i] != NONE)      
		 
        {
            cout << "There is an exit " << dir[i].GetWord() << " to a " << rms[rms[loc].GetExits()[&i]].GetDesc() << "." << endl; 
        }
    }
    //The look command should check which objects (nouns) are in the current room and report them to the player
    for(i = 0; i < NOUNS; i++)
    {
        if(nns[i].GetLoc() == loc)   
        {
            cout << "I see " << nns[i].GetDesc() << "." << endl;  
        }
    }
}
bool parser(int &loc, string wd1, string wd2, words *dir, words *vbs, rooms *rms, nouns *nns)
{
    static bool door_state = false; //Door is closed by default
    int i;
	// words word(*dir);

    for(i = 0; i < DIRS; i++)
    {
        if(wd1 == dir[i].GetWord())
        {
            if(rms[loc].GetExits(dir[i].GetCode()) != NONE)
            // rms[OUTSKIRTS].SetExits(WEST,OUTSKIRTS);
            {
                loc = rms[loc].GetExits(dir[i].GetCode());
                cout << "I am now in a " << rms[loc].GetDesc() << "." << endl;
                // A special case for the corridor storeroom door.
                if(loc == STOREROOM || loc == GATE)
				{
                   nns [STORE_DOOR].SetLoc(loc) = loc;
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

    if(wd2 != "")
    {
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

    if(VERB_ACTION == OPEN)
    {
        if(NOUN_MATCH == STORE_DOOR)
        {
            if(loc == GATE || loc == STOREROOM)
            {
                if(door_state == false)
                {
                    door_state = true;
                    rms[GATE].GetExits()[EAST] = STOREROOM;
                    rms[STOREROOM].GetExits()[WEST] = GATE;
                    nns[STORE_DOOR].GetDesc().clear();
                    nns[STORE_DOOR].GetDesc().assign("an open store room door");
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

    rooms room;
	room.set_rooms(&room);

	words directions;
	directions.set_directions(&directions);

	verbs verb;
	verb.set_verbs(verb);

	// Added code
	nouns noun;
	nouns.set_nouns(&nouns);
	// rooms room[ROOMS];
    // set_rooms(room);

    // set_directions(dir);

    // words verbs[VERBS];
    // set_verbs(verbs);

    // nouns nouns[NOUNS];
    // set_nouns(nouns);

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