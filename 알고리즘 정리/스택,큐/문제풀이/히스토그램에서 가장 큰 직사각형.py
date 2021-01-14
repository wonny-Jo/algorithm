while 1:
    num=list(map(int,input().split())) #num list
    if num[0]==0:
        break
    num.append(0) #스택에 오름차순으로 남아있는것들중에 최대 넓이를 구하기위해 사용
    ans=0 #최대 넓이 저장
    s=[] #탐색하는 벡터의 현재위치보다 이전의 위치 중 현재 위치의 벡터의 값보다 큰 값들의 위치 저장
    for i in range(1,len(num)):
        #벡터를 순서대로 접근하면서 현재 위치 기준으로 이전의 위치들에서의 최대넓이를 구하는 방법으로 진행
        while len(s)!=0 and num[s[-1]]>=num[i]:
            x=s.pop()
            width=0
            if len(s)==0:
                width=i-1 #벡터를 1부터 시작해서 -1
            else:
                width=i-s[-1]-1
            ans=max(ans,num[x]*width)
        s.append(i)
    print(ans)