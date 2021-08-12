
def calc():
  s, p = map(int, input().split())
  if(s*s - 4*p >= 0):
      for i in range(1, min(s, 2000010)):
          if(s*i - i*i == p):
              print("Yes")
              return
      print("No")
      return
  else:
      print("No")

calc()