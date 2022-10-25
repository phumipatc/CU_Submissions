/*
	Task	: d64_q3a_queue_check
	Author	: Phumipat C. [MAGCARI]
	Language: C++
	Created	: 17 October 2022 [23:04]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int n,mFront,mCap,mSize,last,correction;
	cin >> n;
	while(n--){
		cin >> mFront >> mSize >> mCap >> last >> correction;
		bool correct;
		if((mFront + mSize)%mCap == last)	correct = true;
		else								correct = false;
		cout << (correct?"OK":"WRONG") << ' ';
		if(!correction){
			cout << '\n';
		}else if(correction == 1){
			//correct mFront
			mFront = (last - mSize + mCap)%mCap;
			cout << mFront << '\n';
		}else if(correction == 2){
			//correct mSize
			mSize = (last - mFront + mCap)%mCap;
			cout << mSize << '\n';
		}else if(correction == 3){
			//correct mCap
			if(last == mFront + mSize)	mCap = last+1;
			else						mCap = mFront + mSize - last;
			cout << mCap << '\n';
		}else{
			//correct last
			last = (mFront + mSize)%mCap;
			cout << last << '\n';
		}
	}
	return 0;
}
/*
10
0 0 1 0 0
0 2 4 2 0
0 8 8 20 0
0 2 4 0 0
0 2 4 0 2
0 2 4 0 4
1 3 8 7 1
10 100 8 110 3
3 8 2 3 3
3 2 0 5 3
*/