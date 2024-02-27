#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

/* DEFINES	*/
#define FAST_IO                       \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(nullptr);            \
    std::cout.tie(nullptr);
#define f first
#define s second
#define sp << " " <<
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define clr(x) memset(x, 0, sizeof(x))
#define fill(x, y) memset(x, y, sizeof(x))
#define forn(i, n) for (int i = 0; i < n; ++i)
#define inrange(i, a, b) (a <= i && i < b)
#define trav(a, x) for (auto& a : x)
#define sz(x) (int)(x).size()
#define printv(a)                          \
    {                                      \
        for (auto u : a) cout << u << " "; \
        cout << endl;                      \
    }
#define printm(a)                                    \
    {                                                \
        for (auto u : a) cout << u.f sp u.s << endl; \
    }
#define pb push_back
#define eb emplace_back
#define mp make_pair

/* TYPEDEFS	*/
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;

/* CONSTANTS */
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;
const long double EPS = 1e-9;

int main() {
    FAST_IO

    int N, M;
    cin >> N >> M;

    vvi dist(N + 1, vi(N + 1, INF));
    vector<vector<vector<int>>> history(N + 1, vector<vector<int>>(N + 1));

    int f, t, c;
    forn(i, M) {
        cin >> f >> t >> c;

        dist[f][t] = min(dist[f][t], c);
        history[f][t] = {f, t};
    }

    for (int mid = 1; mid <= N; mid++) {
        for (int from = 1; from <= N; from++) {
            for (int to = 1; to <= N; to++) {
                if (from == to) continue;
                if (dist[from][to] > dist[from][mid] + dist[mid][to]) {
                    dist[from][to] = dist[from][mid] + dist[mid][to];
                    history[from][to] = history[from][mid];
                    history[from][to].insert(history[from][to].end(), history[mid][to].begin() + 1, history[mid][to].end());
                }
            }
        }
    }

    for (int from = 1; from <= N; from++) {
        for (int to = 1; to <= N; to++) {
            if (dist[from][to] == INF)
                cout << 0 << ' ';
            else
                cout << dist[from][to] << ' ';
        }
        cout << endl;
    }

    for (int from = 1; from <= N; from++) {
        for (int to = 1; to <= N; to++) {
            if (dist[from][to] == INF) {
                cout << 0 << endl;
                continue;
            }

            cout << sz(history[from][to]) << ' ';

            trav(h, history[from][to]) {
                cout << h << ' ';
            }

            cout << endl;
        }
    }

    return 0;
}