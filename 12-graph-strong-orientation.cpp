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

vector<vector<pair<int, int>>> adj; // adjacency list - vertex and edge pairs
vector<pair<int, int>> edges;

vector<int> tin, low;
int bridge_cnt, comp_cnt;
string orient;
vector<bool> edge_used;
int timer = 0;
int n,m;

void is_bridge(int a, int b){
    cout<<"Edge "<<a<<" to "<<b<<" is a bridge!!"<<endl;
    return ;
}

void storng_orient(int node){
    tin[node] = low[node] = timer++;

    for(auto edge : adj[node]){
        if(edge_used[edge.ss]){
            continue;
        }

        edge_used[edge.ss] = true;
        orient[edge.ss] = node == edges[edge.ss].ff?'>':'<';

        int new_node = edge.ff;

        if(tin[new_node] == -1){
            storng_orient(new_node);
            low[node] = min(low[node],low[new_node]);
            if(tin[node] < low[new_node]){
                is_bridge(node,new_node);
                bridge_cnt++;
            }
        }
        else{
            low[node] = min(low[node],tin[new_node]);
        }
    }
}

void find_components(){
    fr(node,0,n){
        if(tin[node] == -1){
            storng_orient(node);
            comp_cnt++;
        }
    }
}

void read_graph(){
    adj.resize(n);
    edges.resize(m);
    tin.resize(n, -1);
    low.resize(n, -1);
    edge_used.resize(m,false);

    fr(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].pb({b,i});
        adj[b].pb({a,i});
        edges[i] = {a,b};
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
