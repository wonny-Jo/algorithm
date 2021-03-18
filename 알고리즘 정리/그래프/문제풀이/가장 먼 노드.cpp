#include<iostream>


#include <string>
#include <vector>
#include <queue>
using namespace std;

int maxNum = 0;
int dist_num[20001] = { 0 };
bool visited[20001] = { 0 };

void bfs(vector<int> vertex[20001])
{
    queue<pair<int,int>> q;
    q.push({ 1,0 });
    
    while(!q.empty())
    {
        int x = q.front().first;
        int dist = q.front().second;
        q.pop();
        dist_num[dist]++;
        
        for (int i = 0; i < vertex[x].size(); i++)
        {
            int y = vertex[x][i];
            if (y != 1 && !visited[y])
            {
                visited[y] = true;
                q.push({ y,dist + 1 });
            }
        }
        maxNum = dist;
    }
}


int solution(int n, vector<vector<int>> edge) {
    vector<int> vertex[20001];
    for (int i = 0; i < edge.size(); i++) {
        vertex[edge[i][0]].push_back(edge[i][1]);
        vertex[edge[i][1]].push_back(edge[i][0]);
    }

    bfs(vertex);
    return dist_num[maxNum];
}


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   
    cout << solution(6, { {3, 6},{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2} });
    return 0;
}