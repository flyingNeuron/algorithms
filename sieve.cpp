#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fast ios::sync_with_stdio(false); cin.tie(0);

const int N = 1e7+10;
vector<bool> isP(N, true);

void sieve() {
    isP[0] = isP[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (isP[i]) {
            for (int j = i * i; j < N; j += i) {
                isP[j] = false;
            }
        }
    }
}
int main() {
    fast;
    sieve();
    return 0;
}
