#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef long long ll;

ll query(vi& tree, int node, int start, int end, int left, int right){
    if(end < left || right < start){
        return 0;
    }

    if(left <= start && end <= right){
        return tree[node];
    }

    ll left_value = query(tree, node*2, start, (start+end)/2, left, right);
    ll right_value = query(tree, node*2+1, (start+end)/2+1, end, left, right);

    return left_value+right_value;
}

void update(vi& tree, int node, int start, int end, int index){
    if(start == end){
        tree[node] = 1;
        return;
    }

    int mid = (start+end)/2;

    if(index <= mid){
        update(tree, node*2, start, mid, index);
    }
    else {
        update(tree, node*2+1, mid+1, end, index);
    }

    tree[node] = tree[node*2] + tree[node*2+1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int inp;
    map<int, int> mii;
    for(int i=1; i<=N; i++){
        cin >> inp;
        mii[inp] = i;
    }

    vi tree(4*(N+1), 0);
    ll answer = 0;
    for(int i=1; i<=N; i++){
        cin >> inp;
        mii[inp];
        answer += query(tree, 1, 1, N, mii[inp], N);
        update(tree, 1, 1, N, mii[inp]);
    }

    cout << answer << '\n';

    return 0;
}