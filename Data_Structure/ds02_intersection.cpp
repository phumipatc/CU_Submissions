/*
    Task	: ds02_intersection
    Author	: Phumipat C. [MAGCARI]
    Language: C++
    Created	: 18 August 2022 [17:19]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int n,m;
    cin >> n >> m;
    vector<int > a(n),b(m);
    for(auto &x:a)
        cin >> x;
    for(auto &x:b)
        cin >> x;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    vector<int >::iterator it = a.begin(),it2 = b.begin();
    // using map
    map<int ,bool > mapp;
    while(it != a.end() && it2 != b.end()){
        if(*it == *it2){
            if(mapp.find(*it) == mapp.end())
                cout << *it << ' ',mapp[*it] = true;
            it++,it2++;
        }else if(*it < *it2){
            it++;
        }else{
            it2++;
        }
    }
    return 0;
}
