n=int(input())
cnt=0

for i in range(666, 10000000):
    j = str(i)
    if j.find("666") != -1:
        cnt+=1
    if cnt == n :
        print(i)
        break
