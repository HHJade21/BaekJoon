n=int(input())
a=list(map(int,input().split()))
l=0
ll=0
r=n-1
rr=0
a.sort()
min=2000000000
while l<r:
    if abs(a[l]+a[r])<min:
        min=abs(a[l]+a[r])
        ll=l 
        rr=r 
    if a[l]+a[r] <0:
        l+=1 
    else:
        r-=1 
print(a[ll],a[rr])