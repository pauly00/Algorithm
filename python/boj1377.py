#G2
import sys
input = sys.stdin.readline
n = int(input())
arr = []

for i in range(n): # 투플로 (값, 원래 인덱스) 저장
    arr.append((int(input()), i))

max = 0
sorted_num = sorted(arr)

for i in range(n):
    if max < sorted_num[i][1] - i:
        max = sorted_num[i][1] -i

print(max+1)