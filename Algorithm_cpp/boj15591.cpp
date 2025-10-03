// G5
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, q; // n: 노드, q: 쿼리
	cin >> n >> q;

	vector<vector<pair<int, int>>> graph(n + 1); // 그래프 인접 리스트

	for (int i = 0; i < n - 1; i++) {
		int p, q, r; // p, q: 노드, r: 유사도
		cin >> p >> q >> r;
		graph[p].push_back({ q,r }); 
		graph[q].push_back({ p,r });
	}
	for (int i = 0; i < q; i++) {
		int k, v; // k: 유사도 기준, v: 시작 노드
		cin >> k >> v;

		vector<bool> visited(n + 1, false); // 방문 여부
		queue<int> q; // BFS를 위한 큐
		q.push(v);
		visited[v] = true;

		int count = 0; // 조건을 만족하는 노드의 개수

		while (!q.empty()) {
			int current = q.front();
			q.pop();

			for (auto& neighbor : graph[current]) {
				int next_node = neighbor.first;
				int similarity = neighbor.second;

				if (!visited[next_node] && similarity >= k) {
					visited[next_node] = true;
					q.push(next_node);
					count++;
				}
			}
		}

		cout << count << "\n"; // 결과 출력
	}


}