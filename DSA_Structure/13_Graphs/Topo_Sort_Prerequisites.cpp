#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

struct TestCase {
    int n;
    vector<pair<int, int>> prerequisites;
    bool expected;
};

bool canFinishCourses(int n, const vector<pair<int, int>>& prerequisites) {
    // TODO: Write your Topological Sort logic here.
    // pair [a, b] means course a must be taken before course b.
    return false;
}

void runSingleTest(const TestCase& tc, int idx) {
    bool got = canFinishCourses(tc.n, tc.prerequisites);
    cout << "Test " << idx << ": ";
    if (got == tc.expected) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << " | expected = " << (tc.expected ? "true" : "false")
         << ", got = " << (got ? "true" : "false") << endl;
}

void solve() {
    vector<TestCase> tests = {
        // Example from prompt: cycle between 1 and 2
        {3, {{0, 1}, {1, 2}, {2, 1}}, false},

        // Simple linear dependency
        {4, {{0, 1}, {1, 2}, {2, 3}}, true},

        // No prerequisites
        {5, {}, true},

        // Single course
        {1, {}, true},

        // Two-node cycle
        {2, {{0, 1}, {1, 0}}, false},

        // Multiple components, all acyclic
        {6, {{0, 1}, {2, 3}, {3, 4}}, true},

        // Self-contained cycle in one component
        {6, {{0, 1}, {1, 2}, {2, 0}, {4, 5}}, false},

        // Diamond DAG
        {4, {{0, 1}, {0, 2}, {1, 3}, {2, 3}}, true},

        // Repeated-like chain, still acyclic
        {5, {{0, 1}, {1, 2}, {2, 3}, {3, 4}}, true},
    };

    for (int i = 0; i < (int)tests.size(); i++) {
        runSingleTest(tests[i], i + 1);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int _t;cin>>_t;while(_t--)
    solve();
}
