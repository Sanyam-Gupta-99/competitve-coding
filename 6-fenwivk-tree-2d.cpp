#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned ll
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vd vector<double>
#define vs vector<string>
#define vvi vector<vi>
#define vvll vector<vll>
#define ff first
#define ss second
#define pb push_back
#define vpi vector<pi>
#define vpll vector<pll>
#define umap unordered_map
#define uset unordered_set
#define all(x) x.begin(),x.end()
#define fr(i,j,n) for(int i=j;i<n;++i)
#define rfr(i,j,n) for(int i=j; i>=n;--i)
#define MOD 1000000007
#define INF INT_MAX
#define LINF LONG_LONG_MAX  
#define mp make_pair
#define endl "\n"
#define sz  size()
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
struct FenwickTree{
    int n,m;
    vvll bit;
    FenwickTree(int n, int m){
        this->n = n+1;
        this->m = m+1;
        bit.assign(n+1,vll(m+1,0));
    }
    void create_tree(vvi arr){
        fr(i,0,n-1){
            fr(j,0,m-1){
                add(i,j,arr[i][j]);
            }
        }
    }
    void add(int x, int y, int val){
        for(int xind = x+1; xind < n; xind += xind&-xind)
            for(int yind = y+1; yind < m; yind += yind&-yind)
                bit[xind][yind]+=(ll)val;
    }
    ll sum(int x, int y){
        ll ret = 0;
        for(int xind = x+1; xind > 0; xind -= xind&-xind)
            for(int yind = y+1; yind > 0; yind -= yind&-yind)
                ret += (ll)bit[xind][yind];
        return ret;
    }
    ll sum(int l1, int r1, int l2, int r2){
        return sum(l2,r2) - sum(l2,r1-1) - sum(l1-1,r2) + sum(l1-1, r1-1);
    }
};
void solve(){

}

void pre() {
    int t = 1;
    // cin>>t;
    fr(i,0,t){
        // cout<<"Case #"<<i+1<<": ";
        solve();
        // cout<<solve()<<endl;
    }
}

int main() {
	fastIO; 
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	pre();
	return 0; 
	
}
