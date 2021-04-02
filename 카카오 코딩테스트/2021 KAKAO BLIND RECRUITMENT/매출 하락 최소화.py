arr=[[] for _ in range(300001)]
dp=[[0,0] for _ in range(300001)]
# 0이면 본인 체크
# 1이면 본인 자식들 중 가장 최소가 되는것을 찾음

def dfs(leader_num, sales):
    dp[leader_num][0]=sales[leader_num-1]

    if arr[leader_num]==[]:
        return
    
    min_cost=float('inf')
    for new_leader_num in arr[leader_num]:
        dfs(new_leader_num,sales)

        #본인 체크
        dp[leader_num][0]+=min(dp[new_leader_num][0],dp[new_leader_num][1])

        #본인 체크 x
        min_cost=min(min_cost,dp[new_leader_num][0]-dp[new_leader_num][1])

    if min_cost<0:
        dp[leader_num][1]=dp[leader_num][0]-sales[leader_num-1]
    else:
        dp[leader_num][1]=dp[leader_num][0]-sales[leader_num-1]+min_cost


def solution(sales, links):
    for link in links:
        arr[link[0]].append(link[1])

    dfs(1,sales)
    return min(dp[1][0],dp[1][1])


print(solution([14, 17, 15, 18, 19, 14, 13, 16, 28, 17],[[10, 8], [1, 9], [9, 7], [5, 4], [1, 5], [5, 10], [10, 6], [1, 3], [10, 2]]))
#print(solution([5, 6, 5, 3, 4],[[2,3], [1,4], [2,5], [1,2]]))
#print(solution([5, 6, 5, 1, 4],[[2,3], [1,4], [2,5], [1,2]]))
#print(solution([10, 10, 1, 1],[[3,2], [4,3], [1,4]]))