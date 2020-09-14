//
//  main.cpp
//  BST
//
//  Created by Yuteng Wu on 9/12/20.
//  Copyright © 2020 Yuteng Wu. All rights reserved.
//

#include <iostream>
#include <queue>

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
    void levelOrder(BstNode<T> *root);
    void preOrder(BstNode<T> *root);
    void inOrder(BstNode<T> *root);
    void postOrder(BstNode<T> *root);
    BstNode<T> *deleteNode(BstNode<T> *root, T data);
    
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


template<class T>
void BstNode<T>::levelOrder(BstNode<T> *root)
{
    queue<BstNode<T>*> queue;//try not to impliment it with pointers
    
    if(root == NULL) return;
    
    queue.push(root);
    
    while(!queue.empty())
    {
        BstNode<T> *current = queue.front();
        cout <<"            " <<current->data << endl;
        cout<<"           / " << "\\" << endl;
        if(current->left != NULL) queue.push(current->left);
        if(current->right != NULL) queue.push(current->right);
        queue.pop();
    }
    
}


template<class T>
void BstNode<T>::preOrder(BstNode<T> *root)
{
    
    if(root == NULL) return;
    
    cout << root->data << endl;
    
    
    preOrder(root->left);
    
    
    preOrder(root->right);
    
    
    
}




template<class T>
void BstNode<T>::inOrder(BstNode<T> *root)
{
    if(root == NULL) return;
    
    inOrder(root->left);
    
    cout << root->data << endl;
    
    inOrder(root->right);
    
}


template<class T>
void BstNode<T>::postOrder(BstNode<T> *root)
{
    if(root == NULL) return;
    
    inOrder(root->left);
    
    inOrder(root->right);
    
    cout << root->data << endl;
}


template<class T>
BstNode<T> *BstNode<T>:: deleteNode(BstNode<T> *root, T data)
{
    if(root == NULL) return root;
    
    else if(data < root->data) deleteNode(root->left, data);
    else if(data > root->data) root->right  = deleteNode(root->right, data);
    else
    {
        //case 1: No child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
            
        }
        //case 2: One child
        else if(root->left == NULL)
        {
            BstNode<T> *temp = root;
            root = root->right;
            delete temp;
            
        }
        
        else if(root->right == NULL)
        {
            BstNode<T> *temp = root;
            root = root->left;
            delete temp;
        }
        //case 3: Two child
        else
        {
            BstNode<T> *temp = findMin(root);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
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
    root->insert(root, 8);
    root->insert(root, 19);
    root->insert(root, 4);
    
    //temp = root->findMin(root);
    
    //root->display();
    
    //temp = root->findMax(root);
    
    //temp->display();
    
    //root->levelOrder(root);
    
    root->preOrder(root);
    root->deleteNode(root, 19);
    root->preOrder(root);
    
    
    
}
