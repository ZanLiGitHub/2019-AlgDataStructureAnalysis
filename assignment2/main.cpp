//****************************************************************************************************
// Course name: Algorithm & Data Structure Analysis (COMP 7201)
// Author : ZanLi
// ID : a1750906
// Start date : 29/09/2019
// Finish date : 02/10/2019
// Version : 7
//****************************************************************************************************

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

// implementing structures****************************************************************************
// creating a class node. A node includes value, height, left branch and right branch 
template <class T>
class Node
{
    public:
        //the value of this node
        int value;
        //the height of this node           
        int height;        
        //the liftBranch of this node
        Node *leftBranch;    
        //the rightBranch of this node
        Node *rightBranch;  
        //initializing node
        Node(int value, Node *leftBranch, Node *rightBranch):
        value(value), height(0),leftBranch(leftBranch),rightBranch(rightBranch) {}
};

// creating a class AVLTree. An AVLTree includes a root and many functions  
template <class T>
class AVLTree 
{
    public:
        // the root of this tree
        Node<T> *root;
        // initializing a tree
        AVLTree();
        // return the height of this tree
        int height(Node<T>* tree) ;
        // print the tree by preorder
        void preOrder();
        void preOrder(Node<T>* tree) const;
        // print the tree by inorder
        void inOrder();
        void inOrder(Node<T>* tree) const;
        // print the tree by post order
        void postOrder();
        void postOrder(Node<T>* tree) const;
        // search a node with value in the tree
        Node<T>* search(int value);
        Node<T>* search(Node<T>* x, int value) const;
        // insert a node with  value in the tree
        void insert(int value);
        Node<T>* insert(Node<T>* &tree, int value);
        // remove a node with value in the tree
        void remove(int value);
        Node<T>* remove(Node<T>* &tree, Node<T>* z);
        // find the biggest node in this tree
        Node<T>* maxNode(Node<T>* tree);
        // for left left rotation
        Node<T>* LLRotation(Node<T>* k2);
        // for right right rotation
        Node<T>* RRRotation(Node<T>* k1);
        // for left right rotation
        Node<T>* LRRotation(Node<T>* k3);
        // for right left rotaion
        Node<T>* RLRotation(Node<T>* k1);
};


// impelementing functions****************************************************************************
// compare and find the bigger one between two numbers
int max(int num1, int num2) 
{
    if(num1 > num2)
    {
    	return num1;
    }
    else
    {
    	return num2;
    }
}

// initializing an AVLTree, set the root as null
template <class T>
AVLTree<T>::AVLTree():root(NULL)
{
}

// return the height of this node
template <class T>
int AVLTree<T>::height(Node<T>* node) 
{
    if (node != NULL)
    {
        return node->height;
    }
    return 0;
}

// print the tree with preorder 
template <class T>
void AVLTree<T>::preOrder(Node<T>* node) const
{
    if(node != NULL)
    {
        cout<< node->value << " " ;
        preOrder(node->leftBranch);
        preOrder(node->rightBranch);
    }
}
template <class T>
void AVLTree<T>::preOrder() 
{
    if(root != NULL)
    {
        preOrder(root);
    }
    else
    {
        cout << "EMPTY" << endl;
    }
}

// print the tree with inorder 
template <class T>
void AVLTree<T>::inOrder(Node<T>* node) const
{
    if(node != NULL)
    {
        inOrder(node->leftBranch);
        cout<< node->value << " " ;
        inOrder(node->rightBranch);
    }
}
template <class T>
void AVLTree<T>::inOrder() 
{
    if(root != NULL)
    {
        inOrder(root);
    }
    else
    {
        cout << "EMPTY" << endl;
    }
}

// print the tree with postorder 
template <class T>
void AVLTree<T>::postOrder(Node<T>* node) const
{
    if(node != NULL)
    {
        postOrder(node->leftBranch);
        postOrder(node->rightBranch);
        cout<< node->value << " " ;
    }
}
template <class T>
void AVLTree<T>::postOrder() 
{
    if(root != NULL)
    {
        postOrder(root);
    }
    else
    {
        cout << "EMPTY" << endl;
    }
}

// search a node with value in the tree
template <class T>
Node<T>* AVLTree<T>::search(Node<T>* node, int value) const
{
    if (node == NULL || node->value == value)
    {    
        return node;
    }

    if (value < node->value)
    {
        return search(node->leftBranch, value);
    }
    else
    {
        return search(node->rightBranch, value);
    }
}

// find the biggest node in this tree
template <class T>
Node<T>* AVLTree<T>::maxNode(Node<T>* node)
{
    if (node == NULL)
    {
        return NULL;
    }

    while(node->rightBranch != NULL)
    {
        node = node->rightBranch;
    }
    return node;
}

// for left left rotaion
template <class T>
Node<T>* AVLTree<T>::LLRotation(Node<T>* highNode)
{
    Node<T>* lowNode;

    lowNode = highNode->leftBranch;
    highNode->leftBranch = lowNode->rightBranch;
    lowNode->rightBranch = highNode;

    highNode->height = max(height(highNode->leftBranch), height(highNode->rightBranch)) + 1;
    lowNode->height = max(height(lowNode->leftBranch), highNode->height) + 1;

    return lowNode;
}

