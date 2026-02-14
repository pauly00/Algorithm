#S1
from queue import PriorityQueue
import sys
input = sys.stdin.readline
print = sys.stdout.write
n = int(input())
pq = PriorityQueue() # (절대값, 실제값) 튜플로 저장

for i in range(n):
    x = int(input())
    if x ==0: # 비어있음
        if pq.empty():
            print("0\n")
        else: # 값 존재(실제값 출력)
            print(str(pq.get()[1])+"\n")
    else: # 값 추가
        pq.put((abs(x), x)) # 튜플로 넣기(절대값, 실제값)