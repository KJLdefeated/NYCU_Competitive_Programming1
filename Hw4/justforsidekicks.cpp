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
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}
// ----------------------------------------------------------------------------------------------------

struct BIT{
    vector<ll> v;
    void modify(int x,int p){
        for(;x<v.size();x+=(x&-x))v[x]+=p;
    }
    ll query(int l,int r){
        ll a=0,b=0;
        for(;r;r-=(r&-r))a+=v[r];
        for(;l;l-=(l&-l))b+=v[l];
        return a-b;
    }
};

void solve(){
    vector<ll> v(6);
    string s;
    int n,q;
    cin>>n>>q;
    BIT t[6];
    FOR(i,0,6){
        cin>>v[i];
        t[i].v.resize(n+1,0);
    }
    cin>>s;
    for(int i=0;i<n;i++){
        int x=int(s[i]-'0')-1;
        t[x].modify(i+1, 1);
    }
    while(q--){
        int b,k,p;cin>>b;
        if(b==1){
            cin>>k>>p;
            int ori=int(s[k-1]-'0')-1;
            s[k-1]=char(p+'0');
            t[ori].modify(k,-1);
            t[p-1].modify(k, 1);
        }
        if(b==2){
            cin>>k>>p;
            v[k-1]=p;
        }
        if(b==3){
            cin>>k>>p;
            ll ans=0;
            for(int i=0;i<6;i++)ans += v[i] * t[i].query(k-1, p);
            cout<<ans<<endl;
        }
    }
}

int main(){
    INITIO()
    //int t;cin>>t;
    //for(int kase=1;kase<=t;kase++){
        solve();
    //}
    return 0;
}
