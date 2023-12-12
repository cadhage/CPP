#include <bits/stdc++.h>
using namespace std;
void printArray(int array[], int length) 
{ 
    std::cout << "["; 
      
    for(int i = 0; i < length; i++) 
    { 
        std::cout << array[i]; 
          
        if(i < (length - 1)) 
            std::cout << ", "; 
        else
            std::cout << "]" << std::endl; 
    } 
} 
void reverse(int array[], int start, int end) 
{ 
    while(start < end) 
    { 
        int temp = array[start]; 
        array[start] = array[end]; 
        array[end] = temp; 
        start++; 
        end--; 
    } 
} 
void rearrange(int a[],int s,int e){
	if(s==e)
		return ;
	rearrange(a,s+1,e);
	if(a[s]>=0){
		reverse(a,s+1,e);
		rearrange(a,s,e);
	}
}
int main(){
	int array[] = {-12, -11, -13, -5, -6, 7, 5, 3, 6}; 
    int length = (sizeof(array) / sizeof(array[0])); 
    int countNegative = 0; 
      
    for(int i = 0; i < length; i++) 
    { 
        if(array[i] < 0) 
            countNegative++; 
    } 
      
    std::cout << "array: "; 
    printArray(array, length); 
    rearrange(array, 0, (length - 1)); 
      
    reverse(array, countNegative, (length - 1)); 
      
    std::cout << "rearranged array: "; 
    printArray(array, length); 
	return 0;
}
