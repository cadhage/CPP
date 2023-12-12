#include <bits/stdc++.h>
using namespace std;
map<string,string> mother_father,child,m_f,set5;
vector<pair<string,pair<string,pair<string,string>>>> relation;
void add_child(string child_name,string mother,string mf,string father="NA"){
	relation.push_back(make_pair(child_name,make_pair(mother,make_pair(father,mf))));
	
}
void show(string name,string rel){
		for(auto it:relation){
//			cout<<it.first<<" "<<it.second.first<<" "<<it.second.second.first<<" "<<it.second.second.second<<"\n";
			cout<<it.second.first<<" "<<name<<'\n';
			if(it.second.first.compare(name)==0){
				cout<<it.first<<'\n';
			}
		}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string rel;
	while (std::getline(std::cin, rel))
	{
		if(rel.compare("ADD_CHILD")==0){
			string child_name,mother,mf;cin>>child_name>>mother>>mf;
			add_child(child_name,mother,mf);
			std::cout << std::endl;
		}else if(rel.compare("GET_RELATIONSHIP")==0){
			string name,relation;cin>>name>>relation;
			show(name,relation);
			std::cout << std::endl;
		}
	}
	return 0;
}
