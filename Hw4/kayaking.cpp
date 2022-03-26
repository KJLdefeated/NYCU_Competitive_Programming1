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
int b,n,e,sb,sn,se;
vector<pair<ll,string>> speeds;

void dec(string s,int &tb,int &tn,int &te){
    for(auto i:s){
        if(i=='b')tb--;
        if(i=='n')tn--;
        if(i=='e')te--;
    }
}

bool ok(string s,int tb,int tn,int te){
    dec(s,tb,tn,te);
    return (tb>=0)&&(tn>=0)&&(te>=0);
}

bool check(vector<ll> a,ll speed){
    int tb=b,tn=n,te=e;
    bool work=true;
    for(auto i:a){
        bool thiswork=0;
        for(auto j:speeds){
            if(i*j.F >= speed && ok(j.S,tb,tn,te)){
                dec(j.S,tb,tn,te);
                thiswork=1;
                break;
            }
        }
        if(!thiswork){
            work=0;
            break;
        }
    }
    return work;
}

void solve(){
    cin>>b>>n>>e>>sb>>sn>>se;
    vector<ll> a((b+n+e)/2);
    for(auto &it:a)cin>>it;
    sort(rall(a));
    speeds.pb({sb+sb,"bb"});
    speeds.pb({sb+sn,"bn"});
    speeds.pb({sb+se,"be"});
    speeds.pb({sn+sn,"nn"});
    speeds.pb({sn+se,"ne"});
    speeds.pb({se+se,"ee"});
    sort(all(speeds));
    
    ll l=0,r=1e15;
    while(l+1<r){
        ll mid=l+(r-l)/2;
        if(check(a,mid))l=mid;
        else r=mid;
    }
    cout<<l<<endl;
}

int main(){
    INITIO()
    //int t;cin>>t;
    //for(int kase=1;kase<=t;kase++){
        solve();
    //}
    return 0;
}
