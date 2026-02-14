#S5
checklist = [0] * 4 #A,C,G,T
myList = [0] * 4
checkResult = 0 #몇개가 조건 만족하는지

# 윈도우 슬라이딩에서 새로 들어오는 문자 처리
def myAdd(c):
    global checkList, myList, checkResult
    if c=='A':
        myList[0] +=1
        if myList[0] == checkList[0]:
            checkResult +=1
    elif c=='C':
        myList[1] +=1
        if myList[1] == checkList[1]:
            checkResult +=1
    elif c=='G':
        myList[2] +=1
        if myList[2] == checkList[2]:
            checkResult +=1
    elif c=='T':
        myList[3] +=1
        if myList[3] == checkList[3]:
            checkResult +=1

# 윈도우 슬라이딩에서 빠지는 문자 처리
def myRemove(c):
    global checkList, myList, checkResult
    if c=='A':
        if myList[0] == checkList[0]:
            checkResult -=1
        myList[0] -=1
    elif c=='C':
        if myList[1] == checkList[1]:
            checkResult -=1
        myList[1] -=1
    elif c=='G':
        if myList[2] == checkList[2]:
            checkResult -=1
        myList[2] -=1
    elif c=='T':
        if myList[3] == checkList[3]:
            checkResult -=1
        myList[3] -=1

if __name__ == "__main__":
    s, p = map(int, input().split())
    dna = list(input())
    ans = 0

    checkList = list(map(int, input().split()))

    # 초기 체크
    for i in range(4):
        if checkList[i] == 0:
            checkResult +=1
    
    # 첫 윈도우 처리
    for i in range(p):
        myAdd(dna[i])

    if checkResult ==4:
        ans +=1
    
    # 슬라이딩 윈도우
    for i in range(p, s):
        j = i-p
        myAdd(dna[i]) #새로들어오는거
        myRemove(dna[j]) #빠지는거
        if checkResult ==4:
            ans +=1
    
    print(ans)