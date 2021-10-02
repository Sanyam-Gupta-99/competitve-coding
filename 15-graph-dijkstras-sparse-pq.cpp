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
vector<ll> dist;
vector<int> parent;
int n;

bool compare(pair<ll,int>a ,pair<ll,int> b){
    return true;
}

struct ccompare{
    bool operator()(pair<ll,int>& a, pair<ll,int>& b){
        return true;
    }
};

void dijkstras(int source){
    dist[source] = 0LL;

    priority_queue <pair<ll,int>, vector<pair<ll,int>>, ccompare > pq;
    // priority_queue <pair<ll,int>, vector<pair<ll,int>>, decltype(&compare) > pq;
    pq.push(mp(dist[source],source));

    while(!pq.empty()){
        auto edge = pq.top();
        pq.pop();

        if(edge.ff != dist[edge.ss]){
            continue;
        }

        for(auto child : adj[edge.ss]){
            if(dist[edge.ss] + child.ss < dist[child.ff]){
                parent[child.ff] = edge.ss;
                dist[child.ff] = dist[edge.ss] + child.ss;
                pq.push({dist[child.ff],child.ff});
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
