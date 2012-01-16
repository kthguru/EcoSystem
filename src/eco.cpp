// This is the first file of the C++ Project 'EcoSystem', that I'm working on.
// I'm gonna do it all in one file and maybe split it later
// © George Papanikolaou 2011

#include <iostream>
#include <cstring>
#include <ctime>
#include <vector>
#include <cstdlib>
#include "classes.h"

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

// Organism creator function:
Organism  create_Organism (int digit) {
    if (digit==0) { return E; }   // just a abstract pointer for non-animal cell
    else if (digit==1) { return E; } 
    else if (digit==2) { return E; } 
    else if (digit==3) { return E; } 
    else if (digit==4) { Phytoplankton X; return X; } /*****************************/
    else if (digit==5) { Phytoplankton X; return X; } /*   Phytoplankton creation  */
    else if (digit==6) { Phytoplankton X; return X; } /* The same times as "empty" */
    else if (digit==7) { Phytoplankton X; return X; } /*****************************/
    else if (digit==8) { Zooplankton X; return X; } 
    else if (digit==9) { Zooplankton X; return X; }
    else if (digit==10) { Zooplankton X; return X; }
    else if (digit==11) { Squid X; return X; } 
    else if (digit==12) { Squid X; return X; }
    else if (digit==13) { Mylittus X; return X; } 
    else if (digit==14) { Mylittus X; return X; } 
    else if (digit==15) { Shrimp X; return X; } 
    else if (digit==16) { Shrimp X; return X; } 
    else if (digit==17) { Shrimp X; return X; } 
    else if (digit==18) { Octopus X; return X; } 
    else if (digit==19) { Crab X; return X; } 
    else if (digit==20) { Sprattus X; return X; } 
    else if (digit==21) { Dolphin X; return X; }    // These are for the reproduction and the add option. NO RANDOM.
    else if (digit==22) { Shark X; return X; } 
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
    Organism map;   // This is made with a static array
    // Counters:
    int step_counter = 1;
    int org_counter = 0;
    cout << "Placing organisms into the map..." << endl;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
                int digit = RandomInteger(0,20);    // Generate a random digit for the organism creation 
                Organism Y = create_Organism (digit);
                Y.where_x=i;              // Add their place inside the placeholders
                Y.where_y=j;
                map[i][j] = Y
                if ( digit >= 4 ) org_counter++;   // Add one to the organism counter if an organism is been added
        }
    }
    // Placing a shark and a dolphin.
    bool flag=false;
    while (flag==false) {
        int place_x = RandomInteger(0,map.size());
        int place_y = RandomInteger(0,map.size());
        if (map[place_x][place_y].alias='O') {
            Shark S;
            map[place_x][place_y] = S;
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
            map[place_x][place_y] = D;
            flag=true;
            org_counter++;
        }
    }
    cout << "Map initialized successfully" << endl;
    // Done. Starting menus and steps.
    char choice;
    info_print_label:      // <-------- This is the required label for the print and the info actions
    cout << "Press S to make a step\nP to print the map\nA to add an Organism or Infection\nR to restart\nI to get info\nAnything else to quit" << endl;
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
        cout << "System running for " << clock()/CLOCKS_PER_SEC << " seconds" << endl;
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
                    map[inf_x][inf_y] = E;     // Give the pointer to that empty object
                    map[inf_x+1][inf_y] = E;   // For the near cells ( without getting out of limits)
                    map[inf_x][inf_y+1] = E;
                    map[inf_x+1][inf_y+1] = E;
                }
                else {
                    map[inf_x][inf_y] = E;
                    map[inf_x+1][inf_y] = E;
                    map[inf_x][inf_y+1] = E;
                    map[inf_x+1][inf_y+1] = E;
                    map[inf_x][inf_y-1] = E;
                    map[inf_x+1][inf_y-1] = E;
                }
            }
            else if (inf_y == 0 || inf_y == y) {
                map[inf_x][inf_y] = E;
                map[inf_x+1][inf_y] = E;
                map[inf_x][inf_y+1] = E;
                map[inf_x+1][inf_y+1] = E;
                map[inf_x-1][inf_y+1] = E;
                map[inf_x-1][inf_y] = E;
            }
            else if ( inf_x == x ) {
                if (inf_y == 0 || inf_y == y) {
                    map[inf_x][inf_y+1] = E;
                    map[inf_x-1][inf_y+1] = E;
                    map[inf_x-1][inf_y] = E;
                }
                else {
                    map[inf_x][inf_y+1] = E;
                    map[inf_x-1][inf_y+1] = E;
                    map[inf_x-1][inf_y] = E;
                    map[inf_x-1][inf_y-1] = E;
                }
            else {
                map[inf_x][inf_y] = E;
                map[inf_x+1][inf_y] = E;
                map[inf_x][inf_y+1] = E;
                map[inf_x-1][inf_y] = E;
                map[inf_x][inf_y-1] = E;
                map[inf_x+1][inf_y+1] = E;
                map[inf_x-1][inf_y-1] = E;
                map[inf_x+1][inf_y-1] = E;
                map[inf_x-1][inf_y+1] = E;
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
            Organism Q = create_Organism (c);
            map[arow][acollumn] = Q;
            Q.where_x = arow;
            Q.where_y = acollumn;
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
