#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

#define PB push_back
#define MP make_pair
#define X first
#define Y second

char op[4] = {'+','-','*','/'};
int T, BT; //target & best approx
int total_op = 0; //total operations
int v[15]; //current values(v)
bool b[15]; //visited values(b);
pair<int,pair<int,int> > best_res[15];
pair<int,pair<int,int> > current_res[15];

void recur(int d){ 
	for(int i=0;i<d;i++){
		if(!b[i] && abs(v[i]-T) < BT){ 
			BT = abs(v[i]-T);
			total_op = d-6;
			for(int j=0;j+6<d;j++)
				best_res[j] = current_res[j];
		}
	}
	for(int i=0;i<d && BT > 0;i++){
		for(int j=i+1;j<d && BT > 0;j++){
			if(b[i] || b[j]) continue;
			b[i] = b[j] = true;
			//op +
			if(i < j){
				v[d] = v[i]+v[j];
				current_res[d-6] = MP(0,MP(v[i],v[j]));
				recur(d+1);
			}
			//op -
			if(v[i] > v[j]){
				v[d] = v[i]-v[j];
				current_res[d-6] = MP(1,MP(v[i],v[j]));
				recur(d+1);
			}
			else if(v[j] > v[i]){
				v[d] = v[j]-v[i];
				current_res[d-6] = MP(1,MP(v[j],v[i]));
				recur(d+1);
			}
			//op *
			if(v[i]<33000 && v[j] < 33000){ //to not overflow the value
				v[d] = v[i]*v[j];
				current_res[d-6] = MP(2,MP(v[i],v[j]));
				recur(d+1);
			}
			//op /
			if((v[i]%v[j]) == 0){
				v[d] = v[i]/v[j];
				current_res[d-6] = MP(3,MP(v[i],v[j]));
				recur(d+1);
			}
			else if((v[j]%v[i]) == 0){
				v[d] = v[j]/v[i];
				current_res[d-6] = MP(3,MP(v[j],v[i]));
				recur(d+1);
			}
						
			b[i] = b[j] = false;
		}
	}
}

int main(){
	int K; cin>>K;
	bool first = true;
	while(K--){
		if(first)first=false;
		else cout<<endl;
		for(int i=0;i<6;i++) cin>>v[i];
		for(int i=0;i<15;i++) b[i] = false;
		cin>>T; BT = 1000000000;

		recur(6);
		
		cout<<"Target: "<<T<<endl;
		int res = T;
		for(int i=0;i<total_op;i++){
			cout<<best_res[i].Y.X<<" "<<op[best_res[i].X]<<" "<<best_res[i].Y.Y<<" = ";
			switch(op[best_res[i].X]){
				case '+':
					res = best_res[i].Y.X + best_res[i].Y.Y; break;
				case '-':
					res = best_res[i].Y.X - best_res[i].Y.Y; break;
				case '*':
					res = best_res[i].Y.X * best_res[i].Y.Y; break;
				case '/':
					res = best_res[i].Y.X / best_res[i].Y.Y; break;
				default:
					break;
			}
			cout<<res<<endl;
		}
		cout<<"Best approx: "<<res<<endl;
	}
}
