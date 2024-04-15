def solution(id_list, report, k):
    user_report= set()                          # 중복 유저 없는 신고 리스트
    report_list = {id: 0 for id in id_list}     # 신고 누적 딕셔너리
    email_list = {id: 0 for id in id_list}      # 이메일 전송 딕셔너리

    for rt in report:
        # reporter : 신고 한 사람, reported : 신고 당한 사람 
        reporter, reported = rt.split(" ")

        # 중복 유저 없는 신고 리스트에 없다면 추가
        # 신고 당한 사람의 신고 누적 수 증가
        if (reporter, reported) not in user_report:
            user_report.add((reporter, reported))
            report_list[reported] += 1

    # K회 이상 신고 당해 정지 당한 ID 리스트
    banned_list = [id for id in id_list if report_list[id] >= k] 

    # 각 유저 별 결과 메일 수 계산 
    for reporter, reported in user_report:
        if reported in banned_list:
            email_list[reporter] += 1
    
    return list(email_list.values())
