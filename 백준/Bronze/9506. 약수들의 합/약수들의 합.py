while True:
    n=int(input())
    if n==-1:
        break
    arr=[]
    sum=0
    for i in range(1, n):
        if(n%i==0):
            arr.append(i)
            sum = sum+i
    if n!=sum:
        print(n, 'is NOT perfect.', end='')
    else :
        print(n, '= ', end='')
        for j in range(0, len(arr)) :
            print(arr[j], end=' ')
            if(j<len(arr)-1):
                print('+ ', end='')
            
    print('')