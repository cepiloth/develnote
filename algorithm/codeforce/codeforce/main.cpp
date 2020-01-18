#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <stack>
#include <cstring>

using namespace std;

#define MAX_SIZE 100
#define INF 0x7fffffff
#define CENDL "\n"
#define ll long long

int main() {

    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int count; cin >> count;

    while (count--) {
        
        int n; cin >> n;
        vector<int> arr(n+1);
        vector<int> pos(n + 1);

        arr[0] = 0;
        for(int i = 1; i < n+1; i++) {
            cin >> arr[i];
            pos[arr[i]] = i;
        }
        vector<bool> vis(n + 1);
        for (int i = 0; i < n + 1; i++) {
            vis[i] = false;
        }

        
        for (int i = 1; i <= n; i++)
        {
            for (int j = pos[i] - 1; j > 0; j--)
            {
            
                if (j > n - 1)
                    break;
                if (arr[j] < arr[j + 1])
                    break;
                if (vis[j])
                    break;

                swap(arr[j], arr[j + 1]);
                vis[j] = true;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << CENDL;
    }
    return 0;
}