#include <bits/stdc++.h>

using namespace std;

int main(){
	cout.setf(ios::fixed);
	cout.precision(2);
	int n;
	long double W;
	while(cin >> n >> W){
		long double max_happiness = 0.0;
		long double last_safe = 0.0;
		long double success_prob = 1.0;
		long double failure_accum = 0.0;
		string s;
		long double current_prob, value, success, failure;
		for(int i=0; i<n; i++){
			cin >> s >> current_prob >> value;
			value = log(1.0+(value/W)); // current happiness value
			success = current_prob*success_prob*value;
			failure = (1.0-current_prob)*success_prob*last_safe; // multiply by sucess_prob?
			max_happiness = max(max_happiness, success+failure+failure_accum);
			//cout << success << "+" << failure <<" = " << success+failure << endl;
			if(s == "safe"){
				// update safe
				last_safe = value;
			}
			success_prob *= current_prob;
			failure_accum += failure;
		}
		long double res = (exp(max_happiness)-1.0)*W;
		cout << "$" << res << "\n";
	}
}
