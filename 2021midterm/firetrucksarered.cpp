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
using vi = vector<int>;
using mii = map<int,int>;
using cd = complex<double>;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
const double PI   = acos(-1);
const int Mod     = 998244353;
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

int f[200000];

int find(int x){
    if(x == f[x])return x;
    return f[x] = find(f[x]);
}

void uni(int x, int y){
    int a = find(x), b = find(y);
    if(a!=b){
        f[b] = f[a];
        find(y);
    }
}

void solve(){
    int n;cin>>n;
    vector<int> a[n],c;
    set<int> s;
    map<int,int> mp;
    map<pii,int> ans;
    FOR(i,0,n){
        int m;cin>>m;
        a[i].resize(m);
        for(auto &it:a[i]){
            cin>>it;
            s.insert(it);
        }
    }
    int cnt=0;
    for(auto it:s){
        c.pb(it);
        mp[it]=cnt++;
    }
    vector<int> v[cnt];
    FOR(i,0,n){
        for(auto it:a[i])v[mp[it]].pb(i);
    }
    FOR(i,0,n)f[i]=i;
    FOR(i,0,cnt){
        int x=0;
        if(v[i].size())x=v[i][0];
        for(auto it:v[i]){
            int a = find(x), b = find(it);
            if(a!=b){
                f[b] = f[a];
                find(it);
                ans[{x,it}] = c[i];
            }
        }
    }
    for(int i=0;i<n;i++){
        if(find(i) != f[0]){
            cout<<"impossible"<<endl;
            return;
        }
    }
    //FOR(i,0,n)f[i]=i;
    for(auto it:ans){
        int x = it.F.F, y = it.F.S, z = it.S;
        cout<<x+1<<' '<<y+1<<' '<<z<<endl;
    }
}

int main(){
    INITIO()
    //int t;cin>>t;
    //for(int kase=1;kase<=t;kase++){
        //cout<<"Case #"<<kase<<": ";
        solve();
    //}
    return 0;
}

 
