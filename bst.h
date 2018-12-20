//bst.h
//Lamug, Rodolfo
//rlamug

#ifndef BST_H_
#define BST_H_

//libraries
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class BST
{
        public:
                BST(); //Constructor
                bool insert(string); //1 Insert
                int size(); //2 Size
                bool find(string); //3 Find
                void dft(vector<string> &); //4 Print
                void printVector(vector<string>);
                void bft(vector<string> &); //5 Breadth
                double distance(); //6 Distance
                int balanced(); //7 Balanced
                int max(int, int);

        private:
                class Node
                {
                        public:
                                Node(string str)
                                {m_left = NULL; m_right = NULL; m_string = str;}
                                Node *m_left = NULL;
                                Node *m_right = NULL;
                                string m_string;
                };
                Node *m_root;
                bool insert(string, Node *&); //1 Insert
                int size(Node*); //2 Size
                bool find(string, Node*); //3 Find
                void dft(vector<string> &, Node*); //4 Print
                void printVector(vector<string> &, Node*);
                void bft(vector<string> &, Node*); //5 Breadth
                double distance(double, Node*); //6 Distance
                int balanced(Node*); //7 Balanced
};
#endif
