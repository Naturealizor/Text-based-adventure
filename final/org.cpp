#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

enum en_DIRS {NORTH, EAST, SOUTH, WEST};
enum en_ROOMS {SPORTSHOP, CASINO, CARPARK, LOBBY, RESTAURANT, CORRIDOR, STOREROOM, POOL, GARDEN, POND, PUMPROOM};
enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK};

//Added code??? why is this comment here?
enum en_NOUNS {STORE_DOOR, MAGNET, METER, ROULETTE, MONEY, FISHROD};
const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 11;
const int VERBS = 8;

const int NOUNS = 6;



struct words{
    string word;
    int code;
};
/*
class words
{
    private:
        string word;
        int code;
    public:
        words(){
            word ="";
            code = 0;
        }
        words(string wrd, int cde){
            word = wrd;
            code = cde;
        }
        string GetWord(){
            return word;
        }
        void SetWord(string thisWord){
            word = thisWord;
        }
        int GetCode(){
            return code;
        }
        void SetCode(int cde){
            code = cde;
        }
};
*/
struct room
{
    string description;
    int exits_to_room[DIRS];
};
/*
class room
{
    private:
        string description;
        int exits_to_room[DIRS];
    public:
        string GetDesc(){
            return description;
        }
        void SetDescription(string desc){
            description = desc;
        }
}
*/

struct noun
{
    string word;
    string description;
    int code;
    int location;
    bool can_carry;
};
//Create a class for noun here
/*
class noun
{
    private:
        string word;
        string description;
        int code;
        int location;
        bool can_carry;
    public:
        getters and setters and constructors and destructors?
};
*/

void set_rooms(vector<room>&rms)
{
                                                                //REPLACE ACCES .notations WITH SETTERS
    rms[SPORTSHOP].description.assign("sports shop");
    rms[SPORTSHOP].exits_to_room[NORTH] = NONE;
    rms[SPORTSHOP].exits_to_room[EAST] = NONE;
    rms[SPORTSHOP].exits_to_room[SOUTH] = CARPARK;
    rms[SPORTSHOP].exits_to_room[WEST] = NONE;

    rms[CASINO].description.assign("busling casino");
    rms[CASINO].exits_to_room[NORTH] = NONE;
    rms[CASINO].exits_to_room[EAST] = NONE;
    rms[CASINO].exits_to_room[SOUTH] = LOBBY;
    rms[CASINO].exits_to_room[WEST] = NONE;

    rms[CARPARK].description.assign("car park");
    rms[CARPARK].exits_to_room[NORTH] = SPORTSHOP;
    rms[CARPARK].exits_to_room[EAST] = LOBBY;
    rms[CARPARK].exits_to_room[SOUTH] = NONE;
    rms[CARPARK].exits_to_room[WEST] = NONE;

    rms[LOBBY].description.assign("hotel lobby");
    rms[LOBBY].exits_to_room[NORTH] = CASINO;
    rms[LOBBY].exits_to_room[EAST] = RESTAURANT;
    rms[LOBBY].exits_to_room[SOUTH] = CORRIDOR;
    rms[LOBBY].exits_to_room[WEST] = CARPARK;

    rms[RESTAURANT].description.assign("restaurant");
    rms[RESTAURANT].exits_to_room[NORTH] = NONE;
    rms[RESTAURANT].exits_to_room[EAST] = NONE;
    rms[RESTAURANT].exits_to_room[SOUTH] = NONE;
    rms[RESTAURANT].exits_to_room[WEST] = LOBBY;

    rms[CORRIDOR].description.assign("corridor");
    rms[CORRIDOR].exits_to_room[NORTH] = LOBBY;
    rms[CORRIDOR].exits_to_room[EAST] = NONE;
    rms[CORRIDOR].exits_to_room[SOUTH] = GARDEN;
    rms[CORRIDOR].exits_to_room[WEST] = NONE;

    rms[STOREROOM].description.assign("store room");
    rms[STOREROOM].exits_to_room[NORTH] = NONE;
    rms[STOREROOM].exits_to_room[EAST] = NONE;
    rms[STOREROOM].exits_to_room[SOUTH] = NONE;
    rms[STOREROOM].exits_to_room[WEST] = NONE;

    rms[POOL].description.assign("swimming pool area");
    rms[POOL].exits_to_room[NORTH] = NONE;
    rms[POOL].exits_to_room[EAST] = GARDEN;
    rms[POOL].exits_to_room[SOUTH] = PUMPROOM;
    rms[POOL].exits_to_room[WEST] = NONE;

    rms[GARDEN].description.assign("tranquil garden");
    rms[GARDEN].exits_to_room[NORTH] = CORRIDOR;
    rms[GARDEN].exits_to_room[EAST] = POND;
    rms[GARDEN].exits_to_room[SOUTH] = NONE;
    rms[GARDEN].exits_to_room[WEST] = POOL;

    rms[POND].description.assign("patio with a fish pond");
    rms[POND].exits_to_room[NORTH] = NONE;
    rms[POND].exits_to_room[EAST] = NONE;
    rms[POND].exits_to_room[SOUTH] = NONE;
    rms[POND].exits_to_room[WEST] = GARDEN;

    rms[PUMPROOM].description.assign("damp pump room");
    rms[PUMPROOM].exits_to_room[NORTH] = POOL;
    rms[PUMPROOM].exits_to_room[EAST] = NONE;
    rms[PUMPROOM].exits_to_room[SOUTH] = NONE;
    rms[PUMPROOM].exits_to_room[WEST] = NONE;
}

