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
typedef                long long ll;
typedef                unsigned long long ull;
typedef                pair<int,int> pii;
typedef                pair<long,long> pll;
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
void fft(vector<cd> &a, bool invert){
    int n = sz(a);
    if(n == 1)return;
    vector<cd> a0(n/2),a1(n/2);
    for(int i=0;i*2<n;i++){
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);
    double ang = 2 * PI / n * (invert?-1:1);
    cd w(1), wn(cos(ang), sin(ang));
    for(int i=0;i*2<n;i++){
        a[i] = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
        if(invert){
            a[i] /= 2;
            a[i+n/2] /= 2;
        }
        w *= wn;
    }
}

vi multiply(const vi &a,const vi &b){
    vector<cd> fa(a.begin(),a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < sz(a) + sz(b))n<<=1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for(int i=0;i<n;i++)fa[i] *= fb[i];
    fft(fa, true);
    vector<int> result(n);
    for(int i=0;i<n;i++)result[i] = round(fa[i].real());
    return result;
}

void solve(){
    string s;
    cin>>s;
    vector<int> a(sz(s),0), b(sz(s),0);
    FOR(i,0,sz(s)){
        if(s[i] == 'A') a[i]=1;
        else b[sz(s)-i-1]=1;
    }
    vi ans = multiply(a, b);
    for(int i=sz(s);i<2*sz(s)-1;i++)cout<<ans[i]<<endl;
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

 
