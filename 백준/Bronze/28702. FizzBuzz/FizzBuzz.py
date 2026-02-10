ans = 0
for i in range(3):
    s=input()
    if s != 'Fizz' and s!= 'Buzz' and s!='FizzBuzz':
        ans = int(s)
    ans+=1
if ans %3 ==0 and ans%5 == 0:
    print('FizzBuzz')
elif ans%3==0:
    print('Fizz')
elif ans%5==0:
    print('Buzz')
else:
    print(ans)