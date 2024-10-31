#include "Graph_table.hpp"
#include "Graph_matrix.hpp"
using namespace std;

void matrix_test()
{
	matrix::Graph<char, int, INT_MAX, true> g("ABCD", 4);
	g.AddEdge('A', 'B', 1);
	g.AddEdge('A', 'C', 4);
	g.AddEdge('B', 'C', 2);
	g.AddEdge('B', 'D', 9);
	g.AddEdge('C', 'D', 8);
	g.AddEdge('C', 'B', 5);
	g.AddEdge('C', 'A', 3);
	g.AddEdge('D', 'C', 6);
	
	g.Print();
}

void table_test()
{
	string a[] = { "北京", "上海", "合肥", "武汉" };
	adjacency_list::Graph<string, int> g(a, 4);
	g.AddEdge("北京", "上海", 100);
	g.AddEdge("北京", "合肥", 200);
	g.AddEdge("合肥", "武汉", 30);
	
	g.Print();
}

int main()
{
    matrix_test();
    // table_test();

    return 0;
}