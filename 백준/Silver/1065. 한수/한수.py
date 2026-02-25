han = [1]*1001
for i in range(1,1001):
    if i < 100:
        continue
    stri = str(i)
    cha = ord(stri[1])-ord(stri[0])

    for j in range(1, len(stri)-1):
        if ord(stri[j+1])-ord(stri[j]) != cha:
            han[i]=0
            break
n=int(input())
ans=0
for i in range(1,n+1):
    if han[i]==1:
        ans+=1
print(ans)