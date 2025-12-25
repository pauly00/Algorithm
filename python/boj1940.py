#S4
n = int(input())
m = int(input())

arr = list(map(int, input().split()))
arr.sort()
count = 0
i=0
j=n-1

while i<j:
    if arr[i] + arr[j] < m:
        i+=1
    elif arr[i] + arr[j] > m:
        j-=1
    else:
        count+=1
        i+=1
        j-=1

print(count)