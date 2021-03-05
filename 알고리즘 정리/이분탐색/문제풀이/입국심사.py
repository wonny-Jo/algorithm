def solution(n, times):
    answer = 0
    minT=1
    maxT=max(times)*n

    while minT<=maxT:
        avgT=(minT+maxT)//2
        numsOfPeople=0
        for t in times:
            numsOfPeople+=avgT//t;
        if n<=numsOfPeople:
            answer=avgT
            maxT=avgT-1
        else:
            minT=avgT+1
    return answer


print(solution(6,[7,10]))