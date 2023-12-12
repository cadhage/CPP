             #include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> a={4,2,4,5,5};
	auto mm=minmax_element(a.begin(),a.end());
	cout<<mm.second-a.begin()<<'\n';
	int myints[] = {5,20,5,30,30,20,10,10,20};
  std::vector<int> myvector (myints,myints+8);
  auto it = std::adjacent_find (myvector.begin(), myvector.end());

  if (it!=myvector.end())
    cout << "the first pair of repeated elements are: " << *it << '\n';

  //using predicate comparison:
  it = std::adjacent_find (++it, myvector.end(),[](auto a,auto b){
	return a==b;
  });

  if (it!=myvector.end())
    std::cout << "the second pair of repeated elements are: " << *it << '\n';
	return 0;
}
