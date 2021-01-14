####################################################################
from math import ceil

def solution(progresses, speeds):
    answer = []
    while progresses:
        d=ceil((100-progresses[0])/speeds[0]) #처음 위치가 배포되는데 걸리는 날의 수
        cnt=1 # 한번 배포에 몇개가 배포되는지 count
        progresses.pop(0)
        speeds.pop(0)
        while len(progresses)!=0 and progresses[0]+d*speeds[0]>=100:
            cnt+=1
            progresses.pop(0)
            speeds.pop(0)
        answer.append(cnt)
    return answer

########################################################################

progresses=[93,30,55]
speeds=[1,30,5]
print(solution(progresses,speeds))