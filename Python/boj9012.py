# S4
# 괄호 문자열의 올바른 괄호 여부를 판단하는 문제

T = int(input())
for _ in range(T):
    s = input()
    stack = []
    is_valid = True
    
    for char in s:
        if char == '(':
            stack.append(char) # 여는 괄호를 스택에 추가
        elif char == ')':
            if stack:
                stack.pop()
            else:
                is_valid = False
                break
    
    if is_valid and not stack:
        print("YES")
    else:
        print("NO")

