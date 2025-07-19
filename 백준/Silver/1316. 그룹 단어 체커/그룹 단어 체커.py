a=int(input())
ans=0
for i in range(a):
    group = 1
    chk = [0]*26
    s = input()
    chk[ord(s[0])-ord('a')] = 1
    for j in range(1,len(s)):
        if chk[ord(s[j])-ord('a')] == 0: 
            chk[ord(s[j])-ord('a')] = 1
        elif s[j] != s[j-1] :
            group = 0
            break 
    if(group == 1):
        ans+=1
print(ans)
            


