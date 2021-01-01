################################################
from collections import deque
def solution(n, computers):
    answer = 0
    visited = [0 for _ in range(201)]
    q = deque()
    for i in range(n):
        if visited[i] == 0:
            answer += 1
            visited[i] = 1
            q.appendleft(i)
            while q:
                x = q.pop()
                for i in range(n):
                    if i != x and computers[x][i] == 1 and visited[i] == 0:
                        q.appendleft(i)
                        visited[i] = 1

    return answer

################################################

n=3
computers=[[1, 1, 0], [1, 1, 0], [0, 0, 1]]
print(solution(n,computers))