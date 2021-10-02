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
    int N;
    vll bit1,bit2;
    FenwickTree(int n){
        this->N = n+1;  // execution for 1 based fenwick tree
        // this->N = n; // execution for 0 based fenwick tree
        bit1.assign(N,0);
        bit2.assign(N,0);
    }
    void add_range(int l, int r, int x){
        add(bit1,l,x);
        add(bit1,r+1,-x);
        add(bit2,l,x*(l-1));
        add(bit2,r+1,-x*r);
    }
    void add(vll& bit, int index, int value){
        for(index++; index < N; index += index&-index){ // execution for 1 based fenwick tree
        // for(; index < N; index = index|(index+1)){   // execution for 0 based fenwick tree
            bit[index] += (ll)value;
        }
    }
    ll sum(vll& bit, int index){
        ll res = 0;
        for(index++; index > 0; index -= index&-index){ // execution for 1 based fenwick tree
        // for(; index >= 0; index = (index&(index+1))-1){  // execution for 0 based fenwick tree
            res += bit[index];
        }
        return res;
    }
    ll pref_query(int index){
        return sum(bit1,index) * (index) - sum(bit2,index);
    }
    ll query_range(int l,int r){
        return pref_query(r) - pref_query(l-1); 
    }
};

void solve(){
    // cout<<"Execution starts"<<endl;
    FenwickTree bit(4);
    bit.add_range(0,2,1);
    bit.add_range(1,3,1);
    bit.add_range(2,3,1);
    // bit.add_range(3,3,1);
    // bit.add_range(0,3,1);
    cout<<"New values"<<endl;
    cout<<bit.query_range(0,0)<<endl;
    cout<<bit.query_range(0,1)<<endl;
    cout<<bit.query_range(0,2)<<endl;
    cout<<bit.query_range(0,3)<<endl;
    cout<<bit.query_range(0,3)<<endl;
    cout<<bit.query_range(1,3)<<endl;
    cout<<bit.query_range(2,3)<<endl;
    cout<<bit.query_range(3,3)<<endl;

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
