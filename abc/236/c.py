#　コメントなし
# set に含まれるのは　in 演算子
n, m = map(int, input().split())
s = input().split()
t = input().split()

express_set = set()

for i in t:
    express_set.add(i)

for i in s:
    if(i in express_set):
        print('Yes')
    else:
        print('No')
