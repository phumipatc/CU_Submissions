/*
    Task	: ds01_most
    Author	: Phumipat C. [MAGCARI]
    Language: C++
    Created	: 18 August 2022 [17:36]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n;
    string str;
    map<string ,int > mapp;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> str;
        mapp[str]++;
    }
    pair<int ,string> ans = {0,""};
    for(auto x:mapp){
        if(x.second > ans.first)
            ans = {x.second,x.first};
        else if(x.second == ans.first && ans.second < x.first)
            ans.second = x.first;
    }
    cout << ans.second << ' ' << ans.first << '\n';
    return 0;
}