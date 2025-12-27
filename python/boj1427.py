#S5
import sys
print = sys.stdout.write
input = sys.stdin.readline

arr = list(input())

# arr.sort(reverse=True)

for i in range(len(arr)):
    max = i
    for j in range(i+1, len(arr)):
        if arr[j] >arr[max]:
            max = j
    if arr[i] <arr[max]:
        arr[i], arr[max] = arr[max], arr[i]

for i in arr:
    print(i)