#G4
n = int(input())
arr = list(map(int, input().split()))
arr.sort()

count=0

for k in range(n):
    target = arr[k]
    i=0
    j=n-1
    while i<j:
        if arr[i] + arr[j] == target:
            if i!=k and j!=k:
                count+=1
                break
            elif i==k:
                i+=1
            elif j==k:
                j-=1
        elif arr[i] + arr[j] < target:
                i+=1
        else:
                j-=1

print(count)