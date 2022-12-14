#include <bits/stdc++.h>

using namespace std;

class Djset
{
public:
    vector<int> parent; // 记录节点的根
    vector<int> rank;   // 记录根节点的深度（用于优化）
    vector<int> size;   // 记录每个连通分量的节点个数
    vector<int> len;    // 记录每个连通分量里的所有边长度
    int num;            // 记录节点个数

    Djset(int n) : parent(n), rank(n), len(n, 0), size(n, 1), num(n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        // 压缩方式：直接指向根节点
        if (x != parent[x])
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    //按秩合并，即将秩大的根节点设置为秩小的根节点的父节点(避免加深树的深度)
    int merge(int x, int y, int length)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty)
        {
            if (rank[rootx] < rank[rooty])
            {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;

            if (rank[rootx] == rank[rooty])
                rank[rootx] += 1;

            // rooty的父节点设置为rootx,同时将rooty的节点数和边长度累加到rootx,
            size[rootx] += size[rooty];
            len[rootx] += len[rooty] + length;
            // 如果某个连通分量的节点数 包含了所有节点，直接返回边长度
            if (size[rootx] == num)
                return len[rootx];
        }
        return -1;
    }
};

struct Edge
{
    int start; // 顶点1
    int end;   // 顶点2
    int len;   // 长度
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int res = 0;
        int n = points.size();
        Djset ds(n);
        vector<Edge> edges;

        // 建立点-边式数据结构
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                Edge edge = {i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])};
                edges.emplace_back(edge);
            }
        }
        // 按边长度排序
        sort(edges.begin(), edges.end(), [](const auto &a, const auto &b)
             { return a.len < b.len; });

        // 连通分量合并
        for (auto &e : edges)
        {
            res = ds.merge(e.start, e.end, e.len);
            if (res != -1)
                return res;
        }
        return 0;
    }
};

int main()
{
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

    Solution s;
    cout << s.minCostConnectPoints(points) << endl;

    return 0;
}

//
/*
class Solution
{
public:
    struct Edge
    {
        int s, e, w;
        Edge(int a, int b, int c) : s(a), e(b), w(c) {}
        bool operator<(const Edge &g) { return w < g.w; }
    };
    int find(int n)
    {
        if (fa[n] == n)
        {
            return n;
        }
        else
        {
            fa[n] = find(fa[n]);
        }
        return fa[n];
    }

    vector<int> fa;
    vector<Edge> edge;

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        for (int i = 0; i < points.size(); i++)
        {
            fa.push_back(i); //初始化根节点数组
            for (int j = i + 1; j < points.size(); j++)
            {
                edge.emplace_back(Edge(i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])));
            }
        }

        sort(edge.begin(), edge.end());
        int cnt = 0, res = 0;

        for (int i = 0; i < edge.size(); i++)
        {
            int a = edge[i].s, b = edge[i].e, c = edge[i].w;
            int na = find(a), nb = find(b);
            
            if (na != nb)
            {
                cnt++;
                res += c;
                fa[na] = nb;
            }
            if (cnt == points.size() - 1)
                break;
        }
        return res;
    }
};
*/