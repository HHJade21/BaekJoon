from queue import Queue

que = Queue() #큐 선언

n = int(input())

for i in range(1, n+1):
    que.put(i)

while(que.qsize() > 1):
    que.get()
    que.put(que.get())

print(que.queue[0])

