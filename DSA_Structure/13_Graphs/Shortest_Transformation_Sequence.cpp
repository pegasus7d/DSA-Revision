#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

struct TestCase {
    string start;
    string target;
    vector<string> dictionary;
    int expected;
};

int shortestTransformationSequence(const string& start, const string& target, const vector<string>& dictionary) {
    if(start==target)return 1;

    unordered_set<string>st(dictionary.begin(),dictionary.end());
    queue<pair<string,int>>q;
    unordered_set<string>visited;
    q.push({start,1});
    visited.insert(start);


    while(!q.empty()){
        string word=q.front().first;
        int steps=q.front().second;

        q.pop();

        string next=word;

        for(int i=0;i<word.size();i++){
            char original=next[i];
            for(char c='a';c<='z';c++){
                if(c==original)continue;

                next[i]=c;


                if(next==target)return steps+1;
                if(st.find(next)!=st.end() && visited.find(next)==visited.end()){
                    q.push({next,steps+1});
                    visited.insert(next);
                }
            }
            next[i]=original;
        }

    }

    return 0;







    return -1;
}

void runSingleTest(const TestCase& tc, int idx) {
    int got = shortestTransformationSequence(tc.start, tc.target, tc.dictionary);
    cout << "Test " << idx << ": ";
    if (got == tc.expected) {
        cout << "PASS";
    } else {
        cout << "FAIL";
    }
    cout << " | expected = " << tc.expected << ", got = " << got << endl;
}

void solve(){
    vector<TestCase> tests = {
        // Example from prompt
        {"red", "hit", {"red", "bed", "hat", "rod", "rad", "rat", "hit", "bad", "bat"}, 5},

        // Start equals target
        {"same", "same", {"same", "came", "lame"}, 1},

        // No possible path
        {"cat", "dog", {"cat", "cot", "cog", "dat"}, 0},

        // End word missing from dictionary
        {"red", "hit", {"red", "bed", "hat", "rod", "rad", "rat", "bad", "bat"}, 0},

        // Minimal one-letter transformation
        {"a", "c", {"a", "b", "c"}, 2},

        // Multiple shortest routes, same answer length
        {"toon", "plea", {"toon", "poon", "plee", "same", "poie", "plie", "poin", "plea"}, 7},

        // Direct adjacency in dictionary
        {"abc", "abd", {"abc", "abd", "acc"}, 2},

        // Standard reachable chain
        {"lead", "gold", {"lead", "load", "goad", "gold", "bead", "bean"}, 4},
    };

    for (int i = 0; i < (int)tests.size(); i++) {
        runSingleTest(tests[i], i + 1);
    }
}
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    // int _t;cin>>_t;while(_t--)
    solve();
}


// command to run this 