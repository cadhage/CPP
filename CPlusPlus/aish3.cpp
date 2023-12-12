#include <bits/stdc++.h>
using namespace std;
void showlist(list <int> g) 
{ 
    list <int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout <<" "<< *it; 
    cout << '\n'; 
}
int main(){
	list<int> list1,list2;
	for(int i=0;i<10;i++){
		list1.push_back(i*2);
		list2.push_back(i*3);
	}
	cout<<"list1"<<endl;
	showlist(list1);
	showlist(list2);
	cout<<"list1 front"<<list1.front()<<endl;
	cout<<"list2_end"<<list1.back()<<endl;
//	cout<<"list1 Pop_front"<<
	list1.pop_front();
	showlist(list1);
	list1.reverse();
	showlist(list1);
	list1.sort();
	showlist(list1);
	return 0;
}
