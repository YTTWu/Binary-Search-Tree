//
//  main.cpp
//  BST
//
//  Created by Yuteng Wu on 9/12/20.
//  Copyright © 2020 Yuteng Wu. All rights reserved.
//

#include <iostream>

using namespace std;

template<class T>
class BstNode
{
private:
    T data;
    BstNode *root, *left, *right;
    
public:
    BstNode();
    ~BstNode();
    
    BstNode<T> *insert(T data);
};



template<class T>
BstNode<T>::BstNode():root(NULL), left(NULL), right(NULL){}

template<class T>
BstNode<T>::~BstNode()
{
    
}


template<class T>
BstNode<T> *BstNode<T>::insert(T data)
{
    if(root == NULL)
    {
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    
    else if(root->data <= data)
    {
        
    }
}


int main()
{
    cout << "Hello World\n";
}
