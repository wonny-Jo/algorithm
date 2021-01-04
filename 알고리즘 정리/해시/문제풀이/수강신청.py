import sys
K, L = map(int, sys.stdin.readline().split())
map1 = dict()
map2 = dict()
for i in range(L):
    s = sys.stdin.readline().strip()
    map1[s] = i
    map2[i] = s

cnt = 0
for i in range(L):
    if i==map1[map2[i]]:
        cnt+=1
        print(map2[i])
    if cnt==K:
        break
