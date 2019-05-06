/* 
	V1 changed the structs to classes
    V2 created public and private class members
    V3 added constructors
    V4 changed .notations to getters and setters
    V5 trying to alter main() to classes, having trouble
    V6 added additional rooms, verbs, and nouns
    V7 trying to convert arrays into vectors

*/


#include <iostream>
#include <string>
#include <vector>
#include <cctype>   // used for tupper

using namespace std;


enum en_DIRS {NORTH, EAST, SOUTH, WEST};
enum en_ROOMS {OUTSKIRTS, BERG, VALLEY, TEMPLE, STABLES, GATE, STOREROOM, FOUNTAINHEAD, GARDEN, POND, CASTLE, BASEMENT, WELL, PAGODA, SHRINE, ARENA, ESTATE, VILLAGE, CATACOMBS,CRYPT, BARRACKS, MERCHANT,
FARMLAND, FOREST, GRAVEYARD, BRIDGE, CLIFFS, KITCHEN, BATHROOM};    // ADDED BASEMENT - BATHROOM, CHANGED ALL ROOMS
enum en_VERBS {GET, DROP, USE, OPEN, CLOSE, EXAMINE, INVENTORY, LOOK, REST, STORE};    // ADDED REST AND STORE
enum en_NOUNS {STORE_DOOR, SHURIKEN, FLAME_VENT, FIRECRACKERS, SEN, RICE, KATANA, GOURD, AXE, BALLOONS, SUGAR, CLOAK, DAGGER, RING, SPEAR, ASH};    // ADDED KATANA - ASH

const int NONE = -1;
const int DIRS = 4;
const int ROOMS = 30;
const int VERBS = 10;
const int NOUNS = 16;

bool debug = true;

