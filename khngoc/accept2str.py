s1 = input()
s2 = input()

s = s1[0:2]
s1 = s[len(s) - 2: len(s)]
s2 = s
print(s1 + " " + s2) 