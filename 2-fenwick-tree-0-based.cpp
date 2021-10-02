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
    int n;
    vi bit;
    FenwickTree(int n){
        this->n = n;
        bit.assign(n,0);
    }
    void createTree(vi arr){
        fr(i,0,arr.sz){
            add(i, arr[i]);
        }
    }
    void add(int index, int value){
        for(; index < n; index = index|(index+1)){
            bit[index] += value;
        }
    }
    int sum(int index){
        int ret = 0;
        for(; index >= 0; index = (index&(index+1)) - 1){
            ret += bit[index];
        }
        return ret;
    }
    int query(int a,int b){
        return sum(b) - sum(a-1);
    }
};

void solve(){
    vi arr = {1,2,3,4};
    FenwickTree fenwick(arr.sz);
    fenwick.createTree(arr);
    // cout<<"f"<<endl;
    cout<<fenwick.query(0,2)<<" "<<fenwick.query(0,3)<<" "<<fenwick.query(0,0);
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
