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
        int food;       // Ammount of food they need. This is 0,1,2 and when 0 their size is coming down 1.
        char alias;     // This is the alias for the map
        int where_x, where_y;  // Their place in the map
        void interaction(Organism* l) {
            // This is the main interaction fucntion for stuff like eating and reproduction
            if (  alias==*l.alias ) {   
                if ( alias=='P') {
                    Organism* L = create_Organism(5);                // Creating a "child" organism
                    if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
                        map[  where_x-1 ][  where_y-1 ] = *L;
                    map[  where_x+1 ][  where_y+1 ] = *L;
                }
                if ( alias=='Z') {
                    Organism* L = create_Organism(8);                // Creating a "child" organism
                    if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
                        map[  where_x-1 ][  where_y-1 ] = *L;
                    map[  where_x+1 ][  where_y+1 ] = *L;
                }
                if ( alias=='K') {
                    Organism* L = create_Organism(11);                // Creating a "child" organism
                    if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
                        map[  where_x-1 ][  where_y-1 ] = *L;
                    map[  where_x+1 ][  where_y+1 ] = *L;
                }       
                if ( alias=='M') {
                    Organism* L = create_Organism(13);                // Creating a "child" organism
                    if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
                        map[  where_x-1 ][  where_y-1 ] = *L;
                    map[  where_x+1 ][  where_y+1 ] = *L;
                }
                if ( alias=='G') {
                    Organism* L = create_Organism(15);                // Creating a "child" organism
                    if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
                        map[  where_x-1 ][  where_y-1 ] = *L;
                    map[  where_x+1 ][  where_y+1 ] = *L;
                }
                if ( alias=='T') {
                    Organism* L = create_Organism(18);                // Creating a "child" organism
                    if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
                        map[  where_x-1 ][  where_y-1 ] = *L;
                    map[  where_x+1 ][  where_y+1 ] = *L;
                }
                if ( alias=='C') {
                    Organism* L = create_Organism(19);                // Creating a "child" organism
                    if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
                        map[  where_x-1 ][  where_y-1 ] = *L;
                    map[  where_x+1 ][  where_y+1 ] = *L;
                }
                if ( alias=='A') {
                    Organism* L = create_Organism(20);                // Creating a "child" organism
                    if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
                        map[  where_x-1 ][  where_y-1 ] = *L;
                    map[  where_x+1 ][  where_y+1 ] = *L;
                }
                if ( alias=='S') {
                    Organism* L = create_Organism(22);                // Creating a "child" organism
                    if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
                        map[  where_x-1 ][  where_y-1 ] = *L;
                    map[  where_x+1 ][  where_y+1 ] = *L;
                }
                if ( alias=='D') {
                    Organism* L = create_Organism(21);                // Creating a "child" organism
                    if (  where_x == x; ||  where_y == y )        // Adding the "child" in a near cell
                        map[  where_x-1 ][  where_y-1 ] = *L;
                    map[  where_x+1 ][  where_y+1 ] = *L;
                }
            }
            else {
                // The Eating Option:
                if (  size > *l.size ) {
                    map[*l.where_x][*l.where_y] = this  // This Object
                    map[ where_x][ where_y] = &E;      // The *l organism is No More.
                    // Food code:
                    food = 3;
                    size++;
                }
                else {
                    map[ where_x][ where_y] = *l;
                    map[*l.where_x][*l.where_y] = &E;      // The  organism is No More.
                    // The same food code reversed for the l
                    *l.food = 3;
                    *l.size++;
                }
            }
        }
        void move () {
            int movement;
            if ( where_x == 0 ) {
                if (where_y == 0 || where_y == y) {
                    movement = RandomInteger(4,6);
                }
                else {
                    movement = RandomInteger(4,8);
                }
            }
            else if (where_y == 0 || where_y == y) {
                movement = RandomInteger(2,6);
            }
            else if ( where_x == x ) {
                if (where_y == 0 || where_y == y) {
                    movement = RandomInteger(2,4);
                }
                else {
                    movement = RandomInteger(1,4);
                }
            }
            else {
                movement = RandomInteger(1,8);
            }
            // The move now:
            if (movement == 1) { interaction( map[where_x-1][where_y-1]); }
            else if (movement == 2) { interaction( map[where_x-1][where_y]); }
            else if (movement == 3) { interaction( map[where_x-1][where_y+1]); }
            else if (movement == 4) { interaction( map[where_x][where_y+1]); }
            else if (movement == 5) { interaction( map[where_x+1][where_y+1]); }
            else if (movement == 6) { interaction( map[where_x+1][where_y]); }
            else if (movement == 7) { interaction( map[where_x+1][where_y-1]); }
            else { interaction( map[where_x][where_y-1]); }
            // NO FOOD OR SIZE CHECK. The Plankton cannot die from age/size so it can provide food to the supreme organisms.
        }
};

