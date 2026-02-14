// S2
#include <iostream>
using namespace std;

int checkArr[4]; // 각 문자의 최소 필요 개수를 저장하는 배열
int myArr[4]; // 현재 부분 문자열에서 각 문자의 개수를 저장하는 배열
int checkSecret = 0; // 4개의 문자가 모두 충족되었는지 확인하는 변수
void Add(char c); // 새로운 문자를 추가할 때 처리하는 함수
void Remove(char c); // 슬라이딩 윈도우에서 제거할 때 처리하는 함수

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int s, p; // 문자열 길이, 비밀번호의 길이
    cin >> s >> p;

    int ans = 0; // 조건을 만족하는 경우의 수
    string a; // DNA 문자열
    cin >> a;

    // 각 문자의 최소 필요 개수 입력
    for (int i = 0; i < 4; i++) {
        cin >> checkArr[i];
        if (checkArr[i] == 0) // 0이면 이미 조건을 충족한 것으로 간주
            checkSecret++;
    }

    // 첫 번째 부분 문자열의 문자 개수 처리
    for (int i = 0; i < p; i++)
        Add(a[i]);

    // 첫 번째 부분 문자열이 조건을 충족하는지 확인
    if (checkSecret == 4)
        ans++;

    // 슬라이딩 윈도우 방식으로 문자열을 처리
    for (int i = p; i < s; i++) {
        int j = i - p; // 앞쪽 문자를 제거할 인덱스
        Add(a[i]); // 새로운 문자를 추가
        Remove(a[j]); // 앞쪽 문자를 제거

        if (checkSecret == 4) // 4개의 문자가 모두 충족되었으면
            ans++;
    }
    cout << ans << "\n";
}

// 새로운 문자를 추가할 때 처리
void Add(char c) {
    switch (c) {
    case 'A':
        myArr[0]++;
        if (myArr[0] == checkArr[0]) // 최소 필요 개수를 충족하면
            checkSecret++;
        break;

    case 'C':
        myArr[1]++;
        if (myArr[1] == checkArr[1])
            checkSecret++;
        break;

    case 'G':
        myArr[2]++;
        if (myArr[2] == checkArr[2])
            checkSecret++;
        break;

    case 'T':
        myArr[3]++;
        if (myArr[3] == checkArr[3])
            checkSecret++;
        break;
    }
}

// 앞쪽 문자를 제거할 때 처리
void Remove(char c) {
    switch (c) {
    case 'A':
        if (myArr[0] == checkArr[0]) // 최소 필요 개수를 충족한 상태에서 제거하면
            checkSecret--; // 조건을 더 이상 충족하지 않음
        myArr[0]--;
        break;

    case 'C':
        if (myArr[1] == checkArr[1])
            checkSecret--;
        myArr[1]--;
        break;

    case 'G':
        if (myArr[2] == checkArr[2])
            checkSecret--;
        myArr[2]--;
        break;

    case 'T':
        if (myArr[3] == checkArr[3])
            checkSecret--;
        myArr[3]--;
        break;
    }
}
