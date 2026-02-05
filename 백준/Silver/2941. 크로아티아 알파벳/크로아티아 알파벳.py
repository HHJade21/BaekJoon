s=input()
ans=len(s)

for i in range(len(s)):
    if i<len(s)-1 and s[i] == 'c' and (s[i+1] == '=' or s[i+1]=='-'):
        ans-=1
    elif s[i]=="d":
        if i<len(s)-2 and s[i+1]=='z' and s[i+2]=='=':
            ans-=2
        elif i<len(s)-1 and s[i+1]=='-':
            ans-=1
    elif i<len(s)-1 and s[i]=='l' and s[i+1]=='j':
        ans -= 1
    elif i<len(s)-1 and s[i] == 'n' and s[i+1]=='j':
        ans -= 1
    elif i<len(s)-1 and s[i]=='s' and s[i+1]=='=':
        ans-=1
    elif i<len(s)-1 and s[i]=='z' and s[i+1]=='=':
        ans-=1
        if i>0 and s[i-1] == 'd':
            ans += 1

print(ans)   