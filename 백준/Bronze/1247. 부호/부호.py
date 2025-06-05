for i in range(3):
    n = int(input())
    ans = 0
    for j in range(n):
        m = int(input())
        ans = ans+m
    if(ans==0):
        print('0')
    elif(ans>0):
        print('+')
    else:
        print('-')