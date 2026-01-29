t=int(input())#테스트 케이스 입력
for _ in range(t):
    n,m=map(int,input().split())#숫자의 개수, 출력할 문서의 번호
    arr=list(map(int,input().split()))#일단 문서별 중요도 먼저 입력받아서 저장
    q=[]#데이터 처리할 큐 생성
    cnt = [0]*10 #중요도별로 남은 문서가 몇 개인지 기록할 카운트 배열
    next=0 #현재 남아있는 문서들 중 가장 높은 중요도
    for i in range(n):#arr에 입력받은 문서별 중요도를 가공해서 q에 삽입
        q.append([arr[i], i])# [문서의 중요도, 문서의 인덱스]
        cnt[arr[i]]+=1 # 해당 문서의 중요도의 개수를 cnt배열에서 증가시켜주기
        next = max(next, arr[i]) #next에 '현재 들어온 문서중 가장 높은 중요도'갱신
    ans = 0#몇번째 출력인지 저장할 변수(정답 출력할 때 얘 출력할거임)
    while q:#큐가 비기 전까지 계속 반복
        if q[0][0] == next :#큐의 가장 앞에 있는 문서의 중요도가 최고면 출력하기
            ans+=1#출력한 문서의 개수 증가
            if q[0][1]==m:#만약에 이번에 출력해줄 문서의 인덱스가 m이면
                break #while문 탈출
            cnt[next]-=1 #중요도가 next인 문서 하나 출력했으니까 cnt에서 남은 개수 차감
            while cnt[next] == 0:#최대 중요도가 next인게 다 출력돼서 나갔으면
                next-=1 #next갱신
        #만약 위의 if문에 안 걸렸다면 == 중요도가 낮아서 아직 출력하면 안 되는 문서라면
        q.append(q[0])#큐에서 빼서 다시 뒤로 넣어주기
        q.pop(0)
    print(ans)