def get_cards(cards, answer, goal):
    if answer == goal:
        return True
    
    answer.append(cards)
    get_cards()
    
        
def solution_1(cards1, cards2, goal):
    answer = []
    # cards 완전 탐색?
    cards = cards1, cards2
    return get_cards(cards, answer, goal)

def solution_2(cards1, cards2, goal):
    points1, points2 = 0, 0
    for word in goal:
        if points1 < len(cards1) and cards1[points1] == word:
            points1 += 1
        elif points2 < len(cards2) and cards2[points2] == word:
            points2 += 1
        else:
            return "No"
        
    return "Yes"