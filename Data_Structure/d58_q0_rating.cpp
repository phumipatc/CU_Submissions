/*
	Task	: d58_q0_rating
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 21 August 2022 [20:40]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << std::fixed << std::setprecision(2);
	map<string , pair<int ,int > > subj,teach;
	int n,sc;
	string id,t;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> id >> t >> sc;
		subj[id].first+=sc;
		subj[id].second++;
		teach[t].first+=sc;
		teach[t].second++;
	}
	for(auto x:subj)
		cout << x.first << ' ' << (double )x.second.first/x.second.second << '\n';
	for(auto x:teach)
		cout << x.first << ' ' << (double )x.second.first/x.second.second << '\n';
	return 0;
}