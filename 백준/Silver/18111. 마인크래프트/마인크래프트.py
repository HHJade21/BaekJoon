n,m,b = map(int, input().split())

arr = []

for i in range(n):
    arr.append(list(map(int,input().split())))

ans = 987654321
height = 0

for k in range(257):
    sum = 0
    tmp = b 
    for i in range(n):
        for j in range(m):
            if arr[i][j] < k:
                sum += k-arr[i][j]
                tmp -= k-arr[i][j]
            else:
                sum += 2*(arr[i][j]-k)
                tmp += arr[i][j]-k
    if tmp < 0 :
        continue
    elif ans >= sum:
        ans = sum
        height = k
print(ans, height)
                