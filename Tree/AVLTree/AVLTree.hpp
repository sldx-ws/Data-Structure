#pragma once

#include <iostream>
#include <ctime>
#include <utility> // pair
#include <cstdlib> // abs
using namespace std;

template <class K, class V>
struct AVLTreeNode
{
	AVLTreeNode(const pair<K, V>& kv)
		: _kv(kv)
	{}
	
	AVLTreeNode<K, V>* _left   = nullptr;
	AVLTreeNode<K, V>* _right  = nullptr;
	AVLTreeNode<K, V>* _parent = nullptr;
	int _bf = 0;  // balance factor
	pair<K, V> _kv;
};

template <class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv);
	int Height(Node* root);	
	bool IsBalance();
	void InOrder();

private:
	void RotateL(Node* parent);  // 左单旋
	void RotateR(Node* parent);  // 右单旋
	void RotateLR(Node* parent); // 左右双旋
	void RotateRL(Node* parent); // 右左双旋
	void _InOrder(Node* root);
	bool _IsBalance(Node* root);

private:
	Node* _root = nullptr;
};

template <class K, class V>
bool AVLTree<K, V>::Insert(const pair<K, V>& kv)
{
	if (_root == nullptr)
	{
		_root = new Node(kv);
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
	if (parent->_kv.first < kv.first)
	{
		parent->_right = cur;
		cur->_parent = parent;
	}
	else
	{
		parent->_left = cur;
		cur->_parent = parent;
	}

	while (parent)
	{
		if (cur == parent->_left) parent->_bf--;
		else parent->_bf++;

		if (parent->_bf == 0)
		{
			break;
		}
		else if (parent->_bf == 1 || parent->_bf == -1)
		{
			cur = parent;
			parent = parent->_parent;
		}
		else if (parent->_bf == 2 || parent->_bf == -2)
		{
			if (parent->_bf == 2)
			{
				if (cur->_bf == 1)
					RotateL(parent);
				else if (cur->_bf == -1)
					RotateRL(parent);
			}
			else if (parent->_bf == -2)
			{
				if (cur->_bf == -1)
					RotateR(parent);
				else if (cur->_bf == 1)
					RotateLR(parent);
			}

			break;
		}
	}

	return true;
}

template <class K, class V>
void AVLTree<K, V>::RotateL(Node* parent)
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

	parent->_bf = subR->_bf = 0;
}

template <class K, class V>
void AVLTree<K, V>::RotateR(Node* parent)
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

	subL->_bf = parent->_bf = 0;
}

template <class K, class V>
void AVLTree<K, V>::RotateLR(Node* parent)
{
	Node* subL = parent->_left;
	Node* subLR = subL->_right;
	int bf = subLR->_bf;

	RotateL(parent->_left);
	RotateR(parent);

	if (bf == -1) // subLR左子树新增
	{
		parent->_bf = 1;
		subL->_bf = 0;
		subLR->_bf = 0;
	}
	else if (bf == 1) // subLR右子树新增
	{
		parent->_bf = 0;
		subL->_bf = -1;
		subLR->_bf = 0;
	}
	else if (bf == 0) // subLR自己新增
	{
		parent->_bf = 0;
		subL->_bf = 0;
		subLR->_bf = 0;
	}
}

template <class K, class V>
void AVLTree<K, V>::RotateRL(Node* parent)
{
	Node* subR = parent->_right;
	Node* subRL = subR->_left;
	int bf = subRL->_bf;

	RotateR(parent->_right);
	RotateL(parent);

	if (bf == -1) // subLR左子树新增
	{
		parent->_bf = 0;
		subR->_bf = 1;
		subRL->_bf = 0;
	}
	else if (bf == 1) // subLR右子树新增
	{
		parent->_bf = -1;
		subR->_bf = 0;
		subRL->_bf = 0;
	}
	else if (bf == 0) // subLR自己新增
	{
		parent->_bf = 0;
		subR->_bf = 0;
		subRL->_bf = 0;
	}
}

template <class K, class V>
int AVLTree<K, V>::Height(Node* root)
{
	if (root == nullptr)
		return 0;
	
	int leftHeight = Height(root->_left);
	int rightHeight = Height(root->_right);
	
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

template <class K, class V>
bool AVLTree<K, V>::_IsBalance(Node* root)
{
	if (root == nullptr)
		return true;

	int leftHeight = Height(root->_left);
	int rightHeight = Height(root->_right);

	if (rightHeight - leftHeight != root->_bf)
	{
		cout << root->_kv.first << "平衡因子异常" << endl;
		return false;
	}

	return abs(rightHeight - leftHeight) < 2
		&& _IsBalance(root->_left)
		&& _IsBalance(root->_right);
}

template <class K, class V>
bool AVLTree<K, V>::IsBalance()
{
	return _IsBalance(_root);
}

template <class K, class V>
void AVLTree<K, V>::_InOrder(Node* root)
{
	if (root == nullptr)
		return;

	_InOrder(root->_left);
	cout << root->_kv.first << ":" << root->_kv.second << endl;
	_InOrder(root->_right);
}

template <class K, class V>
void AVLTree<K, V>::InOrder()
{
	_InOrder(_root);
	cout << endl;
}