s=input()
st =[]
b=input()
def isBomb():
    for i in range(1,len(b)+1):
        if st[-i] != b[-i]:
            return False 
    return True 


for i in s:
    st.append(i)
    if len(st) >= len(b) and i == b[-1] and isBomb():
        del st[-len(b):len(st)]

if len(st)==0:
    print("FRULA")
else:
    for i in st:
        print(i,end='')
