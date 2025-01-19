# B1
# 가장 큰 금민수
n = int(input())

for num in range(n, 1, -1):
    if all(x in ['4', '7'] for x in str(num)): # 금민수인지 확인
        print(num)
        break