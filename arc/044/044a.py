n = int(input())

def is_prime(n):
    if(n < 2):
        return False
    i = 2
    while(i*i <= n):
        if(n%i == 0):
            return False
        i = i + 1
    return True

def like_prime(n):
    res = str(n)
    if(int(res[len(res)-1])%2 == 0 or int(res[len(res)-1]) == 5):
        return False
    sum = 0
    for i in range(len(res)):
        sum += int(res[i])
    if(sum%3 == 0):
        return False
    return True

if(n == 1):
    print('Not Prime')
elif(is_prime(n)):
    print('Prime')
else:
    if(like_prime(n)):
        print('Prime')
    else:
        print('Not Prime')