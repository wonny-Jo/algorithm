def solution(record):
    answer = []
    id_name_matching_table={}
    print_order=[]
    for command in record:
        comm = list(command.split(' '))
        if comm[0] != 'Leave':
            comm, user_id, name=comm[:]
            id_name_matching_table[user_id]=name
        else:
            comm, user_id=comm[:] 
        if comm != 'Change':
            print_order.append([comm, user_id])     
        
    for comm, user_id in print_order:
        if comm=='Enter':
            answer.append(id_name_matching_table[user_id]+'님이 들어왔습니다.')
        elif comm=='Leave':
            answer.append(id_name_matching_table[user_id]+'님이 나갔습니다.')

    return answer

print(solution(["Enter uid1234 Muzi", 
                "Enter uid4567 Prodo",
                "Leave uid1234",
                "Enter uid1234 Prodo",
                "Change uid4567 Ryan"]))
