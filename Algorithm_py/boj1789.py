import math

# s는 합계
s = int(input())

# n을 구해야 함
n = int((math.sqrt(1 + 8 * s) - 1) // 2)

print(n)