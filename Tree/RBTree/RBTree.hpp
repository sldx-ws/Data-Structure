#pragma once

#include <iostream>
#include <utility>   // pair
#include <algorithm> // swap
using namespace std;

enum Colour
{
    BLACK,
    RED
};

template <class K, class V>
struct RBTreeNode
{
    RBTreeNode(const pair<K, V>& kv)
        : _kv(kv)
    {}

    RBTreeNode<K, V>* _left   = nullptr;
    RBTreeNode<K, V>* _right  = nullptr;
    RBTreeNode<K, V>* _parent = nullptr;
    pair<K, V> _kv;
    Colour _col = RED;
};

template <class K, class V>
class RBTree
{
    typedef RBTreeNode<K, V> Node;
public:
    bool Insert(const pair<K, V>& kv);
    Node* Find(const K& key);
    void InOrder();

private:
	void RotateL(Node* parent);  // 左单旋
	void RotateR(Node* parent);  // 右单旋
    void _InOrder(Node* root);

private:
    Node* _root = nullptr;
};

template <class K, class V>
bool RBTree<K, V>::Insert(const pair<K, V>& kv)
{
    if (_root == nullptr)
    {
        _root = new Node(kv);
        _root->_col = BLACK;
        return true;
    }

    // double pointer
    Node* parent = nullptr;
    Node* cur = _root;
    while (cur)
    {
        if (cur->_kv.first < kv.first)
        {
            parent = cur;
            cur = cur->_right;
        }
        else if (cur->_kv.first > kv.first)
        {
            parent = cur;
            cur = cur->_left;
        }
        else
        {
            return false;
        }
    }

    cur = new Node(kv);
    cur->_parent = parent;
    if (parent->_kv.first < kv.first)
        parent->_right = cur;
    else
        parent->_left = cur;


    while (parent && parent->_col == RED)
    {
        Node* grandfather = parent->_parent;
        if (grandfather->_left == parent)
        {
            Node* uncle = grandfather->_right;
            // 情况1：u存在且红
            if (uncle && uncle->_col == RED)
            {
                parent->_col = BLACK;
                 uncle->_col = BLACK;
                grandfather->_col = RED;

                cur = grandfather;
                parent = cur->_parent;
            }
            else
            {
                // 情况2：单旋
                if (cur == parent->_left) 
                {
                    RotateR(grandfather);
                    parent->_col = BLACK;
                    grandfather->_col = RED;
                }
                else
                {
                    // 情况3：双旋
                    RotateL(parent);
                    RotateR(grandfather);
                    cur->_col = BLACK;
                    grandfather->_col = RED;
                }

                break;
			}
		}
        else
        {
            Node* uncle = grandfather->_left;
            // 情况1：u存在且红
            if (uncle && uncle->_col == RED)
            {
                parent->_col = BLACK;
                 uncle->_col = BLACK;
                grandfather->_col = RED;

                cur = grandfather;
                parent = cur->_parent;
            }
            else
            {
                // 情况2：单旋
                if (cur == parent->_right)
                {
                    RotateL(grandfather);
                    parent->_col = BLACK;
                    grandfather->_col = RED;
                }
                else
                {
                    // 情况3：双旋
                    RotateR(parent);
                    RotateL(grandfather);
                    cur->_col = BLACK;
                    grandfather->_col = RED;
                }

                break;
            }
        }
    }

    _root->_col = BLACK;

    return true;
}

template <class K, class V>
typename RBTree<K, V>::Node* RBTree<K, V>::Find(const K& key)
{
    Node* cur = _root;
    while (cur)
    {
        if (cur->_kv.first < key)
            cur = cur->_right;
        else if (cur->_kv.first > key)
            cur = cur->_left;
        else    
            return cur;
    }

    return nullptr;
}


template <class K, class V>
void RBTree<K, V>::RotateL(Node* parent)
{
	Node* subR = parent->_right;
	Node* subRL = subR->_left;

	parent->_right = subRL;
	if (subRL)
		subRL->_parent = parent;

	subR->_left = parent;
	Node* ppNode = parent->_parent;
	parent->_parent = subR;

	if (ppNode == nullptr) // 或者 if (_root == parent)
	{
		_root = subR;
		_root->_parent = nullptr;
	}
	else
	{
		if (ppNode->_left == parent)
			ppNode->_left = subR;
		else
			ppNode->_right = subR;

		subR->_parent = ppNode;
	}
}

template <class K, class V>
void RBTree<K, V>::RotateR(Node* parent)
{
	Node* subL = parent->_left;
	Node* subLR = subL->_right;

	parent->_left = subLR;
	if (subLR)
		subLR->_parent = parent;

	subL->_right = parent;
	Node* ppNode = parent->_parent;
	parent->_parent = subL;

	if (ppNode == nullptr)
	{
		_root = subL;
		_root->_parent = nullptr;
	}
	else
	{
		if (ppNode->_left == parent)
			ppNode->_left = subL;
		else
			ppNode->_right = subL;

		subL->_parent = ppNode;
	}
}

template <class K, class V>
void RBTree<K, V>::_InOrder(Node* root)
{
	if (root == nullptr)
		return;

	_InOrder(root->_left);
	cout << root->_kv.first << ":" << root->_kv.second << endl;
	_InOrder(root->_right);
}

template <class K, class V>
void RBTree<K, V>::InOrder()
{
	_InOrder(_root);
	cout << endl;
}