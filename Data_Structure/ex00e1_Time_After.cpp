/*
    Task	: ex00e1_Time_After
    Author	: Phumipat C. [MAGCARI]
    Language: C++
    Created	: 10 August 2022 [09:54]
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,m,x;
    scanf("%d %d %d",&h,&m,&x);
    m+=x;
    h+=m/60;
    m%=60;
    h%=24;
    printf("%02d %02d",h,m);
    return 0;
}