#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
   int t;
    int n;
   cin>>t;
   while(t--){
       cin>>n;
       std::cout << (n-1)/2 << std::endl;
   }

    return 0;
}
