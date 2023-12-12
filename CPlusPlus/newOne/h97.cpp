// C++ program to fin maximum cash flow among a set of persons 
#include<iostream> 
using namespace std; 

// Number of persons (or vertices in the graph) 
#define N 3 

// A utility function that returns index of minimum value in arr[] 
int getMin(int arr[]) 
{ 
	int minInd = 0; 
	for (int i=1; i<N; i++) 
		if (arr[i] < arr[minInd]) 
			minInd = i; 
	return minInd; 
} 

// A utility function that returns index of maximum value in arr[] 
int getMax(int arr[]) 
{ 
	int maxInd = 0; 
	for (int i=1; i<N; i++) 
		if (arr[i] > arr[maxInd]) 
			maxInd = i; 
	return maxInd; 
} 

// A utility function to return minimum of 2 values 
int minOf2(int x, int y) 
{ 
	return (x<y)? x: y; 
} 

// amount[p] indicates the net amount to be credited/debited 
// to/from person 'p' 
// If amount[p] is positive, then i'th person will amount[i] 
// If amount[p] is negative, then i'th person will give -amount[i] 
void minCashFlowRec(int amount[]) 
{ 
	// Find the indexes of minimum and maximum values in amount[] 
	// amount[mxCredit] indicates the maximum amount to be given 
	//				 (or credited) to any person . 
	// And amount[mxDebit] indicates the maximum amount to be taken 
	//				 (or debited) from any person. 
	// So if there is a positive value in amount[], then there must 
	// be a negative value 
	int mxCredit = getMax(amount), mxDebit = getMin(amount); 

	// If both amounts are 0, then all amounts are settled 
	if (amount[mxCredit] == 0 && amount[mxDebit] == 0) 
		return; 

	// Find the minimum of two amounts 
	int min = minOf2(-amount[mxDebit], amount[mxCredit]); 
	amount[mxCredit] -= min; 
	amount[mxDebit] += min; 
	cout << "Person " << mxDebit << " pays " << min 
		<< " to " << "Person " << mxCredit << endl; 
	minCashFlowRec(amount); 
} 
void minCashFlow(int graph[][N]) 
{ 
	int amount[N] = {0};
	for (int p=0; p<N; p++) 
	for (int i=0; i<N; i++) 
		amount[p] += (graph[i][p] - graph[p][i]); 

	minCashFlowRec(amount); 
} 
int main() 
{ 
	int graph[N][N] = { {0, 1000, 2000}, 
						{0, 0, 5000}, 
						{0, 0, 0},}; 

	// Print the solution 
	minCashFlow(graph); 
	return 0; 
} 

