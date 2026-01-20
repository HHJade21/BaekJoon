n = int(input())
arr = list(map(int, input().split()))
maxNum = max(arr)

sum = 0

for i in range(n):
    sum += arr[i]/maxNum*100

print(sum/n)