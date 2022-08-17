/*
    Task	: ds01_pair_sum
    Author	: Phumipat C. [MAGCARI]
    Language: C++
    Created	: 17 August 2022 [10:29]
*/
#include<bits/stdc++.h>
using namespace std;
void map_method(){
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
}
void vector_method(){
    int n,m,num;
    cin >> n >> m;
    vector<int > v(n);
    vector<bool> pos(2000010,false);
    for(auto &x:v)
        cin >> x;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            pos[v[i]+v[j]] = true;
    while(m--){
        cin >> num;
        cout << (pos[num]?"YES\n":"NO\n");
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    // map_method();
    vector_method();
    return 0;
}