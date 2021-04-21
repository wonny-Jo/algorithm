from itertools import combinations

def solution(relation):
    key_len=len(relation[0])
    key_idx=[i for i in range(key_len)]
    candidate_key_list=[]
    for i in range(1,key_len+1):
        for idxs in list(map(list,combinations(key_idx,i))):
            already=False
            for candidate_key in candidate_key_list:
                cnt=0
                for i in candidate_key:
                    if i in idxs:
                        cnt+=1
                if cnt==len(candidate_key):
                    already=True
                    break
            if already==True:
                continue

            check_lists=[]
            for row in range(len(relation)):
                list_item=[]
                for idx in idxs:
                    list_item.append(relation[row][idx])
                if list_item in check_lists:
                    already=True
                    break
                check_lists.append(list_item)
            
            if already==True:
                continue
            candidate_key_list.append(idxs)
    return len(candidate_key_list)

print(solution([["100","ryan","music","2"],
                ["200","apeach","math","2"],
                ["300","tube","computer","3"],
                ["400","con","computer","4"],
                ["500","muzi","music","3"],
                ["600","apeach","music","2"]]))

print(solution([['a',1,'aaa','c','ng'],
                ['b',1,'bbb','c','g'],
                ['c',1,'aaa','d','ng'],
                ['d',2,'bbb','d','ng']]))