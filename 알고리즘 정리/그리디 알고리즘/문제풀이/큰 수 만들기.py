def solution(number, k):
    answer = ''
    idx=0
    n=len(number)-k
    while n>0:
        max_num='0'
        for i in range(idx,len(number)-n+1):
            if max_num<number[i]:
                max_num=number[i]
                idx=i
            if number[i]=='9':
                break
        idx+=1
        answer+=max_num
        n-=1
    return answer