// S2
#include <iostream>
using namespace std;

int checkArr[4]; // 각각의 최소 요구 개수 저장 배열
int myArr[4]; // 현재 검사 중인 부분 문자열에서 개수 저장
int checkSecret = 0; // 조건 만족 여부 확인 변수
void Add(char c); // 새로 들어온 문자 처리
void Remove(char c); // 제거할 문자 처리

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int s, p; // 문자열 길이, 비밀번호
	cin >> s >> p;

	int ans = 0; // 조건을 만족하는 개수
	string a; // DNA 문자열
	cin >> a;

	// 각 문자의 최소 요구 개수 입력
	for (int i = 0; i < 4; i++) {
		cin >> checkArr[i];
		if (checkArr[i] == 0) // 0이면 바로 만족
			checkSecret++;
	}

	// 첫 번째 부분 문자열에 대해 처리
	for (int i = 0; i < p; i++)
		Add(a[i]);
	
	// 처음 문자열 만족 시
	if (checkSecret == 4)
		ans++;
	
	// 두 번째 부분 문자열부터 끝까지 슬라이싱 윈도우 방식 활용
	for (int i = p; i < s; i++) {
		int j = i - p; // 윈도우에서 제거할 문자의 인덱스
		Add(a[i]); // 새로 들어오는 문자 추가
		Remove(a[j]); // 빠져나가는 문자 추가

		if (checkSecret == 4) // 4개의 문자가 모두 조건 만족 시
			ans++;
	}
	cout << ans << "\n";
}

// 새로 들어온 문자 처리
void Add(char c) {
	switch (c) {
	case 'A':
		myArr[0]++;
		if (myArr[0] == checkArr[0]) // 최소 요구 개수 도달 시
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

// 제거할 문자 처리
void Remove(char c) {
	switch (c) {
	case 'A':
		if (myArr[0] == checkArr[0]) // 최소 요구 개수 도달 시
			checkSecret--; // 원래대로 돌린다
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