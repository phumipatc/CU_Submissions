/*
	Task	: d64_q1a_card_battle
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 24 August 2022 [11:59]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m,num,sum;
	cin >> n >> m;
	map<int ,int > mapp;
	for(int i=1;i<=n;i++){
		cin >> num;
		mapp[num]++;
	}
	for(int i=1;i<=m;i++){
		cin >> sum;
		while(sum--){
			cin >> num;
			auto it = mapp.upper_bound(num);
			if(it == mapp.end()){
				cout << i << '\n';
				return 0;
			}
			(*it).second--;
			if((*it).second == 0)
				mapp.erase(it);
		}
	}
	cout << m+1 << '\n';
	return 0;
}