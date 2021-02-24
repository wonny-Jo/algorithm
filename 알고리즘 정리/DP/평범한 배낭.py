import sys
input=sys.stdin.readline

N,K=list(map(int,input().split()))
dp=[0 for _ in range(100001)]
W=[0]
V=[0]

for i in range(1, N+1):
    w,v=list(map(int,input().split()))
    W.append(w)
    V.append(v)

for i in range(1,N+1):
    for j in range(K,0,-1):
        if W[i]<=j:
            dp[j]=max(dp[j],dp[j-W[i]]+V[i])

print(dp[K])

