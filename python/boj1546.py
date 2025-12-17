#B1
n = int(input()) # 과목개수
scores = list(map(int, input().split())) # 점수 리스트
max_score = max(scores) #최고점수
sum_score = sum(scores)

print(sum_score / max_score * 100 / n)