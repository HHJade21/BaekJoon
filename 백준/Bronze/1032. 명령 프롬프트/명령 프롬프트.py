n=int(input())
res=list(input())
for _ in range(n-1):
    s=input()
    for i in range(len(s)):
        if(s[i]!=res[i]):
            res[i]='?'
for i in res:
    print(i,end='')