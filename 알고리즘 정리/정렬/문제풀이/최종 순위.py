import sys
T=int(sys.stdin.readline())

for a in range(T):
    adj=[[0 for _ in range(501)] for _ in range(501)] #adj[a][b] # b보다 a가 순위가 높음
    indegree=[0 for _ in range(501) ]#indegree: 나보다 앞에 몇명 있는지
    N=int(sys.stdin.readline())
    rank=list(map(int,sys.stdin.readline().split())) #rank: 순위(index)에 따른 넘버
    for i in range(N):
        for j in range(i+1,N):
            adj[rank[i]][rank[j]]=1
            indegree[rank[j]]+=1

    M=int(input())
    for i in range(M):
        num = list(map(int, sys.stdin.readline().split()))
        # 순위 바꾸기
        if adj[num[0]][num[1]]==1:
            adj[num[0]][num[1]]=0
            adj[num[1]][num[0]]=1
            indegree[num[0]]+=1
            indegree[num[1]]-=1
        else:
            adj[num[1]][num[0]] = 0
            adj[num[0]][num[1]] = 1
            indegree[num[1]] += 1
            indegree[num[0]] -= 1

    #위상정렬, indegree가 0부터 순서대로 정렬
    now=0
    for i in range(1,N+1):
        if indegree[i]==0:
            now=i

    result=[]
    for i in range(N):
        if now==0:
            break
        result.append(now)
        start=now
        now=0
        for j in range(1,N+1):
            if adj[start][j]==1:
                indegree[j]-=1
                if indegree[j]==0:
                    now=j

    # 모두 위상정렬이 될때만 출력 아니면 불가능. 
    # 처음에 작년의 순위를 알려주기때문에 ?인경우는 없다.
    if len(result)==N:
        print(*result)
    else:
        print("IMPOSSIBLE")
