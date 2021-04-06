from bisect import bisect_left,bisect_right

def solution(words, queries):
    word_list=[[] for _ in range(10001)]
    reversed_word_list=[[] for _ in range(10001)]
    for word in words:
        word_length=len(word)
        word_list[word_length].append(word)
        reversed_word=word[::-1]
        reversed_word_list[word_length].append(reversed_word)
    
    for w_l in word_list:
        w_l.sort()
    for r_w_l in reversed_word_list:
        r_w_l.sort()
    
    answer=[]
    for query in queries:
        query_length=len(query)
        if query[0]=='?':
            reversed_query=query[::-1]
            answer.append(bisect_right(reversed_word_list[query_length],reversed_query.replace('?','z'))
            -bisect_left(reversed_word_list[query_length],reversed_query.replace('?','a')))
        else:
            answer.append(bisect_right(word_list[query_length],query.replace('?','z'))
            -bisect_left(word_list[query_length],query.replace('?','a')))

    return answer


print(solution(["frodo", "front", "frost", "frozen", "frame", "kakao"],
                ["fro??", "????o", "fr???", "fro???", "pro?"]))