def solution(keymap, targets):
    answer = []
    # keymap 값의 최소 횟수를 저장하는 딕셔너리 생성
    min_keymap_list = {}
    for keys in keymap:
        for i, key in enumerate(keys):
            # 1. key 값이 min_keymap_list에 없을 경우
            # 2. key 값이 min_keymap_list에 있지만 기존 값보다 작을 경우
            if key not in min_keymap_list or i+1 < min_keymap_list[key]:
                min_keymap_list[key] = i+1

    for target in targets:
        min_press = 0
        for word in target:
            # keymap에 word 값이 없을 경우
            if word not in min_keymap_list:
                min_press = -1
                break
            min_press += min_keymap_list[word]
        answer.append(min_press)

    return answer