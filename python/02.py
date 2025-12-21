def solution(arr):
    # 중복 제거
    arr = list(set(arr))
    # 내림차순
    arr.sort(reverse=True)
    # print(arr)
    return arr

if __name__ == "__main__":
    # 예시코드
    arr = [4,2,2,1,3,4]
    # arr = [2,1,1,3,2,5,4]
    print(solution(arr))