from itertools import combinations

def solution(orders, course):
    course_table=[{} for _ in range(11)]
    course_count_max=[0 for _ in range(11)]

    for order in orders:
        order=sorted(order)
        start=course[0]
        end=min(len(order),course[-1])
        for i in range(start,end+1):
            for comb in list(map(''.join,combinations(order,i))):
                if comb not in course_table[i].keys():
                    course_table[i][comb]=1
                else:
                    course_table[i][comb]+=1
                course_count_max[i]=max(course_count_max[i],course_table[i][comb])

    answer = []
    for i in course:
        if course_count_max[i]>1:
            for key in course_table[i].keys():
                if course_table[i][key]==course_count_max[i]:
                    answer.append(key)
    answer.sort()
    return answer




print(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"],[2,3,4]))
print(solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"],[2,3,5]))
print(solution(["XYZ", "XWY", "WXA"],[2,3,4]))