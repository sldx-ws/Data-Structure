#include "RBTree.hpp"

void TestRBTree()
{
	RBTree<int, int> rb;
	for (auto e : { 4, 2, 6, 1, 3, 5, 0, 7, 8, 9})
	{
		rb.Insert(make_pair(e, e));
	}

	rb.InOrder();

	RBTreeNode<int, int>* ret = rb.Find(3);
	cout << "3 : " << ret->_kv.second << endl;
}


int main()
{
    TestRBTree();
    return 0;
}