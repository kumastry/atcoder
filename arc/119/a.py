

def f(mid,  num, n):
    if(n >= mid*num):
        return True
    else:
        return False

n = int(input())


num = 1
b = 0
while(num > n):
    num *= 2
    b += 1

ans = 1e18
num = 1
for i in range(b):
    r = 1e18
    l = 0
    while(r - l > 1):
        mid = (r+l) // 2
        if(f(mid, num, n)):
            l = mid
        else:
            r = mid
    c = n - num*l
    ans = min(ans, c+l+i)
    num *= 2
print(ans)