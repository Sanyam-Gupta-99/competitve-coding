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
        this->n = n+1;
        bit.assign(n+1,0);
    }
    void createTree(vi arr){
        fr(i,0,arr.sz){
            add(i, arr[i]);
        }
    }
    void add(int index, int value){
        for(++index ; index < n; index += (index & (-index))){
            bit[index] += value;
        }
    }
    void range(int l,int r,int value){
        add(l, value);
        add(r+1,-value);
    }
    int sum(int index){
        int ret = 0;
        for(++index ; index > 0; index -= (index & (-index))){
            ret += bit[index];
        }
        return ret;
    }
    int point_query(int a){
        return sum(a);
    }
};

void solve(){
    vi arr = {0,0,0,0};
    FenwickTree fenwick(arr.sz);
    fenwick.createTree(arr);
    cout<<fenwick.point_query(0)<<" "<<fenwick.point_query(1)<<" "<<fenwick.point_query(2)<<" "<<fenwick.point_query(3)<<endl;
    // cout<<"f"<<endl;
    fenwick.range(0,1,1);
    cout<<fenwick.point_query(0)<<" "<<fenwick.point_query(1)<<" "<<fenwick.point_query(2)<<" "<<fenwick.point_query(3)<<endl;

    fenwick.range(0,2,2);
    cout<<fenwick.point_query(0)<<" "<<fenwick.point_query(1)<<" "<<fenwick.point_query(2)<<" "<<fenwick.point_query(3)<<endl;

    fenwick.range(0,3,3);
    cout<<fenwick.point_query(0)<<" "<<fenwick.point_query(1)<<" "<<fenwick.point_query(2)<<" "<<fenwick.point_query(3)<<endl;
    

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
