// This is the first file of the C++ Project 'EcoSystem', that I'm working on.
// I'm gonna do it all in one file and maybe split it later
// © George Papanikolaou 2011

#include <iostream>
#include <cstring>
#include <ctime>
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
    private:
        int age;
        int size;
        int growth;     // Growth Percentage
        int food;       // Ammount of food they need
    public:
        void interaction() {
            // This is the main interaction fucntion for stuff like eating and reproduction
            if ( /* The organism is the same -> reproduction, else eating if possible*/ ) {}
        }
        void move() {
            int movement = RandomInteger(1,8);
        }
        Organism() {      // Constructor of the class
           age = RandomInteger(1,50); //Those are in the type of ** steps ** step counter
        }
};

class Plankton: public Organism {
    private:
    public:
};

class Zooplankton: public Plankton {
    private:
    public:
};

class Phytoplankton: public Plankton {
    private:
    public:
};

/* <--- ^-Plankton ---- Non-Plankton-v ---> */

class NPlankton: public Organism {
    private:
    public:
}

class Invertebrate: public NPlankton {
    private:
    public:
}

class Vertebrate: public NPlankton {
    private:
    public:
}
// One Step Deeper --------------------- 
class Mollusca: public Invertebrate {
    private:
    public:
}

class Arthropoda: public Invertebrate {
    private:
    public:
}

class Squid: public Mollusca {
    private:
    public:
}

class Octopus: public Mollusca {
    private:
    public:
}

class Mylittus: public Mollusca {
    private:
    public:
}

class Crab: public Arthropoda {
    private:
    public:
}

class Shrimp: public Arthropoda {
    private:
    public:
}
// Higher Fish -----------------------
class Chordata: public Vertebrate {
    private:
    public:
}

class Sprattus: public Chordata {
    private:
    public:
}

class Dolpin: public Chordata {
    private:
    public:
}

class Shark: public Chordata {
    private:
    public:
}
/* ========================= Declaration of the classes ends here =========================== */

int main() {
    restart_label:
    srand((int)time(0));
    cout << "Generating the system" << endl;
    wait(1);
    int x=RandomInteger(15,20);
    int y=RandomInteger(15,20);
    Organism map[x][y];
    cout << "The map has " << x << " length and" << y << " width" << endl;
    // Counters:
    int step_counter = 1;
    int org_counter = 0;
    int N = x*y;
    cout << "Placing organisms into the map" << endl;
    for (int i=0; i>=(N/2)+2; i++) {
        int place_x = RandomInteger(0,N);
        int place_y = RandomInteger(0,N);
        map[place_x][place_y] = Phytoplankton p1;
        /* Create more organisms here randomly (problably with another function or class) -------- */
        org_counter++;
    }
    // Placing a shark and a dolphin.
    int place_x = RandomInteger(0,N);
    int place_y = RandomInteger(0,N);
    map[place_x][place_y] = Shark s;
    place_x = RandomInteger(0,N);
    place_y = RandomInteger(0,N);
    map[place_x][place_y] = Dolpin d;
    org_counter+=2;
    // Done. Starting menus and steps.
    char choice;
    cout << "Press C to make a step\nP to print the map\nR to restart\nI to get info\nAnything else to quit" << endl;
    cin >> choice;
    while (choice == 'C' || choice == 'c') {
        /* <-------Actions for one step --------> */
        cout << "Press C to make a step\nP to print the map\nR to restart\nI to get info\nAnything else to quit" << endl;
        getline (cin,choice);
        step_counter++;
    }
    if (choice == 'R' || choice == 'r')
        goto restart_label;
    else if (choice == 'I' || choice == 'i') {
        cout << "Press 1 to get general info or the character of the organism for specific" << endl;
        // Return to the main loop
    }
    else if (choice == 'A' || choice == 'a') {
        /* <---Add "Organism/Comdition manipulation code" here ---> */
        // Return to the main loop
    }
    else if (choice == 'P' || choice == 'p') {
        int i,j;
        for (i=0; i=x; i++) {
            for (j=0; j=y; j++) {
                if ( map[i][j] == /*SOME ORGANISM*/ ) {
                    cout << "letter for the orgnism";
                }
            }
            cout << endl; //Change the line in the stdout
        }
        // Return to the main loop
    }
    else { cout << "System quitting after " << clock()/CLOCKS_PER_SEC << " seconds" << endl; }
}
