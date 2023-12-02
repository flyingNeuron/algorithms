#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define fastIO ios::sync_with_stdio(false);\
cin.tie(0);

int two_pointers_onesided(const vector<int> &vec, int n, int t){
    int sum=0,ans=0, left=0;
    for(int right=0; right < n; ++right){
        sum+= vec[right];

        while (sum==t){
            sum -= vec[left];
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    return ans;
}

int main(){
    fastIO;
    int t; cin >> t;
    while(t--){
        int n,s; cin>>n>>s;
        vector<int> vec(n);
        for(int i=0; i<n; ++i){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        int res = two_pointers(vec,n,s);
        cout<<res<<endl;
    }
    return 0;
}
