import math
y = int(input())
m = int(input())
d = int(input())

after = 735369
if(m <= 2):
    m += 12
    y -= 1

before = 365*y + math.floor(y/4) - math.floor(y/100)+math.floor(y/400) + math.floor((306*(m+1))/10) + d - 429
print(after - before)