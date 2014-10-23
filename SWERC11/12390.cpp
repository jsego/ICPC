#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int A[500005];

int main(){
	int N, B;
	while(cin>>N>>B, N != -1 && B != -1){
		int mini = 1, maxi = 0, mid = 0;
		for(int i=0;i<N;i++){ cin>>A[i]; maxi = max(maxi, A[i]+1);}
		sort(A, A+N);
		while(mini < maxi){
			mid = (maxi+mini)/2;
			bool ok = true;
			int b = 0;
			for(int i = N-1;i>=0;i--){ //check if good
				b += (A[i]+mid-1)/mid; //required boxes
				if(b > B){ok = false; break;}
			}
			if(ok) maxi = mid;
			else mini = mid+1;
		}
		cout<<maxi<<endl;
	}
}
