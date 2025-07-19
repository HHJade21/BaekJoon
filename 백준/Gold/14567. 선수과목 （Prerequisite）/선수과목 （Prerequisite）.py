from collections import deque
n, m = map(int, input().split())  # 노드 수(n)와 간선 수(m)
g = [[] for _ in range(n + 1)]    # 인접 리스트로 그래프 초기화
ind = [0] * (n + 1)               # 각 노드의 진입 차수
ans = [0] * (n + 1)               # 각 노드의 수강 가능 학기

for _ in range(m):
    a, b = map(int, input().split())
    g[a].append(b)     # a → b 간선 추가
    ind[b] += 1        # b의 진입 차수 증가

q = deque()
for i in range(1, n + 1):
    if ind[i] == 0:
        ans[i] = 1     # 진입 차수가 0이면 첫 학기에 수강 가능
        q.append(i)

while q:
    now = q.popleft()
    for i in g[now]:
        ind[i] -= 1
        if ind[i] == 0:
            ans[i] = ans[now] + 1
            q.append(i)

for i in range(1, n + 1):
    print(ans[i], end=' ')
