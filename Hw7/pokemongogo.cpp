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
int n,ans,cnt=0 , g[22][22]={}, dp[1<<22][22];
map<string,int> mp;
vector<int> pok[22];
vector<pii> p, v;

int dfs(int i,int j){
    if(dp[i][j] != -1)return dp[i][j];
    if(i == (1 << (n+1))-1 && j==0)return dp[i][j]=0;
    int res = 1e9+5;
    for(int k=0;k<=n;k++){
        if(!((i >> k) & 1)){
            res= min(res, dfs((i | (1 << k)), k) + g[j][k]);
        }
    }
    /*
     int b = i;
     while(b){
         cout<<(b&1);
         b/=2;
     }
     cout<<' '<<j<<' ';
     cout<<res<<endl;
    */
    
    return dp[i][j] = res;
}

void f(vector<int> a, int id){
    if(a.size() == n+1){
        
        for(int i=0;i<=n;i++){
            if(a[i])continue;
            a[i] = 1;
            
            int cn=0;
            for(int i=0, k=1;i<sz(a);i++, k*=2)
                cn += a[i] * k;
            if(dp[cn][i]!=-1){
                ans = min(ans, dp[cn][i] + g[0][i]);
                //for(int i=0;i<sz(a);i++)cout<<a[i];
                //cout<<' '<<i<<' ';
                //cout<<dp[cn][i]<<' ';
                //cout<<endl;
            }
            a[i]=0;
        }
        //cout<<endl;
        
    }
    int k = sz(a);
    FOR(i,0,sz(pok[id]))a.pb(1);
    for(int i=0;i < pok[id].size();i++){
        a[i+k]=0;
        f(a, id+1);
        a[i+k]=1;
    }
}

void solve(){
    cin>>n;
    p.resize(n+1);
    v.resize(n);
    FOR(i,0,n){
        int r,c;cin>>r>>c;
        string s;cin>>s;
        if(mp.count(s)==0){
            mp[s] = cnt++;
        }
        pok[mp[s]].pb(i);
        v[i] = {r,c};
    }
    p[0] = {0,0};
    for(int i=0,k=1;i<cnt;i++){
        for(int j=0;j<pok[i].size();j++){
            p[k++] = v[pok[i][j]];
        }
    }
    FOR(i,0,n+1){
        FOR(j,0,n+1){
            g[i][j] = abs(p[i].F-p[j].F) + abs(p[i].S-p[j].S);
            //cout<<g[i][j]<<' ';
        }
        //cout<<endl;
    }
    memset(dp, -1, sizeof(dp));
    dfs(0,0);
    ans=1e9+5;
    f({0}, 0);
    cout<<ans<<endl;
}

int main(){
    INITIO()
    //int t;cin>>t;
    //while(t--){
        solve();
    //}
    return 0;
}
