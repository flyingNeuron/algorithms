
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(0);

const int N = 1e7+10;
vector<int> digitSums(N, 0);

void precomputeDigitSums() {
    for (int i = 0; i < 10; i++) {
        digitSums[i] = i;
    }
    for (int i = 10; i < N; i++) {
        int num = i;
        while (num > 0) {
            digitSums[i] += num % 10;
            num /= 10;
        }
    }
}
int main() {
    fast;
    precomputePrefixCount();
    return 0;
}
