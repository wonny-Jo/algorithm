n=int(input())
arr=list(map(int,input().split()))

arr.sort()
total=0
sum=0
for num in arr:
    sum+=num
    total+=sum

print(total)