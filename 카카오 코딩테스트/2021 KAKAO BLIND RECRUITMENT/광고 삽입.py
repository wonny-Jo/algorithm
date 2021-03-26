def solution(play_time, adv_time, logs):
    h,m,s=map(int,play_time.split(":"))
    play_second=h*3600+m*60+s
    h,m,s=map(int,adv_time.split(":"))
    adv_second=h*3600+m*60+s

    arr=[0 for _ in range(360001)]
    for str_logs in logs:
        log1,log2=str_logs.split('-')
        start_h,start_m,start_s=map(int,log1.split(":"))
        start_second=start_h*3600+start_m*60+start_s
        end_h,end_m,end_s=map(int,log2.split(":"))
        end_second=end_h*3600+end_m*60+end_s
        arr[start_second]+=1
        arr[end_second]-=1

    for i in range(1,play_second+1):
        arr[i]+=arr[i-1]
    for i in range(1,play_second+1):
        arr[i]+=arr[i-1]
    
    max_time=0
    max_sum=arr[adv_second]
    for start_time in range(1,play_second):
        end_time=start_time+adv_second if start_time+adv_second<play_second else play_second
        if max_sum<arr[end_time]-arr[start_time]:
            max_sum=arr[end_time]-arr[start_time]
            max_time=start_time+1

    s=max_time%60
    max_time//=60
    m=max_time%60
    max_time//=60
    h=max_time

    return ''.join('{:02d}:{:02d}:{:02d}').format(h,m,s)


print(solution("02:03:55","00:14:15",["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"]))