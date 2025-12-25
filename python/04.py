# 프로그래머스 - 모의고사
def solution(answers):
    #1번: 12345 2번: 21232425 3번: 3311224455
    patterns = [
        [1,2,3,4,5],
        [2,1,2,3,2,4,2,5],
        [3,3,1,1,2,2,4,4,5,5]
    ]
    scores = [0] *3
    for i, ans in enumerate(answers): # enumerate: 인덱스와 값을 같이 반환
        for j, pattern in enumerate(patterns):
            if ans == pattern[i%len(pattern)]: # 정답일 때(패턴의 길이로 나눈 나머지 인덱스)
                scores[j]+=1
    max_score = max(scores)
    highest_scores = []
    for i, score in enumerate(scores):
        if score == max_score:
            highest_scores.append(i+1)
    return highest_scores

if __name__ == "__main__":
    # 예시코드
    answers = [1,2,3,4,5]
    print(solution(answers))