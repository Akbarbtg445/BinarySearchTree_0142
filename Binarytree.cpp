#include <iostream>
using namespace std;

class Node
{
    public:
    int info;
    Node *leftchild;
    Node *rightchild;

    //constructor fot the node class
    Node()
    {
        leftchild = nullptr;//initialize left child to null
        rightchild = nullptr;//initialize right child to null
    }
};

class BinaryTree
{
    public:
    Node *ROOT;

    BinaryTree()
    {
        ROOT = nullptr;//intializeing root to null
    }

    void search(int element, Node *&parent, Node*currentnode)
    {
        //this function searches the curentnode of the specificated node as well as the curent
        currentnode = ROOT;
        parent = nullptr;
        while ((currentnode != nullptr)&&(currentnode->info !=element))
        {
            parent = currentnode;
            if (element < currentnode->info)
            currentnode = currentnode->leftchild;
            else
            currentnode = currentnode->rightchild;
        }
    }
    void insert()
    {
        int x;
        cout << "Masukan nilai:";
        cin >> x;

        // step 1 Alocate memory for the new node
        Node *newnode = new Node();

        //step 2 Asign value to the data field of new node
        newnode->info = x;

        //step 3 make the left and right child of the new node point to the null
        newnode->leftchild = nullptr;
        newnode->rightchild = nullptr;
    }
}