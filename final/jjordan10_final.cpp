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
private:
    string word;
    int code;
public:
    void set_directions(words *dir);
    words(){
        string word ="";
        code = 0;
    }
    words(string wrd, int cde){
        word = wrd;
        code = cde;
    }
    string GetWord(){
        return word;
    }
    void SetWord(string sWord){
        word = sWord;
    }
    int GetCode(){
        return code;
    }
    void SetCode(int cde){
        code = cde;
    }
};

class rooms {
private:
    string description;
    int exits_to_room[DIRS];
public:
    void set_rooms(rooms *rms);
    // Constructor
    rooms(){
        description = "";
    };
    rooms(string desc, int dir){
        description = desc;
        exits_to_room[dir] = dir;
    };
    // Getters
    string GetDesc(){
        return description;
    }
    int GetExits(int dir){
        return exits_to_room[dir];
    }
    // Setters
    void SetDesc(string desc){
        description = desc;
    }
    void SetExits(int dir, int room){
        exits_to_room[dir] = room;
    }

};
class nouns {
private:
    string word;
    string description;
    int code;
    int location;
    bool can_carry;
public:
    void set_nouns(nouns *nns);
    // Constructor
    nouns(){
        word = "";
        code = 0;
    };
    // Getters for the private 
    string GetDesc(){
        return description;
    }
    string GetWord(){
        return word;
    }
    int GetCode(){
        return code;
    }
    int GetLoc(){
        return location;
    }
    bool GetCarry(){
        return can_carry;  
    }
    // Setters
    void SetDesc(string desc){
        description = desc;
    }
    void SetWord(string wrd){
        word = wrd;
    }
    void SetCode(int cde){
        code = cde;
    }
    void SetLoc(int loc){
        location = loc;
    }
    void SetCarry(bool carry){
        can_carry = carry;
    }

};

class verbs {
private:
    string word;
    int code;
public:
    void set_verbs(words *vbs);
    verbs(){
        word = "";
        code = 0;
    }
    // verbs(string wrd, int cde){
    //     word = wrd;
    //     code = cde;
    // }
    string GetWord(){
        return word;
    }
    void SetWord(string wrd){
        word = wrd;
    }
    int GetCode(){
        return code;
    }
    void SetCode(int cde){
        code = cde;
    }

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
	
	// replaced .notations
    rms[OUTSKIRTS].SetDesc("Ashina Outskirts");
    rms[OUTSKIRTS].SetExits(NORTH,NONE);
    rms[OUTSKIRTS].SetExits(EAST, NONE);
    rms[OUTSKIRTS].SetExits(SOUTH, NONE);
    rms[OUTSKIRTS].SetExits(WEST, POND);

    rms[BERG].SetDesc("Undead Berg");
    rms[BERG].SetExits(NORTH,STORE_DOOR);
    rms[BERG].SetExits(EAST, NONE);
    rms[BERG].SetExits(SOUTH, NONE);
    rms[BERG].SetExits(WEST, NONE);

    rms[VALLEY].SetDesc("Unseen Valley");
    rms[VALLEY].SetExits(NORTH, BERG);
    rms[VALLEY].SetExits(EAST, TEMPLE);
    rms[VALLEY].SetExits(SOUTH, NONE);
    rms[VALLEY].SetExits(WEST, NONE);

    rms[TEMPLE].SetDesc("Dilapidated Temple");
    rms[TEMPLE].SetExits(NORTH, GARDEN);
    rms[TEMPLE].SetExits(EAST, NONE);
    rms[TEMPLE].SetExits(SOUTH, NONE);
    rms[TEMPLE].SetExits(WEST, VALLEY);

    rms[STABLES].SetDesc("Stables");
    rms[STABLES].SetExits(NORTH, NONE);
    rms[STABLES].SetExits(EAST, NONE);
    rms[STABLES].SetExits(SOUTH, NONE);
    rms[STABLES].SetExits(WEST, STORE_DOOR);

    rms[GATE].SetDesc("Castle Gate");
    rms[GATE].SetExits(NORTH, CASTLE);
    rms[GATE].SetExits(EAST, POND);
    rms[GATE].SetExits(SOUTH, GARDEN);
    rms[GATE].SetExits(WEST, BERG);

    rms[STOREROOM].SetDesc("Store Room");
    rms[STOREROOM].SetExits(NORTH, NONE);
    rms[STOREROOM].SetExits(EAST, STABLES);
    rms[STOREROOM].SetExits(SOUTH, BERG);
    rms[STOREROOM].SetExits(WEST, NONE);

    rms[FOUNTAINHEAD].SetDesc("Fountainhead");
    rms[FOUNTAINHEAD].SetExits(NORTH, NONE);
    rms[FOUNTAINHEAD].SetExits(EAST, NONE);
    rms[FOUNTAINHEAD].SetExits(SOUTH, NONE);
    rms[FOUNTAINHEAD].SetExits(WEST, CASTLE);

