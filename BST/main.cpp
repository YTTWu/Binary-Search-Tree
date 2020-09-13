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
    
    BstNode<T> *insert(BstNode<T> *root, T data);
    BstNode<T> *findMin(BstNode<T> *root);
    BstNode<T> *findMax(BstNode<T> *root);
    
    void display();
    
};




//-----------------------------------------------------



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


template<class T>
BstNode<T> *BstNode<T>::findMin(BstNode<T> *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->left == NULL )
    {
        return root;
    }
    
       return findMin(root->left);
    
    
    
    
    
    
    
    
}


template<class T>
BstNode<T> *BstNode<T>::findMax(BstNode<T> *root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if(root->right == NULL)
    {
        return root;
    }
    
    return findMax(root->right);
}




template<class T>
void BstNode<T>::display()
{
    cout << data << endl;
}












int main()
{
    BstNode<int> *root = NULL;
    
    BstNode<int> *temp;
    root = root->insert(root,5);
    root->insert(root, 10);
    root->insert(root, 3);
    root->insert(root, 2);
    root->insert(root, 1);
    
    temp = root->findMin(root);
    
    temp->display();
    
    temp = root->findMax(root);
    
    temp->display();
    
}
