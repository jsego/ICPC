
#include <iostream>

using namespace std;

int main() {
	int L, W, N, l, w;
	while (cin >> W >> N) {
		int area = 0;
		for (int i = 0; i < N; ++i) {
			cin >> w >> l;
			area += w * l;
		}
		cout << area / W << "\n";
	}
}
