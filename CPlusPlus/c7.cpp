#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <limits>
#include <numeric>
#include <regex>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <queue>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore();
    for(int t = 0; t < T; ++t)
    {
        int N, K;
        cin >> N >> K;
        cin.ignore();

        for(int i = 0; i <= K; ++i)
            cout << (N - K + i) << ' ';
        for(int i = 1; i < N - K; ++i)
            cout << i << ' ';
        cout << endl;
    }

    return 0;
}
