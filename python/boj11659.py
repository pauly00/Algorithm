#S3
import sys


n, m = map(int, input().split())
num_list = list(map(int, input().split()))

prefix_sum = [0]
tmp = 0

for i in num_list:
    tmp+=i
    prefix_sum.append(tmp)

for _ in range(m):
    i, j = map(int, sys.stdin.readline().split())
    print(prefix_sum[j] - prefix_sum[i-1])
