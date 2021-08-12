
def pow(x, n):
    ans = 1
   
    while n:
        if n % 2:
            ans *= x
        x *= x
        n >>= 1
    return ans

n, m = map(int, input().split())
nn = pow(10, n)
print(nn)
print((nn//m)%m)