def isConnected(answer):
    for x,y,a in answer:
        if a==0:
            if y==0 or (x-1,y,1) in answer or (x,y,1) in answer or (x,y-1,0) in answer:
                continue
            else:
                return False
        else:
            if (x,y-1,0) in answer or (x+1,y-1,0) in answer or ((x-1,y,1) in answer and (x+1,y,1) in answer):
                continue
            else:
                return False
        return True


def solution(n, build_frame):
    answer=set()
    for x,y,a,b in build_frame:
        if b==1:
            answer.add((x,y,a))
            if isConnected(answer)==False:
                answer.remove((x,y,a))
        elif b==0 and (x,y,a) in answer:
            answer.remove((x,y,a))
            if isConnected(answer)==False:
                answer.add((x,y,a))
    answer=sorted(list(list(i) for i in answer))
    return answer


print(solution(5,[[1,0,0,1],
                  [1,1,1,1],
                  [2,1,0,1],
                  [2,2,1,1],
                  [5,0,0,1],
                  [5,1,0,1],
                  [4,2,1,1],
                  [3,2,1,1]]))
print(solution(5,[[0,0,0,1],
                  [2,0,0,1],
                  [4,0,0,1],
                  [0,1,1,1],
                  [1,1,1,1],
                  [2,1,1,1],
                  [3,1,1,1],
                  [2,0,0,0],
                  [1,1,1,0],
                  [2,2,0,1]]))