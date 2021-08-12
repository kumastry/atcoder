s = input()
w = int(input())
for i in range(len(s)):
    if(i%w  == 0):
        print(s[i], end='')
print('')