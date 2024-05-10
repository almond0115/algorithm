tc = int(input())
f_word = input()
sentence = input()

if f_word in sentence:
    print(f"#{test_case} {sentence.count(f_word)}")