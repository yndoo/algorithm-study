def solution(id_list, report, k):
    answer = dict.fromkeys(id_list,0)
    report = list(set(report)) #중복 신고 없애기
    report_list=dict.fromkeys(id_list,0) #report_list : 신고 받은 수 딕셔너리
    # 신고 받은 수 세기
    for rep in report:
        a, b = rep.split()
        report_list[b]+=1
    # 처리 결과 횟수 세기
    for rep in report:
        a, b = rep.split()
        if report_list[b]>=k:
            answer[a]+=1
    return list(answer.values())