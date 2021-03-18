from collections import deque

v=[[] for _ in range(0,20001)]
visited=[0 for _ in range(0,20001)]
dist_num=[0 for _ in range(0,20001)]

def bfs(i):
    q=deque()
    q.append([i,0])
    visited[i]=1
    dist_num[0]+=1
    maxNum=0
    while q:
        x,dist=q.popleft()
        dist_num[dist]+=1

        for y in v[x]:
            if visited[y]==0:
                visited[y]=1
                q.append([y,dist+1])
        maxNum=dist
    return maxNum


def solution(n, edge):
    for e in edge:
        v[e[0]].append(e[1])
        v[e[1]].append(e[0])
    
    maxNum=bfs(1)
    return dist_num[maxNum]

print(solution(6,[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))