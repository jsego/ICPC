#include <bits/stdc++.h>

using namespace std;

int main(){
	int W, H, B;
	while(cin >> W >> H >> B){
		vector<vector<int>> A1(H,vector<int>(W,0)), A2(H,vector<int>(W,0));
		for(int h=0; h<H; ++h){
			for(int w=0; w<W; ++w){
				cin >> A1[h][w];
			}
		}
		int pre_h, pre_w;
		for(int i=0; i<B; ++i){
			for(int h=0; h<H; ++h){
				for(int w=0; w<W; ++w){
					A2[h][w] = 0;
					for(int off_h=-1;off_h<2;++off_h){
						pre_h = (h+off_h<0?H-1:(h+off_h==H?0:h+off_h));
						for(int off_w=-1;off_w<2;++off_w){
							pre_w = (w+off_w<0?W-1:(w+off_w==W?0:w+off_w));
							A2[h][w] += A1[pre_h][pre_w];
						}
					}
				}
			}
			swap(A1, A2);	
		}
		set<int> s;
		for(int h=0; h<H; ++h){
			for(int w=0; w<W; ++w){
				s.insert(A1[h][w]);
			}
		}
		cout << s.size() << endl;
	}
}
