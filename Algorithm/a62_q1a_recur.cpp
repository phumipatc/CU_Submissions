/*
	Task	: a62_q1a_recur
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 11 February 2023 [18:01]
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 1<<8 + 5;
int ans[N][N];
void matrix(int a,int b,int x,int y){
	if(a == 0){
		ans[x][y] = b;
		return ;
	}
	matrix(a-1,b,x,y);
	matrix(a-1,b-1,x,y+(1<<(a-1)));
	matrix(a-1,b+1,x+(1<<(a-1)),y);
	for(int i=1;i<=1<<(a-1);i++)
		for(int j=1;j<=1<<(a-1);j++)
			ans[i+x+(1<<(a-1))-1][j+y+(1<<(a-1))-1] = ans[i+x-1][j+y-1];
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int a,b;
	cin >> a >> b;
	matrix(a,b,1,1);
	for(int i=1;i<=1<<a;i++){
		for(int j=1;j<=1<<a;j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}