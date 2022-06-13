def sum_of_list(lst):
    sum = 0
    for i in lst:
        sum += i
    return sum

lst = []
n = int(input())
for i in range(n):
    lst.append(int(input()))
print(sum_of_list(lst))