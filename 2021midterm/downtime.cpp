#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
#ifdef DEBUG
#else
#define deb(...)
#define debit(...)
#define INITIO()
#endif
#define MEM(i,j) memset(i,j,sizeof i);
#define endl        '\n'
#define F           first
#define S           second
#define pb          push_back
#define pf          push_front
#define eb          emplace_back
#define all(a)      a.begin(),a.end()
#define sz(a) (int)a.size()
#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define vii         vector<vector<int>>;
#define vi          vector<int>;
#define mii         map<int,int>;
typedef                long long ll;
typedef                unsigned long long ull;
typedef                pair<int,int> pii;
const double Eps  = 1e-8;
const int Inf     = 1e9+9;
const int Mod     = 1e9+9;
const int N       = 1e6+9;
const int dx4[4] = {0, 1, 0, -1};
const int dy4[4] = {-1, 0, 1, 0};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll x, ll y){if( y==0 )return x;return gcd( y, x%y );}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
ll mul(ll a, ll b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}

// -----------------------------------------------------------------------------------------------------

void solve(){
    int n,k;cin>>n>>k;
    int cnt=0,cmt=0;
    vector<int> a(n+1,-1);FOR(i,0,n)cin>>a[i];
    map<int,int> mp;
    for(int i=0,j=0;i<=101100 && j<n;i++){
        if(mp[i] > 0){cmt-=mp[i];mp[i]=0;}
        while(a[j]==i){
            mp[a[j]+1000]++;
            cmt++;
            j++;
        }
        cnt=max(cmt/k + (cmt%k?1:0),cnt);
    }
    cout<<cnt<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    //freopen("a.in","r",stdin);freopen("out.txt","w",stdout);
    //int t;cin>>t;
    //while(t--){
        solve();
    //}
    return 0;
}
