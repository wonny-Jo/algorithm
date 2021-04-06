def solution(p):
    #step1. 빈문자열이면 빈문자열을 반환
    if p=='':
        return ''

    #step2. 균형잡힌 문자열 u,v로 분리
    cnt=0
    if p[0]=='(':
        cnt+=1
    else:
        cnt-=1
    i=1
    while cnt!=0:
        if p[i]=='(':
            cnt+=1
        else:
            cnt-=1
        i+=1
    
    u=p[:i]
    v=p[i:]

    #step3. u가 올바른 문자열이면 v를 처음부터 다시 시작
    if u[0]=='(':
        u+=solution(v)
    #step4. u가 올바른 문자열이 아니면 수행
    else:
        v='('+solution(v)+')'
        u=u[1:-1]
        nu=''
        for i in range(len(u)):
            if u[i]=='(':
                nu+=')'
            else:
                nu+='('  
        u=v+nu
    return u

print(solution("(()())()"))
print(solution(")("))
print(solution("()))((()"))