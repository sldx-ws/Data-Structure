#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cstddef>  // size_t

namespace adjacency_list
{

using namespace std;

template <class W>
struct Edge
{
	Edge(int dstIdx, const W& w)
		: _dstIdx(dstIdx)
		, _next(nullptr)
		, _w(w)
	{}
	
	int _dstIdx;
	Edge<W>* _next;
	W _w;
};


template <class V, class W, bool Direction = false>
class Graph
{
	typedef adjacency_list::Edge<W> Edge;
public:
	Graph(const V* arr, size_t n)
	{
		_vertexes.reserve(n);
		for (size_t i = 0; i < n; ++i)
		{
			_vertexes.push_back(arr[i]);
			_indexMap[arr[i]] = i;
		}
		
		_table.resize(n, nullptr);
	}
	
	void AddEdge(const V& src, const V& dst, const W& w)
	{
		size_t srcIdx = GetVertexIndex(src);
		size_t dstIdx = GetVertexIndex(dst);

		Edge* eg = new Edge(dstIdx, w);
		eg->_next = _table[srcIdx];
		_table[srcIdx] = eg;
		
		// 无向图
		if (Direction == false)
		{
			Edge* eg = new Edge(srcIdx, w);
			eg->_next = _table[dstIdx];
			_table[dstIdx] = eg;
		}
	}

    size_t GetVertexIndex(const V& v)
	{
		auto it = _indexMap.find(v);
		if (it != _indexMap.end())
		{
			return it->second;
		}
		else
		{
			throw invalid_argument("顶点不存在");
			
			return -1;
		}
	}

	void Print();

private:
	vector<V> _vertexes;    // 顶点集合
	map<V, int> _indexMap;  // 顶点映射下标 
	vector<Edge*> _table;   // 邻接表
};



template<class V, class W, bool Direction>
void Graph<V, W, Direction>::Print()
{
    cout << "Vertexes:" << endl;
    for (size_t i = 0; i < _vertexes.size(); ++i)
    {
        cout << "[" << i << "]" << "->" << _vertexes[i] << endl;
    }
    cout << endl;
    
    cout << "Adjacency List:" << endl;
    for (size_t i = 0; i < _table.size(); ++i)
    {
        cout << _vertexes[i] << "[" << i << "]->";
        Edge* cur = _table[i];
        while (cur)
        {
        cout << "[" << _vertexes[cur->_dstIdx] << ":" << cur->_dstIdx << ":" << cur->_w << "]->"; 
            cur = cur->_next;
        }
        cout << "nullptr" << endl;
    }
}

}  // end of namespace adjacency_list
