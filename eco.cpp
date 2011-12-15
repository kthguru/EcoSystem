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
      // srand((int)time(0));
      // cout << RandomInteger(1,8) << endl;
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
            if ( // The master class is the same -> reproduction, else eating if possible
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
                x=RandomInteger(9,13);
                y=RandomInteger(9,13);
                Organism map[x][y];
                cout << "Generating the map" << endl;
                cout << "The map has " << x << " length and" << y << " width" << endl;
                int N = x*y;
                cout << "Placing organisms into the map" << endl;
                for (int i=0; i=N/2; i++) {
                    int place_x = RandomInteger(1,N);
                    int place_y = RandomInteger(1,N);
                    map [place_x][place_y] = Phytoplankton o1
                }
            }
        }
        else if (choice == 2) {
            if (running=false)
                cout << "System not running" << endl;
            else {
                //Pause system here:
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
