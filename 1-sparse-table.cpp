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

struct SparseTable{
    int n;
    int k;
    vvi st;
    
    SparseTable(int n, int k){
        this->n = n;
        this->k = k;
        st.assign(n,vi(k+1,0));
    }
    void create_table(vi arr){
        fr(i,0,n){
            st[i][0] = arr[i];
        }
        fr(j,1,k+1){
            for(int i = 0; i+(1<<j)-1 < n; i++){
                // for max range query type;
                st[i][j] = st[i][j-1] + st[i+(1<<(j-1))][j-1];
            }
        }
    }
    int query(int l, int r){
        int ret = 0;
        rfr(i,k,0){
            if(r-l+1 >= (1<<i)){
                ret += st[l][i];
                l += (1<<i);
            }
        }
        return ret;
    }
};

void solve(){
    vi arr = {1,1,1};
    SparseTable st(3,log2(3));
    st.create_table(arr);
    cout<<st.query(0,2)<<" "<<st.query(0,1)<<" "<<st.query(0,0);
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
