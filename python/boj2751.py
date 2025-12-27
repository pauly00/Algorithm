#S5
import sys
input = sys.stdin.readline
print = sys.stdout.write
n = int(input())
arr = [int(input()) for _ in range(n)]

arr.sort()

for i in arr:
    print(str(i) + '\n')