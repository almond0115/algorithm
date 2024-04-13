def solution(word):
    answer = []
    vowels = ['A', 'E', 'I', 'O', 'U']
    def generate_words(word):
        if len(word) == 5:
            return
        for vowel in vowels:
            answer.append(word + vowel)
            generate_words(word + vowel)

    generate_words('')
    return answer.index(word) + 1