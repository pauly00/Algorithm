# S4
# 스택

N = int(input())

stack = []
for char in range(N):
    char = input()
    if char == "pop":
        stack.pop() 
        if stack: 
            print(stack[-1])
        else:
            print(-1)
    elif char == "top":
        print(stack[-1] if stack else -1)
    elif char == "size":
        print(len(stack))
    elif char == "empty":
        print(1 if not stack else 0)
    else: # push
        if char.startswith("push"):
            _, value = char.split()
            stack.append(int(value))
