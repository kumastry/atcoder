sa = -1
sb = -1

n = int(input())
f = False
if(n%2 == 0):
  for i in range(70):
      for j in range(70):
         
          if(3**(i+1) + 5**(j+1) == n):
              sa = i+1
              sb = j+1
              f = True
      if(3**(i+1) > n):
          break




if(f):
    print(sa, sb, sep=' ')
else:
    print(-1)
