
#include <algorithm>
#include <cmath>
#include <complex>
#include <iostream>

#define EXP(a) cpx(cos(a), sin(a))

using namespace std;

typedef complex<double> cpx;

const double two_pi = 4 * acos(0);

void FFT(cpx * in, cpx * out, int step, int size, int dir) {
	if (size == 1) {
		out[0] = in[0];
		return;
	}
	
	FFT(in, out, step * 2, size / 2, dir);
	FFT(in + step, out + size / 2, step * 2, size / 2, dir);
	
	for (int i = 0; i < size / 2; i++) {
		cpx even = out[i];
		cpx odd = out[i + size / 2];
		out[i] = even + EXP(dir * two_pi * i / size) * odd;
		out[i + size / 2] = even + EXP(dir * two_pi * (i + size / 2) / size) * odd;
	}
}

int main() {
	cpx A[524288], B[524288];
	int D, M, N, k[200000], d;
	while (cin >> N) {
		M = 0;
		for (int i = 0; i < N; ++i) {
			cin >> k[i];
			if (M < k[i]) M = k[i];
		}
		
		for (D = 1; D < 2 * M; D <<= 1);
		fill(A, A + D, 0);
		for (int i = 0; i < N; ++i)
			A[k[i]] = 1;
		
		FFT(A, B, 1, D, 1);
		for (int i = 0; i < D; ++i)
			B[i] = B[i] * B[i];
		
		FFT(B, A, 1, D, -1);
		for (int i = 0; i < N; ++i)
			A[k[i]] += cpx(1, 0);
		
		cin >> M;
		int res = 0;
		for (int i = 0; i < M; ++i) {
			cin >> d;
			if (d < D && abs(A[d]) > 0.5)
				res++;
		}
		cout << res << "\n";
	}
}

