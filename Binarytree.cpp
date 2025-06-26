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

        //step 4 locate the node which will be the parent of the node to be insert
        Node *parent = nullptr;
        Node *currentnode = nullptr;
        search(x,parent,currentnode);

        //step 5 if parent is NUll (tree is empty)
        if (parent == nullptr)
        {
            //5a mark the new node as ROOT
            ROOT = newnode;
            
            //5b exit
            return;
        }

        //step 6 if the value in the data field of new noode is less than that of parent
        if (x <parent->info)
        {
            //6a make thre left child of parent point to the new node 
            parent->leftchild = newnode;

            //6b exit 
            return;
        }
    }
}