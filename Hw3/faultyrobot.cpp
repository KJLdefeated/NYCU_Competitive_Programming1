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
#define sz(a)       (int)a.size()
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
int sub(int a, int b) {return (a - b) % 6 + ((a >= b) ? 0 : 6);}
// ----------------------------------------------------------------------------------------------------
int n,m,vis[1005],ans[1005]={};
vector<pii> edge[10005];

void dfs(int x,int cnt){
    int p=1;
    for(auto [u,v]:edge[x]){
        if(v)p=0;
        if(!vis[u]){
            if(v){
                vis[u]=1;
                dfs(u,cnt);
                vis[u]=0;
            }
            else if(!cnt){
                vis[u]=1;
                dfs(u,1);
                vis[u]=0;
            }
        }
    }
    if(p){
        ans[x]=1;
    }
}

void solve(){
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        if(u>0){
            edge[u].pb({v,0});
        }
        else{
            u=-u;
            edge[u].pb({v,1});
        }
    }
    FOR(i,1,n+1)vis[i]=0;
    vis[1]=1;
    dfs(1,0);
    int an=0;
    FOR(i,1,n+1)an+=ans[i];
    cout<<an<<endl;
}

int main(){
    INITIO()
    //int t;
    //while(t--){
        solve();
    //}
    return 0;
}
