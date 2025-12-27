#G5
import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**4)

def isPrime(num):
    if num<2:
        return False
    for i in range(2, int(num**0.5)+1):
        if int(num) % i ==0:
            return False
    return True

def dfs(num):
    if len(str(num)) == n:
        print(num)
    else:
        for i in range(1, 10):
            if isPrime(num*10 + i):
                dfs(num*10 +i)

if __name__ =="__main__":
    n = int(input())
    dfs(2) # 일의 자리 소수 기준
    dfs(3)
    dfs(5)
    dfs(7)