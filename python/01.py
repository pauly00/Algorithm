def solution(num):
    # 원본 미변경
    # num_sorted = sorted(num)
    num.sort()
    return num


if __name__ == "__main__":
    # 예시코드
    num = [1,-5,2,4,3]
    # num=[2,1,1,3,2,5,4]
    print(solution(num))