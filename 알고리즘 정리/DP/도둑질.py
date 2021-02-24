import sys
input=sys.stdin.readline

##################################
dp=[[0,0] for _ in range(1000001)]
def solution(money):
    dp[0][0]=money[0]
    dp[1][0]=money[0]
    dp[1][1]=money[1]
    size=len(money)
    for i in range(2,size-1):
        dp[i][0]=max(dp[i-2][0]+money[i],dp[i-1][0])
        dp[i][1]=max(dp[i-2][1]+money[i],dp[i-1][1])
    dp[size-1][1]=max(dp[size-3][1]+money[size-1],dp[size-2][1])
    return max(dp[size-1][1],dp[size-2][0])

###################################
print(solution([1,2,3,1]))

