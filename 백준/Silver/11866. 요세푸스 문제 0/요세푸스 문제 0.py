n,k=map(int,input().split())
a=[]
yo =[]
for i in range(1,n+1):
    a.append(i)

while a:
    idx=0
    for _ in range(k-1):
        a.append(a[0])
        a.pop(0)
    yo.append(a[0])
    a.pop(0)
    
print('<',end='')
for i in range(len(yo)):
    print(yo[i],end='')
    if i < len(yo)-1:
        print(', ',end='')
print('>')