#include<bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
  
// #define ordered_set tree<pi, null_type,less<pi>, rb_tree_tag,tree_order_statistics_node_update> 

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

int n;
// adj is matrix and stores the dist
vector<vector<int>> adj; // adjacency matrix of graph

struct Edge {
    int w = INF, to = -1;
};

void primsdense(int source = 0){
    int tot_w = 0;
    vb selected(n, false);
    vector<Edge> min_e(n);
    min_e[source].w = 0;
    fr(i,0,n){
        int v = -1;
        fr(j,0,n){
            if((!selected[j]) &&(v == -1 || min_e[j].w < min_e[v].w)){
                v = j;
            }
        }
        if(min_e[v].w == INF){
            cout<<"no MST"<<endl;
            return;
        }
        selected[v] = true;
        tot_w += min_e[v].w;

        if(min_e[v].to != -1){
            cout<<v<<" "<<min_e[v].to<<endl;
        }

        fr(i,0,n){
            if(adj[v][i] < min_e[i].w){
                min_e[i].to = v;
                min_e[i].w = adj[v][i];
            }
        }
    }
    cout<<tot_w<<endl;
}

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
