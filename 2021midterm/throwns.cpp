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
using vii = vector<vector<int>>;
using vi = vector<int>;
using mii = map<int,int>;
using cd = complex<double>;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
const double PI   = acos(-1);
const ll  Inf     = 2e18+9;
const int Mod     = 998244353;
const int N       = 1e5+9;
const int dx[4] = {0, 1,  0, -1};
const int dy[4] = {1, 0, -1,  0};
const int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
ll gcd(ll a, ll b){if( b==0 )return a;return gcd( b, a%b );}
ll lcm(ll a,ll b){return a * b / gcd(a, b);}
int mul(int a, int b) {return (1LL * a * b) % Mod;}
ll add(ll a, ll b) {a += b;if (a >= Mod) a -= Mod;if (a < 0) a += Mod;return a;}
ll sub(ll a, ll b) {return (a - b) % Mod + ((a >= b) ? 0 : Mod);}
// ----------------------------------------------------------------------------------------------------

void solve(){
    int n,m;cin>>n>>m;
    int ans=0, cnt=0,cur=0, vis[35]={};
    stack<int> st;st.push(0);
    while(m--){
        string s;
        cin>>s;
        if(s == "undo"){
            cin>>cnt;
            while(cnt--)st.pop();
            cur = st.top();
        }
        else {
            int p = 0, neg=0;
            if(s[0]=='-'){
                s.erase(s.begin());
                neg=1;
            }
            reverse(all(s));
            for(int i=0, k=1;i<sz(s);i++, k*=10){
                p += k*(s[i] - '0');
            }
            if(neg)p*=-1;
            while(p+cur < 0)p+=n;
            cur = (p+cur)%n;
            st.push(cur);
            if(!vis[cur]){
                vis[cur]=1;
                ans++;
            }
            
        }
    }
    cout<<cur<<endl;
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

 
