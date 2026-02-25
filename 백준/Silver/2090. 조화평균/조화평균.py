n=int(input())
a = list(map(int,input().split()))
mul=1
for i in a:
    mul *= i 
sum=0
for i in range(len(a)):
    a[i] = mul//a[i]
    sum += a[i] 
#분자에는 sum, 분모에는 mul 
#걔를 뒤집음

gcd = 0

def ucl(a,b):
    if a<b:
        a,b=b,a
    while b>0:
        a,b = b, a%b
    return a
    

print(mul//ucl(mul,sum), '/',sum//ucl(mul,sum),sep='')