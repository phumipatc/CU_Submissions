/*
    Task	: ds01_pair_sum
    Author	: Phumipat C. [MAGCARI]
    Language: C++
    Created	: 17 August 2022 [10:29]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n,m,num;
    cin >> n >> m;
    map<int ,int > mapp;
    for(int i=1;i<=n;i++){
        cin >> num;
        mapp[num]++;
    }
    while(m--){
        cin >> num;
        bool found = false;
        for(auto x:mapp){
            if(x.first >  num)                          break;
            if(x.first*2 == num && x.second == 1)       continue;
            if(mapp.find(num - x.first) == mapp.end())  continue;
            found = true;
            break;
        }
        cout << (found?"YES":"NO") << '\n';
    }
    return 0;
}