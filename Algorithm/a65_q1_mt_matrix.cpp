#include<bits/stdc++.h>
using namespace std;
int u,v,w,p;
int findValue(int sz,long long r,long long c){
    if(sz == 1){
        if(r == 1){
            if(c == 1)  return u;
            else        return v;
        }else{
            if(c == 1)  return w;
            else        return p;
        }
    }
    long long shift = (1ll << (sz-1));
    if(r < 1+shift && c < 1+shift){
        // upper left zone
//        printf("upper left\n");
        return findValue(sz-1,r,c);
    }else if(r >= 1+shift && c<1+shift){
        // lower left zone
        long long newr = r-(1+shift)+1;
//        printf("lower left\n");
        return -findValue(sz-1,newr,c);
    }else if(r < 1+shift && c>=1+shift){
        // upper right zone
        long long newr = r;
        long long newc = c-(1+shift)+1;
//        printf("upper right\n");
        return findValue(sz-1,newc,newr);
    }else{
        // lower right zone
        long long newr = r-(1+shift)+1;
        long long newc = c-(1+shift)+1;
//        printf("lower right\n");
        return -findValue(sz-1,newc,newr);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n,m;
    cin >> n >> m >> u >> v >> w >> p;
    while(m--){
        long long r,c;
        cin >> r >> c;
        cout << findValue(n,r,c) << '\n';
//        printf("\n");
    }
    return 0;
}