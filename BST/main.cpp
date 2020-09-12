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
    BstNode *left, *right;
    
    
public:
    BstNode();
    ~BstNode();
    
    BstNode<T> *insert(BstNode<T> *bst, T data);
};



template<class T>
BstNode<T>::BstNode(){}

template<class T>
BstNode<T>::~BstNode()
{
    
}


template<class T>
BstNode<T> *BstNode<T>::insert(BstNode<T> *root, T data)
{
    if(root == NULL)
    {
        BstNode<T> *newRoot = new BstNode<T>();
        newRoot->data = data;
        newRoot->left = NULL;
        newRoot->right = NULL;
        root = newRoot;
    }
    
    else if(data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}


int main()
{
    BstNode<int> *root = NULL;
    
    root = root->insert(root,5);
    root = root->insert(root, 10);
    root = root->insert(root, 3);
    root = root->insert(root, 2);
    root = root->insert(root, 1);
}
