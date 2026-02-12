stack = []
n = int(input())
res = []
now = 1
clear = True
for i in range(n):
    next = int(input())
    while now <= next:
        stack.append(now)
        res.append('+')
        now+=1
    if stack[-1] != next:
        clear = False
        break 
    res.append('-')
    stack.pop()
if not clear :
    print("NO")
else :  
    for i in res :
        print(i)