def solution(n, results):
    answer = 0
    arr = [[0 for _ in range(101)] for _ in range(101)]
    for i in range(1,n+1):
        arr[i][i] = 1
    for r in results:
        arr[r[0]][r[1]] = 1
    for k in range(1,n+1):
        for i in range(1, n + 1):
            for j in range(1, n + 1):
                if arr[i][k] == 1 and arr[k][j] == 1:
                    arr[i][j] = 1

    for i in range(1,n+1):
        cnt=0
        for j in range(1,n+1):
            if arr[i][j]==1 or arr[j][i]==1:
               cnt+=1
        if cnt==n:
            answer+=1
    return answer


print(solution(5,[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))