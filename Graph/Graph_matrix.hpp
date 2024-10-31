#pragma once
#include <vector>
#include <map>
#include <queue>
#include <functional>
#include <climits>    // INT_MAX

namespace matrix
{

using namespace std;

template <class V, class W, W W_MAX = INT_MAX, bool Direction = false>
class Graph
{
	typedef Graph<V, W, W_MAX, Direction> Self;
public:
	struct Edge
	{
		Edge(size_t srcIdx, size_t dstIdx, const W& w)
			:_srcIdx(srcIdx)
			, _dstIdx(dstIdx)
			, _w(w)
		{}
		
		bool operator>(const Edge& e) const
		{
			return _w > e._w;
		}
		
		size_t _srcIdx;
		size_t _dstIdx;
		W _w;
	};

	Graph() = default;

	Graph(const V* arr, size_t n)
	{
		_vertexes.reserve(n);
		for (size_t i = 0; i < n; ++i)
		{
			_vertexes.push_back(arr[i]);
			_indexMap[arr[i]] = i;
		}
		
		_matrix.resize(n);
		for (size_t i = 0; i < _matrix.size(); ++i)
		{
			_matrix[i].resize(n, W_MAX);
		}
	}
	
	void AddEdge(const V& src, const V& dst, const W& w)
	{
		size_t srcIdx = GetVertexIndex(src);
		size_t dstIdx = GetVertexIndex(dst);

		/*
		_matrix[srcIdx][dstIdx] = w;
		
		// 无向图
		if (Direction == false)
		{
			_matrix[dstIdx][srcIdx] = w;
		}
		*/
		
		_AddEdge(srcIdx, dstIdx, w);
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

	void BFS(const V& src);
	void DFS(const V& src);
	W Kruskal(Self& minTree);
	void Print();

private:
	void _AddEdge(size_t src, size_t dst, const W& w);
	void _DFS(size_t srcIdx, vector<bool>& visited);

private:
	vector<V> _vertexes;        // 顶点集合
	map<V, int> _indexMap;      // 顶点映射下标 
	vector<vector<W>> _matrix;  // 邻接矩阵
};	



template<class V, class W, W W_MAX, bool Direction>
void Graph<V, W, W_MAX, Direction>::BFS(const V& src)
{
	size_t srcIdx = GetVertexIndex();

	// 队列和标记数组
	queue<int> q;
	vector<bool> visited(_vertexes.size(), false);
	
	q.push(srcIdx);
	visited[srcIdx] = true;
	int levelSize = 1;
	
	size_t n = _vertexes.size();
	while (!q.empty())
	{
		// 一层一层出
		for (int i  = 0; i < levelSize; ++i)
		{
			int front = q.front();
			q.pop();
			cout << front << ":" << _vertexes[front] << " ";
			
			// 把顶点front的邻接顶点入队
			for (size_t i = 0; i < n; ++i)
			{
				if (_matrix[front][i] != W_MAX)
				{
					if (visited[i] == false)
					{
						q.push(i);
						visited[i] = true;
					}
				}
			}
		}
		cout << endl;
		
		levelSize = q.size();
	}
	
	cout << endl;
}

template<class V, class W, W W_MAX, bool Direction>
void Graph<V, W, W_MAX, Direction>::DFS(const V& src)
{
	size_t srcIdx = GetVertexIndex(src);
	vector<bool> visited(_vertexes.size(), false);
	
	_DFS(srcIdx, visited);
	
	// 不是连通图
	// 遍历visited数组，然后DFS
}

template<class V, class W, W W_MAX, bool Direction>
void Graph<V, W, W_MAX, Direction>::_DFS(size_t srcIdx, vector<bool>& visited)
{
	cout << srcIdx << ":" << _vertexes[srcIdx] << endl;
	visited[srcIdx] = true;
	
	// 找一个srcIdx相邻的没有访问过的点，去往深度遍历
	for (size_t i  =0; i < _vertexes.size(); ++i)
	{
		if (_matrix[srcIdx][i] != W_MAX && visited[i] == false)
		{
			_DFS(i, visited);
		}
	}
}

template<class V, class W, W W_MAX, bool Direction>
void Graph<V, W, W_MAX, Direction>::_AddEdge(size_t srcIdx, size_t dstIdx, const W& w)
{
	_matrix[srcIdx][dstIdx] = w;
	
	// 无向图
	if (Direction == false)
	{
		_matrix[dstIdx][srcIdx] = w;
	}
}

template<class V, class W, W W_MAX, bool Direction>
void Graph<V, W, W_MAX, Direction>::Print()
{
	cout << "Vertexes:" << endl;
	for (size_t i = 0; i < _vertexes.size(); ++i)
	{
		cout << "[" << i << "]" << "->" << _vertexes[i] << endl;
	}
	cout << endl;
	
	cout << "Matrix:" << endl << " ";
	for (size_t i = 0; i < _vertexes.size(); ++i)
	{ 
		cout << "  " << _vertexes[i]; // row
	}
	cout << endl;
	
	for (size_t i = 0; i < _matrix.size(); ++i)
	{
		cout << _vertexes[i];  // col
		for (size_t j = 0; j < _matrix[i].size(); ++j)
		{
			if (_matrix[i][j] == W_MAX)
				printf("%3c", '*');
			else
				printf("%3d", _matrix[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

// template<class V, class W, W W_MAX, bool Direction>
// W Graph<V, W, W_MAX, Direction>::Kruskal(Self& minTree)
// {
// 	size_t n = _vertexes.size();
	
// 	minTree._vertexes = _vertexes;
// 	minTree._indexMap = _indexMap;
// 	minTree._matrix.resize(n);
// 	for (size_t i = 0; i < n; ++i)
// 	{
// 		minTree._matrix[i].resize(n, W_MAX);
// 	}
	
// 	priority_queue<Edge, vector<Edge>, greater<Edge>> minQue;
	
// 	for (size_t i = 0; i < n; ++i)
// 	{
// 		for (size_t j = 0; j < n; ++j)
// 		{
// 			if (i < j && _matrix[i][j] != W_MAX)
// 			{
// 				minQue.push(Edge(i, j, _matrix[i][j]));
// 			}
// 		}
// 	}
	
// 	// 选出(n - 1)条边
// 	int size = 0;
// 	W totalW = W();
// 	unionFindSet ufs(n);
// 	while (!minQue.empty())
// 	{
// 		Edge min = minQue.top();
// 		minQue.pop();
		
// 		if (!ufs.InSet(min._srcIdx, min._dstIdx))
// 		{
// 			cout << _vertexes[min._srcIdx] << "->" << _vertexes[min._dstIdx] << ":" << min._w << endl;
// 			minTree._AddEdge(min._srcIdx, min._dstIdx, min._w);
// 			ufs.Union(min._srcIdx, min._dstIdx);
// 			++size;
// 			totalW += min._w;
// 		}
// 		else
// 		{
// 			cout << "构成环了：";
// 			cout << _vertexes[min._srcIdx] << "->" << _vertexes[min._dstIdx] << ":" << min._w << endl;
// 		}
// 	}
	
// 	if (size == n - 1)
// 		return totalW;
// 	else
// 		return W();
// }

}  // end of namespace matrix
