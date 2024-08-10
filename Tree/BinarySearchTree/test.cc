#include "BinarySearchTree.hpp"

void TestBSTree()
{
    BSTree<int> t;

    for (auto e : { 3, 6, 7, 1, 0, 2, 9, 8, 4, 5 })
        t.Insert(e);

    t.Erase(6);
    t.InOrder();
}

int main()
{
    TestBSTree();

    return 0;
}