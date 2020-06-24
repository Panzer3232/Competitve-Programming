/*
Let us consider the following problem to understand Binary Indexed Tree.
We have an array arr[0 . . . n-1]. We would like to
1 Compute the sum of the first i elements.
2 Modify the value of a specified element of the array arr[i] = x where 0 <= i <= n-1.
*/
#include<bits/stdc++.h> 

using namespace std;
int getSum(int BITree[], int index) 
{ 
    int sum = 0;  
    index = index + 1; 
    while (index>0) 
    { 
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
void update(int BITree[], int n, int index, int val) 
{ 
    index = index + 1; 
    while (index <= n) 
    { 
    BITree[index] += val; 
    index += index & (-index); 
    } 
} 
int *constructBITree(int freq[],int n){
    int *BITree=new int[n+1];
    for(auto i=0 ; i<n ;i++){
        BITree[i]=0;
    }
     for(auto i=0 ;i<n ; i++){
        update(BITree,n,i,freq[i]);
    }
    return BITree;
}
int main()
{
 int freq[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int n = sizeof(freq)/sizeof(freq[0]); 
    int *BITree = constructBITree(freq, n); 
    cout << "Sum of elements in arr[0..5] is "
        << getSum(BITree, 5); 
  
    freq[3] += 6; 
    update(BITree, n, 3, 6); 
  
    cout << "\nSum of elements in arr[0..5] after update is "
        << getSum(BITree, 5); 
  
    return 0;  
    return 0;
}
