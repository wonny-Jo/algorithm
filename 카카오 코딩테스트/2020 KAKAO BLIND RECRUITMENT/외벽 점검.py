from itertools import permutations

def solution(n, weak, dist):
    numOfWeak=len(weak)
    for i in range(numOfWeak):
        weak.append(weak[i]+n)
    for i in range(1,len(dist)+1):
        subDist=dist[-i:]
        start=0
        while start<numOfWeak:
            for subDistTemp in list(map(list,permutations(subDist,i))):
                startPos=start
                endNum=weak[start]
                cnt=0
                for distNum in subDistTemp:
                    endNum+=distNum
                    while weak[startPos]<=endNum:
                        cnt+=1
                        startPos+=1
                        if cnt==numOfWeak:
                            return i
                    endNum=weak[startPos]
            start+=1

    return -1

print(solution(12,[1, 5, 6, 10],[1, 2, 3, 4]))
print(solution(12,[1, 3, 4, 9, 10],[3, 5, 7]))