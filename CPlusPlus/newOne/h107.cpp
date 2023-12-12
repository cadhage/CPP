#include <bits/stdc++.h> 
using namespace std; 
const int MAX = 1000; 
bool areRotations(string s1,string s2){
	if(s1.size()!=s2.size())
		return false;
	string temp=s1+s1;
	return temp.find(s2)!=string::npos;
}
int main() 
{ 
   string str1 = "AACD", str2 = "ACDA"; 
   if (areRotations(str1, str2)) 
     printf("Strings are rotations of each other"); 
   else
      printf("Strings are not rotations of each other"); 
   return 0; 
} 
