n = int(input())
s = input()
k = int(input())

ch = s[k-1]
for i in range(n):
    if(s[i] == ch):
        print(ch, end='')
    else:
        print('*', end='')
