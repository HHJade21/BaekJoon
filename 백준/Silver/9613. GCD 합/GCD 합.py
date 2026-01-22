def gcd(a,b):
    if a<b:
        a,b=b,a
    while b>0:
        a, b = b,a%b 
    return a

t=int(input())
for _ in range(t):
    arr=list(map(int,input().split()))
    sum=0
    for i in range(1, arr[0]):
        for j in range(i+1, arr[0]+1):
            sum+=gcd(arr[i], arr[j])
    print(sum)