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
const int N       = 1e5+9;
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

int n,m,indg[N],dp[N]={},vis[N]={};
vector<int> edge[N], redge[N], scc[N];
queue<int> s;

void dfs1(int x){
    if(vis[x])return;
    vis[x]=1;
    for(auto i:edge[x])dfs1(i);
    s.push(x);
}

void dfs2(int p,int x){
    if(!vis[x])return;
    vis[x]=0;
    scc[p].pb(x);
    for(auto i:redge[x]){
        dfs2(p,i);
    }
}

int kosaraju(){
    FOR(i,1,n+1)dfs1(i);
    int p=0;
    while(s.size()){
        int x = s.front();
        s.pop();
        if(vis[x])dfs2(p++,x);
    }
    return p;
}

void solve(){
    cin>>n>>m;
    while(m--){
        int u,v;cin>>u>>v;
        edge[u].pb(v);
        redge[v].pb(u);
        indg[v]++;
    }
    queue<int> q;
    int k=1;
    FOR(i,1,n+1){
        if(!indg[i]){
            q.push(i);
            dp[i]=1;
            k=0;
        }
    }
    if(k)q.push(1);
    while(q.size()){
        int x = q.front();
        q.pop();
        for(auto it:edge[x]){
            if(!dp[it])q.push(it);
            dp[it] = max(dp[it], dp[x]+1);
        }
    }
    int ans=0;
    FOR(i,1,n+1)ans = max(dp[i],ans);
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

 
