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

class SegmentTree{
    vi tree;
    int n;
public :
    SegmentTree(int n){
        this->n = 4*n;
        tree.assign(4*n,0);
    }
    int combine_tree(int a,int b){
        return a+b;
    }
    void create_tree(vi& arr, int ver, int t_l, int t_r){
        if(t_l == t_r){
            tree[ver] = arr[t_l];
        }
        else{
            int t_m = (t_l + t_r)>>1;
            create_tree(arr,2*ver,t_l,t_m);
            create_tree(arr,2*ver + 1,t_m+1,t_r);
            tree[ver] = combine_tree(tree[2*ver],tree[2*ver+1]);
        }
    }
    int calc_sum(int l,int r,int ver,int t_l,int t_r){
        if(l > r){
            return 0;
        }
        if(t_l == l && t_r == r){
            return tree[ver];
        }
        else{
            int t_m = (t_l+t_r)>>1;
            return combine_tree(calc_sum(l,min(r,t_m),2*ver,t_l,t_m), calc_sum(max(t_m+1,l),r,2*ver+1,t_m+1,t_r));
        }
    }

    void update(int pos,int new_val,int ver,int t_l,int t_r){
        if(t_l == t_r){
            tree[ver] = new_val;
        }
        else{
            int t_m = (t_l+t_r)>>1;
            if(pos <= t_m){
                update(pos,new_val,2*ver,t_l,t_m);
            }
            else{
                update(pos,new_val,2*ver+1,t_m+1,t_r);
            }
            tree[ver] = combine_tree(tree[2*ver], tree[2*ver+1]);
        }
    }
};

void solve(){
    vi arr = {1,2,3,4,5,6};
    SegmentTree t(arr.sz);
    t.create_tree(arr,1,0,arr.sz-1);
    cout<<t.calc_sum(0,5,1,0,arr.sz-1)<<endl;
    cout<<t.calc_sum(0,4,1,0,arr.sz-1)<<endl;
    cout<<t.calc_sum(0,3,1,0,arr.sz-1)<<endl;
    
    t.update(4,10,1,0,arr.sz-1);
    
    cout<<t.calc_sum(0,5,1,0,arr.sz-1)<<endl;
    cout<<t.calc_sum(0,4,1,0,arr.sz-1)<<endl;
    cout<<t.calc_sum(0,3,1,0,arr.sz-1)<<endl;
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
