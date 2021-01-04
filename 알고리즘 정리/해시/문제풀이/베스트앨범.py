import heapq

def solution(genres, plays):
    m=dict() #장르에 대한 인덱스 정보배열
    v=[] #장르에 대한 곡 정보를 담음
    sumOfGenres=[0]*101 #장르별 노래 재생수
    idx=0
    for i in range(len(genres)):
        if m.get(genres[i])==None: #장르에 인덱스 부여
            m[genres[i]]=idx
            idx+=1
            pq=[]
            v.append(pq)

        sumOfGenres[m[genres[i]]]+=plays[i] #장르별 총 재생수 업데이트

        # 장르마다 최대 2개씩 많이 재생된 곡 정보를 가짐
        if len(v[m[genres[i]]])<2:
            heapq.heappush(v[m[genres[i]]], [plays[i], i])
        elif len(v[m[genres[i]]])==2 and (plays[i]>v[m[genres[i]]][0][0]
            or (plays[i]==v[m[genres[i]]][0][0] and i<v[m[genres[i]]][0][1])):
            heapq.heappop(v[m[genres[i]]])
            heapq.heappush(v[m[genres[i]]],[plays[i],i])

    #장르를 재생수기준 내림차순 정렬
    pq=[]
    for i in range(idx):
        heapq.heappush(pq,[-sumOfGenres[i],i])

    # 장르별 최대 2개씩 answer에 추가
    answer = []
    while pq:
        num=pq[0][1]
        heapq.heappop(pq)


        if len(v[num])==1: # 곡이 하나인 경우
            n=v[num][0][1]
            heapq.heappop(v[num])
            answer.append(n)
        else: # 곡이 두개인 경우
            fir=v[num][0]
            heapq.heappop(v[num])
            sec=v[num][0]
            heapq.heappop(v[num])
            if fir[0]==sec[0]:
                answer.append(fir[1])
                answer.append(sec[1])
            else:
                answer.append(sec[1])
                answer.append(fir[1])
    return answer


genres=["classic", "pop", "classic", "classic", "pop"]
plays=[500, 600, 150, 800, 2500]
print(solution(genres,plays))
