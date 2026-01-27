n,k=map(int,input().split())
s=input()
st=[]
for i in range(n):
    #스택이 비어있지 않고
    #뺄 수 있는 회수가 남아있고
    #stack의 top이 s[i]보다 작은 동안
    while len(st)!=0 and k>0 and st[-1]<s[i]:
        st.pop()#전부 빼버린다
        k-=1#빼기 횟수 차감
    st.append(s[i])

while k>0:#빼기 횟수가 남아있으면 마저 다 빼주기(뒤에서)
    st.pop()
    k-=1

for i in st:
    print(i,end='')