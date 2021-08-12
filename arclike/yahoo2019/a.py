import math as mt
n, k  = map(int, input().split())
if(mt.ceil(n/2) >= k):
    print('YES')
else:
    print('NO')