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
#define FILE()      freopen("in.txt","r",stdin);//freopen("out.txt","w",stdout);
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
const int  Inf     = 1e9+7;
const int N       = 1e6+9;
const int dy[4] = {1, 0, -1,  0};
const int dx[4] = {0, 1,  0, -1};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll a, ll b){if( b==0 )return a;return gcd( b, a%b );}
ll lcm(ll a, ll b){return a * b / gcd(a, b);}
ll mul(ll a, ll b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}
// ----------------------------------------------------------------------------------------------------
int q,n,f[N], st[N];
ll cnt[N]={}, siz[N], tot=0, mx=0;
vector<pii> qey;
vector<ll> ans;

int find(int x){
    if(x == f[x]) return x;
    return f[x] = find(f[x]);
}

void unio(int x,int y){
    x = find(x);y = find(y);
    if(x != y){
        f[x] = y;
        cnt[y] += cnt[x];
        siz[y] += siz[x];
    }
}

void solve(){
    cin>>n>>q;
    FOR(i,0,n){
        cin>>cnt[i];
        st[i] = 1;
        siz[i] = 1;
        f[i] = i;
    }
    while(q--){
        string c;
        cin>>c;
        if(c == "D"){
            int v;cin>>v;
            st[v] = 0;
            qey.pb({0,v});
        }
        else if(c == "QM")qey.pb({1,0});
        else qey.pb({2,0});
    }
    
    ll sum=0, k=0;
    FOR(i,0,n){
        if(st[i]){
            sum += cnt[i];
            k++;
        }
        else {
            tot += sum * k;
            sum=0;
            k=0;
        }
    }
    tot += sum*k;

    FOR(i,1,n){
        if(st[i-1] && st[i])unio(i-1,i);
    }

    FOR(i,0,n){
        if(st[i])mx = max(mx, cnt[i] * siz[i]);
    }

    reverse(all(qey));
    vector<ll> ans;
    for(auto [ty, x]: qey){
        if(ty == 0){
            if(x+1 < n && st[x+1]){
                int g= find(x+1);
                tot -= cnt[g] * siz[g];
                unio(x+1, x);
            }
            if(x-1 >=0 && st[x-1]){
                int g= find(x-1);
                tot -= cnt[g] * siz[g];
                unio(x-1, x);
            }
            st[x]=1;
            int fr = find(x);
            tot += cnt[fr] * siz[fr];
            mx = max(mx ,cnt[fr] * siz[fr]);
        }
        else if(ty == 1){
            ans.pb(mx);
        }
        else {
            ans.pb(tot);
        }
    }
    reverse(all(ans));
    for(auto x:ans)cout<<x<<endl;
}

int main(){
    INITIO()
    //FILE()
    //int t;cin>>t;
    //while(t--){
        solve();
    //}
    return 0;
}
