# B2
# 주차 요금 (여러 숫자들 입력)
a, b, c = map(int, input().split())
time = [0] * 101 # 현재 시간 (최대 100개)
pay = 0 # 최종 요금

for _ in range(3): # 최대 3대의 트럭
    start, end = map(int, input().split())
    for i in range(start, end):
        time[i] += 1

# 트럭 개수와 주차 요금을 곱함
for i in time:
    if i == 1:
        pay += a
    elif i == 2:
        pay += (2 * b)
    elif i == 3:
        pay += (3 * c)

print(pay)