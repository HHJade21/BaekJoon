st = []

n = int(input())
res = []
now = 1
clear = True
for i in range(n):
    next = int(input())
    while now <= next:
        st.append(now)
        res.append('+')
        now+=1
    if st[-1] != next:
        clear = False
        break 
    res.append('-')
    st.pop()

if len(st)>0:
    clear = False

if not clear :
    print("NO")
else :  
    for i in res :
        print(i)