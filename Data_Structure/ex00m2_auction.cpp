/*
	Task	: ex00m2_auction
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 08 September 2022 [22:54]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m,a;
	cin >> n >> m >> a;
	vector<int > num(n+1);
	for(int i=1;i<=n;i++)
		cin >> num[i];
	char opr;
	int u,i,v;
	while(a--){
		cin >> opr;
		if(opr == 'B'){
			cin >> u >> i >> v;
		}else{
			cin >> u >> i;
		}
	}
	return 0;
}