#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(a) (a.begin(),a.end())

int n;ll a[202], d[202][202];

ll oper(int i,int j,int k){
    return a[i]*a[j]*a[k] + (a[i]^a[j]^a[k]);
}

ll dp(int x,int y){
    if(x + 1 >= y)return 0;
    if(d[x][y] != 2e18+5)return d[x][y];
    for(int i = x+1;i<y;i++){
        d[x][y] = min(d[x][y] ,dp(x,i)+dp(i,y)+oper(x,i,y));
    }
    return d[x][y];
}

int main(){
    cin>>n;
    FOR(i,0,n)FOR(j,0,n)d[i][j] = 2e18+5;
    FOR(i,0,n)cin>>a[i];
    cout<<dp(0,n-1)<<endl;
    return 0;
}