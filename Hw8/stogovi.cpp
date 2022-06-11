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
const int N       = 3e5+9;
//const int dx[4] = {0, 1,  0, -1};
//const int dy[4] = {1, 0, -1,  0};
//const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
//const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll a, ll b){if( b==0 )return a;return gcd( b, a%b );}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
int mul(int a, int b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}
//----------------------------------------------------------------------------------------------------
vector<int> e[N];
int n,m,dep[N]={},siz[N]={},p[20][N]={},f[N]={};

void dfs(int x){
    siz[x] = 1;
    for(auto it:e[x]){
        dep[it] = dep[x] + 1;
        dfs(it);
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

void prelca(){
    dfs(0);
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            p[i][j] = p[i-1][p[i-1][j]];
        }
    }
}

int find(int x){
    if(x == f[x])return x;
    return f[x] = find(f[x]);
}

void solve(){
    cin>>n;
    FOR(i,1,n+1)f[i]=i;
    vector<pii> ans;
    FOR(i,1,n+1){
        char c;
        cin>>c;
        int v,w;
        if(c=='a'){
            cin>>v;
            v = find(v);
            p[0][i] = v;
            e[v].pb(i);
        }
        else if(c=='b'){
            cin>>v;
            v = find(v);
            f[i] = p[0][v];
            ans.pb({v,-1});
        }
        else {
            cin>>v>>w;
            v = find(v);
            w = find(w);
            f[i] = v;
            ans.pb({v,w});
        }
    }
    prelca();
    for(auto [v,w]:ans){
        if(w == -1){
            cout<<v<<endl;
        }
        else{
            int x = lca(v,w);
            cout<<dep[x]<<endl;
        }
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
