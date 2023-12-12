#include <bits/stdc++.h>
using namespace std;
bool areAnagram(string a,string b){
	if(a.size()!=b.size())
		return false;
	int val=0;
	for(int i=0;i<a.size();i++){
		val^=(int)a[i];
		val^=(int)b[i];
	}
	return val==0;
}
int main() 
{ 
    string str1 = "geeksforgeeks"; 
    string str2 = "forgeeksgeeks"; 
    if (areAnagram(str1, str2)) 
        cout << "The two strings are anagram of each other"; 
    else
        cout << "The two strings are not anagram of each other"; 
   
    return 0; 
} 
