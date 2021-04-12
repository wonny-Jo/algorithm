from collections import deque

def isRange(x1,y1,x2,y2,n):
    if x1<0 or x1>=n or y1<0 or y1>=n or x2<0 or x2>=n or y2<0 or y2>=n:
        return False
    return True

def solution(board):
    moveDir=[[-1,0],[1,0],[0,-1],[0,1]]
    n=len(board)
    q=deque()
    q.append([[0,0],[1,0],0,0]) #좌표 2개, mainAxis, count
    visited=[[[0,0] for _ in range(n)] for _ in range(n)]
    visited[0][0][0]=1
    while q:
        [x1,y1],[x2,y2],mainAxis,cnt=q.popleft()
        if x2==n-1 and y2==n-1:
            return cnt
        
        # 단순 이동
        for i in range(4):
            nx1=x1+moveDir[i][0]
            ny1=y1+moveDir[i][1]
            nx2=x2+moveDir[i][0]
            ny2=y2+moveDir[i][1]
            if isRange(nx1,ny1,nx2,ny2,n) and board[ny1][nx1]==0 and board[ny2][nx2]==0 and visited[ny1][nx1][mainAxis]==0:
                q.append([[nx1,ny1],[nx2,ny2],mainAxis,cnt+1])
                visited[ny1][nx1][mainAxis]=1
        
        # 90도 회전
        crossAxis=(mainAxis+1)%2
        if mainAxis==0: #0이면 가로, 1이면 세로
            nx1,nx2=x1,x2
            ny1,ny2=y1-1,y2-1
            if isRange(nx1,ny1,nx2,ny2,n) and board[ny1][nx1]==0 and board[ny2][nx2]==0 and visited[ny1][nx1][crossAxis]==0:
                q.append([[nx1,ny1],[x1,y1],crossAxis,cnt+1])
                visited[ny1][nx1][crossAxis]=1
            if isRange(nx1,ny1,nx2,ny2,n) and board[ny1][nx1]==0 and board[ny2][nx2]==0 and visited[ny2][nx2][crossAxis]==0:  
                q.append([[nx2,ny2],[x2,y2],crossAxis,cnt+1])
                visited[ny2][nx2][crossAxis]=1
            nx1,nx2=x1,x2
            ny1,ny2=y1+1,y2+1
            if isRange(nx1,ny1,nx2,ny2,n) and board[ny1][nx1]==0 and board[ny2][nx2]==0 and visited[y1][x1][crossAxis]==0:
                q.append([[x1,y1],[x1,y1+1],crossAxis,cnt+1])
                visited[y1][x1][crossAxis]=1
            if isRange(nx1,ny1,nx2,ny2,n) and board[ny1][nx1]==0 and board[ny2][nx2]==0 and visited[y2][x2][crossAxis]==0:
                q.append([[x2,y2],[x2,y2+1],crossAxis,cnt+1])
                visited[y2][x2][crossAxis]=1
        
        else:
            nx1,nx2=x1-1,x2-1
            ny1,ny2=y1,y2
            if isRange(nx1,ny1,nx2,ny2,n) and board[ny1][nx1]==0 and board[ny2][nx2]==0 and visited[y1][x1-1][crossAxis]==0:
                q.append([[x1-1,y1],[x1,y1],crossAxis,cnt+1])
                visited[y1][x1-1][crossAxis]=1
            if isRange(nx1,ny1,nx2,ny2,n) and board[ny1][nx1]==0 and board[ny2][nx2]==0 and visited[y2][x2-1][crossAxis]==0:
                q.append([[x2-1,y2],[x2,y2],crossAxis,cnt+1])
                visited[y2][x2-1][crossAxis]=1
            nx1,nx2=x1+1,x2+1
            ny1,ny2=y1,y2
            if isRange(nx1,ny1,nx2,ny2,n) and board[ny1][nx1]==0 and board[ny2][nx2]==0 and visited[y1][x1][crossAxis]==0:
                q.append([[x1,y1],[x1+1,y1],crossAxis,cnt+1])
                visited[y1][x1][crossAxis]=1
            if isRange(nx1,ny1,nx2,ny2,n) and board[ny1][nx1]==0 and board[ny2][nx2]==0 and visited[y2][x2][crossAxis]==0:
                q.append([[x2,y2],[x2+1,y2],crossAxis,cnt+1])
                visited[y2][x2][crossAxis]=1



print(solution([[0, 0, 0, 1, 1],
                [0, 0, 0, 1, 0],
                [0, 1, 0, 1, 1],
                [1, 1, 0, 0, 1],
                [0, 0, 0, 0, 0]]))

print(solution([[0, 0, 0, 0, 0, 0, 1], 
                [1, 1, 1, 1, 0, 0, 1], 
                [0, 0, 0, 0, 0, 0, 0], 
                [0, 0, 1, 1, 1, 1, 0], 
                [0, 1, 1, 1, 1, 1, 0], 
                [0, 0, 0, 0, 0, 1, 1], 
                [0, 0, 1, 0, 0, 0, 0]]))