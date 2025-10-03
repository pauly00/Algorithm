// P3
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N; // 더미 개수
    cin >> N;
    long long nim = 0;

    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        long long g = (x % 2 == 0) ? (x / 2 - 1) : ((x + 1) / 2);
        nim ^= g;
    }

    cout << (nim ? "koosaga" : "cubelover");
}