class words{
private:
    string vWord;
    int code;
public:
    void set_directions(words *dir);
    words(){
        string vWord ="";
        code = 0;
    }
    words(string wrd, int cde){
        vWord = wrd;
        code = cde;
    }
    string GetvWord(){
        return vWord;
    }
    void SetvWord(string sWord){
        vWord = sWord;
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
        exits_to_room[DIRS] = dir;
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
    string vWord;
    string description;
    int code;
    int location;
    bool can_carry;
public:
    void set_nouns(nouns *nns);
    // Constructor
    nouns(){
        vWord = "";
        code = 0;
    };
    // Getters for the private 
    string GetDesc(){
        return description;
    }
    string GetvWord(){
        return vWord;
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
    void SetvWord(string wrd){
        vWord = wrd;
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
    string vWord;
    int code;
public:
    void set_verbs(verbs *vbs);
    verbs(){
        vWord = "";
        code = -1;
    }
    verbs(string wrd, int cde){
        vWord = wrd;
        code = cde;
    }
    string GetvWord(){
        return vWord;
    }
    void SetvWord(string wrd){
        vWord = wrd;
    }
    int GetCode(){
        return code;
    }
    void SetCode(int cde){
        code = cde;
    }

};
// Gets access to the class using ::
void rooms::set_rooms(rooms *rms)
{
	// replaced .notations using setters
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

    rms[GARDEN].SetDesc("Tranquil Garden");
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


    rms[BASEMENT].SetDesc("Temple Basement");
    rms[BASEMENT].SetExits(NORTH, GARDEN);
    rms[BASEMENT].SetExits(EAST, NONE);
    rms[BASEMENT].SetExits(SOUTH, NONE);
    rms[BASEMENT].SetExits(WEST, VALLEY);

    // FROM HERE DOWN THE EXITS WILL HAVE TO BE FINISHED
    rms[WELL].SetDesc("Abandoned Well");
    rms[WELL].SetExits(NORTH, NONE);
    rms[WELL].SetExits(EAST, NONE);
    rms[WELL].SetExits(SOUTH, NONE);
    rms[WELL].SetExits(WEST, NONE);
    
    rms[PAGODA].SetDesc("Three Storied Pagoda");
    rms[PAGODA].SetExits(NORTH, NONE);
    rms[PAGODA].SetExits(EAST, NONE);
    rms[PAGODA].SetExits(SOUTH,NONE);
    rms[PAGODA].SetExits(WEST, NONE);
    
    rms[SHRINE].SetDesc("Senpo Shrine");
    rms[SHRINE].SetExits(NORTH, NONE);
    rms[SHRINE].SetExits(EAST, NONE);
    rms[SHRINE].SetExits(SOUTH, NONE);
    rms[SHRINE].SetExits(WEST, NONE);
    
    rms[ARENA].SetDesc("Boss Arena");
    rms[ARENA].SetExits(NORTH, NONE);
    rms[ARENA].SetExits(EAST, NONE);
    rms[ARENA].SetExits(SOUTH, NONE);
    rms[ARENA].SetExits(WEST, NONE);

    rms[ESTATE].SetDesc("Ashina Estate");
    rms[ESTATE].SetExits(NORTH, NONE);
    rms[ESTATE].SetExits(EAST, NONE);
    rms[ESTATE].SetExits(SOUTH, NONE);
    rms[ESTATE].SetExits(WEST, NONE);

    rms[VILLAGE].SetDesc("Small village");
    rms[VILLAGE].SetExits(NORTH, NONE);
    rms[VILLAGE].SetExits(EAST, NONE);
    rms[VILLAGE].SetExits(SOUTH, NONE);
    rms[VILLAGE].SetExits(WEST, NONE);

    rms[CATACOMBS].SetDesc("Castle Catacombs");
    rms[CATACOMBS].SetExits(NORTH, NONE);
    rms[CATACOMBS].SetExits(EAST, NONE);
    rms[CATACOMBS].SetExits(SOUTH, NONE);
    rms[CATACOMBS].SetExits(WEST, NONE);

    rms[CRYPT].SetDesc("Royal Crypt");
    rms[CRYPT].SetExits(NORTH, NONE);
    rms[CRYPT].SetExits(EAST, NONE);
    rms[CRYPT].SetExits(SOUTH, NONE);
    rms[CRYPT].SetExits(WEST, NONE);

    rms[BARRACKS].SetDesc("Barracks");
    rms[BARRACKS].SetExits(NORTH, NONE);
    rms[BARRACKS].SetExits(EAST, NONE);
    rms[BARRACKS].SetExits(SOUTH, NONE);
    rms[BARRACKS].SetExits(WEST, NONE);

    rms[MERCHANT].SetDesc("Mysterious Merchant");
    rms[MERCHANT].SetExits(NORTH, NONE);
    rms[MERCHANT].SetExits(EAST, NONE);
    rms[MERCHANT].SetExits(SOUTH, NONE);
    rms[MERCHANT].SetExits(WEST, NONE);

    rms[FARMLAND].SetDesc("Village Farmland");
    rms[FARMLAND].SetExits(NORTH, NONE);
    rms[FARMLAND].SetExits(EAST, NONE);
    rms[FARMLAND].SetExits(SOUTH, NONE);
    rms[FARMLAND].SetExits(WEST, NONE);

    rms[FOREST].SetDesc("Eto Forest");
    rms[FOREST].SetExits(NORTH, NONE);
    rms[FOREST].SetExits(EAST, NONE);
    rms[FOREST].SetExits(SOUTH, NONE);
    rms[FOREST].SetExits(WEST, NONE);

    rms[GRAVEYARD].SetDesc("Temple Graveyard");
    rms[GRAVEYARD].SetExits(NORTH, NONE);
    rms[GRAVEYARD].SetExits(EAST, NONE);
    rms[GRAVEYARD].SetExits(SOUTH, NONE);
    rms[GRAVEYARD].SetExits(WEST, NONE);

    rms[BRIDGE].SetDesc("Castle Bridge");
    rms[BRIDGE].SetExits(NORTH, NONE);
    rms[BRIDGE].SetExits(EAST, NONE);
    rms[BRIDGE].SetExits(SOUTH, NONE);
    rms[BRIDGE].SetExits(WEST, NONE);

    rms[CLIFFS].SetDesc("Outskirt Cliffs");
    rms[CLIFFS].SetExits(NORTH, NONE);
    rms[CLIFFS].SetExits(EAST, NONE);
    rms[CLIFFS].SetExits(SOUTH, NONE);
    rms[CLIFFS].SetExits(WEST, NONE);

    rms[KITCHEN].SetDesc("Castle Kitchen");
    rms[KITCHEN].SetExits(NORTH, NONE);
    rms[KITCHEN].SetExits(EAST, NONE);
    rms[KITCHEN].SetExits(SOUTH, NONE);
    rms[KITCHEN].SetExits(WEST, NONE);

    rms[BATHROOM].SetDesc("It's a bathroom");
    rms[BATHROOM].SetExits(NORTH, NONE);
    rms[BATHROOM].SetExits(EAST, NONE);
    rms[BATHROOM].SetExits(SOUTH, NONE);
    rms[BATHROOM].SetExits(WEST, NONE);


}
void words::set_directions(words *dir)
{
	// replaced .notations 
    dir[NORTH].SetCode(NORTH);
    dir[NORTH].SetvWord("NORTH");
    dir[EAST].SetCode(EAST);
    dir[EAST].SetvWord("EAST");
    dir[SOUTH].SetCode(SOUTH);
    dir[SOUTH].SetvWord("SOUTH");
    dir[WEST].SetCode(WEST);
    dir[WEST].SetvWord("WEST");
}
void verbs::set_verbs(verbs *vbs)
{
	// replaced .notations
    vbs[GET].SetCode(GET);
    vbs[GET].SetvWord("GET");
    vbs[DROP].SetCode(DROP);
    vbs[DROP].SetvWord("DROP");
    vbs[USE].SetCode(USE);
    vbs[USE].SetvWord("USE");
    vbs[OPEN].SetCode(OPEN);
    vbs[OPEN].SetvWord("OPEN");
    vbs[CLOSE].SetCode(CLOSE);
    vbs[CLOSE].SetvWord("CLOSE");
    vbs[EXAMINE].SetCode(EXAMINE);
    vbs[EXAMINE].SetvWord("EXAMINE");
    vbs[INVENTORY].SetCode(INVENTORY);
    vbs[INVENTORY].SetvWord("INVENTORY");
    vbs[LOOK].SetCode(LOOK);
    vbs[LOOK].SetvWord("LOOK");
    vbs[REST].SetCode(REST);
    vbs[REST].SetvWord("REST");
    vbs[STORE].SetCode(STORE);
    vbs[STORE].SetvWord("STORE");
}
void nouns::set_nouns(nouns *nns)
{
	// replaced .notations
    // increase to at least 15
    nns[STORE_DOOR].SetvWord("DOOR");
    nns[STORE_DOOR].SetCode(STORE_DOOR);
    nns[STORE_DOOR].SetDesc("The gate is closed from this side");
    nns[STORE_DOOR].SetCarry(false);
    nns[STORE_DOOR].SetLoc(GATE);
    nns[SHURIKEN].SetvWord("SHURIKEN");
    nns[SHURIKEN].SetCode(SHURIKEN);
    nns[SHURIKEN].SetDesc("Shinobis shuriken");
    nns[SHURIKEN].SetCarry(true);
    nns[SHURIKEN].SetLoc(OUTSKIRTS);
    nns[FLAME_VENT].SetvWord("FLAME_VENT");
    nns[FLAME_VENT].SetCode(FLAME_VENT);
    nns[FLAME_VENT].SetDesc("Flame vent");
    nns[FLAME_VENT].SetCarry(true);
    nns[FLAME_VENT].SetLoc(VALLEY);
    nns[FIRECRACKERS].SetvWord("FIRECRACKERS");
    nns[FIRECRACKERS].SetCode(FIRECRACKERS);
    nns[FIRECRACKERS].SetDesc("Roberts firecrackers");
    nns[FIRECRACKERS].SetCarry(true);
    nns[FIRECRACKERS].SetLoc(BERG);
    nns[SEN].SetvWord("SEN");
    nns[SEN].SetCode(SEN);
    nns[SEN].SetDesc("some money");
    nns[SEN].SetCarry(true);
    nns[SEN].SetLoc(NONE);
    nns[RICE].SetvWord("RICE");
    nns[RICE].SetCode(RICE);
    nns[RICE].SetDesc("a serving of delicious rice");
    nns[RICE].SetCarry(true);
    nns[RICE].SetLoc(OUTSKIRTS);
    // Additional nouns
    nns[KATANA].SetvWord("FUSHIGIRI");
    nns[KATANA].SetCode(KATANA);
    nns[KATANA].SetDesc("The Mortal Blade");
    nns[KATANA].SetCarry(true);
    nns[KATANA].SetLoc(FOUNTAINHEAD);
    nns[GOURD].SetvWord("GOURD");
    nns[GOURD].SetCode(GOURD);
    nns[GOURD].SetDesc("A healing gourd");
    nns[GOURD].SetCarry(true);
    nns[GOURD].SetLoc(TEMPLE);
    nns[AXE].SetvWord("AXE");
    nns[AXE].SetCode(AXE);
    nns[AXE].SetDesc("Heavy axe");
    nns[AXE].SetCarry(true);
    nns[AXE].SetLoc(STABLES);
    nns[BALLOONS].SetvWord("BALLOONS");
    nns[BALLOONS].SetCode(BALLOONS);
    nns[BALLOONS].SetDesc("Mibu spirit balloons");
    nns[BALLOONS].SetCarry(true);
    nns[BALLOONS].SetLoc(GARDEN);
    nns[SUGAR].SetvWord("SUGAR");
    nns[SUGAR].SetCode(SUGAR);
    nns[SUGAR].SetDesc("Gachin Sugar for stealth");
    nns[SUGAR].SetCarry(true);
    nns[SUGAR].SetLoc(POND);
    nns[CLOAK].SetvWord("CLOAK");
    nns[CLOAK].SetCode(CLOAK);
    nns[CLOAK].SetDesc("Traveling cloak");
    nns[CLOAK].SetCarry(true);
    nns[CLOAK].SetLoc(GATE);
    nns[DAGGER].SetvWord("DAGGER");
    nns[DAGGER].SetCode(DAGGER);
    nns[DAGGER].SetDesc("A deadly sidearm");
    nns[DAGGER].SetCarry(true);
    nns[DAGGER].SetLoc(STOREROOM);
    nns[RING].SetvWord("RING");
    nns[RING].SetCode(RING);
    nns[RING].SetDesc("Ring of the Illusionary Isles");
    nns[RING].SetCarry(false);
    nns[RING].SetLoc(FOUNTAINHEAD);
    nns[SPEAR].SetvWord("SPEAR");
    nns[SPEAR].SetCode(SPEAR);
    nns[SPEAR].SetDesc("Folding spear");
    nns[SPEAR].SetCarry(true);
    nns[SPEAR].SetLoc(OUTSKIRTS);
    nns[ASH].SetvWord("ASH");
    nns[ASH].SetCode(ASH);
    nns[ASH].SetDesc("Bundle of Ash");
    nns[ASH].SetCarry(true);
    nns[ASH].SetLoc(BERG);
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
        if(rms[loc].GetExits(i) != NONE)      
        {                                                                       // had to add loc to GetExits. is this right?
            cout << "There is an exit " << dir[i].GetvWord() << " to a " << rms[rms[loc].GetExits(i)].GetDesc() << "." << endl; 
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
bool parser(int &loc, string wd1, string wd2, words *dir, verbs *vbs, rooms *rms, nouns *nns)
{
    static bool door_state = false; //Door is closed by default
    int i;

    for(i = 0; i < DIRS; i++)
    {
        if(wd1 == dir[i].GetvWord())
        {
            if(rms[loc].GetExits(dir[i].GetCode()) != NONE)
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
        if(wd1 == vbs[i].GetvWord())
        {
            VERB_ACTION = vbs[i].GetCode();
            break;
        }
    }

    if(wd2 != "")
    {
        for(i = 0; i < NOUNS; i++)
        {
            if(wd2 == nns[i].GetvWord())
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
    if(debug){
        cout << "starting program";
    }
    string command;
    string word_1;
    string word_2;

	vector<room> rooms(ROOMS);
	set_rooms(rooms);

	
    // if(debug){
    //     cout << "hello";
    // }

	// vector<string>vROOMS;
    // if(debug) cout << "asdf";
    // vROOMS.push_back("OUTSKIRTS");
    // if(debug) cout << vROOMS[0] << endl;
    // vROOMS.push_back("BERG");
    // vROOMS.push_back("VALLEY");
    // vROOMS.push_back("TEMPLE");
    // vROOMS.push_back("STABLES");
    // vROOMS.push_back("GATE");
    // vROOMS.push_back("STOREROOM");
    // vROOMS.push_back("FOUNTAINHEAD");
    // vROOMS.push_back("GARDEN");
    // vROOMS.push_back("POND");
    // vROOMS.push_back("CASTLE");
    // vROOMS.push_back("BASEMENT");
    // vROOMS.push_back("WELL");
    // vROOMS.push_back("PAGODA");
    // vROOMS.push_back("SHRINE");
    // vROOMS.push_back("ARENA");
    // vROOMS.push_back("ESTATE");
    // vROOMS.push_back("VILLAGE");
    // vROOMS.push_back("CATACOMBS");
    // vROOMS.push_back("CRYPT");
    // vROOMS.push_back("BARRACKS");
    // vROOMS.push_back("MERCHANT");
    // vROOMS.push_back("FARMLAND");
    // vROOMS.push_back("RIVER");
    // vROOMS.push_back("FOREST");
    // vROOMS.push_back("GRAVEYARD");
    // vROOMS.push_back("BRIDGE");
    // vROOMS.push_back("CLIFFS");
    // vROOMS.push_back("KITCHEN");
    // vROOMS.push_back("BATHROOM");
    // if(debug){
    //     cout << vROOMS[0] << endl;
    // }


    // vector<string>NOUNS(16);
    // NOUNS.push_back("STORE_DOOR");
    // NOUNS.push_back("SHURIKEN");
    // NOUNS.push_back("FLAME_VENT");
    // NOUNS.push_back("FIRECRACKERS");
    // NOUNS.push_back("SEN");
    // NOUNS.push_back("RICE");
    // NOUNS.push_back("KATANA");
    // NOUNS.push_back("GOURD");
    // NOUNS.push_back("AXE");
    // NOUNS.push_back("BALLOONS");
    // NOUNS.push_back("SUGAR");
    // NOUNS.push_back("CLOAK");
    // NOUNS.push_back("DAGGER");
    // NOUNS.push_back("RING");
    // NOUNS.push_back("SPEAR");
    // NOUNS.push_back("ASH");

    // vector<string>VERBS;
    // VERBS.push_back("GET");
    // VERBS.push_back("DROP");
    // VERBS.push_back("USE");
    // VERBS.push_back("OPEN");
    // VERBS.push_back("CLOSE");
    // VERBS.push_back("EXAMINE");
    // VERBS.push_back("INVENTORY");
    // VERBS.push_back("LOOK");
    // VERBS.push_back("REST");
    // VERBS.push_back("STORE");

    // vector<string>DIRS;
    // DIRS.push_back("NORTH");
    // DIRS.push_back("SOUTH");
    // DIRS.push_back("EAST");
    // DIRS.push_back("WEST");
    if(debug) cout << "carry on";
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

