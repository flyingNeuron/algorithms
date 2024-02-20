#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastIO ios::sync_with_stdio(false); cin.tie(0);

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(){
    fastIO;
    int t; cin >> t;
    
    // Precompute sum of digits for all numbers up to 2*10^5
    vector<int> sumDigits(200001);
    for (int i = 1; i <= 200000; ++i)
        sumDigits[i] = sumOfDigits(i);
    
    vector<int> prefixSum(200001);
    for (int i = 1; i <= 200000; ++i)
        prefixSum[i] = prefixSum[i - 1] + sumDigits[i];

    while (t--) {
        int n; cin >> n;
        cout << prefixSum[n] << endl;
    }
    return 0;
}
