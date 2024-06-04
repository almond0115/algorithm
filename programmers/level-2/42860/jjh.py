def solution(name):
    def min_move_to_char(target):
        return min(ord(target) - ord('A'), ord('Z') - ord(target) + 1)
    
    total_moves = 0

    for char in name:
        total_moves += min_move_to_char(char)
    
    min_cursor_moves = len(name) - 1
    for i in range(len(name)):
        next_i = i + 1
        while next_i < len(name) and name[next_i] == 'A':
            next_i += 1

        min_cursor_moves = min(min_cursor_moves, i + len(name) - 1 + min(i, len(name) - next_i))

    return total_moves + min_cursor_moves
