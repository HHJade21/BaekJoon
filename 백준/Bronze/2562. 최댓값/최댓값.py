a = []

for i in range(9):
    b = int(input())
    a.append(b)

m = 0
num=0

for i in range(0,9) :
    if(m<a[i]):
        m=a[i]
        num=i

print(m)
print(num+1)