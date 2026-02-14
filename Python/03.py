# 프로그래머스 - 두 개 뽑아서 더하기
def solution(numbers):
    arr = []
    for i in range(len(numbers)):
        for j in range(i+1, len(numbers)):
            arr.append(numbers[i] + numbers[j])
        
    return sorted(set(arr))

if __name__ == "__main__":
    # 예시코드
    numbers = [2,1,3,4,1]
    print(solution(numbers))