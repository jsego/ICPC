/*
*  Javier Segovia
*  Accepted in 0.008
*/
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;
#define SL size()
#define LE length()
#define PB push_back
#define MP make_pair
int main(){
	int N;
	while (cin>>N && N ) {
		int size = (int)(sqrt((double)N+0.000000001)+0.000000001);
		if (size*size<N ) {
			size++;
		}
		int fil=0,col=0,mid=size*(size-1)+1;
		//cout<<"MID: "<<mid<<" SL: "<<size<<endl;
		if((size&1) == 0){//de arriba a abajo
			if (N>=mid) { //cout<<"ENT 1"<<endl;
				fil = size*size - N +1;
				col = size;
			}
			else { //cout<<"ENT 2"<<endl;
				fil = size;
				col = size - (mid-N);
			}

		}
		else {//de abajo a arriba
			if (N>=mid) { //cout<<"ENT 3"<<endl;
				col = size*size - N +1;
				fil = size;
			}
			else { //cout<<"ENT 4"<<endl;
				col = size;
				fil = size - (mid-N);
			}
		}
		cout<<col<<" "<<fil<<endl;
	}
}