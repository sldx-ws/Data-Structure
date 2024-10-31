#pragma once
#include <vector>
#include <map>
#include <cstddef>  // size_t
#include <cstdlib>  // abs
#include <algorithm>

#if 0
template<class T>
class UnionFindSet
{
public:
	UnionFindSet(const T* a, size_t n)
	{
		_a.reserve(n);
		for (size_t i = 0; i < _a.size(); ++i)
		{
			_a.push_back(a[i]);
			_indexMap[a[i]] = i;
		}
	}
	
private:
	std::vector<T> _a;  		  // 编号找人
	std::map<T, int> _indexMap;   // 人找编号
};
#endif

class unionFindSet
{
public:
    unionFindSet(size_t n)
        : _ufs(n, -1)
    {}

    int FindRoot(int x)
    {
        int root = x;
        while (_ufs[root] >= 0) root = _ufs[root];

        // 路径压缩
        while (_ufs[x] >= 0)
        {
            int parent = _ufs[x];
            _ufs[x] = root;

            x = parent;
        }

        return root; 
    }

    void Union(int x1, int x2)
    {
        int root1 = FindRoot(x1);
        int root2 = FindRoot(x2);

        if (root1 == root2) return;

        // 控制数量小的往大的合并
        if (abs(_ufs[root1]) < abs(_ufs[root2])) swap(root1, root2);

        _ufs[root1] += _ufs[root2];
        _ufs[root2] = root1;
    }

    // 集合个数
    size_t Size()
    {
        size_t size = 0;

        for ( auto& e : _ufs )
        {
            if ( e < 0 ) ++size;
        }

        return size;
    }

private:
    std::vector<int> _ufs;
};
