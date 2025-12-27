#B1
n = int(input())
num = [int(input()) for _ in range(n)]
# num.sort()

for i in range(len(num) -1):
    for j in range(len(num) -1-i):
        if num[j] > num[j+1]:
            num[j] ,num[j+1] = num[j+1], num[j]


for i in num:
    print(i)