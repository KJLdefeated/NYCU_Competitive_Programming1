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
//const int  Inf     = 1e9+7;
const int N       = 2e5+9;
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
vector<int> e[N];
int n,dep[N]={},siz[N]={},p[20][N]={};

void dfs(int x,int d){
    siz[x] = 1;
    dep[x] = d+1;
    for(auto it:e[x]){
        dfs(it,d+1);
        siz[x] += siz[it];
    }
}

int lca(int a,int b){
    if(dep[a] > dep[b])swap(a,b);
    if(dep[a] != dep[b]){
        int dif = dep[b] - dep[a];
        for(int i=0;i<20;i++){
            if(dif&1)b = p[i][b];
            dif>>=1;
        }
    }
    if(a==b)return a;
    for(int i=19;i>=0;i--){
        if(p[i][a] != p[i][b]){
            a = p[i][a];
            b = p[i][b];
        }
    }
    return p[0][a];
}

void solve(){
    cin>>n;
    FOR(i,1,n+1){
        cin>>p[0][i];
        e[p[0][i]].pb(i);
    }
    dfs(0,0);
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }
    int m;cin>>m;
    while(m--){
        int t;cin>>t;
        vector<int> a,b(t,1);
        while(t--){
            int x;cin>>x;
            a.pb(x);
        }
        ll ans=0;
        for(int i=0;i<sz(a);i++){
            for(int j=0;j<sz(a);j++){
                if(i!=j && lca(a[i],a[j]) == a[j]){
                    b[i]=0;
                    break;
                }
            }
            if(b[i])ans+=1ll*siz[a[i]];
        }
        cout<<ans<<endl;
    }
}

int main(){
    INITIO()
    //int t;cin>>t;
    //while(t--){
        solve();
    //}
    return 0;
}
