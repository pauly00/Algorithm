// G4
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//// 컴파일 에러 발생!!!!

// 별똥별 가로, 세로, 트램펄린 한 변 길이, 별똥별 수
int n, m, l, k;
vector<pair<int, int>> stars; // 별똥별 좌표 저장 리스트

// 트램펄린이 좌표(x, y)에 있을 때 포함되는 별똥별 수 계산
int boundStar(int x, int y) {
    int res = 0; // 범위 내 별똥별 수 저장
    // 좌표 검사
    for (auto star : stars) {
        if (x <= star.first && star.first <= x + l && // 트램펄린 범위를 l로 수정
            y <= star.second && star.second <= y + l) // 트램펄린 범위를 l로 수정
            res++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n >> m >> l >> k;

    // 별똥별 좌표 입력 처리
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        stars.push_back(make_pair(x, y));
    }

    int res = INT_MIN; // 최대 별똥별 개수 저장 변수

    // 모든 별똥별 쌍 검사 후 범위 내의 별똥별 수 계산
    for (auto star1 : stars) {
        for (auto star2 : stars) {
            // 별똥별의 좌표 기준 최대 별똥별 개수 갱신
            res = max(res, boundStar(star1.first, star2.second));
        }
    }

    // 트램펄린이 포함하지 못한 별똥별 수 계산
    cout << k - res << "\n";

    return 0;
}