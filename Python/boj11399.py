#S3
n = int(input())
arr = list(map(int, input().split()))
# arr.sort()

# 삽입정렬
for i in range(1, n):
    insert = i
    insert_value = arr[i]
    for j in range(i-1, -1, -1):
        if arr[j] <arr[i]:
            insert = j+1
            break
        if j ==0:
            insert = 0
    for k in range(i, insert, -1):
        arr[k] = arr[k-1]
    arr[insert] = insert_value

total = 0
for i in range(n):
    total += arr[i] * (n - i)
print(total)