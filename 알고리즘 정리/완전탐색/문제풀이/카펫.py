from math import sqrt
from math import floor
def solution(brown, yellow):
    answer = []
    total=brown+yellow
    for i in range(1,floor(sqrt(yellow))+1):
        if yellow%i==0:
            w=i+2
            h=(yellow//i)+2
            if w*h==total:
                answer.append(h)
                answer.append(w)
                break
    return answer

##########################################

print(solution(10,2))