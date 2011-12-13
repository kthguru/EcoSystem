// This is the first file of the C++ Project 'EcoSystem', that I'm working on.
// I'm gonna do it all in one file and split it later maybe
// © George Papanikolaou 2011

#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;
srand (time(NULL));

class Organism
{
    private:
        int age;
        int size;
        int growth;     //Growth Percentage
        bool reproduction;
        bool sex;       // 0 for female, 1 for male
    public:
        
};

class Plankton: public Organism
{
    private:
    public:
};

class Zooplankton: public Plankton
{
    private:
    public:
};

class Phytoplankton: public Plankton
{
    private:
    public:
};

int main()
{
    int choice;
    cout << "Welcome - Please select one of the functions:" << endl;
    cout << "1 - Start\n2 - Pause\n3 - Resume\n4 - Restart" << endl;
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
        if (choice == 1)
            {}
        elseif (choice == 2)
            {}
        elseif (choice == 3)
            {}
        else
            {}
        cin >> choice;
    return 0;
}


