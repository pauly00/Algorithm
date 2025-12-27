#P5
n, l = map(int, input().split())
data = list(map(int, input().split()))
from collections import deque
dq = deque()

for i in range(n):
    while dq and dq[-1][0] > data[i]:
        dq.pop()
    dq.append((data[i], i)) # 괄호 2개 쓰는 이유: 튜플로 넣기 위해
    if dq[0][1] <=i-l: # 범위 벗어난 것 제거
        dq.popleft()
    print(dq[0][0], end=' ')