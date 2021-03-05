import sys
input=sys.stdin.readline
n=int(input())
data=list(map(int,input().split()))

result=[]

def lowerBound(start, end, key):
    while start < end:
        mid = (start + end) // 2
        if result[mid] == key:
            end = mid
        elif key < result[mid]:
            end = mid
        elif result[mid] < key:
            start = mid + 1
    return end


for i in range(n):
    if result ==[] or result[-1]<data[i]:
        result.append(data[i])
    else:
        idx=lowerBound(0,len(result),data[i])
        result[idx]=data[i]

print(len(result))


