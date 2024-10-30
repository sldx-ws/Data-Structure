#pragma once
#include <vector>
#include <map>
#include <cstddef>  // size_t

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

    int FindRoot(int x)  // 可压缩路径
    {
        int parent = x;
        while (_ufs[parent] >= 0) parent = _ufs[parent];

        return parent; 
    }

    void Union(int x1, int x2)
    {
        int root1 = FindRoot(x1);
        int root2 = FindRoot(x2);

        if (root1 == root2) return;

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
