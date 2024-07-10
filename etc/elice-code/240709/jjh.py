def k_selected_number(a, queries):
    results = []
    for query in queries:
        i, j, k = query
        selected_numbers = sorted(a[i-1:j])
        results.append(selected_numbers[k-1])
    return results

# 예제 입력
a = [1, 7, 6, 8, 1, 6, 4, 5]
queries = [(2, 5, 2)]

# 함수 호출 및 결과 출력
results = k_selected_number(a, queries)
for result in results:
    print(result)

