// This is the first file of the C++ Project 'EcoSystem', that I'm working on.
// I'm gonna do it all in one file and maybe split it later
// © George Papanikolaou 2011

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

// This is a system function to generate random numbers where I need.
int RandomInteger(int low, int high) {
      int k;
      double d;
      d = (double)rand()/(1.0 + (double)RAND_MAX);
      k = (int) (d*(high - low + 1));
      return (low + k);
      // cout << RandomInteger(1,8) << endl;    <--- This is what you need to generate
}

// This is the main function for time operations
void wait (int seconds) {
    clock_t endwait;
    endwait = clock () + seconds * CLOCKS_PER_SEC;
    while (clock() < endwait) {/* Nothing to see here */}
}

// Declaration of the classes begins here =========================================
class Organism {
    private:
        int age;
        int size;
        int growth;     // Growth Percentage
        int food;       // Ammount of food they need
        bool sex;       // 0 for female, 1 for male
        void interaction() {
            // This is the main interaction fucntion for stuff like eating and reproduction
            if ( /* The master class is the same -> reproduction, else eating if possible*/ ) {}
        }
    public:
        void move() {
            int movement = RandomInteger(1,8);
        }
        Organism() {      // Constructor of the class
           age = RandomInteger(1,50);
           sex = RandomInteger(0,1);
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
// Declaration of the classes ends here ==========================================

int main() {
    srand((int)time(0));
    int choice;
    bool running = false;
    cout << "Welcome - Please select one of the functions:" << endl;
    cout << "1 - Start\n2 - Pause\n3 - Resume\n4 - Restart\n5- Add new object\n6- Get info\nElse to quit" << endl;
    cin >> choice;
    while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6) {
        if (choice == 1) {
            if (running=true)
                cout << "System already running" << endl;
            else {
                // <--- Generating system here --->
                clock_t run_clock = clock();
                int x=RandomInteger(9,13);
                int y=RandomInteger(9,13);
                Organism map[x][y];
                cout << "Generating the map" << endl;
                cout << "The map has " << x << " length and" << y << " width" << endl;
                int N = x*y;
                cout << "Placing organisms into the map" << endl;
                for (int i=0; i=N/2; i++) {
                    int place_x = RandomInteger(1,N);
                    int place_y = RandomInteger(1,N);
                    map [place_x][place_y] = Phytoplankton o1;
                    // Create more organisms here (problably with another function or class)
                }
            }
        }
        else if (choice == 2) {
            if (running=false)
                cout << "System not running" << endl;
            else {
                run_clock = 0;
                cout << "System paused" << endl;
            }
        }
        else if (choice == 3) {
            if (running=true)
                cout << "System already running" << endl;
            else {
                //Resume system here:
            }
        }
        else if (choice == 4) {
            // Restart system here
        }
        else if (choice == 5) {
            //Add new object to the list and the system (with user input) here
        }    
        else {
            // Code to give info to the user here (user input) statistics, organism info etc. 
        }
        cout << "1 - Start\n2 - Pause\n3 - Resume\n4 - Restart\n5- Add new object\n6- Get info\nElse to quit" << endl;
        cin >> choice;
    }
    return 0;
}
