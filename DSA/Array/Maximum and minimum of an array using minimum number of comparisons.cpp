#include<bits/stdc++.h>
using namespace std;

struct Pair{
    int min;
    int max;
};

struct Pair  getMinMax(int a[],int start,int end){
    struct Pair minmax,mml,mmr;
    int mid;
    if(start==end){
        minmax.min=a[start];
        minmax.max=a[start];
        return minmax;
    }
     if (end==start+1){
        if(a[start]>a[end]){
            minmax.max=a[start];
            minmax.min=a[end];
        }
        else{
            minmax.max=a[end];
            minmax.min=a[start];
        }
        
        return minmax;
    }
    
        mid=(start+end)/2;
        mml= getMinMax(a,start,mid);
        mmr=getMinMax(a,mid+1,end);
        if(mml.min<mmr.min){
            minmax.min=mml.min;
        }
        else
        minmax.min=mmr.min;
        
        if(mmr.max>mml.max){
            minmax.max=mmr.max;
        }
        else 
        minmax.max=mml.max;
        
        return minmax;
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    struct Pair minmax= getMinMax(a,0,n-1);
     cout<<"Max"<<" "<<minmax.max<<"\n";
     cout<<"Min"<<" "<<minmax.min;
     
    return 0;
}
