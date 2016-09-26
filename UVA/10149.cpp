#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

map<int,vector<int> > T[385];

int sumA(vector<int> &d){
	int res=0;
	for(int i=0;i<5;i++) res+=d[i];
	return res;
}

int sumIf(vector<int> &d,int c){
	int res=0;
	for(int i=0;i<5;i++) if(d[i] == c) res+=c;
	return res;
}

int checkThree(vector<int> &d){
	if(d[0] == d[1] && d[1] == d[2]) return sumA(d);
	if(d[1] == d[2] && d[2] == d[3]) return sumA(d);
	if(d[2] == d[3] && d[3] == d[4]) return sumA(d);
	return 0;
}

int checkFour(vector<int> &d){
	if(d[0] == d[1] && d[1] == d[2] && d[2] == d[3]) return sumA(d);
	if(d[1] == d[2] && d[2] == d[3] && d[3] == d[4]) return sumA(d);
	return 0;
}

int checkFive(vector<int> &d){
	if(d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[3] == d[4]) return 50;
	return 0;
}

int shortStraight(vector<int> &d){
	vector<bool> b(7,false);
	for(int i=0;i<int(d.size());i++) b[d[i]] = true;
	if(b[1] && b[2] && b[3] && b[4]) return 25;
	if(b[2] && b[3] && b[4] && b[5]) return 25;
	if(b[3] && b[4] && b[5] && b[6]) return 25;
	return 0;
}

int longStraight(vector<int> &d){
	vector<bool> b(7,false);
	for(int i=0;i<int(d.size());i++) b[d[i]] = true;
	if(b[1] && b[2] && b[3] && b[4] && b[5]) return 35;
	if(b[2] && b[3] && b[4] && b[5] && b[6]) return 35;
	return 0;
}

int fullHouse(vector<int> &d){
	if(d[0] == d[1] && d[1] != d[2] && d[2] == d[3] && d[3] == d[4]) return 40;
	if(d[0] == d[1] && d[1] == d[2] && d[2] != d[3] && d[3] == d[4]) return 40;
	return 0;
}

int getV(int i,vector<int> &d){
	if(i<6) return sumIf(d,i);
	if(i == 6) return sumA(d);
	if(i == 7) return checkThree(d);
	if(i == 8) return checkFour(d);
	if(i == 9) return checkFive(d);
	if(i == 10) return shortStraight(d);
	if(i == 11) return longStraight(d);
	if(i == 12) return fullHouse(d);
	return 0;
}

int main(){
	vector<int> inp(5,0);
	while(cin>>inp[0]>>inp[1]>>inp[2]>>inp[3]>>inp[4]){
		vector<int> r(13,0);
		sort(inp.begin(),inp.end());
		vector<vector<int> > th;
		th.push_back(inp);
		for(int i=0;i<12;i++){
			cin>>inp[0]>>inp[1]>>inp[2]>>inp[3]>>inp[4];
			sort(inp.begin(),inp.end());
			th.push_back(inp);		
		}
		for(int i=0;i<385;i++) T[i].clear();
		T[0][0] = r ;

		int maxv = 0, cv;
		vector<int> a(15,0), ca;		

		for(int i=0;i<13;i++){//asignacion
			for(int j=0;j<13;j++){//tirada
				int v = getV(i,th[j]);
				cout<<i<<" "<<j<<" "<<v<<" = "<<th[j][0]<<" "<<th[j][1]<<" "<<th[j][2]<<" "<<th[j][3]<<" "<<th[j][4]<<endl;
				for(int p = v;p<346;p++){
					for(map<int,vector<int> >::iterator it = T[p-v].begin(); it != T[p-v].end(); it++){
						cv = it->first; ca = it->second;
						if( (cv & (1<<j)) == 0){
							cv = cv|(1<<j); 
							ca[i] = v;
							T[p][cv] = ca;
							if(cv == 8191){
								if(p > maxv){
									maxv = p;
									for(int k = 0 ; k<int(ca.size());k++) a[k] = ca[k];
									a[13] = ((a[0] + a[1] + a[2] + a[3] + a[4] + a[5])>=63?35:0);
									a[14] = maxv+a[13];
								}
								else if(p == maxv && a[13] == 0){
									for(int k = 0 ; k<int(ca.size());k++) a[k] = ca[k];
									a[13] = ((a[0] + a[1] + a[2] + a[3] + a[4] + a[5])>=63?35:0);
									a[14] = maxv+a[13];
								}
							}
						}
					}				
				}	
			}		
		}
		
		for(int i=0;i<15;i++) cout<<(i>0?" ":"")<<a[i]; cout<<endl;
			
	}
}
