/*
	Task	: a58_q1b_triple
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 03 February 2023 [22:30]
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	while(m--){
		int target;
		cin >> target;
		for(int i=1;i<=n-3;i++){
			int j=i+1,k=n;
			while(j<k){
				if(a[i]+a[j]+a[k] == target){
					cout << "YES\n";
					goto next;
				}else if(a[i]+a[j]+a[k]>target)
					k--;
				else
					j++;
			}
		}
		cout << "NO\n";
		next:;
	}
	return 0;
}