#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define sz(a) a.size()
#define all(a) (a.begin(),a.end())
const double PI = acos(-1);
using cd = complex<double>;

void fft(vector<cd> &a, bool invert){
    int n = sz(a);
    if(n==1) return;
    vector<cd> a0(n/2), a1(n/2);
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
        a[i+n/2] = a0[i] - w*a1[i];
        if(invert){
            a[i]/=2;
            a[i+n/2]/=2;
        }
        w*=wn;
    }
}

vector<int> multiply(const vector<int>&a, const vector<int>&b){
    vector<cd> fa(a.begin(),a.end()), fb(b.begin(),b.end());
    int n = 1;
    while(n<sz(a) + sz(b))n<<=1;
    fa.resize(n);
    fb.resize(n);
    fft(fa,false);
    fft(fb,false);
    for(int i=0;i<n;i++)fa[i] *= fb[i];
    fft(fa,true);
    vector<int> res(n);
    for(int i=0;i<n;i++)res[i] = round(fa[i].real());
    return res;
}

int main(){
    int n;cin>>n;
    vector<int> a(n),b(n,1);
    FOR(i,0,n)cin>>a[i];
    vector<int> res = multiply(a,b);
    for(auto it:res)cout<<it<<' ';
    return 0;
}