
#include <iostream>

#define M 1000000007

using namespace std;

int main() {
	string S;
	int hp, wp, hm, wm;
	long long K[2000][2000];
	while (cin >> hp >> wp >> hm >> wm) {
		long long d = 1;
		for (int i = 0; i < wp; ++i)
			d = (d * 2) % M;
		
		long long e = 1;
		for (int i = 0; i < hp; ++i)
			e = (e * d) % M;
			
		//std::cout << d << " " << e << "\n";

		long long x = 0;
		for (int i = 0; i < hp; ++i) {
			cin >> S;
			long long y = 0;
			for (int j = 0; j < wp; ++j)
				y = (2 * y + (S[j] == 'o')) % M;
			//cout << i << ":" << y << "\n";
			x = (d * x + y) % M;
		}
		//cout << x << "\n";
		
		for (int i = 0; i < hm; ++i) {
			cin >> S;
			K[i][0] = 0;
			for (int j = 0; j < wp; ++j)
				K[i][0] = (2 * K[i][0] + (S[j] == 'o')) % M;
			//cout << i << " " << 0 << ":" << K[i][0] << "\n";
			for (int j = wp; j < wm; ++j) {
				long long y = (2 * K[i][j - wp] + M - d * (S[j - wp] == 'o') % M) % M;
				K[i][j + 1 - wp] = (y + (S[j] == 'o')) % M;
				//cout << i << " " << j + 1 - wp << ":" << K[i][j + 1 - wp] << "\n";
			}
		}
		
		int res = 0;
		for (int i = 0; i <= wm - wp; ++i) {
			long long y = 0;
			for (int j = 0; j < hp; ++j)
				y = (d * y + K[j][i]) % M;
			//cout << 0 << " " << i << ":" << y << "\n";
			if (x == y) res++;
			
			for (int j = hp; j < hm; ++j) {
				long long z = (d * y + M - e * K[j - hp][i] % M) % M;
				y = (z + K[j][i]) % M;
				//cout << (j + 1 - hp) << " " << i << ":" << y << "\n";
				if (x == y) res++;
			}
		}
		cout << res << "\n";
	}
}
