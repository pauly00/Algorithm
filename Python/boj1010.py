# S5
# 다리 놓기
import sys
imput = sys.stdin.readline

def bridge(n, m):
    # 동적 프로그래밍 배열 초기화 (n+1 x m+1)
    dp = [[0 for _ in range(m+1)] for _ in range(n+1)]

    # N = 1일때는 동일
    for i in range(1, m+1):
        dp[1][i] = i

    # N = 2이상일 때
    for i in range(2, n+1):
        for j in range(i, m+1): # 서쪽 다리의 개수가 동쪽 다리 개수 이상이어야 함
            for k in range(j, i-1, -1): # 가능한 서쪽 조합 계산
                dp[i][j] += dp[i-1][k-1]

    return dp[n][m] # 경우의 수 반환
    
def main():
    T = int(input())
    for _ in range(T):
        n, m = map(int, input().split())
        print(bridge(n, m))

if __name__ == '__main__':
    main()