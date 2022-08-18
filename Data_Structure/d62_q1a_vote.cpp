/*
    Task	: d62_q1a_vote
    Author	: Phumipat C. [MAGCARI]
    Language: C++
    Created	: 18 August 2022 [17:58]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n,k;
    string str;
    map<string ,int > mapp;
    vector<pair<int ,string > > v;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> str;
        mapp[str]++;
    }
    for(auto x:mapp){
        v.push_back({x.second,x.first});
    }
    sort(v.rbegin(),v.rend());
    int cnt = 0;
    cout << v[min((int )v.size()-1,k-1)].first << '\n';
    return 0;
}