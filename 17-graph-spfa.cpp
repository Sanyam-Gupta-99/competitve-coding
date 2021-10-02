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
#define INF2 1e9
#define LINF LONG_LONG_MAX  
#define mp make_pair
#define endl "\n"
#define sz  size()
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<vector<pair<int, int>>> adj;
vll dist;
int n;

void spfa(int source){
    dist.assign(n,INF);
    vb inqueue(n,false);
    vi cnt(n,0);
    queue<int> q;
    dist[source] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        inqueue[node] = false;

        for(auto edge : adj[node]){
            if(dist[node] != INF && dist[node] + edge.ss < dist[edge.ff]){
                dist[edge.ff] = max((ll)INT_MIN,dist[node] + edge.ss);
                if(!inqueue[edge.ff]){
                    q.push(edge.ff);
                    inqueue[edge.ff] = true;
                    cnt[edge.ff]++;

                    if(cnt[edge.ff] >= n){
                        cout<<"Negative cycle found"<<endl;
                        return;
                    }
                }
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