void set_directions(words *dir)
{
                                                                            //REPLACE ACCESS .notations with SETTERS
    dir[NORTH].code = NORTH;
    dir[NORTH].word = "NORTH";
    dir[EAST].code = EAST;
    dir[EAST].word = "EAST";
    dir[SOUTH].code = SOUTH;
    dir[SOUTH].word = "SOUTH";
    dir[WEST].code = WEST;
    dir[WEST].word = "WEST";
}

void set_verbs(words *vbs)
{
    //ALT Double click is your friend.
                                                                            //REPLACE ACCESS .notations with SETTERS
    //enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK};
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

void set_nouns(noun *nns)
{
                                                                            //REPLACE ACCESS .notations with SETTERS
    //enum en_NOUNS {STORE_DOOR, MAGNET, METER, ROULETTE, MONEY, FISHROD};
    nns[STORE_DOOR].word = "DOOR";
    nns[STORE_DOOR].code = STORE_DOOR;
    nns[STORE_DOOR].description = "a closed store room door";
    nns[STORE_DOOR].can_carry = false;
    nns[STORE_DOOR].location = CORRIDOR;

    nns[MAGNET].word = "MAGNET";
    nns[MAGNET].code = MAGNET;
    nns[MAGNET].description = "a magnet";
    nns[MAGNET].can_carry = true;
    nns[MAGNET].location = NONE;

    nns[METER].word = "METER";
    nns[METER].code = METER;
    nns[METER].description = "a parking meter";
    nns[METER].can_carry = false;
    nns[METER].location = CARPARK;

    nns[ROULETTE].word = "ROULETTE";
    nns[ROULETTE].code = ROULETTE;
    nns[ROULETTE].description = "a roulette wheel";
    nns[ROULETTE].can_carry = false;
    nns[ROULETTE].location = CASINO;

    nns[MONEY].word = "MONEY";
    nns[MONEY].code = MONEY;
    nns[MONEY].description = "some money";
    nns[MONEY].can_carry = true;
    nns[MONEY].location = NONE;

    nns[FISHROD].word = "ROD";
    nns[FISHROD].code = FISHROD;
    nns[FISHROD].description = "a fishing rod";
    nns[FISHROD].can_carry = false;
    nns[FISHROD].location = SPORTSHOP;
}

void section_command(string Cmd, string &wd1, string &wd2)
{
                                                                //DOUBLE CHECK FOR ACCESS .notatiosn
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
            words.erase(words.begin() + i);
    }
    for(i = 0; i < words.size(); i++)
    {
        for(j = 0; j < words.at(i).size(); j++)
        {
            if(islower(words.at(i).at(j)))
                words.at(i).at(j) = toupper(words.at(i).at(j));
        }
    }
    if(words.size() == 0)
        cout << "No command given" << endl;
    if(words.size() == 1)
        wd1 = words.at(0);
    if(words.size() == 2)
    {
        wd1 = words.at(0);
        wd2 = words.at(1);
    }
    if(words.size() > 2)
        cout << "Command too long. Only type one or two words (direction or verb and noun)" << endl;
}
                        //vector<room>&rms
void look_around(int loc, vector<room>&rms, words *dir, noun *nns)
{

    int i;
    
    cout << "I am in a " << rms[loc].description << "." << endl;       //ACCESS .notation was used
    for(i = 0; i < DIRS; i++)
    {
        if(rms[loc].exits_to_room[i] != NONE)       //ACCESS .notation was used
        {
            cout << "There is an exit " << dir[i].word << " to a " << rms[rms[loc].exits_to_room[i]].description << "." << endl; //ACCESS .notation was used
        }
    }

    //The look command should check which objects (nouns) are in the current room and report them to the player
    for(i = 0; i < NOUNS; i++)
    {
        if(nns[i].location == loc)                      //??                                //ACCESS .notation was used
        {
            cout << "I see " << nns[i].description << "." << endl;                          //ACCESS .notation was used
        }
    }

}
                                                                    //vector<room>&rms
bool parser(int &loc, string wd1, string wd2, words *dir, words *vbs, vector<room>&rms, noun *nns)
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
                if(loc == STOREROOM || loc == CORRIDOR)
                    nns[STORE_DOOR].location = loc;
                return true;
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
            if(loc == CORRIDOR || loc == STOREROOM)
            {
                if(door_state == false)
                {
                    door_state = true;
                    rms[CORRIDOR].exits_to_room[EAST] = STOREROOM;
                    rms[STOREROOM].exits_to_room[WEST] = CORRIDOR;
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
        else{
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

    // room rooms[ROOMS];

    vector<room> rooms(ROOMS);
    set_rooms(rooms);

    words directions[DIRS];
    set_directions(directions);

    words verbs[VERBS];
    set_verbs(verbs);

    noun nouns[NOUNS];
    set_nouns(nouns);

    int location = CARPARK;

    while(word_1 != "QUIT")
    {
        command.clear();
        cout << "What shall i do? ";
        getline(cin, command);

        word_1.clear();
        word_2.clear();

        section_command(command, word_1, word_2);

        if(word_1 != "QUIT")
            parser(location, word_1, word_2, directions, verbs, rooms, nouns);
    }
    return 0;

}