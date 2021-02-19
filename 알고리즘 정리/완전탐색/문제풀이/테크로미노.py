import sys
input=sys.stdin.readline

########################################################################
#테크로미노 블록 형태                                                           
#1.     2.      3.      4.      5.      6.      7.      8.      9.      10.
                                                     #
  ####    #       #       ##      ###      #       ###    #       ###       ##
          #       ###      #        #      #              #       #          #
          #                #              ##              ##                 #
          #

#11.     12.     13.     14.     15.     16.        17.     18.     19.
             ##                              #
    ##      ##     #       ##        #      ###       ###     #         #
    ##             ##       ##      ##                 #      ##       ## 
                    #               #                         #         #

########################################################################

n,m=list(map(int,input().split()))
a=[[] for _ in range(n)]
for i in range(n):
    a[i]=list(map(int,input().split()))

result=0
for i in range(n):
    for j in range(m):
        temp=0
        if j + 3 < m: #1
            temp = max(temp,a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i][j + 3])
        if i + 3 < n: #2
            temp = max(temp,a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 3][j])
        if i + 1 < n and j + 2 < m: #3, 5, 9, 14, 17
            temp = max(temp,a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 1][j + 2])
            temp = max(temp,a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 2])
            temp = max(temp,a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j])
            temp = max(temp,a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 1][j + 2])
            temp = max(temp,a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i + 1][j + 1]) 
        if i + 2 < n and j + 1 < m: #4, 8, 10, 13, 18
            temp = max(temp,a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 2][j])
            temp = max(temp,a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j + 1])
            temp = max(temp,a[i][j] + a[i][j + 1] + a[i + 1][j + 1] + a[i + 2][j + 1])
            temp = max(temp,a[i][j] + a[i + 1][j] + a[i + 1][j + 1] + a[i + 2][j + 1])
            temp = max(temp,a[i][j] + a[i + 1][j] + a[i + 2][j]+a[i + 1][j + 1])       
        if i + 2 < n and j - 1 >= 0: #6, 15, 19
            temp = max(temp,a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 2][j - 1])
            temp = max(temp,a[i][j] + a[i + 1][j] + a[i + 1][j - 1] + a[i + 2][j - 1])
            temp = max(temp,a[i][j] + a[i + 1][j] + a[i + 2][j] + a[i + 1][j - 1])
        if i - 1 >= 0 and j + 2 < m: #7, 12, 16
            temp = max(temp,a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 2])
            temp = max(temp,a[i][j] + a[i][j + 1] + a[i - 1][j + 1] + a[i - 1][j + 2])
            temp = max(temp,a[i][j] + a[i][j + 1] + a[i][j + 2] + a[i - 1][j + 1])          
        if i + 1 < n and j + 1 < m: #11
            temp = max(temp,a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1])                           
        result=max(result,temp)
print(result)