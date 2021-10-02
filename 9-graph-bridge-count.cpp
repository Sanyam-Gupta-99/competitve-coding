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

int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void is_bridge(int a,int b){
    cout<<"Node "<<a<<" to "<<b<<" is a bridge"<<endl;
}

void dfs(int node,int parent = -1){
    tin[node] = low[node] = timer++;
    visited[node] = true;
    for(auto child : adj[node]){
        if(child == parent){
            continue;
        }
        if(visited[child]){
            low[node] = min(low[node],tin[child]);
        }
        else{
            dfs(child, node);
            low[node] = min(low[node],low[child]);
            if(tin[node] < low[child]){
                is_bridge(node, child);
            }
        }  
    }
}

void find_bridge(){
    timer = 0;
    visited.assign(n,false);
    tin.assign(n,-1);
    low.assign(n,-1);
    fr(i,0,n){
        if(!visited[i]){
            dfs(i);
        }
    }
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
