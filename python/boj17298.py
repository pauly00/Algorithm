#G4
n = int(input())
result = [0] *n
arr = list(map(int, input().split()))
stack = []

for i in range(n):
    while stack and arr[stack[-1]] < arr[i]:
        result[stack.pop()] = arr[i]
    stack.append(i) # 인덱스 저장

while stack:
    result[stack.pop()] = -1
answer = ""

print(" ".join(map(str, result))) # 리스트를 문자열로 변환하여 출력