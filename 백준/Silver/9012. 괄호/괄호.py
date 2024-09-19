t = int(input())

for k in range(t):
    stack = []
    a=input()
    for i in a:
        correct = True
        if i == '(':
            stack.append(i)
        else:
            if stack: #비어있지 않은 경우 == 열린 괄호가 있는 경우
                stack.pop()#닫아준다.
            else: # 스택에 여는 괄호가 없을경우
                correct = False
                break
    
    if not correct or stack: # break문으로 끊겼거나 열린 게 남아있으면
        print("NO")
    else: #끊기지도 않고, 열린 게 전부 닫혔으면
        print("YES")