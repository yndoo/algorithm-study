def solution(record):
    answer = []
    logs = []
    uid_dict = {}
    mystr = {"Enter":"들어왔습니다.", "Leave":"나갔습니다."}
    for rec in record:
        rlist = rec.split()
        if len(rlist)==3:
            log, uid, name = rlist
            uid_dict[uid]=name
        else:
            log, uid = rlist
        
        if log != "Change":
            logs.append([log, uid])
        

    for log in logs:
        answer.append(f"{uid_dict[log[1]]}님이 {mystr[log[0]]}")
        
    return answer