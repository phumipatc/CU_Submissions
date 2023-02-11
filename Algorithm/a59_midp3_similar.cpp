/*
	Task	: a59_midp3_similar
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 10 February 2023 [22:42]
*/
#include<bits/stdc++.h>
using namespace std;
const int N = (1<<17)+10;
char a[N],b[N];
bool similar(int l1,int r1,int l2,int r2){
	if(l1 == r1)	return a[l1] == b[l2];
	int mid1 = (l1+r1)/2;
	int mid2 = (l2+r2)/2;
	return (similar(l1,mid1,l2,mid2) && similar(mid1+1,r1,mid2+1,r2)) || (similar(l1,mid1,mid2+1,r2) && similar(mid1+1,r1,l2,mid2));
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> a+1 >> b+1;
	int n = strlen(a+1);
	cout << (similar(1,n,1,n)?"YES":"NO") << '\n';
	return 0;
}