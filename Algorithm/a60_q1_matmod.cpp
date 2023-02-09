/*
	Task	: a60_q1_matmod
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 03 February 2023 [22:51]
*/
#include<bits/stdc++.h>
using namespace std;
int MOD;
struct A{
	int a[2][2];
	A operator * (const A&o) const{
		A temp;
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				temp.a[i][j] = 0;
				for(int k=0;k<2;k++)
					temp.a[i][j]+=a[i][k]*o.a[k][j],temp.a[i][j]%=MOD;
			}
		}
		return temp;
	}
};
A now;
A p[32];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n;
	cin >> n >> MOD;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			cin >> now.a[i][j];
	p[0] = now;
	for(int i=1;i<=31;i++)
		p[i] = p[i-1]*p[i-1];
	n--;
	for(int i=0;i<=31;i++)
		if(n&(1<<i)){
			now = now*p[i];
		}
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			cout << now.a[i][j] << ' ';
	return 0;
}