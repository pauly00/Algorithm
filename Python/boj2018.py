#S5
n = int(input())
count, start, end, sum = 1,1,1,1
while end !=n:
    if sum==n: # 정답
        count+=1
        end +=1
        sum+= end
    elif sum>n: #초과
        sum-=start
        start+=1
    else: # 부족
        end+=1
        sum+=end

print(count)