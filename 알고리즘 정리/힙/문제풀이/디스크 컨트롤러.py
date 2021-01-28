##################################################################
import heapq
from math import floor
def solution(jobs):
    jobs.sort() #시작 시간 기준 오름차순 정렬
    answer = 0
    start = 0 #작업 진행시작시간
    minHeap=[]
    for job in jobs:
        # 다음 작업중 가장 빠른 시작 시간보다 start가 작으면 이전 작업들중 작업 시간이 가장 적게 걸리는 것 우선으로 작업 진행
        while minHeap and job[0]>start:
            temp = heapq.heappop(minHeap)
            answer += start - temp[1] + temp[0]
            start += temp[0]
        # 다음 작업 시작 시간이 start보다 큰 경우는 start를 해당 작업 시작 시간으로 설정
        if not minHeap and job[0]>start:
            start = job[0]
        heapq.heappush(minHeap,[job[1],job[0]])

    #남은 작업중 시간이 가장 적게걸리는 순으로 작업 진행
    while minHeap:
        temp = heapq.heappop(minHeap)
        answer += start - temp[1] + temp[0]
        start += temp[0]
    return floor(answer/len(jobs))
##################################################################

jobs=[[0, 3], [1, 9], [2, 6]]
print(solution(jobs))

