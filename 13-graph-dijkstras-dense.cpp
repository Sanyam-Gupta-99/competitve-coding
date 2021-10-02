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

vector<vector<pair<int, int>>> adj;
vector<int> dist;
vector<int> parent;
vector<bool> visited;
int n;


void dijkstras(int source){
    dist.assign(n,INF);
    visited.assign(n,false);
    parent.assign(n,-1);
    dist[source] = 0;
    fr(i,0,n){
        int node = -1;
        fr(j,0,n){
            if(node == -1 || dist[j]< dist[node]){
                node = j;
            }
        }
        if(dist[node] == INF){
            break;
        }
        visited[node] = true;
        for(auto child : adj[node]){
            if(dist[node] + child.ss < dist[child.ff]){
                dist[child.ff] = dist[node] + child.ss;
                parent[child.ff] = node;
            }
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
