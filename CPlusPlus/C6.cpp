#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int t, sa, sb, len, i, j, k;
	cin >> t;
	while (t--) {
		cin >> s;
		cin >> sa >> sb;
		len = s.length();
		for (i=0;i<len;i++) {
			if (s[i] == 'A') {
				j = i;
			}
			if (s[i] == 'B') {
				k = i;
			}
		}
		if ((k - j) % (sa + sb)) {
			cout << "safe" << endl;
		}
		else {
			cout << "unsafe" << endl;
		}
	}
    return 0;
}
