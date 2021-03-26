def solution(new_id):
    #step1. 대문자를 소문자로 
    answer=new_id.lower()
    #step2. 허용되지 않는 문자 제거
    i=0
    while i<len(answer):
        c=answer[i]
        #if ('a'<=c<='z') or ('0'<=c<='9') or c=='-' or c=='_' or c=='.':
        if c.isalnum() or c in '-_.':
            i+=1
            continue
        answer=answer.replace(c,'')

    #step3. ..를 .로 바꾸기
    while '..' in answer:
        answer=answer.replace('..','.')
    
    #step4. 맨앞과 뒤가 .이면 제거
    if answer!='' and answer[0]=='.':
        answer=answer[1:]
    if answer!='' and answer[-1]=='.':
        answer=answer[:-1]
    
    #step5. 빈 문자열일 경우 a추가
    if answer=='':
        answer+='a'
    
    #step6. 길이가 16자 이상이면 앞의 15자만 남김
    if len(answer)>=16:
        answer=answer[:15]
        if answer[-1]=='.':
            answer=answer[:-1]
    
    #step7. 길이가 2자 이하이면 마지막 문자를 길이가 3이 될때까지 반복해서 끝에 붙임
    while len(answer)<3:
        answer+=answer[-1]
    return answer


print(solution("...!@BaT#*..y.abcdefghijklm"))
print(solution("z-+.^."))
print(solution("=.="))
print(solution("123_.def"))
print(solution("abcdefghijklmn.p"))