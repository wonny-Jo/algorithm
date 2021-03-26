from bisect import bisect_left

def solution(info, query):
    table=[[[[[] for _ in range(4)] for _ in range(4)] for _ in range(4)] for _ in range(4)]
    idx_table={}
    idx_table['cpp']=0
    idx_table['java']=1
    idx_table['python']=2
    idx_table['backend']=0
    idx_table['frontend']=1
    idx_table['junior']=0
    idx_table['senior']=1
    idx_table['chicken']=0
    idx_table['pizza']=1
    idx_table['-']=3

    for info_str in info:
        item_list=info_str.split(' ')
        for i in range(16):
            item_temp=item_list.copy()
            for n in range(4):
                if i&(1<<n):
                    item_temp[n]='-'
            table[idx_table[item_temp[0]]][idx_table[item_temp[1]]][idx_table[item_temp[2]]][idx_table[item_temp[3]]].append(int(item_temp[4]))

    answer = []
    for query_str in query:
        query_str=query_str.replace(' and','')
        item_list=query_str.split(' ')
        point_list=table[idx_table[item_list[0]]][idx_table[item_list[1]]][idx_table[item_list[2]]][idx_table[item_list[3]]]
        # count=0
        # for point in point_list:
        #     if point>=int(item_list[4]):
        #         count+=1
        point_list.sort()
        count=len(point_list)-bisect_left(point_list,int(item_list[4]))
        answer.append(count)
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