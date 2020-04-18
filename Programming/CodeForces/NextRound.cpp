#include <bits/stdc++.h> 
  
using namespace std;

int main()
{
    int n,k,sum=0;
    cin>>n>>k;
    std::vector<int>ar(n) ;
 for(int i=0;i<n;i++){
     cin>>ar[i];
 }
for(int i=0;i<n;i++){
    if(ar[i]>=ar[k-1]&&ar[i]>0)
    sum++;
}
 std::cout << sum << std::endl;
    return 0;
}

