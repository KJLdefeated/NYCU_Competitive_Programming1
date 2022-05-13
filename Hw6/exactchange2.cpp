#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <list>
#include <string.h>
#include <complex>
#include <sstream>
using namespace std;
#define INITIO()    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define FILE()      freopen("a.in","r",stdin);freopen("out.txt","w",stdout);
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define pf          push_front
#define all(a)      a.begin(),a.end()
#define rall(a)     a.rbegin(),a.rend()
#define sz(a)       (int)a.size()
#define FOR(i,a,b)  for(int i = (a); i < (b); i++)
using vii = vector<vector<int>>;
using vi = vector<int>;
using mii = map<int,int>;
using cd = complex<double>;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
const double PI   = acos(-1);
const ll Mod     = 1e9+7;
//const ll  Inf     = 2e18+9;
//const int N       = 1e5+9;
//const int dx[4] = {0, 1,  0, -1};
//const int dy[4] = {1, 0, -1,  0};
//const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
//const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll a, ll b){if( b==0 )return a;return gcd( b, a%b );}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
int mul(int a, int b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}
// ----------------------------------------------------------------------------------------------------
int a[105],dp[105][1000005],Max = 1e9+5;
void solve(){
    int n,m,cnt=0;cin>>m>>n;
    FOR(i,1,n+1){
        cin>>a[i];
        cnt+=a[i];
    }
    FOR(i,0,104)FOR(j,0,cnt+5)dp[i][j]=Max;
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=cnt;j++){
            if(j >= a[i]){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-a[i]] + 1);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    for(int i=m;i<=1000000;i++){
        if(dp[n][i]!=Max){
            cout<<i<<' '<<dp[n][i]<<endl;
            return;
        }
    }
}

int main(){
    INITIO()
    int t;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

 
