n=int(input())
res=""
for _ in range(n):
    s=input()
    if res == "":
        res = list(s)
        continue
    for i in range(len(s)):
        if(s[i]!=res[i]):
            res[i]='?'
for i in res:
    print(i,end='')