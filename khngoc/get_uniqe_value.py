def get_unique_values(lst):
    answer = []
    for i in lst:
        if i not in answer:
            answer.append(i)
    return answer

n = int(input())
lst = []
for i in range(n):
    lst.append(int(input()))
print(get_unique_values(lst))