# B2
# 소수 단어
import math

def isPrime(sum):
    if sum < 2:
        return False
    # 2부터 n의 제곱근까지 나누어 떨어지는 수가 있는지 확인
    for i in range(2, int(math.sqrt(sum))+1):
        if sum % i == 0: # 소수가 아닌 경우
            return False
    return True

def main():
    word = input() # 단어 입력
    sum = 0
    for c in word:
        if c.isupper(): # 대문자인 경우
            sum += ord(c) - 38 # A: 65
        else: # 소문자인 경우
            sum += ord(c) - 96 # a: 97
    print('It is a prime word.' if isPrime(sum) else 'It is not a prime word.')

if __name__ == '__main__':
    main()