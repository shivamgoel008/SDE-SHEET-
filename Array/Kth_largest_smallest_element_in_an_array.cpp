#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll              long long int
#define endl            "\n"
#define MOD             1e9 + 7
#define test()          ll t; cin>>t; while(t--)
#define precision(x,y)  fixed<<setprecision(y)<<x
#define ordered_set     tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
 
bool compare(ll a,ll b)
{
    return a<b;
}

/* 1.using priority queue/ heap - time(nlog(n)), space(log(n))
   2.using sorting -- time(nlog(n)) space (1) 
   3.using quick sort -- time((n)) , space (1);
*/

int parition(vector<int>&v, int low, int high)
{
    int pivot=v[high];
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(v[j]>pivot)
        {
            i++;
            swap(v[i],v[j]);
        }
    }

    i++;
    swap(v[i],v[high]);

    return i;
}
int quickSort(vector<int>&v, int low, int high, int k)
{
        int partitionIndex=parition(v,low, high);
        cout<<partitionIndex<<endl;

        if(partitionIndex==k-1)
        return v[partitionIndex];

        else if(partitionIndex>k-1)
        return quickSort(v,low,partitionIndex-1,k);

    
        return quickSort(v,partitionIndex+1, high, k);

}

int main ()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    test()
    {
        ll i,j,n,k;
        cin>>n>>k;

        vector<int>v(n);

        for(i=0;i<n;i++)
        cin>>v[i];

        for(auto i:v)
        cout<<i<<" ";
        cout<<endl;

        cout<<quickSort(v,0,n-1, k)<<endl;
    }
    return 0;
}