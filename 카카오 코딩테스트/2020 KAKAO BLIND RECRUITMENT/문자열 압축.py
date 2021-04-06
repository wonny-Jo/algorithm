def solution(s):
    s_len = len(s)
    answer = s_len
    end = (s_len // 2) + 1
    for comp_len in range(1, end):
        string = ""
        num = 1
        comp_str = s[0:comp_len]
        for j in range(comp_len, s_len+comp_len, comp_len):
            compare_str = s[j:j+comp_len]
            if len(comp_str) != len(compare_str):
                if num > 1:
                    string += str(num)
                string += comp_str
                if compare_str != "":
                    string += compare_str
                break

            if comp_str == compare_str:
                num += 1
            else:
                if num > 1:
                    string += (str(num) + comp_str)
                else:
                    string += comp_str
                comp_str = compare_str
                num = 1
            comp_str = s[j:j+comp_len]

        answer = min(len(string), answer)
    return answer

print(solution("aabbaccc"))
print(solution("ababcdcdababcdcd"))
print(solution("abcabcdede"))
print(solution("abcabcabcabcdededededede"))
print(solution("xababcdcdababcdcd"))