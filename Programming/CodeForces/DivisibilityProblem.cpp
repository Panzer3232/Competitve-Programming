#include <bits/stdc++.h>

using namespace std;

int main()
{
    #ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

int t;
cin>>t;
while(t--){
    int a,b;
    cin>>a>>b;
    if(a%b==0)
    std::cout << 0 << std::endl;
    else
    cout<< b-(a%b)<<endl;
}

    return 0;
}
