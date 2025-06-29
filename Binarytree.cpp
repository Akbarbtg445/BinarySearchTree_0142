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
        //step 7 if the value in the data field of the new node is greater than that of the parent
        else if (x >parent->info)
        {
            //7a make the right child of the parent point to the new node
            parent->rightchild = newnode;

            //7b exit 
            return;
        }
    }

    bool isEmpty()

    { 
       //check if the tree is empty
        return ROOT == nullptr;
    } 

    void inorder (Node *ptr)
    {
        if (isEmpty())
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

        inorder (ptr->leftchild);
        cout << ptr ->info << " ";//parent
        inorder (ptr->rightchild);
    }

    void preorder (Node *ptr)
    {
        if (isEmpty())
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

     cout << ptr ->info << " ";//parent
        preorder (ptr->leftchild);
        preorder (ptr->rightchild);
    }

    void postorder (Node *ptr)
    {
        if (isEmpty())
        {
            cout << "tree is empty" << endl;
            return;
        }
        if (ptr == nullptr)
        return;

     
        postorder (ptr->leftchild);
        postorder (ptr->rightchild);
        cout << ptr ->info << " ";//parent
    }
};

int main()
{
    BinaryTree x;
    while (true)
    {
        cout << "\nMenu" << endl;
        cout << "1. Implement insert operation" << endl;
        cout << "2. Perform inorder traversal" << endl;
        cout << "3. Perform preorder traversal" << endl;
        cout << "4. Perform postorder traversal" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice (1-5) : ";

        char ch;
        cin >> ch;
        cout << endl;

        switch (ch)
        {
        case '1':
        {
            x.insert();
            break;
        }
        case '2':
        {
            x.inorder(x.ROOT);
            break;
        }
        case '3':
        {

            x.preorder(x.ROOT);
            break;
        }
        case '4':
        {

            x.postorder(x.ROOT);
            break;
        }
        case '5':
            return 0;
        default:
        {
            cout << "Invalid option" << endl;
            break;
        }
        }
    }
};