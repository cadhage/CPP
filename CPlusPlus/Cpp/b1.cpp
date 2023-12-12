#include <bits/stdc++.h>
using namespace std;

class Widget {
	public:
//	… // ctors, etc.
		void addFilter() const; // add an entry to filters
	private:
		int divisor; // used in Widget's filter
};
template<typename C>
void workWithContainer(const C& div)
{
	vector<C> a={1,5,3,7,5};
	//cout<<typename C::value_type;
//	value_type();
	if (std::all_of(begin(a), end(a),
		[=](const auto &value)
						{ return value %diviser != 0; }))
		cout<<"yes";
	else{
	}
}
int main(){
//	int x;
	workWithContainer(2);
	return 0;
}
