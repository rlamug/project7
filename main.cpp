//main.cpp
//Lamug, Rodolfo
//rlamug

//libraries
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>

//.h file
#include"bst.h"

using namespace std;

int main()
{
        vector<string> values; //Vector of strings
        BST function; //Declare object called function of class BST
        string str;
        string command;

        while (cin >> command)
        {
                if (command != "echo" && command != "insert" && command != "size" && command != "find" && command != "print" && command != "breadth" && command != "distance" && command != "balanced" && command != "rebalance") //prints error message if illegal command is used
                {
                        cin >> ws;
                        getline(cin, str);
                        cerr << "Illegal command <" << command << ">." << endl;
                }
                else if (command == "echo") //echo command
                {
                        cin >> ws;
                        getline(cin, str);
                        cout << str << endl;
                }
                else if (command == "insert") // insert command
                {
                        cin >> ws;
                        getline(cin, str);
                        if (function.insert(str) == false) //error message
                        {
                                cerr << "insert <" << str << "> failed. String already in tree." << endl;
                        }
                }
                else if (command == "size") //size command
                {
                        cout << function.size() << endl;
                }
                else if (command == "find") //find command
                {
                        cin >> ws;
                        getline(cin, str);
                        if (function.find(str) == true)
                        {
                                cout << "<" << str << ">" << " is in tree." << endl;
                        }
                        else
                        {
                                cout << "<" << str << ">" << " is not in tree." << endl;
                        }
                }
                else if (command == "print") //print command
                {
                        function.dft(values);
                        function.printVector(values);
                        values.clear();
                }
                else if (command == "breadth") //breadth command
                { 
                        function.bft(values);
                        function.printVector(values);
                        values.clear();
                }
                else if (command == "distance") //distance command
                {
                        cout << "Average distance of nodes to root = " << function.distance() << endl;
                }
                else if (command == "balanced") //balanced command
                {
                        if (function.balanced() > -1)
                        {
                                cout << "Tree is balanced." << endl;
                        }
                        else
                        {
                                cout << "Tree is not balanced." << endl;
                        }
                }

        }

        return 0;
}
