def gcd(a, b):
  if(a%b):
    return gcd(b, a%b)
  else:
    return b


def lcm(a, b):
    return a * b // gcd(a, b)


n = int(input())
a = list(map(int, input().split()))

if(n == 1):
    print(int(a[0]%1000000007))
else:
    lc = lcm(a[0], a[1])
    for i in range(2, n):
        lc = lcm(a[i], lc)
    ans = 0
    for i in range(n):
        ans += lc//a[i]
    print(int(ans%1000000007))