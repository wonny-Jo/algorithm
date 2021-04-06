def solution(words, queries):
    word_cnt=dict()
    for word in words:
        if word in word_cnt.keys():
            word_cnt[word]+=1
        else:
            word_cnt[word]=1
        for i in range(1,len(word)):
            front_word='?'*i+word[i:]
            if front_word in word_cnt.keys():
                word_cnt[front_word]+=1
            else:
                word_cnt[front_word]=1
            back_word=word[:-i]+'?'*i
            if back_word in word_cnt.keys():
                word_cnt[back_word]+=1
            else:
                word_cnt[back_word]=1

    answer = []
    for query in queries:
        if query in word_cnt.keys():
            answer.append(word_cnt[query])
        else:
            answer.append(0)
    return answer


print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"],
                ["fro??", "????o", "fr???", "fro???", "pro?"]))