// for right right rotation
template <class T>
Node<T>* AVLTree<T>::RRRotation(Node<T>* highNode)
{
    Node<T>* lowNode;

    lowNode = highNode->rightBranch;
    highNode->rightBranch = lowNode->leftBranch;
    lowNode->leftBranch = highNode;

    highNode->height = max( height(highNode->leftBranch), height(highNode->rightBranch)) + 1;
    lowNode->height = max( height(lowNode->rightBranch), highNode->height) + 1;

    return lowNode;
}

// for left right rotation
template <class T>
Node<T>* AVLTree<T>::LRRotation(Node<T>* highNode)
{
    highNode->leftBranch = RRRotation(highNode->leftBranch);

    return LLRotation(highNode);
}

// for right left rotation
template <class T>
Node<T>* AVLTree<T>::RLRotation(Node<T>* highNode)
{
    highNode->rightBranch = LLRotation(highNode->rightBranch);

    return RRRotation(highNode);
}

// insert a node with  value in the tree
template <class T>
Node<T>* AVLTree<T>::insert(Node<T>* &node, int value)
{	
	// if there is no node
    if (node == NULL) 
    {
        node = new Node<T>(value, NULL, NULL);
    }
    // should insert the node into the left branch
    else if (value < node->value) 
    {
        node->leftBranch = insert(node->leftBranch, value);
        // the tree losts balance
        if (height(node->leftBranch) - height(node->rightBranch) == 2)
        {
            if (value < node->leftBranch->value)
            {
                node = LLRotation(node);
            }
            else
            {
                node = LRRotation(node);
            }
        }
    }
    // should insert the node into the right branch
    else if (value > node->value) 
    {
        node->rightBranch = insert(node->rightBranch, value);
        // the tree losts balance
        if (height(node->rightBranch) - height(node->leftBranch) == 2)
        {
            if (value > node->rightBranch->value)
            {
                node = RRRotation(node);
            }
            else
            {
                node = RLRotation(node);
            }
        }
    }
    //value equals to node's value
    else 
    {
    	// do nothing
    }
    node->height = max( height(node->leftBranch), height(node->rightBranch)) + 1;
    return node;
}
template <class T>
void AVLTree<T>::insert(int value)
{
    insert(root, value);
}

// remove a node with value in the tree
template <class T>
Node<T>* AVLTree<T>::remove(Node<T>* &node, Node<T>* removeNode)
{
    // if the root or removenode is null
    if (node==NULL || removeNode==NULL)
    {
        return NULL;
    }
    // the remove node is in the left branch
    if (removeNode->value < node->value)        
    {
        node->leftBranch = remove(node->leftBranch, removeNode);
        // the tree losts balance
        if (height(node->rightBranch) - height(node->leftBranch) == 2)
        {
            Node<T> *r =  node->rightBranch;
            if (height(r->leftBranch) > height(r->rightBranch))
            {
                node = RLRotation(node);
            }
            else
            {
                node = RRRotation(node);
            }
        }
    }
    // the remove node is in the right branch
    else if (removeNode->value > node->value)
    {
        node->rightBranch = remove(node->rightBranch, removeNode);
        // the tree losts balance
        if (height(node->leftBranch) - height(node->rightBranch) == 2)
        {
            Node<T> *l =  node->leftBranch;
            if (height(l->rightBranch) > height(l->leftBranch))
            {
                node = LRRotation(node);
            }
            else
            {
                node = LLRotation(node);
            }
        }
    }
    // the node is remove node
    else    
    {
        // the node has left branch and right branch
        if ((node->leftBranch!=NULL) && (node->rightBranch!=NULL))
        {
            Node<T>* max = maxNode(node->leftBranch);
            node->value = max->value;
            node->leftBranch = remove(node->leftBranch, max);
        }
        // the node has either left branch or right branch 
        else
        {  
            if (node->leftBranch == NULL)
            {
            	node = node->rightBranch;
            }
            else
            {
            	node = node->leftBranch;
            }
        }
    }
    return node;
}
template <class T>
void AVLTree<T>::remove(int value)
{
    Node<T>* removeNode = search(root, value); 
    if (removeNode != NULL)
    {
        root = remove(root, removeNode);
    }
}


//Main function***************************************************************************************
int main()
{
	AVLTree<int>* tree=new AVLTree<int>();

	int value;
	string input1, input2, substr;
	vector<string> inputs;

	getline(cin, input1);
	stringstream ss(input1);
	
	while(ss >> input2)
	{
		inputs.push_back(input2);
	}

	for(long long unsigned int i=0; i<inputs.size(); i++)
	{
		if(inputs[i].at(0) == 'A')
		{
			substr = inputs[i].substr(1,inputs[i].length()-1);
			value = stoi(substr);
			tree->insert(value);
		}

		if(inputs[i].at(0) == 'D')
		{
			substr = inputs[i].substr(1,inputs[i].length()-1);
			value = stoi(substr);
			tree->remove(value);
		}

		if(inputs[i] == "IN")
		{
			tree->inOrder();
		}

		if(inputs[i] == "PRE")
		{
			tree->preOrder();
		}

		if(inputs[i] == "POST")
		{
			tree->postOrder();
		}
	}

    cin.get();
    return 0;
}