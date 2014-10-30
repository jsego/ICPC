#include<iostream>
using namespace std;
int source[10005];
int destination[10005];
int start[10005];
int duration[10005];

int main(){
	int N, M;
	while(cin>>N>>M, N!= 0 && M!=0){
		for(int n=0;n<N;n++)
			cin>>source[n]>>destination[n]>>start[n]>>duration[n];
		int st, en;
		for(int m=0;m<M;m++){
			cin>>st>>en;
			int res = 0;
			for(int n=0;n<N;n++){
				if(start[n] < st+en && start[n]+duration[n] > st)
					res++;
			}
			cout<<res<<endl;
		}
	}
}