    rms[GARDEN].SetDesc("tranquil garden");
    rms[GARDEN].SetExits(NORTH, GATE);
    rms[GARDEN].SetExits(EAST, NONE);
    rms[GARDEN].SetExits(SOUTH, TEMPLE);
    rms[GARDEN].SetExits(WEST, NONE);

    rms[POND].SetDesc("Coy Pond");
    rms[POND].SetExits(NORTH, FOUNTAINHEAD);
    rms[POND].SetExits(EAST, OUTSKIRTS);
    rms[POND].SetExits(SOUTH, NONE);
    rms[POND].SetExits(WEST, GATE);

    rms[CASTLE].SetDesc("Ashina Castle");
    rms[CASTLE].SetExits(NORTH, NONE);
    rms[CASTLE].SetExits(EAST, FOUNTAINHEAD);
    rms[CASTLE].SetExits(SOUTH, GATE);
    rms[CASTLE].SetExits(WEST, NONE);
}
void words::set_directions(words *dir)
{
	// replaced .notations 
    dir[NORTH].SetCode(NORTH);
    dir[NORTH].SetWord("NORTH");
    dir[EAST].SetCode(EAST);
    dir[EAST].SetWord("EAST");
    dir[SOUTH].SetCode(SOUTH);
    dir[SOUTH].SetWord("SOUTH");
    dir[WEST].SetCode(WEST);
    dir[WEST].SetWord("WEST");
}
void verbs::set_verbs(words *vbs)
{
	// replaced .notations
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
	// replaced .notations
    nns[STORE_DOOR].SetWord("DOOR");
    nns[STORE_DOOR].SetCode(STORE_DOOR);
    nns[STORE_DOOR].SetDesc("The gate is closed from this side");
    nns[STORE_DOOR].SetCarry(false);
    nns[STORE_DOOR].SetLoc(GATE);
    nns[SHURIKEN].SetWord("SHURIKEN");
    nns[SHURIKEN].SetCode(SHURIKEN);
    nns[SHURIKEN].SetDesc("Shinobis shuriken");
    nns[SHURIKEN].SetCarry(true);
    nns[SHURIKEN].SetLoc(OUTSKIRTS);
    nns[FLAME_VENT].SetWord("FLAME_VENT");
    nns[FLAME_VENT].SetCode(FLAME_VENT);
    nns[FLAME_VENT].SetDesc("Flame vent");
    nns[FLAME_VENT].SetCarry(true);
    nns[FLAME_VENT].SetLoc(VALLEY);
    nns[FIRECRACKERS].SetWord("FIRECRACKERS");
    nns[FIRECRACKERS].SetCode(FIRECRACKERS);
    nns[FIRECRACKERS].SetDesc("Roberts firecrackers");
    nns[FIRECRACKERS].SetCarry(true);
    nns[FIRECRACKERS].SetLoc(BERG);
    nns[SEN].SetWord("SEN");
    nns[SEN].SetCode(SEN);
    nns[SEN].SetDesc("some money");
    nns[SEN].SetCarry(true);
    nns[SEN].SetLoc(NONE);
    nns[RICE].SetWord("RICE");
    nns[RICE].SetCode(RICE);
    nns[RICE].SetDesc("a serving of delicious rice");
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
        // had to add loc to GetExits. is this right?
        if(rms[loc].GetExits(i) != NONE)      
		 
        {                                                                       // had to add loc to GetExits. is this right?
            cout << "There is an exit " << dir[i].GetWord() << " to a " << rms[rms[loc].GetExits(i)].GetDesc() << "." << endl; 
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
                   nns[STORE_DOOR].SetLoc(loc);
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
                    rms[GATE].SetExits(EAST, STOREROOM);
                    rms[STOREROOM].SetExits(WEST, GATE);
                    nns[STORE_DOOR].SetDesc("");
                    nns[STORE_DOOR].SetDesc("an open store room door");
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
    string command;
    string word_1;
    string word_2;

    rooms rms;
    rms.set_rooms(&rms);

	words directions;
	directions.set_directions(&directions);

	verbs vbs;
	vbs.set_verbs(&vbs);

    nouns nns;
    nns.set_nouns(&nns);

    int location = TEMPLE;

    while(word_1 != "QUIT")
    {
        command.clear();
        cout << "What would you like to do? ";
        getline(cin, command);

        word_1.clear();
        word_2.clear();

        section_command(command, word_1, word_2);

        if(word_1 != "QUIT")
            parser(location, word_1, word_2, &directions, &vbs, &rms, &nns);
  }
  return 0;

}