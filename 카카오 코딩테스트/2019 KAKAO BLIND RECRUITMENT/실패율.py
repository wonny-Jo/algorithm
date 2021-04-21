def solution(N,stages):
    stage_pass_num=[0 for _ in range(N+2)]
    stage_stay_num=[0 for _ in range(N+2)]
    for stage in stages:
        for i in range(1,stage+1):
            stage_pass_num[i]+=1
        stage_stay_num[stage]+=1
    failure_rate=[]
    for i in range(1,N+1):
        if stage_pass_num[i]==0:
            failure_rate.append([i,0])
        else:
            failure_rate.append([i,stage_stay_num[i]/stage_pass_num[i]])
    failure_rate.sort(reverse=True, key= lambda x : x[1])
    answer=[]
    for i,_ in failure_rate:
        answer.append(i)
    return answer

print(solution(5,[2, 1, 2, 6, 2, 4, 3, 3]))
print(solution(4,[4,4,4,4,4]))
