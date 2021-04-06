def solution(key, lock):
    lock_arr=[[-1 for _ in range(61)] for _ in range(61)]
    lock_cnt=0
    for i in range(len(lock)):
        for j in range(len(lock)):
            lock_arr[20+i][20+j]=lock[i][j]
            if lock[i][j]==0:
                lock_cnt+=1

    for _ in range(4):
        for i in range(40):
            for j in range(40):
                cnt=0
                for r in range(len(key)):
                    for c in range(len(key)):
                        if key[r][c]==1:
                            if lock_arr[i+r][j+c]==0:
                                cnt+=1
                            elif lock_arr[i+r][j+c]==1:
                                cnt-=1
                
                if lock_cnt==cnt:
                    return True

        key_temp=[[0 for _ in range(len(key))] for _ in range(len(key))]
        for r in range(len(key)):
            for c in range(len(key)):
                key_temp[c][len(key)-1-r]=key[r][c]
        key=key_temp
        
    return False


print(solution([[0, 0, 0], 
                [1, 0, 0], 
                [0, 1, 1]],
               [[1, 1, 1],
                [1, 1, 0],
                [1, 0, 1]]))