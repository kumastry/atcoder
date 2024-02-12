# 反省点
# 格子点を見逃していた
# 全方向の考慮が漏れていた
x1, y1, x2, y2 = map(int, input().split())

adds = [[1, 2], [-1, 2], [1, -2], [-1, -2],
        [2, 1], [-2, 1], [2, -1], [-2, -1]]
has_exist = False
for add1 in adds:
    for add2 in adds:
        x1_copy = x1
        y1_copy = y1
        x1_copy += add1[0] + add2[0]
        y1_copy += add1[1] + add2[1]
        if(x1_copy == x2 and y1_copy == y2):
            has_exist = True
if(has_exist):
    print("Yes")
else:
    print("No")



