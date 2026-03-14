n=int(input())
a = [list(input()) for _ in range(n)]
vis = [[0]*n for _ in range(n)]
dy=[-1,1,0,0]
dx=[0,0,-1,1]
cnt=0#아파트단지의 수
tmp=0#현재 탐색중인 아파트단지의 총 집의 수
ans=[]#단지내 집의 수 정렬할 리스트
def dfs(y,x):
    vis[y][x]=1
    global tmp 
    tmp+=1
    for i in range(4):
        ny=y+dy[i]
        nx=x+dx[i]
        if ny<0 or nx<0 or ny>=n or nx>=n :
            continue 
        if vis[ny][nx] or a[ny][nx]=='0':
            continue
        dfs(ny,nx)

for i in range(n):
    for j in range(n):
        if vis[i][j]==0 and a[i][j]=='1':
            tmp=0
            dfs(i,j)
            cnt+=1
            ans.append(tmp)
print(cnt)
ans.sort()
for i in ans:
    print(i)