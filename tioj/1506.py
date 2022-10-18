a1 = float(input())
a2 = float(input())
b1 = float(input())
b2 = float(input())
x = (a1-a2)/(b2-b1)*100
y = (a1*b2-a2*b1)/(a1-a2)*100
x = round(x)
y = round(y)
print(x//100,'.',x%100,sep='')
print(y//100,'.',y%100,sep='')

