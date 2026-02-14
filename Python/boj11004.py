#S5
import sys
print = sys.stdout.write
input = sys.stdin.readline
n, k = map(int, input().split())
arr = list(map(int, input().split()))

# arr.sort()
# 퀵정렬
def quickSort(start, end, array):
    global arr
    if start < end:
        pivot = partition(start, end)
        if pivot == array:
            return
        elif array < pivot:
            quickSort(start, pivot-1, array)
        else:
            quickSort(pivot+1, end, array)

def swap(i, j):
    global arr
    arr[i], arr[j] = arr[j], arr[i]

def partition(start, end):
    global arr
    if start +1== end:
        if arr[start] >arr[end]:
            swap(start, end)
        return end
    
    mid = (start+end) // 2
    swap(start, mid)
    pivot = arr[start]
    i = start+1
    j = end
    while i<=j:
        while pivot <arr[j] and j>0:
            j-=1
        while pivot >arr[i] and i <len(arr)-1:
            i+=1
        if i <=j:
            swap(i, j)
            i+=1
            j-=1
    arr[start] = arr[j]
    arr[j] = pivot
    return j


quickSort(0, n-1, k-1)
print(str(arr[k-1]))