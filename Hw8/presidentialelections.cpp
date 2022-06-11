#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
#ifdef DEBUG
#else
#define deb(...)
#define debit(...)
#endif
#define INITIO()    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define FILE        freopen("a.in","r",stdin);freopen("out.txt","w",stdout);
#define MEM(i,j) memset(i,j,sizeof i);
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define pf          push_front
#define eb          emplace_back
#define all(a)      a.begin(),a.end()
#define sz(a)       (int)a.size()
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define vii         vector<vector<int>>;
#define vi          vector<int>;
#define mii         map<int,int>;
#define ever        ;;
typedef                long long ll;
typedef                unsigned long long ull;
typedef                pair<int,int> pii;
const double Eps  = 1e-8;
const int Inf     = 1e9+9;
const int Mod     = 1000000009;
const int N       = 1e5+9;
const int dx4[4] = {0, 1, 0, -1};
const int dy4[4] = {-1, 0, 1, 0};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int gcd(int a, int b){if( b==0 )return a;return gcd( b, a%b );}
int lcm(int a,int b){return a * b / gcd(a, b);}
ll mul(ll a, ll b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}
// -----------------------------------------------------------------------------------------------------
ll inf = 1e15+5;
int n,d[3000],c[3000],f[3000],u[3000];
ll dp[3000][5005];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>d[i]>>c[i]>>f[i]>>u[i];
    for(int i=0;i<=2500;i++)for(int j=0;j<=5000;j++)dp[i][j]=inf;
    dp[0][2500]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=5000;j++){
            if(dp[i-1][j]!=inf){
                if(c[i] > f[i]){
                    ll dx = max((c[i]+u[i]+f[i])/2 - c[i] + 1, 0);
                    if(f[i] + u[i] >= c[i])dp[i][j-d[i]] = min(dp[i][j-d[i]], dp[i-1][j]);
                    dp[i][j+d[i]] = min(dp[i][j+d[i]], dp[i-1][j]+dx);
                }
                else {
                    ll dx = (c[i]+u[i]+f[i])/2 - c[i] + 1;
                    if(c[i] + u[i] >  f[i]){
                        dp[i][j+d[i]] = min(dp[i][j+d[i]], dp[i-1][j]+dx);
                    }
                    dp[i][j-d[i]] = min(dp[i][j-d[i]], dp[i-1][j]);
                }
            }
        }
    }
    ll ans = inf;
    for(int i=2501;i<=5000;i++)ans=min(dp[n][i],ans);
    if(ans==inf)cout<<"impossible"<<endl;
    else cout<<ans<<endl;
}

int main(){
    INITIO()
    //int t;cin>>t;
    //while(t--){
        solve();
    //}
    return 0;
}
