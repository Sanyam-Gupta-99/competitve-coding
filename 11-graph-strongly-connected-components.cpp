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

vector<vector<int>> adj, adj_rev;
vector<bool> used;
vector<int> order, component;

vector<int> roots(n, 0);
vector<int> root_nodes;
vector<vector<int>> adj_scc(n);

void dfs(int node){
    used[node] = true;

    for(auto child : adj[node]){
        if(!used[child]){
            dfs(child);
        }
    }
    order.push_back(node);
}

void dfs_graph(){
    used.assign(adj.sz,false);
    fr(i,0,adj.sz){
        if(!used[i]){
            dfs(i);
        }
    }
}

void dfs_rev(int node){
    component.pb(node);
    used[node] = true;
    for(auto child : adj_rev[node]){
        if(!used[child]){
            dfs_rev(child);
        }
    }
}

void calc_strongly(){
    reverse(all(order));
    used.assign(adj.sz,false);
    for(auto node : order){
        if(!used[node]){
            dfs_rev(node);

            int root = component.front();
            for(auto u : component){
                roots[u] = root;
            }
            root_nodes.pb(root);
            component.clear();
        }
    }
    fr(v,0,n){
        for(auto u : adj[v]){
            int root_v = roots[v];
            int root_u = roots[u];

            if(root_u != root_v){
                adj_scc[root_v].push_back(root_u);
            }
        }
    }
}

void read_graph(){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
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
