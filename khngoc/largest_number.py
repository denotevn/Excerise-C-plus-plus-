def max3(a, b, c):
    if a > b and a > c:
        return a
    return b if b > c else c


a = int(input())
b = int(input())
c = int(input())
print(max3(a, b, c))
