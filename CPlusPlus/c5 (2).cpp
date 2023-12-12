#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int d;
		cin >> d;
		string str;
		cin >> str;
		int p = 0, i, req, proxy = 0;
		if( d % 4 == 0)
			req = (d * 3) / 4;
		else
			req = ((d * 3) / 4) + 1;
		for(i = 0; i < d; i++)
			if(str.at(i) == 'P')
				p++;
		if(p >= req)
			cout << "0" << endl;
		else
		{
			for(i = 2; i < d - 2; i++)
			{
				if(proxy + p == req)
					break;
				else
					if(str.at(i) == 'A')
						if((str.at(i - 1) == 'P' || str.at(i - 2) == 'P') && (str.at(i + 1) == 'P' || str.at(i + 2) == 'P'))
							proxy++;
			}
			if(proxy + p < req)
				cout << "-1" << endl;
			else
				cout << proxy << endl;
		}
	}
}
