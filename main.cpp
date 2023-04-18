#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vl = vector<ll>;

constexpr auto mxDist = int{ 100'0000 };
constexpr auto inf = int{ 987'654'321 };

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	auto dist = vi(mxDist + 1, inf);
	dist[n] = 0;

	auto q = deque<int>{};
	q.push_front(n);

	while (!q.empty()) {
		auto f = q.front();
		q.pop_front();

		if (f == k) {
			break;
		}

		if (2 * f <= mxDist && dist[f] < dist[2 * f]) {
			dist[2 * f] = dist[f];
			q.push_front(2 * f);
		}

		if (f + 1 <= mxDist && dist[f] + 1 < dist[f + 1]) {
			dist[f + 1] = dist[f] + 1;
			q.push_back(f + 1);
		}

		if (0 <= f - 1 && dist[f] + 1 < dist[f - 1]) {
			dist[f - 1] = dist[f] + 1;
			q.push_back(f - 1);
		}
	}

	cout << dist[k];

	return 0;
}