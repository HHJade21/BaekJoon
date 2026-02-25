sum=0
n=0
s=int(input())
while True:
    n+=1
    sum+=n 
    if sum>s:
        break 
print(n-1)