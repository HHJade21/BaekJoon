a=[]

n = int(input())

for _ in range(n):
    age,name=input().split()
    a.append([int(age), _, name])

a.sort()

for i in range(n):
    print(a[i][0], a[i][2])