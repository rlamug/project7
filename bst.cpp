//bst.cpp
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

//Constructor
BST::BST()
{
        m_root = NULL;
}

//Insert Function: Inserts string into tree if is isn't already in there
bool BST::insert(string str) 
{
        return insert(str, m_root);
}

bool BST::insert(string str, Node* & cur_root)
{
        if (cur_root == NULL)
        {
                cur_root = new Node(str);
                return  true;
        }
        else if (str == cur_root->m_string) //string is already in tree
        {
                return false;
        }
        else
        {
                if (str < cur_root->m_string) //inserts to left
                {
                        return insert(str, cur_root->m_left);
                }
                if (str > cur_root->m_string) //inserts to right
                {
                        return insert(str, cur_root-> m_right);
                }
                return true;
        }
}

//Size Function: Prints size of tree
int BST::size()
{
        return size(m_root);
}

int BST::size(Node* cur_root)
{

        if (cur_root == NULL)
        {
                return 0;
        }
        else
        {
                return size(cur_root->m_left) + size(cur_root->m_right) + 1;
        }
}

//Find Function: Finds given string and prints it, else prints error message
bool BST::find(string str)
{
        return find(str, m_root);
}

bool BST::find(string str, Node* cur_root)
{
        if (cur_root == NULL)
        {
                return false;
        }
        else if (str < cur_root->m_string) //searches through left side
        {
                return find(str, cur_root->m_left);
        }
        else if (str == cur_root->m_string) //found string
        {
                return true;
        }
        else if (str > cur_root->m_string) //searches through right side
        {
                return find(str, cur_root->m_right);
        }
        else
        {
                return false;
        }
}

//DFT Function: Recursive Depth First Traversal(DFT). Traverse the tree using a depth-first algorithm
void BST::dft(vector<string> &values)
{
        dft(values, m_root);
}

void BST::dft(vector<string> &values, Node* cur_root)
{
        if (cur_root == NULL)
        {
                return;
        }
        //Inorder Depth First Traversal
        dft(values, cur_root->m_left);
        values.push_back(cur_root->m_string);
        dft(values, cur_root->m_right);
}

//Vector Print Function: Prints all the elements of tree within {}
void BST::printVector(vector<string> values)
{
        unsigned int i;
        cout << "{";
        for (i=0; i<values.size(); ++i)
        {
                cout << values[i];
                if (i < values.size() - 1)
                {
                        cout << ", ";
                }
        }
        cout << "}" << endl;
}

//BFT Function: Bepth First Traversal(BFT)
void BST::bft(vector<string> &values)
{
        bft(values, m_root);
}

void BST::bft(vector<string> &values, Node* cur_root)
{
        if (cur_root == NULL)
        {
                return;
        }
        queue<Node*> queue; //Create empty queue
        queue.push(m_root); 

        while (!queue.empty()) //loops while queue is not empty
        { 
                values.push_back(queue.front() -> m_string); //Call to front() to get element

                if (queue.front()->m_left != NULL) //Enqueue left child on to queue
                {        
                        queue.push(queue.front()->m_left); 
                }
                if (queue.front()->m_right != NULL) //Enqueue right child on to queue
                {
                        queue.push(queue.front()->m_right); 
                }
                queue.pop(); //removes element from queue
        }
}

//Distance Funciton: Prints average distance of nodes to root = followed  by  the average (as a double) of all the node distances from root.
double BST::distance()
{
        double sum = distance(0, m_root);
        int nodes = size();
        return (sum/ (double) nodes);
}

double BST::distance(double x, Node* cur_root)
{
        if (cur_root == NULL)
        {
                return 0;
        }
        return (distance(x + 1, cur_root->m_left) + distance(x + 1, cur_root->m_right) + x);
}

//Balance Function:
int BST::balanced()
{
        return balanced(m_root);
}

int BST::balanced(Node *cur_root)
{
        if (cur_root == NULL)
        {
                return 0; //balanced but of height zero
        }
        if (abs(balanced(cur_root->m_left) - balanced(cur_root->m_right)) > 1 /*tree is not balanced*/|| balanced(cur_root->m_left) == -1 /*left subtree is not balanced*/|| balanced(cur_root->m_right) == -1 /*right subtree is not balanced*/) //Either of children's subtrees (left or right) is not balanced
        {
                return -1; //Im not balanced
        }
        else //returns largest of children's subtree plus one (plus one is because cur_node also needs to be counted in height)
        {
                return (max(balanced(cur_root->m_left), balanced(cur_root->m_right)) + 1); //compares which tree has highest height value
        }
}

//Max Function: Compares two numbers and returns the one with the greatest value
int BST::max(int a, int b)
{
        return a>=b ? a:b;
}

/*void BST::insert_from_vector(vector <string> &elements,
  int start_index, int end_index)
  {
// this call should recursively insert elements[start_index]..elements[end_index]
// // on each recursive call, you send a different start_index and end_index
// // to the recursive calls
// handle the base cases where the range is of size zero or one
// think carefully about what should happen in each of these cases
// figure out the index of the middle element:
// int middle_index = ...   (if there are two possible middle indexes,
// e.g. middle of  an array of 4 is 1 or 2,
// pick the smallest)
// use your existing insert() to insert elements[middle_index];
// recursively call insert_from_vector with middle_index+1 .. end_index
// recursively call insert_from_vector with start_index .. middle_index - 1
// }
*/
