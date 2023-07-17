#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> ans = grid;
        int ansTime = 0;

        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 2)
                {
                    pair<int, int> coordinate = {row, col};
                    q.push({coordinate, 0});
                }
            }
        }

        while (!q.empty())
        {

            auto fnode = q.front();
            q.pop();

            int x = fnode.first.first;
            int y = fnode.first.second;
            int time = fnode.second;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 and newX < ans.size() and newY >= 0 and newY < ans[0].size() and ans[newX][newY] == 1)
                {
                    pair<int, int> newCoordinate = {newX, newY};
                    ansTime = max(ansTime, time + 1);
                    q.push({newCoordinate, time + 1});

                    ans[newX][newY] = 2;
                }
            }
        }

        for (int row = 0; row < ans.size(); row++)
        {
            for (int col = 0; col < ans[0].size(); col++)
            {
                if (ans[row][col] == 1)
                {
                    return -1;
                }
            }
        }

        return ansTime;
    }
};