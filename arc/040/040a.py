n = int(input())
s = n*[[]]
for i in range(n):
    s[i] = input()  
t = 0
a = 0
for i in range(n):
    for j in range(len(s[i])):
        if(s[i][j] == 'R'):
            t += 1
        if(s[i][j] == 'B'):
            a += 1
if(t > a):
   print('TAKAHASHI')
elif(t < a):
    print("AOKI")
else:
    print('DRAW')