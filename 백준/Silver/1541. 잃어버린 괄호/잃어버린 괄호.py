s = input()
ans = 0
tmp1 = 0
tmp2 = 0
plus = 1
for i in s:
    if i == '+':
        tmp2 += tmp1
        tmp1 = 0
    elif i == '-' :
        ans += plus * (tmp2+tmp1) 
        tmp1 = 0
        tmp2 = 0
        plus = -1
    else :
        tmp1 *= 10
        tmp1 += ord(i)-ord('0')

ans += plus * (tmp2+tmp1)

print(ans)

