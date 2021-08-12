a, b, c = map(int, input().split())

A = a*(a+1)//2
B = b*(b +1)//2
C = c*(c+1)//2

ans = A*B*C
print(ans%998244353)