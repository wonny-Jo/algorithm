def solution(n, s, a, b, fares):
    fares_arr=[[float('inf') for _ in range(201)] for _ in range(201)]
    for start,end,weight in fares:
        fares_arr[start][end]=weight
        fares_arr[end][start]=weight
    for i in range(1,n+1):
        fares_arr[i][i]=0

    for k in range(1,n+1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                fares_arr[i][j]=min(fares_arr[i][j],fares_arr[i][k]+fares_arr[k][j])

    answer=float('inf')
    for i in range(1,n+1):
        answer=min(answer,fares_arr[s][i]+fares_arr[i][a]+fares_arr[i][b])

    return answer



print(solution(6,4,6,2,[[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]))
print(solution(7,3,4,1,[[5, 7, 9], [4, 6, 4], [3, 6, 1], [3, 2, 3], [2, 1, 6]]))
print(solution(6,4,5,6,[[2,6,6], [6,3,7], [4,6,7], [6,5,11], [2,5,12], [5,3,20], [2,4,8], [4,3,9]]))