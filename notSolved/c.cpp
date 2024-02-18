#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <list>
#include <numeric>
#include <limits>
#include <functional>
#include <utility>

using namespace std;
#define  int          long long
#define  sz(s)        (int)s.size()
#define  all(v)       (v).begin(),(v).end()

template <typename A, typename B> ostream& operator<< (ostream &cout, pair<A, B> const &p) { return cout << '(' << p.first << ',' << p.second << ')'; }
template <typename A, typename B> istream& operator>> (istream& cin, pair<A, B> &p) {cin >> p.first; return cin >> p.second;}
template <typename A> ostream& operator<< (ostream &cout, vector<A> const &v) {cout << '['; for(int i = 0; i < v.size(); i++) {if (i) cout << ','; cout << v[i];} return cout << ']';}
template <typename A> istream& operator>> (istream& cin, vector<A> &x){for(int i = 0; i < x.size()-1; i++) cin >> x[i]; return cin >> x[x.size()-1];}
template <typename A, typename B> A amax (A &a, B b){ if (b > a) a = b ; return a; }
template <typename A, typename B> A amin (A &a, B b){ if (b < a) a = b ; return a; }

long long mod = 1000000007LL; // New modulo value
const long long inf = 1e18;

int solve() {
    int n , m;
    cin>>n>>m;

    vector<int> nums(n);
    for(int i = 0 ; i < n;i++){
        cin>>nums[i];
        nums[i] = nums[i]% mod;
    }
    string s;
    cin>>s;

    int prod = 1;
    for(int i = 0; i < n;i++){
        prod = (nums[i]* prod );
    }
   
    vector<int> result;
    int left = 0; int right = n -1;
    for(int i= 0 ; i < n  ;i++){
        result.push_back(prod % m);
        if(s[i] == 'L'){
            prod = prod / nums[left];
            left++;
        }
        else if(s[i] == 'R'){
            prod = prod / nums[right];
            right--;
        }
    }
    
    for(int & x : result) cout<<x<<" ";
    cout<<endl;
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
