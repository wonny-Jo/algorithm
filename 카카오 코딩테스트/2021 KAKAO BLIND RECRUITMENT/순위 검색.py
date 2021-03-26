from bisect import bisect_left

def solution(info, query):
    score_table={}
    for info_str in info:
        item_list=info_str.split(' ')
        for i in range(16):
            item=''
            for n in range(4):
                if i&(1<<n):
                    item+='-'
                else:
                    item+=item_list[n]
            if item not in score_table.keys():
                score_table[item]=[]
            score_table[item].append(int(item_list[4]))

    for key in score_table.keys():
        score_table[key].sort()

    answer = []
    for query_str in query:
        item_list=query_str.split(' ')
        item=item_list[0]+item_list[2]+item_list[4]+item_list[6]
        if item in score_table.keys():
            score_list=score_table[item]
            count=len(score_list)-bisect_left(score_list,int(item_list[7]))
            answer.append(count)
        else:
            answer.append(0)
    return answer


print(solution(
    ["java backend junior pizza 150",
    "python frontend senior chicken 210",
    "python frontend senior chicken 150",
    "cpp backend senior pizza 260",
    "java backend junior chicken 80",
    "python backend senior chicken 50"],
    ["java and backend and junior and pizza 100",
    "python and frontend and senior and chicken 200",
    "cpp and - and senior and pizza 250",
    "- and backend and senior and - 150",
    "- and - and - and chicken 100",
    "- and - and - and - 150"])
    )