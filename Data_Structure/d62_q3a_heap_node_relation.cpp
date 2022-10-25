/*
	Task	: d62_q3a_heap_node_relation
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 21 October 2022 [14:49]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,m;
	cin >> n >> m;
	while(m--){
		int a,b;
		cin >> a >> b;
		a++,b++;
		if(a == b){
			cout << "a and b are the same node\n";
		}else if(a>b){
			while(a != 0 && a != b)
				a/=2;
			if(a == b)
				cout << "b is an ancestor of a\n";
			else
				cout << "a and b are not related\n";
		}else if(b>a){
			while(b != 0 && a != b)
				b/=2;
			if(a == b)
				cout << "a is an ancestor of b\n";
			else
				cout << "a and b are not related\n";
		}
	}
	return 0;
}