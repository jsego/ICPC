
#include <algorithm>
#include <iostream>

using namespace std;

struct stone {
	int X, Y, W, H;
	bool isect(struct stone & S) {
		return X <= S.X + S.W && S.X <= X + W && Y <= S.Y + S.H && S.Y <= Y + H;
	}
	bool operator<(struct stone & S) const {
		return X + W < S.X + S.W;
	}
};

struct stone S[50001];
int N, mf[50001], A[50001];

int uf(int n) {
	if (mf[n] == n) return n;
	else return mf[n] = uf(mf[n]);
}

int main() {
	while (cin >> N) {
		for (int i = 0; i < N; ++i) {
			mf[i] = i;
			cin >> S[i].X >> S[i].Y >> S[i].W >> S[i].H;
		}
		sort(S, S + N);
		
		for (int i = 0; i < N; ++i)
			for (int j = i - 1; j >= 0 && S[i].X <= S[j].X + S[j].W; --j)
				if (S[i].isect(S[j]))
					mf[uf(j)] = i;
		
		fill(A, A + N, 0);
		for (int i = 0; i < N; ++i)
			A[uf(i)] += S[i].W * S[i].H;
		cout << *max_element(A, A + N) << "\n";
	}
}
