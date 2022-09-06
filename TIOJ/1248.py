while True:   
    s = input()
    if s[0] == '0' and s[-1] == '0':
        break
    print(eval(s))
