import math
x, k, d = map(int, input().split())

if(abs(x) >= k*d):
    print(abs(x) - k*d)
else:
    st1 = math.floor(x/d)
    x = abs(x) - d*st1
    x = abs(x)
    dd = k-st1
   
    if(dd%2==1):
        print(abs(x-d))
    else:
        print(x)


