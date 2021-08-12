def f(d, x, m):
    val = 0
    base = 1
    for j in range(len(x)):
        if(val > m):
          return False
        val += int(x[len(x)-1-j])*base
        base *= d


    if(val <= m):
        return True
    else:
      	return False

x = input()
m = int(input())

if(len(x) != 1):
    d = -1
    for i in range(len(x)):
        if(d < int(x[i])):
            d = int(x[i])
    r = 10**61
    l = d
    while r-l>1:
      mid = (l+r)//2
      if(f(mid, x, m)):
        l = mid
      else:
        r = mid
    print(max(l-d, 0))
else:
  if(int(x) <= m):
    print(1)
  else:
    print(0)

