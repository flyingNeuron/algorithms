// https://c...content-available-to-author-only...s.com/algebra/binary-exp.html
// https://f...content-available-to-author-only...8.com/p-cpps-101/
//https://cp-algorithms.com/algebra/binary-exp.html
//https://forthright48.com/p-cpps-101/

#include <bits/stdc++.h>
using namespace std;

vector <int> prime_factorization(int n) {
    vector <int> temp;

    for (int i = 2; i * 1LL * i<= n; ++i) {
        while (n % i == 0) {
            n /= i;
            temp.push_back(i);
        }
    }
   // cout << n << endl;
   if (n > 1) temp.push_back(n);

    return temp;
} // O( sqrt(n) )

const int N = 1e5 + 5;
vector <bool> isPrime;
vector <int> primes;

void sieve() {
    isPrime.assign(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < N; i++) {
        if (!isPrime[i]) continue;

        for (int j = i * i; j < N; j += i) {
            isPrime[j] = false;
        }
    }
    for (int i = 2; i < N; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}


vector <int> prime_fact(int n) {
    vector <int> temp;
    for (auto &x: primes) {
        if ( x * x > n) break;
        while (n % x == 0) {
            n /= x;
            temp.push_back(x);
        }
    }
    if (n > 1) temp.push_back(n);
    return temp;
} // O ( sqrt(n) / ln (sqrt(n)) ) ~ O (sqrt(n) / ln (n))


vector <pair<int,int>> prime_fact_pair(int n) {
    vector <pair<int,int>> temp;
    for (auto &x: primes) {
        if ( x * x > n) break;
        int cnt = 0;
        while (n % x == 0) {
            n /= x;
            cnt++;
        }
        temp.push_back( {x, cnt} );
    }
    if (n > 1) temp.push_back( {n, 1} );
    return temp;
} // O ( sqrt(n) / ln (sqrt(n)) ) ~ O (sqrt(n) / ln (n))

long long count_divisors(const vector<pair<int, int>>& factorization) {
    long long res = 1;
    for (const auto& p : factorization) {
        res = (res * (p.second + 1));
    }
    return res;
}

long long sum_divisors(const vector<pair<int, int>>& factorization) {
    long long res = 1;
    for (const auto& p : factorization) {
        long long sum = 0;
        int exponent = p.second;
        long long v = 1;
        while (exponent--) {
            v *= p.first;
            sum += v;
        }
        res *= sum;
    }
    return res;
}

vector<pair<int, int>> gcd(const vector<pair<int, int>>& a,
                           const vector<pair<int, int>>& b) {
    map<int, int> mp;
    for (const auto& p : a) mp[p.first] = p.second;
    vector<pair<int, int>> res;
    for (const auto& p : b) {
        if (mp.count(p.first)) {
            res.push_back({p.first, min(p.second, mp[p.first])});
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

//    int n;
//    cin >> n;
//    vector <int> v = prime_factorization(n);
//    for (auto &x: v) {
//        cout << x << ' ';
//    }
//    cout << endl;

    sieve();
//
//    int n;
//    cin >> n;
//    vector <int> v = prime_fact(n);
//    for (auto &x: v) {
//        cout << x << ' ';
//    }
//    cout << endl;


    int n;
    cin >> n;
    auto v = prime_fact_pair(n);
    for (auto &x: v) {
        cout << x.first << ' ' << x.second << endl;
    }
    cout << endl;

    return 0;

}



#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

long long binPow(long long base, long long exponent) {
    // 3^5 =3^2 x 3^2 x 3
    if (exponent == 0) return 1;
    long long res = 1;
    if ( exponent % 2 ) {
        res = base;
        exponent--;
    }
    long long half = binPow(base, exponent / 2);
    res = (res * half * half);
    return res;
} // O(log (exponent))


long long binPowMod(long long base, long long exponent, long long mod) {
    // 3^5 =3^2 x 3^2 x 3
    if (exponent == 0) return 1;
    long long res = 1;
    if ( exponent % 2 ) {
        res = base % mod;
        exponent--;
    }
    long long half = binPowMod(base, exponent / 2, mod) % mod;
    res = (((res * half) % mod) * half) % mod;
    return res;
} // O(log (exponent))

//https://c...content-available-to-author-only...s.com/algebra/binary-exp.html


/// pow(base, exponent)
long long power(long long base, int exonent) {
    if (exponent == 0) return 1;
    auto half_power = power(base, exponent / 2);
    return half_power * half_power * (exponent % 2 ? base : 1);
}

/// pow(base, exponent)
long long power_modulo(long long base, int exonent) {
    if (exponent == 0) return 1;
    auto half_power = power_modulo(base, exponent / 2);
    return ((half_power * half_power) % mod * (exponent % 2 ? base : 1)) % mod;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    cout << binPow(2 , 3) << endl;
    cout << binPowMod(3, 18132, 17) << endl;
    return 0;

}




