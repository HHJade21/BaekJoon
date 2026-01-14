a = int(input())

for i in range(a):
    r,s=input().split()
    r=int(r)
    for j in range(len(s)):
        for k in range(r):
            print(s[j],end='')
    print()