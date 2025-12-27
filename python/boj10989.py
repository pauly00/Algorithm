#B1
import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
count = [0] *10001

# 계수 정렬
for _ in range(n):
    count[int(input())] +=1 # 해당 숫자 카운트

for i in range(10001): # 여기서 정렬
    if count[i] !=0: # 해당 숫자가 존재할 때
        for _ in range(count[i]):
            print(str(i) + "\n")