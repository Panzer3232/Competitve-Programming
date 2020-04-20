#include <bits/stdc++.h>
#include <string>
  
using namespace std;

int main()
{
  string str,s2;
  getline(cin,str);
  int n=str.size();
  for(int i=0;i<n;i++){
      if(str.at(i)=='a'||str.at(i)=='e'||str.at(i)=='i'||str.at(i)=='o'||str.at(i)=='y'||str.at(i)=='u'||str.at(i)=='A'||str.at(i)=='E'
      ||str.at(i)=='I'||str.at(i)=='O'||str.at(i)=='U'||str.at(i)=='Y')
        continue;
  else{
      s2+='.';
      s2+=tolower(str[i]);
  }
  }
  std::cout << s2 << std::endl;
    return 0;
}

