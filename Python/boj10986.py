#G3
n, m = map(int, input().split())
arr = list(map(int, input().split()))
sum = [0] * n # 누적합 배열
count = [0]*m # 나머지 개수 세기 배열
sum[0] = arr[0] # 첫 번째 누적합 초기화
result = 0

for i in range(1, n): # 누적합
    sum[i] = sum[i-1] + arr[i]

# 나머지 개수 세기
for i in range(n):
    remainder = sum[i] %m
    if remainder ==0: # 나머지 0
        result+=1
    count[remainder]+=1

# 나머지 개수로 경우의 수 계산
for i in range(m):
    if count[i]>1:
        result +=(count[i] * (count[i]-1) // 2)

print(result)