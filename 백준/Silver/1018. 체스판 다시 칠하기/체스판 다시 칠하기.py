bw = []
wb = []

for i in range(8):
    if i%2 == 0 :
        bw.append("BW"*4)
        wb.append("WB"*4)
    else:
        bw.append("WB"*4)
        wb.append("BW"*4)

n,m=map(int,input().split())
chess = []

for i in range(n):
    chess.append(input())

ans = 64

for i in range(n-7):
    for j in range(m-7):
        bwCnt = 0
        wbCnt = 0
        for p in range(8):
            for q in range(8):
                if bw[p][q] != chess[i+p][j+q]:
                    bwCnt+=1
                else:
                    wbCnt+=1
        if bwCnt < ans :
            ans = bwCnt 
        if wbCnt < ans:
            ans = wbCnt

print(ans)
