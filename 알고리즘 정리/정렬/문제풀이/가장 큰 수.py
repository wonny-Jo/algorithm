from functools import cmp_to_key

def compare(s1,s2):
    short_len=min(len(s1),len(s2))
    s1_temp=s1[:short_len]
    s2_temp=s2[:short_len]
    if s1_temp>s2_temp:
        return -1
    elif s1_temp<s2_temp:
        return 1

    s1_temp=s1
    s2_temp=s2
    while len(s1_temp)<4:
        s1_temp+=s1
    while len(s2_temp)<4:
        s2_temp+=s2
    if s1_temp > s2_temp:
        return -1
    elif s1_temp < s2_temp:
        return 1
    else:
        return 0

def solution(numbers):
    number=[]
    for num in numbers:
        number.append(str(num))
    number.sort(key=cmp_to_key(compare))
    answer = ''
    for num in number:
        answer+=num
    if answer[0]=='0':
        return '0'
    return answer

numbers=[6,10,2]
print(solution(numbers))