class NON: public Organism {  // A subclass for cells without organisms
    public:
        NON () {
            char alias = 'O';
            int size = 0;
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
        void move () {                  // The move function for NPlankton organisms with the ability to die.
            int movement;
            if ( where_x == 0 ) {
                if (where_y == 0 || where_y == y) {
                    movement = RandomInteger(4,6);
                }
                else {
                    movement = RandomInteger(4,8);
                }
            }
            else if (where_y == 0 || where_y == y) {
                movement = RandomInteger(2,6);
            }
            else if ( where_x == x ) {
                if (where_y == 0 || where_y == y) {
                    movement = RandomInteger(2,4);
                }
                else {
                    movement = RandomInteger(1,4);
                }
            }
            else {
                movement = RandomInteger(1,8);
            }
            // The move now:
            if (movement == 1) { interaction( map[where_x-1][where_y-1]); }
            else if (movement == 2) { interaction( map[where_x-1][where_y]); }
            else if (movement == 3) { interaction( map[where_x-1][where_y+1]); }
            else if (movement == 4) { interaction( map[where_x][where_y+1]); }
            else if (movement == 5) { interaction( map[where_x+1][where_y+1]); }
            else if (movement == 6) { interaction( map[where_x+1][where_y]); }
            else if (movement == 7) { interaction( map[where_x+1][where_y-1]); }
            else { interaction( map[where_x][where_y-1]); }
            // Food size check now:
            if (food=0) size--;       // Size reduced due to no food for 2 steps
            else food--;
            // Size check:
            if (size==0) {
                map[where_x][where_y] = &E;
            }
        }
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
Organism & create_Organism (int digit) {
    if (digit==0) { return &E; }   // just a abstract pointer for non-animal cell
    else if (digit==1) { return &E; } 
    else if (digit==2) { return &E; } 
    else if (digit==3) { return &E; } 
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
    else if (digit==21) { Dolphin X; return &X; }    // These are for the reproduction and the add option. NO RANDOM.
    else if (digit==22) { Shark X; return &X; } 
}

int main() {
    restart_label:      // This is the required label for the restart action
    srand((int)time(0));
    NON E;  // Creating the empty object
    extern int x=RandomInteger(15,20);
    extern int y=RandomInteger(15,20);
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
                *Y.where_x=i;        // Add their place inside the placeholders
                *Y.where_y=j;
                row.push_back( *Y ); // Add an element to the row
                if ( digit >= 4 ) org_counter++;   // Add one to the organism counter if an organism is been added
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
    cout << "Map initialized successfully" << endl;
    // Done. Starting menus and steps.
    char choice;
    info_print_label:      // <-------- This is the required label for the print and the info actions
    cout << "Press S to make a step\nP to print the map\nA to add an organism or Infection\nR to restart\nI to get info\nAnything else to quit" << endl;
    cin >> choice;
    while (choice == 'S' || choice == 's') {
        for (int i=0;i=x;i++) {
            for (int j=0; j=y; j++) {
                map[i][j].move();           // Calling the move function of all the organisms to make a step  
            }
        }
        step_counter++;
        cout << "Press S to make a step\nP to print the map\nA to add an organism or Infection\nR to restart\nI to get info\nAnything else to quit" << endl;
        // Yes you have need to hit 's' everytime, for every step. I need something like conio.h for *nix to implement a continuous loop.
        cin >> choice;
    }
    if (choice == 'R' || choice == 'r')
        goto restart_label;
    else if (choice == 'I' || choice == 'i') {
        // Starting to count organisms:
        int P_cn=0, Z_cn=0, K_cn=0, M_cn=0, G_cn=0, T_cn=0, C_cn=0, A_cn=0, D_cn=0, S_cn=0;    // Counters
        for (i=0; i=x; i++) {
            for (j=0; j=y; j++) {
                // Maybe there is THE NEED FOR >>*<<map[i][j] down below here
                if ( map[i][j].alias == 'P' ) P_cn++;
                else if ( map[i][j].alias == 'Z' ) Z_cn++;
                else if ( map[i][j].alias == 'K' ) K_cn++;
                else if ( map[i][j].alias == 'M' ) M_cn++;
                else if ( map[i][j].alias == 'G' ) G_cn++;
                else if ( map[i][j].alias == 'T' ) T_cn++;
                else if ( map[i][j].alias == 'C' ) C_cn++;
                else if ( map[i][j].alias == 'A' ) A_cn++;
                else if ( map[i][j].alias == 'S' ) S_cn++;
                else if ( map[i][j].alias == 'D' ) D_cn++;
        }
        cout<< "There are " << org_counter << " total organisms in the map. "
            << "The spesific organisms are:\n Phytoplankton(P) - " << P_cn <<"\n Zooplankton(Z) - " << Z_cn << "\n Squid(K) - "<< K_cn
            << "\n Mylittus(M) - "<< M_cn << "\n Shrimp(G) - " << G_cn << "\n Octopus(T) - "<< T_cn
            <<"\n Crab(C) - " << C_cn << "\n Sprattus(A) - " << A_cn << "\n Dolpin(D) - " << D_cn << "\n Shark(S) - " << S_cn << endl;
        goto info_print_label;
    }
    else if (choice == 'A' || choice == 'a') {
        // User organism creation loop:
        cout << "Press the alias of the Organism you want to add or I to add an infection" << endl;
        char adding;
        cin >> adding;
        if ( adding == 'I' || adding == 'i' ) {
            // The Infection code here:
            cout << "Press the number of the row you want the infection to appear." << endl;
            int inf_x;
            cin >> inf_x;
            cout << "Press the number of the collumn." << endl;
            int inf_y;
            cin >> inf_y;
            // Killing the near organisms:
            if ( inf_x == 0 ) {
                if (inf_y == 0 || inf_y == y) {
                    map[inf_x][inf_y] = &E;     // Give the pointer to that empty object
                    map[inf_x+1][inf_y] = &E;   // For the near cells ( without getting out of limits)
                    map[inf_x][inf_y+1] = &E;
                    map[inf_x+1][inf_y+1] = &E;
                }
                else {
                    map[inf_x][inf_y] = &E;
                    map[inf_x+1][inf_y] = &E;
                    map[inf_x][inf_y+1] = &E;
                    map[inf_x+1][inf_y+1] = &E;
                    map[inf_x][inf_y-1] = &E;
                    map[inf_x+1][inf_y-1] = &E;
                }
            }
            else if (inf_y == 0 || inf_y == y) {
                map[inf_x][inf_y] = &E;
                map[inf_x+1][inf_y] = &E;
                map[inf_x][inf_y+1] = &E;
                map[inf_x+1][inf_y+1] = &E;
                map[inf_x-1][inf_y+1] = &E;
                map[inf_x-1][inf_y] = &E;
            }
            else if ( inf_x == x ) {
                if (inf_y == 0 || inf_y == y) {
                    map[inf_x][inf_y+1] = &E;
                    map[inf_x-1][inf_y+1] = &E;
                    map[inf_x-1][inf_y] = &E;
                }
                else {
                    map[inf_x][inf_y+1] = &E;
                    map[inf_x-1][inf_y+1] = &E;
                    map[inf_x-1][inf_y] = &E;
                    map[inf_x-1][inf_y-1] = &E;
                }
            else {
                map[inf_x][inf_y] = &E;
                map[inf_x+1][inf_y] = &E;
                map[inf_x][inf_y+1] = &E;
                map[inf_x-1][inf_y] = &E;
                map[inf_x][inf_y-1] = &E;
                map[inf_x+1][inf_y+1] = &E;
                map[inf_x-1][inf_y-1] = &E;
                map[inf_x+1][inf_y-1] = &E;
                map[inf_x-1][inf_y+1] = &E;
            }
        }
        else {
            cout << "Press the number of the row you want the Organism to be added" << endl;
            int arow;
            cin >> arow;
            cout << "Now press the number of the collumn you want the Organism to be added" << endl;
            int acollumn;
            cin >> acollumn;
            int c;
            if ( adding == 'P' || adding == 'p' ) c=4;         // Matching aliases with codes for the create_Organism function
            else if ( adding == 'Z' || adding == 'z' ) c=8;
            else if ( adding == 'K' || adding == 'k' ) c=11;
            else if ( adding == 'M' || adding == 'm' ) c=13;
            else if ( adding == 'G' || adding == 'g' ) c=15;
            else if ( adding == 'T' || adding == 't' ) c=18;
            else if ( adding == 'C' || adding == 'c' ) c=19;
            else if ( adding == 'A' || adding == 'a' ) c=20;
            else if ( adding == 'D' || adding == 'd' ) c=21;
            else if ( adding == 'S' || adding == 's' ) c=22;
            else { 
                cout << "There is no " << adding << " alias in the system" << endl;
                goto info_print_label;
            }
            Organism* Q = create_Organism (c);
            map[arow][acollumn] = *Q;
            *Q.where_x = arow;
            *Q.where_y = acollumn;
            cout << "Success" << endl;
            goto info_print_label;
        }
    }
    else if (choice == 'P' || choice == 'p') {
        // Print option: (for the console)
        int i,j;
        for (i=0; i=x; i++) {
            for (j=0; j=y; j++) {
                // Maybe there is THE NEED FOR >>*<<map[i][j] down below here
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
