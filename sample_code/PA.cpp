#include <iostream>
#include <utility>
#include <unordered_set>
#include <map>
#include <cassert>
#include <cstdlib>

using namespace std;

map<int, int> ans;

void qs(const unordered_set<int>& bulb, const unordered_set<int>& holder, int t)
{
    if(bulb.size() == 0) return;
    unordered_set<int> bulb_small, bulb_big, holder_small, holder_big;
    auto it = bulb.begin();
    advance( it, rand() % bulb.size() );
    int pivot_bulb = *it, pivot_holder;
    for(auto i : holder){
        int cmp_result;
        cout << "C " << pivot_bulb << " " << i << endl;
        cin >> cmp_result;
        if(cmp_result == -1){
            holder_big.insert(i);
        } else if(cmp_result == 1){
            holder_small.insert(i);
        } else {
            pivot_holder = i; 
        }
    }
    for(auto i : bulb){
        int cmp_result;
        cout << "C " << i << " " << pivot_holder << endl;
        cin >> cmp_result;
        if(cmp_result == 1){
            bulb_big.insert(i);
        } else if(cmp_result == -1){
            bulb_small.insert(i);
        }
    }
    ans[pivot_bulb] = bulb_small.size() + 1 + t;
    qs(bulb_small, holder_small, t);
    qs(bulb_big, holder_big, ans[pivot_bulb]);
}

int main()
{
    srand(time(NULL));
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    unordered_set<int> bulb;
    for(int i = 1; i <= N; ++i){
        bulb.insert(i);
    }
    qs(bulb, bulb, 0);
    cout << "A" << endl;
    for(auto p : ans){
        cout << p.second << "\n";
    }
}
