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
            if ( k.alias==l.alias ) {
                //Reproduction. Call the create function --> which_Organism
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
// One Step Deeper --------------------- 
class Mollusca: public Invertebrate {
    public:
}

class Arthropoda: public Invertebrate {
    public:
}

class Squid: public Mollusca {
    public:
        Squid() {
            char alias = 'K';
            int age = RandomInteger(1,5);
            int size = 2;
        }
}

class Octopus: public Mollusca {
    public:
        Octopus() {
            char alias = 'T';
            int age = RandomInteger(1,5);
            int size = 3;
        }
}

class Mylittus: public Mollusca {
    public:
        Mylittus() {
            char alias = 'M';
            int age = RandomInteger(1,5);
            int size = 2;
        }
}

class Crab: public Arthropoda {
    public:
        Crab() {
            char alias = 'C';
            int age = RandomInteger(1,5);
            int size = 3;
        }
}

class Shrimp: public Arthropoda {
    public:
        Shrimp() {
            char alias = 'G';
            int age = RandomInteger(1,5);
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
            int age = RandomInteger(1,5);
            int size = 3;
        }
}

class Dolpin: public Chordata {
    public:
        Dolpin() {
            char alias = 'D';
            int age = RandomInteger(1,5);
            int size = 4;
        }
}

class Shark: public Chordata {
    public:
        Shark() {
            char alias = 'S';
            int age = RandomInteger(1,5);
            int size = 4;
        }
}
/* ========================= Declaration of the classes ends here =========================== */

Organism* which_Organism (int digit) {
    if (digit==0) return NON* X;   // just a abstract pointer for non-animal cell
    else if (digit==1) return NON* X;
    else if (digit==2) return NON* X;
    else if (digit==3) return  
    else if (digit==4) return 
    else if (digit==5) return 
    else if (digit==6) return 
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
    for (int i = 0; i < x; i++) {
        vector<Organism*> row;    // Create an empty row
        for (int j = 0; j < y; j++) {
                int digit = RandomInteger(0,20);    // Generate a random digit for the organism creation 
                row.push_back( which_Organism (digit); ); // Add an element to the row
        }
        map.push_back(row);       // Add the row to the main vector
    /* org_counter++; */
    }
    // Placing a shark and a dolphin.
    int place_x = RandomInteger(0,map.size());
    int place_y = RandomInteger(0,map.size());
    map[place_x][place_y] = Shark s;
    place_x = RandomInteger(0,map.size());
    place_y = RandomInteger(0,map.size());
    map[place_x][place_y] = Dolpin d;
    org_counter+=2;
    // Done. Starting menus and steps.
    char choice;
    info_print_label:      // -------- This is the required label for the print and the info actions
    cout << "Press S to make a step\nP to print the map\nR to restart\nI to get info\nAnything else to quit" << endl;
    cin >> choice;
    while (choice == 'S' || choice == 's') {
        /* <-------Actions for one step. Call the move function of all organisms--------> */
        cout << "Press S to make a step\nP to print the map\nR to restart\nI to get info\nAnything else to quit" << endl;
        cin >> choice;
        step_counter++;
    }
    if (choice == 'R' || choice == 'r')
        goto restart_label;
    else if (choice == 'I' || choice == 'i') {
        cout << "Press 1 to get general info or the character of the organism for specific" << endl;
        // Give general and specific information Return to the main loop
    }
    else if (choice == 'A' || choice == 'a') {
        /* <---Add "Organism/Condition manipulation code" here ---> */
        // Return to the main loop
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
