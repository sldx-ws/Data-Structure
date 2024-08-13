#include "AVLTree.hpp"

void TestAVLTree01()
{
	AVLTree<int, int> t;
	for (auto e : { 4, 2, 6, 1, 3, 5, 0, 7, 9, 8 })
	{
		t.Insert(make_pair(e, e));
	}

	t.InOrder();

	cout << t.IsBalance() << endl;
}

void TestAVLTree02()
{
	srand((unsigned int)time(0));
	const size_t N = 1000;
	AVLTree<int, int> t;
	for (size_t i = 0; i < N; ++i)
	{
		size_t x = rand();
		t.Insert(make_pair(x, x));
	}

	cout << t.IsBalance() << endl;
}

int main()
{
	// TestAVLTree01();
	TestAVLTree02();
	
	return 0;
}