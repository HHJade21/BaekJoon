n=int(input())
angmu=[]
for _ in range(n):
    angmu.append(list(input().split()))
ans = list(input().split())

while ans:
    chk=0
    for i in range(n):
        if angmu[i] and ans and angmu[i][0] == ans[0]:
            chk=1
            angmu[i].pop(0)
            ans.pop(0)
            break
    if chk == 0:
        break 

chk = 1
for i in range(n):
    if angmu[i]:
        chk=0
if ans or chk==0:
    print('Impossible')
else:
    print('Possible')