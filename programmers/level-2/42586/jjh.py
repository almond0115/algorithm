def solution(progresses, speeds):
    answer = []

    while progresses:
        # progresses 작업 진도 업데이트
        for i in range(len(progresses)):
            progresses[i] += speeds[i]

        count = 0
        while True:
            if not progresses or progresses[0] < 100:
                break

            progresses.pop(0)
            speeds.pop(0)
            count += 1
            
        if count == 0:
            continue
        
        answer.append(count)

    return answer
