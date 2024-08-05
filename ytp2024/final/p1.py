a = int(input())
s = str(a)
c = "0"
flag = 0
for i in range(len(s)):
    if flag == 0 and s[i] == "1":
        flag = 1
        c = c+"2"
        continue
    if flag:
        c = c+"0"
    else:
        c = c+s[i]

b = int(c)
print(b-a)

