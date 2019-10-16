#include <iostream>
/*
 *  以朋友圈举例更容易理解
 */
class UF1
{
private:
    int count; //并查集的数量，朋友圈数量
    int *id;   //并查集的元素，朋友圈每个人的备注（编号）
    int *sz;   //并查集的大小，朋友圈的大小
public:
    UF1(int n) //构造函数
    {
        count = n;
        id = new int[n];
        sz = new int[n];

        for (int i = 0; i < n; i++)
        {
            id[i] = i; //初始状态，每个人只属于自己的圈子
            sz[i] = 1; //每个人的朋友仅有自己一个人
        }
    }
    ~UF1() { delete[] id; } //析构函数

    int size() //返回并查集数量，这些人朋友圈的数量
    {
        return count;
    }

    bool isConnect(int a, int b) //检查两个元素是否连通，是否在同一个圈子
    {
        return Find(a) == Find(b);
    }

    int Find(int p) //查找最原始的元素，这个朋友圈最出名的
    {
        if (p >= count)
            return -1;
        /*
             p   0 1 2 3 4 5  
             p[] 2 1 3 5 4 5
             result count = 3(0-2-3-5 1 4)
             */
        while (p != id[p])
            p = id[p];
        return p;
    }

   bool Union(int a, int b) //结交新朋友，改变朋友圈
    {
        int pa = Find(a), pb = Find(b);
        if (pa == pb)
            return false;          //在同一个朋友圈就不用并了
        if (sz[pa] > sz[pb]) //a朋友圈大，b并入a
        {
            id[pb] = pa;
            sz[pa] += sz[pb];
        }
        else
        {
            id[pa] = pb;
            sz[pb] += sz[pa];
        }
        count--; //并入后，朋友圈就减少1
        return true;
    }
};
