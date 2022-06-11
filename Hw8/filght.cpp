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

int n,vis[2505],dis[2505], siz[2505], h1[2505], h2[2505],c1[2505],c2[2505],p[2505];
vector<int> edge[2505];

pii treedia(int x){
    for(int i=1;i<=n;i++){
        vis[i]=0;
        dis[i]=0;
    }
    queue<int> q;
    q.push(x);
    while(q.size()){
        int top = q.front();
        q.pop();
        vis[top]=1;
        for(auto it:edge[top]){
            if(!vis[it]){
                dis[it] = dis[top]+1;
                q.push(it);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(dis[x] < dis[i])x = i;
    }
    for(int i=1;i<=n;i++){
        vis[i]=0;
        dis[i]=0;
    }
    q.push(x);
    while(q.size()){
        int top = q.front();
        q.pop();
        vis[top]=1;
        for(auto it:edge[top]){
            if(!vis[it]){
                dis[it] = dis[top]+1;
                q.push(it);
            }
        }
    }
    int id=0;
    for(int i=1;i<=n;i++){
        if(dis[id] < dis[i])id=i;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(dis[i] == dis[id]/2 + (dis[id]%2?1:0))ans = i;
    }
    if(dis[id] == 0)ans = x;
    return {ans, id};
}

void record(int x, int height, int child)
{
    if (height > h1[x])
    {
        h2[x] = h1[x]; c2[x] = c1[x];
        h1[x] = height; c1[x] = child;
    }
    else if (height > h2[x])
    {
        h2[x] = height; c2[x] = child;
    }
}

void dfs1(int x){
    h1[x] = h2[x] = 0;
    for(auto it:edge[x]){
        if(p[x] != it){
            p[it] = x;
            dfs1(it);
            record(x,h1[it]+1,it);
        }
    }
}

void dfs2(int x){
    if(p[x] != x){
        int y = p[x];
        if(c1[y] == x)record(x,h2[y]+1,y);
        else record(x,h1[y]+1,y);
    }
    for(auto it:edge[x]){
        if(it != p[x]){
            dfs2(it);
        }
    }
}

int treecentroid(int x){
    int ans=x;
    FOR(i,1,n+1) h1[i] = h2[i] = c1[i] = c2[i] = p[i] = 0;
    p[x] = x;
    dfs1(x);
    dfs2(x);
    for(int i=1;i<=n;i++){
        //cout<<h1[i]<<' ';
        if(h1[i] && h1[i] < h1[ans]){
            ans = i;
        }
    }
    //cout<<endl;
    return ans;
}

void solve(){
    cin>>n;
    vector<pii> ed;
    FOR(i,0,n-1){
        int u,v;cin>>u>>v;
        edge[u].pb(v);
        edge[v].pb(u);
        ed.pb({u,v});
    }
    int ans=1e9+5, a[4]={};
    for(auto [u,v]:ed){
        for(auto it = edge[u].begin();it!=edge[u].end();it++){
            if(*it == v){
                edge[u].erase(it);
                break;
            }
        }
        for(auto it = edge[v].begin();it!=edge[v].end();it++){
            if(*it == u){
                edge[v].erase(it);
                break;
            }
        }
        int k = treecentroid(u);
        int j = treecentroid(v);
        //cout<<k<<' '<<j<<endl;
        edge[k].pb(j);
        edge[j].pb(k);
        int y = treedia(u).second;
        if(ans > dis[y]){
            ans = dis[y];
            a[0] = u;
            a[1] = v;
            a[2] = k;
            a[3] = j;
        }
        for(auto it = edge[k].begin();it!=edge[k].end();it++){
            if(*it == j){
                edge[k].erase(it);
                break;
            }
        }
        for(auto it = edge[j].begin();it!=edge[j].end();it++){
            if(*it == k){
                edge[j].erase(it);
                break;
            }
        }
        edge[u].pb(v);
        edge[v].pb(u);
    }
    cout<<ans<<endl;
    cout<<a[0]<<' '<<a[1]<<endl;
    cout<<a[2]<<' '<<a[3]<<endl;
}

int main(){
    INITIO()
    //int t;cin>>t;
    //while(t--){
        solve();
    //}
    return 0;
}
