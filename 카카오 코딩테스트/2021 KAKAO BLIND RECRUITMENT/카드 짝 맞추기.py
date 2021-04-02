from itertools import permutations
from collections import deque
import copy


def isRange(y,x):
    if y<0 or y>=4 or x<0 or x>=4:
        return False
    return True

def bfs(board,i,j,num):
    moveDirection=[[-1,0],[1,0],[0,-1],[0,1]]
    visited=[[0 for _ in range(4)] for _ in range(4)]
    q=deque()
    visited[i][j]=1
    q.append([i,j,0])

    while q:
        y,x,cnt=q.popleft()
        if board[y][x]==num:
            board[y][x],i,j=0,y,x
            return cnt,i,j
        
        for d in range(4):
            ny=y+moveDirection[d][0]
            nx=x+moveDirection[d][1]
            if isRange(ny,nx) and visited[ny][nx]==0:
                visited[ny][nx]=1
                q.append([ny,nx,cnt+1])

            while isRange(ny,nx) and board[ny][nx]==0:
                ny+=moveDirection[d][0]
                nx+=moveDirection[d][1]
            if not isRange(ny,nx):
                ny-=moveDirection[d][0]
                nx-=moveDirection[d][1]
            visited[ny][nx]=1
            q.append([ny,nx,cnt+1])


def min_solution(board,num_list,r,c):
    time=0
    temp_board=copy.deepcopy(board)
    i=r
    j=c
    for num in num_list:
        if temp_board[i][j]==num:
            temp_board[i][j]=0
            dist,i,j=bfs(temp_board,i,j,num)
            time+=dist
        else:
            dist,i,j=bfs(temp_board,i,j,num)
            time+=dist
            dist,i,j=bfs(temp_board,i,j,num)
            time+=dist
        time+=2
    return time

def solution(board, r, c):
    card_num=[]
    for i in range(4):
        for j in range(4):
            if board[i][j]!=0 and board[i][j] not in card_num:
                card_num.append(board[i][j])
    
    answer = float('inf')
    for li in list(map(list,permutations(card_num,len(card_num)))):
        answer=min(answer,min_solution(board,li,r,c))
    return answer




print(solution([[1,0,0,3],
                [2,0,0,0],
                [0,0,0,2],
                [3,0,1,0]],1,0))
print(solution([[3,0,0,2],
                [0,0,1,0],
                [0,1,0,0],
                [2,0,0,3]],0,1))