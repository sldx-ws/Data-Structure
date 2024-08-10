#pragma once

#include <iostream>
#include <algorithm>
using namespace std;

template <class K>
struct BSTreeNode
{
    BSTreeNode(const K& key)
        : _key(key)
    {}

    BSTreeNode<K>* _left = nullptr;
    BSTreeNode<K>* _right = nullptr;
    K _key;
};

template <class K>
class BSTree
{
    typedef BSTreeNode<K> Node;
public:
    void Insert(const K& key);
    void Erase(const K& key);
    Node* Find(const K& key);
    void InOrder();
private:
    void _InOrder(Node* root);
private:
    Node* _root = nullptr;
};

template <class K>
void BSTree<K>::Insert(const K& key)
{
    if (_root == nullptr)
    {
        _root = new Node(key);
        return;
    }

    // double pointer (or signal double)
    Node* parent = nullptr;
    Node* cur = _root;
    while (cur)
    {
        if (cur->_key < key)
        {
            parent = cur;
            cur = cur->_right;
        }
        else if (cur->_key > key)
        {
            parent = cur;
            cur = cur->_left;
        }
        else 
        {
            return;
        }
    }

    cur = new Node(key);
    if (parent->_key < key)
        parent->_right = cur;
    else if (parent->_key > key)
        parent->_left = cur;
}

template <class K>
void BSTree<K>::Erase(const K& key)
{
    // double pointer
    Node* parent = nullptr;
    Node* cur = _root;

    while (cur)
    {
        if (cur->_key < key)
        {
            parent = cur;
            cur = cur->_right;
        }
        else if (cur->_key > key)
        {
            parent = cur;
            cur = cur->_left;
        }
        else
        {
            // 1.左为空
            // 2.右为空
            // 3.左右都不为空
            if (cur->_left == nullptr)
            {
                if (cur == _root)
                {
                    _root = cur->_right;
                }
                else
                {
                    if (parent->_right == cur)
                        parent->_right = cur->_right;
                    else
                        parent->_left = cur->_right;                    
                }

                delete cur;
            }
            else if (cur->_right == nullptr)
            {
                if (cur == _root)
                {
                    _root = cur->_left;
                }
                else
                {
                    if (parent->_right == cur)
                        parent->_right = cur->_left;
                    else
                        parent->_left = cur->_left;                   
                }

                delete cur;
            }
            else
            {
                // double pointer
                Node* rightMinParent = cur;
                Node* rightMin = cur->_right;
                while (rightMin->_left)
                {
                    rightMinParent = rightMin;
                    rightMin = rightMin->_left;
                }

                cur->_key = rightMin->_key;

                if (rightMin == rightMinParent->_left)
                    rightMinParent->_left = rightMin->_right;
                else
                    rightMinParent->_right = rightMin->_right;

                delete rightMin;
            }
        }
    }
}

template <class K>
typename BSTree<K>::Node* BSTree<K>::Find(const K& key)
{
    Node* cur = _root;
    while (cur)
    {
        if (cur->_key < key)
            cur = cur->_left;
        else if (cur->_key > key)
            cur = cur->_right;
        else 
            return cur;
    }

    return nullptr;
}

template <class K>
void BSTree<K>::InOrder() // 类外调用拿不到_root
{
    _InOrder(_root);
    cout << endl;
}

template <class K>
void BSTree<K>::_InOrder(Node* root)
{
    if (root == nullptr) return;

    _InOrder(root->_left);
    cout << root->_key << " ";
    _InOrder(root->_right);
}