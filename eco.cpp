// This is the first file of the C++ Project 'EcoSystem', that I'm working on.
// I'm gonna do it all in one file and maybe split it later
// © George Papanikolaou 2011

#include <iostream>
#include <cstring>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;

/* This is a system function to generate random numbers where I need. */
int RandomInteger(int low, int high) {  
    int k;
    int dif=high-low+1; 
    k = low + rand() % dif; 
    return k;  
} 

// This is the main function for time operations
void wait(int seconds) {
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {/* Nothing to see here */}
}

/* ========================= Declaration of the classes begins here =========================== */
class Organism {
    public:
        int size;       // This can be 0,1,2,3,4 - 0=DEAD
        int growth;     // Growth Percentage is how much they grow of they get all the food:
        int food;       // Ammount of food they need
        char alias;     // This is the alias for the map
        void interaction(Organism* k, Organism* l) {
            // This is the main interaction fucntion for stuff like eating and reproduction
            if ( *k.alias==*l.alias ) {
                if (*k.alias=='K') {
                    Organism* L = create_Organism(11);
                    
                }
            }
        }
        void move ( Organism* m ) {
            int movement = RandomInteger(1,8);
            // <-- MOVE HERE --> */
        }
        
};

class NON: public Organism {  // A subclass for cells without organisms
    public:
        NON () {
            char alias = 'O';
        }
};

class Plankton: public Organism {
    public:
};

class Zooplankton: public Plankton {
    public:
        Zooplankton() {
            char alias = 'Z';
            int size = 1;
        }
};

class Phytoplankton: public Plankton {
    public:
        Phytoplankton() {
            char alias = 'P';
            int size = 1;
        }
};

/* <--- ^-Plankton ---- Non-Plankton-v ---> */

class NPlankton: public Organism {
        int age;
    public:
}

class Invertebrate: public NPlankton {
    public:
}

class Vertebrate: public NPlankton {
    public:
}
// One Stsp Deeper --------------------- 
class Mollusca: public Invertebrate {
    public:
}

class Arthropoda: public Invertebrate {
    public:
}
// This are the real organism classes:
class Squid: public Mollusca {
    public:
        Squid() {
            char alias = 'K';
            int age = 1;
            int size = 2;
        }
}

class Octopus: public Mollusca {
    public:
        Octopus() {
            char alias = 'T';
            int age = 1;
            int size = 3;
        }
}

class Mylittus: public Mollusca {
    public:
        Mylittus() {
            char alias = 'M';
            int age = 1;
            int size = 2;
        }
}

class Crab: public Arthropoda {
    public:
        Crab() {
            char alias = 'C';
            int age = 1;
            int size = 3;
        }
}

class Shrimp: public Arthropoda {
    public:
        Shrimp() {
            char alias = 'G';
            int age = 1;
            int size = 2;
        }
}
// Higher Fish -----------------------
class Chordata: public Vertebrate {
    public:
}

class Sprattus: public Chordata {
    public:
        Sprattus() {
            char alias = 'A';
            int age = 1;
            int size = 3;
        }
}

class Dolpin: public Chordata {
    public:
        Dolpin() {
            char alias = 'D';
            int age = 1;
            int size = 4;
        }
}

class Shark: public Chordata {
    public:
        Shark() {
            char alias = 'S';
            int age = 1;
            int size = 4;
        }
}
/* ========================= Declaration of the classes ends here =========================== */

// Organism creator function:
Organism * create_Organism (int digit) {
    if (digit==0) { NON X; return &X; }   // just a abstract pointer for non-animal cell
    else if (digit==1) { NON X; return &X; } 
    else if (digit==2) { NON X; return &X; } 
    else if (digit==3) { NON X; return &X; } 
    else if (digit==4) { Phytoplankton X; return &X; } /*****************************/
    else if (digit==5) { Phytoplankton X; return &X; } /*   Phytoplankton creation  */
    else if (digit==6) { Phytoplankton X; return &X; } /* The same times as "empty" */
    else if (digit==7) { Phytoplankton X; return &X; } /*****************************/
    else if (digit==8) { Zooplankton X; return &X; } 
    else if (digit==9) { Zooplankton X; return &X; }
    else if (digit==10) { Zooplankton X; return &X; }
    else if (digit==11) { Squid X; return &X; } 
    else if (digit==12) { Squid X; return &X; }
    else if (digit==13) { Mylittus X; return &X; } 
    else if (digit==14) { Mylittus X; return &X; } 
    else if (digit==15) { Shrimp X; return &X; } 
    else if (digit==16) { Shrimp X; return &X; } 
    else if (digit==17) { Shrimp X; return &X; } 
    else if (digit==18) { Octopus X; return &X; } 
    else if (digit==19) { Crab X; return &X; } 
    else if (digit==20) { Sprattus X; return &X; } 
}

