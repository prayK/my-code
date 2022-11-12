#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int res = 0;
        int size = points.size();

        vector<int> visit(size, 0);                       //标记该点是否访问过
        vector<int> lowest(size, INT_MAX);                //记录当前集合A与集合B之间的最小距离值
        vector<vector<int>> dis(size, vector<int>(size)); //存储各点之间的距离

        for (unsigned int i = 0; i < size; ++i)
        {
            for (unsigned int j = i + 1; j < size; ++j)
            {
                dis[j][i] = dis[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            }
        }
        visit[0] = 1; //标记0号位置已经访问过

        for (unsigned int i = 0; i < size; ++i)
        {
            lowest[i] = dis[0][i]; //从第0个点开始，从第一个点开始用1即可
        }
        for (unsigned int i = 1; i < size; ++i)
        {
            int minIndex = -1;
            int minValue = INT_MAX;

            for (unsigned int j = 0; j < size; ++j)
            {
                if ((visit[j] == 0) && (lowest[j] < minValue))
                {
                    minIndex = j;
                    minValue = lowest[j];
                }
            }
            visit[minIndex] = 1; //标记已经访问过
            //lowest[minIndex] = -1;
            res += minValue;

            for (unsigned int j = 0; j < size; ++j)
            {
                if ((visit[j] != 1) && (dis[minIndex][j] < lowest[j]))
                {
                    lowest[j] = dis[minIndex][j];
                }
            }
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    cout << minCostConnectPoints(points) << endl;
    return 0;
}