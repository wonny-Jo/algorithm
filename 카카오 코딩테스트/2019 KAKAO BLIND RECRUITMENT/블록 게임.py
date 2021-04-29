blocks = [
    [[[0, 0], [1, 0], [1, 1], [1, 2]],      #   @XX
     [[0, 1], [0, 2]],],                    #   @@@
                                                       
    [[[0, 0], [1, 0], [2, 0], [2, -1]],     #   X@
     [[0, -1], [1, -1]]],                   #   X@
                                            #   @@

    [[[0, 0], [1, 0], [2, 0], [2, 1]],      #   @X
     [[0, 1], [1, 1]]],                     #   @X
                                            #   @@
                                                
    [[[0, 0], [1, 0], [1, -1], [1, -2]],    #  XX@
     [[0, -1], [0, -2]]],                   #  @@@
                                                
    [[[0, 0], [1, 0], [1, -1], [1, 1]],     #  X@X
     [[0, -1], [0, 1]]],                    #  @@@
]

# 영역 범위를 넘어가는지 확인하는 함수
def isRange(y,x,n):
    if y<0 or y>=n or x<0 or x>=n:
        return False
    return True

# 지정된 5개의 블록중에 같은것이 있는지 확인하는 함수
# 있다면 해당 block의 idx 반환, 없다면 -1 반환
def isPossibleBlock(y,x,N,board):
    for idx in range(len(blocks)):
        block=blocks[idx][0]
        for dy,dx in block:
            if not isRange(y+dy,x+dx,N) or board[y][x]!=board[y+dy][x+dx]:
                break
        else:
            return idx
    return -1

# 검은 볼을 넣을 수 있는지 확인하는 함수
def checkBlankOfBoard(y,x,blockNum,board,blocking_blocks):
    for dy,dx in blocks[blockNum][1]:
        if board[y+dy][x+dx]!=0 or blocking_blocks[x+dx]!=[]:
            return False
    return True

def removeBlock(y,x,blockNum,board,blocking_blocks):
    block=blocks[blockNum][0]
    for dy,dx in block:
        if board[y+dy][x+dx] in blocking_blocks[x+dx]:
            blocking_blocks[x+dx].remove(board[y+dy][x+dx])
        board[y+dy][x+dx]=0


def blockUpdate(y,x,blockNum,blocking_blocks,board,candidate_blocks):
    removeBlock(y,x,blockNum, board, blocking_blocks)
    answer=1

    idx=0
    while idx<len(candidate_blocks):
        y,x,blockNum=candidate_blocks[idx]
        if checkBlankOfBoard(y, x, blockNum, board, blocking_blocks):
            removeBlock(y,x,blockNum, board, blocking_blocks)
            answer+=1
            candidate_blocks.remove([y,x,blockNum])
            idx=0
            continue
        idx+=1
    return answer

def solution(board):
    answer = 0
    N=len(board)
    blocking_blocks=[[] for _ in range(N)] # x축 기준으로 접근하는 위치 위로 검은 블록이 오는것을 막는 다른 블록을 담고있는 리스트
    candidate_blocks=[] # 직사각형의 가능성은 있으나 현재로는 불가능한 블록들을 담는 리스트

    # board를 left-top부터 순차적으로 탐색
    for y in range(N):
        for x in range(N):
            if board[y][x]==0:
                continue

            # 5개의 블록 중 해당 블록과 같은 모양이 되는것이 있는지 확인
            blockNum=isPossibleBlock(y, x, N, board)
            if blockNum!=-1:
                # 직사각형을 위해 검은 볼을 채울 수 있는지 확인
                if checkBlankOfBoard(y, x, blockNum, board, blocking_blocks):
                    answer+=blockUpdate(y,x,blockNum, blocking_blocks, board, candidate_blocks)
                else: #검은 볼을 채울 수 없는 경우에 후보 블록 구성 및 blocking 구성
                    candidate_blocks.append([y,x,blockNum])
                    if board[y][x] not in blocking_blocks[x]:
                        blocking_blocks[x].append(board[y][x])
            else: #블록 모양이 없으면 blocking에 추가
                if board[y][x] not in blocking_blocks[x]:
                    blocking_blocks[x].append(board[y][x])
    return answer


print(solution([[0,0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,4,0,0,0],
                [0,0,0,0,0,4,4,0,0,0],
                [0,0,0,0,3,0,4,0,0,0],
                [0,0,0,2,3,0,0,0,5,5],
                [1,2,2,2,3,3,0,0,0,5],
                [1,1,1,0,0,0,0,0,0,5]]))#2

print(solution([[0, 2, 0, 0], 
                [1, 2, 0, 4], 
                [1, 2, 2, 4], 
                [1, 1, 4, 4]]))#3

print(solution([[0, 0, 1, 1, 1], 
                [0, 0, 0, 1, 0], 
                [3, 0, 0, 2, 0], 
                [3, 2, 2, 2, 0], 
                [3, 3, 0, 0, 0]]))#0

print(solution([[0, 0, 0, 0, 0], 
                [1, 0, 0, 2, 0], 
                [1, 2, 2, 2, 0], 
                [1, 1, 0, 0, 0], 
                [0, 0, 0, 0, 0]]))#2

print(solution([[0,0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0,0],
                [0,0,0,2,2,0,0,0,0,0],
                [0,0,0,2,1,0,0,0,0,0],
                [0,0,0,2,1,0,0,0,0,0],
                [0,0,0,0,1,1,0,0,0,0],
                [0,0,0,0,0,0,0,0,0,0],
                [0,0,0,0,0,0,0,0,0,0]]))#1

print(solution([[0, 0, 0, 0],
                [1, 2, 0, 0], 
                [1, 2, 2, 2], 
                [1, 1, 0, 0]]))#2

print(solution([[0, 0, 0, 0],
                [0, 2, 0, 1], 
                [2, 2, 2, 1], 
                [0, 0, 1, 1]]))#2