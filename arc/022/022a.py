s = input()
ict = 'ict'
ICT = 'ICT'
index = 0
f = False
for i in range(len(s)):
    if(ict[index] == s[i] or ICT[index] == s[i]):
        index += 1
    if(index >= 3):
        f = True
        break
if(f):
    print('YES')
else:
    print('NO')