int main() {
    restart_label:      // This is the required label for the restart action
    srand((int)time(0));
    int x=RandomInteger(15,20);
    int y=RandomInteger(15,20);
    cout << "The map will have " << x << " length and" << y << " width" << endl;
    cout << "Generating the system!" << endl;
    wait(1);
    vector < vector<Organism*> > map;   // Trying to create a container for all the objects - The map
    // Counters:
    int step_counter = 1;
    int org_counter = 0;
    cout << "Placing organisms into the map..." << endl;
    for (int i = 0; i <= x; i++) {
        vector<Organism*> row;    // Create an empty row
        for (int j = 0; j <= y; j++) {
                int digit = RandomInteger(0,20);    // Generate a random digit for the organism creation 
                Organism* Y = create_Organism (digit);
                row.push_back( *Y ); // Add an element to the row
                if ( digit >= 4 ) org_counter++;   // Add one to the organis counter if an organism is been added
        }
        map.push_back(row);       // Add the row to the main vector
    }
    // Placing a shark and a dolphin.
    bool flag=false;
    while (flag==false) {
        int place_x = RandomInteger(0,map.size());
        int place_y = RandomInteger(0,map.size());
        if (map[place_x][place_y].alias='O') {
            Shark S;
            map[place_x][place_y] = &S;
            flag=true;
            org_counter++;
        }
    }
    flag=false;
    while (flag==false) {
        int place_x = RandomInteger(0,map.size());
        int place_y = RandomInteger(0,map.size());
        if (map[place_x][place_y].alias='O') {
            Dolpin D;
            map[place_x][place_y] = &D;
            flag=true;
            org_counter++;
        }
    }
    // Done. Starting menus and steps.
    char choice;
    info_print_label:      // <-------- This is the required label for the print and the info actions
    cout << "Press S to make a step\nP to print the map\nA to add an organism\nR to restart\nI to get info\nAnything else to quit" << endl;
    cin >> choice;
    while (choice == 'S' || choice == 's') {
        /* <-------Actions for one step. Call the move function of all organisms--------> */
        cout << "Press S to make a step\nP to print the map\nA to add an organism\nR to restart\nI to get info\nAnything else to quit" << endl;
        // Yes you need to hit 's' evrytime, for every step. I need something like conio.h for *nix to implement a continuous loop.
        cin >> choice;
        step_counter++;
    }
    if (choice == 'R' || choice == 'r')
        goto restart_label;
    else if (choice == 'I' || choice == 'i') {
        // Give general and specific information
        cout<< "There are " << org_counter << " total organisms in the map. "
            << "The spesific organisms are:\n Phytoplankton - P\n Zooplankton - Z\n Squid - K\n Mylittus - M"
            << "\n Shrimp - G\n Octopus - T\n Crab - C\n Sprattus - A\n Dolpin - D\n Shark - S" << endl;
        goto info_print_label;
    }
    else if (choice == 'A' || choice == 'a') {
        // User organism creation loop:
        cout << "Press the alias of the Organism you want to add" << endl;
        char adding;
        cin >> adding;
        cout << "Press the number of the row you want the organism to be added" << endl;
        int arow;
        cin >> arow;
        cout << "Now press the number of the collumn you want the organism to be added" << endl;
        int acollumn;
        cin >> acollumn;
        Organism* Q = create_Organism (adding);
        map[arow][acollumn] = *Q;
        cout << "Success" << endl;
        goto info_print_label;
    }
    else if (choice == 'P' || choice == 'p') {
        int i,j;
        for (i=0; i=x; i++) {
            for (j=0; j=y; j++) {
                cout << map[i][j].alias << "-";
            }
            cout << "\b" << endl;   //Change the line in the stdout
        }
        cout << "-------------------------------"
        goto info_print_label;
    }
    else { cout << "System quitting after " << clock()/CLOCKS_PER_SEC << " seconds" << endl; }
    return 0;
}
