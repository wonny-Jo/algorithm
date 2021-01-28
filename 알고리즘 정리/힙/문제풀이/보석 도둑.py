import sys
import heapq
N, K = map(int, sys.stdin.readline().split())
v=[]
C=[]
for i in range(N):
    v.append(list(map(int,sys.stdin.readline().split())))
for i in range(K):
    C.append(int(sys.stdin.readline()))

# 오름차순 정렬
v.sort()
C.sort()

result=0
j=0
maxHeap=[]
for i in range(K):
    # 가방 무게보다 작은 보석들은 maxHeap에 다 넣어줌
    while j<N and v[j][0]<=C[i]:
        heapq.heappush(maxHeap,-v[j][1])
        j+=1
    # maxHeap중 가장 가격이 높은 하나만 빼서 더해줌
    if maxHeap:
        result+=-heapq.heappop(maxHeap)
print(result)