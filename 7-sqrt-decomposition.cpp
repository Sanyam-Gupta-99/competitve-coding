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
struct SQRT{
    int n;
    int len;
    vi sqrt_arr;

    SQRT(int n){
        this->n = n;
        this->len = (int)sqrt(n+0.0) + 1;
        sqrt_arr.assign(len,0);
    }
    void create(vi& arr){
        fr(i,0,n){
            sqrt_arr[i/len] += arr[i];
        }
    }
    ll query(int l , int r, vi& arr){
        ll sum = 0;
        int c_l = l/len, c_r = r/len;
        if(c_l == c_r){
            fr(i,l,r+1){
                sum += arr[i];
            }
        }
        else{
            fr(i,l,(c_l+1)*len){
                sum += arr[i];
            }
            fr(i,c_l+1,c_r){
                sum += sqrt_arr[i];
            }
            fr(i,c_r*len,r+1){
                sum += arr[i];
            }
        }
        return sum;
    }
};

void solve(){
    vi arr = {1,2,3,4,5,6,7,8,9};
    SQRT _Sqrt(arr.sz);
    _Sqrt.create(arr);
    cout<<_Sqrt.query(1,2,arr)<<endl;
    cout<<_Sqrt.query(1,3,arr)<<endl;
    cout<<_Sqrt.query(1,4,arr)<<endl;

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
