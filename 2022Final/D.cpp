#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
const int N = 1e6+5;
int n,m;
ll dp[3005][3005]={};

bool cmp(pii a,pii b){
    return 1ll * a.S * b.F > 1ll * a.F * b.S;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    cin>>n>>m;
    vector<pii> a(n), b;
    FOR(i,0,n)cin>>a[i].F>>a[i].S;
    sort(all(a), cmp);
    b.pb({0,0});
    FOR(i,0,min(n,3000))b.pb(a[i]);
    n = min(n,3000);
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= b[i].F) dp[i][j] = max(dp[i][j], dp[i-1][j-b[i].F] + b[i].S);
            ans = max(ans, dp[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}