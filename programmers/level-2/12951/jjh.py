def solution_1(s):
    answer = []
    word_list = s.split(" ")
    for word in word_list:
        answer.append(word.capitalize())

    return ' '.join(answer)

def solution_2(s):
    word_list = s.split(" ")
    return ' '.join(word.capitalize() for word in word_list)