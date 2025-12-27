#P5
import sys
input = sys.stdin.readline
print = sys.stdout.write
result = 0

# 병합정렬
def merge_sort(start, end):
    global result
    if end - start < 1 : return # 정렬 완료
    mid = (start+end) // 2
    merge_sort(start, mid) # 분할
    merge_sort(mid+1, end)

    for i in range(start, end+1): # 병합
        temp[i] = arr[i]

    k = start
    index1 = start
    index2 = mid + 1
    
    # 두 부분 배열 병합
    while index1 <=mid and index2 <=end:
        if temp[index1] > temp[index2]: # 오른쪽 배열의 값이 더 작을 때
            arr[k] = temp[index2]
            result += (index2 -k)
            k+=1
            index2+=1
        else:
            arr[k] = temp[index1]
            k+=1
            index1 +=1

    # 남은 값들 복사
    while index1<=mid:
        arr[k] = temp[index1]
        k+=1
        index1 +=1
    while index2 <=end:
        arr[k] = temp[index2]
        k+=1
        index2 +=1

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    arr.insert(0, 0)
    temp = [0] * int(n+1)
    merge_sort(1, n)
    print(str(result))