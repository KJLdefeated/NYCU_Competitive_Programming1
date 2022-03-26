#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <stdio.h>
#include <list>
#include <string.h>
#include <sstream>
using namespace std;
#define INITIO()    ios_base::sync_with_stdio(false);cin.tie(NULL);
#define FILE        freopen("a.in","r",stdin);freopen("out.txt","w",stdout);
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define pf          push_front
#define eb          emplace_back
#define all(a)      a.begin(),a.end()
#define rall(a)      a.rbegin(),a.rend()
#define sz(a)       (int)a.size()
#define FOR(i,a,b)  for(int i = (a); i < (b); i++)
#define vii         vector<vector<int>>;
#define vi          vector<int>;
#define mii         map<int,int>;
#define ever        ;;
typedef                long long ll;
typedef                unsigned long long ull;
typedef                pair<int,int> pii;
typedef                pair<long,long> pll;
const ll  Inf     = 2e18+9;
const int Mod     = 1e9+7;
const int N       = 1e5+9;
const int dx[4] = {0, 1,  0, -1};
const int dy[4] = {1, 0, -1,  0};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll a, ll b){if( b==0 )return a;return gcd( b, a%b );}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
ll mul(ll a, ll b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}
// ----------------------------------------------------------------------------------------------------
int n,m,t,st,ed,k;
struct Edge{
    int v;ll w;
    bool operator<(const Edge &cmp) const {
        return cmp.w < w;
    }
};

vector<Edge> g[100005];
ll dis[100005],spiderdis[100005];

bool check(ll val){
    if(spiderdis[st] < val)return 0;
    if(spiderdis[ed] < val)return 0;
    FOR(i,0,n)dis[i]=Inf;
    priority_queue<Edge> pq;
    pq.push({st,0});
    while(pq.size()){
        auto node = pq.top(); pq.pop();
        if(dis[node.v] <= node.w)continue;
        dis[node.v] = node.w;
        for(auto it:g[node.v]){
            if(spiderdis[it.v] >= val && dis[it.v] > it.w + node.w){
                pq.push({it.v, it.w + node.w});
            }
        }
    }
    //FOR(i,0,n)cout<<dis[i]<<endl;
    return dis[ed] <= t;
}

void solve(){
    cin>>n>>m>>t;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    cin>>st>>ed;
    cin>>k;
    priority_queue<Edge> pq;
    while(k--){
        int x;cin>>x;
        pq.push({x,0});
    }
    FOR(i,0,n)spiderdis[i]=Inf;
    while(pq.size()){
        auto node = pq.top(); pq.pop();
        if(spiderdis[node.v] <= node.w)continue;
        spiderdis[node.v] = node.w;
        for(auto it:g[node.v]){
            if(spiderdis[it.v] > it.w + node.w){
                pq.push({it.v,it.w + node.w});
            }
        }
    }
    ll ans=0,step= 1;
    FOR(i,0,62)step*=2;
    while(step > 0){
        if(check(ans+step)) ans += step;
        step=(step>>1);
    }
    cout<<ans<<endl;
}

int main(){
    INITIO()
    //int t;cin>>t;
    //for(int kase=1;kase<=t;kase++){
        solve();
    //}
    return 0;
}
