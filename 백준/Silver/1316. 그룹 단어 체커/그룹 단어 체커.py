n=int(input())
ans=0

for _ in range(n):
    s = input()
    group=1
    cnt=[0]*26
    cnt[ord(s[0])-97]=1
    for i in range(1, len(s)):
        if s[i]!=s[i-1]:
            if cnt[ord(s[i])-97]==1:
                group=0
            else:
                cnt[ord(s[i])-97]=1
    if group :
        ans+=1
print(ans)