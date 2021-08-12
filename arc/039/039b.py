
def f(n):
    r = 1
    for i in range(1,n+1):
        r *= i
    return r

n, k = map(int, input().split())
if(k >= n):
    add = k%n
    ans = f(n) // ( f(add)*f(n-add)  )
    print(ans%1000000007)
else:
    ans = f(n+k-1) // (f(n-1)*f(k))
    print(ans%1000000007)