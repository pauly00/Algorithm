#S2
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**4) # 재귀 깊이 제한 늘리기
n, m = map(int, input().split())
arr = [[] for _ in range(n+1)]
visit = [False] * (n+1)

def dfs(v):
    visit[v] = True
    for i in arr[v]:
        if not visit[i]:
            dfs(i)

for _ in range(m):
    a, b = map(int, input().split())
    arr[a].append(b)
    arr[b].append(a) # 무방향 그래프

count =0

for i in range(1, n+1):
    if not visit[i]:
        dfs(i)
        count+=1

print(str(count))