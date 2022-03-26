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
    vector<ll> t;
    void modify(int id,ll val){
        for(;id<t.size();id+=(id&-id))t[id]+=val;
    }
    ll query(int x){
        ll ans=0;
        for(;x;x-=(x&-x))ans+=t[x];
        return ans;
    }
};

void solve(){
    int n,m;cin>>n>>m;
    BIT tree;
    tree.t.resize(n+2,0);
    while(m--){
        char c;cin>>c;
        int i, val;
        if(c=='+'){
            cin>>i>>val;
            tree.modify(i+1,val);
        }
        if(c=='?'){
            cin>>i;
            cout<<tree.query(i)<<endl;
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
