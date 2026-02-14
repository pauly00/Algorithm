#S2
n = int(input())
arr = [0] * n # 입력 받을 수열

for i in range(n):
    arr[i] = int(input())

stack = []
num = 1 # 스택에 넣을 숫자
result = True
answer = ""

for i in range(n):
    target = arr[i] # 목표 숫자
    if target >= num: # 스택에 넣어야 하는 경우
        while target >= num: # 목표 숫자까지 넣기
            stack.append(num)
            num +=1
            answer +="+\n"
        stack.pop()
        answer +="-\n"
    else: # 스택에서 빼야 하는 경우
        n = stack.pop()
        if n>target: # 불가능한 경우
            result = False
            print("NO")
            break
        else:
            answer += "-\n"

if result:
    print(answer)