#include <iostream>
 using namespace std;

void swap(int *xp,int *xn){
     int temp=*xp;
     *xp=*xn;
     *xn= temp;
 }

 void selectionsort(int arr[],int n){
     int i,j,min_indx;
     for(i=0;i<n;i++){
         min_indx=i;
         for(j=(i+1);j<n;j++){
             if(arr[j]<arr[j+1])
             min_indx=j;
         }
         swap(&arr[min_indx],&arr[i]);
     }
 }
 void printarray(int arr[],int n){
     int i;
     for(i=0;i<n;i++){
         cout<<arr[i]<<" ";
         cout<< endl ;
     }
 }
 int main(){
     int arr[] ={66,22,11,56};
     int n= sizeof(arr)/sizeof(arr[0]);
     selectionsort(arr,n);
     cout<<"Sorted : \n";
     printarray(arr,n);
     return 0;
 }