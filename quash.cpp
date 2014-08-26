#include <iostream>
#include <string>
#include <sstream>
#include "HashTable.h"
#include "MaxHeap.h"
#include "QuashObject.h"


//load commands from the std namespace that are to be used
using std::cout; using std::cin; using std::endl; using std::string;

int main()
{
    //set up input variables
    bool input = 1;  int value; string x; int i=0;
    std::string command;

    QuashObject QuashObject;

    //Input loop
    while(input){

        string s;
        cin >> s;
        std::istringstream ss(s);
        while (!ss.eof())
        {
            string x;
            if ( command.compare("insert") == 0 || command.compare("lookup") == 0 || command.compare("delete") == 0){
                getline( ss, x, ' ' );
                value = atoi(x.c_str());
                i=1;
            }
            else {
                getline( ss, x, ' ' );
                command = x;
            }
        }

        //check for exit command
        if ( command.compare("exit") == 0 ){
            return 0;
        }

        else if ( command.compare("insert") == 0 && i==1 ){
            QuashObject.insert(value);
            command = "";
            i=0;
        }

        else if ( command.compare("print") == 0 ){
            QuashObject.print();
            command = "";
            i=0;
        }

        else if ( command.compare("lookup") == 0 && i==1 ){
            QuashObject.find(value);
            command = "";
            i=0;
        }

        else if ( command.compare("delete") == 0 && i==1 ){
            QuashObject.remove(value);
            command = "";
            i=0;
        }

        else if ( command.compare("deleteMax") == 0 ){
            QuashObject.deleteMax();
            command = "";
            i=0;
        }


    }

}
