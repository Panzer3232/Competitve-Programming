/*
Chef is playing a card game with his friend Morty Smith.

The rules of the game are as follows:

There are two piles of cards, pile A and pile B, each with N cards in it. Pile A belongs to Chef and pile B belongs to Morty.
Each card has one positive integer on it
The ‘power’ of a card is defined as the sum of digits of the integer on that card
The game consists of N rounds
In each round, both players simultaneously draw one card each from the top of their piles and the player who draws the card with higher power wins this round and gets a point. If the powers of both players' cards are equal then they get 1 point each.
The winner of the game is the player who has more points at the end of N rounds. If both players have equal number of points then the game ends in a draw.
The game is now over and Chef has told Morty to find the winner. Unfortunately, this task is too complex for him. Help Morty find the winner.

Input:
First line will contain T, number of testcases.
The first line of each test case will contain N, the number of rounds played.
The ith of the next N lines of each test case will contain Ai and Bi, the number on the card drawn by Chef and Morty respectively in round i.
Output:
For each test case, output two space separated integers on a new line:
Output

0 if Chef wins,
1 if Morty wins,
2 if it is a draw,
followed by the number of points the winner had.
(If it is a draw then output either player’s points).
Constraints
1≤T≤1000
1≤N≤100
1≤Ai,Bi≤109
Subtasks
100 points : No additional constraints
Sample Input:
2
3
10 4
8 12
7 6
2
5 10
3 4
Sample Output:
0 2
2 1
Explanation:
Test Case 1:

Round 1:

Chef’s card has power 1+0 = 1,
Morty’s card has power 4.
Therefore, Morty wins the round.

Round 2:

Chef’s card has power 8,
Morty’s card has power 1+2 = 3.
Therefore, Chef wins the round.

Round 3:

Chef’s card has power 7,
Morty’s card has power 6.
Therefore, Chef wins the round.

Therefore, Chef wins the game with 2 points (Morty has 1 point).

Test Case 2:

Round 1:

Chef’s card has power 5,
Morty’s card has power 1+0=1.
Therefore, Chef wins the round.

Round 2:

Chef’s card has power 3,
Morty’s card has power 4.
Therefore, Morty wins the round.
*/

#include<bits/stdc++.h>
using namespace std;
 
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")
 
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define MAX 100000
#define pow2(x) ((x)*(x))
#define ll long long
#define ld long double
#define eb emplace_back
#define pb push_back
#define pf push_front
 
#define mod 1000000007
#define clock (clock() * 1000.0 / CLOCKS_PER_SEC)
 
#define mp make_pair
#define ff first
#define ss second
#define null NULL
 
#define all(c) (c).begin(),(c).end()
#define nl "\n"
 
typedef vector<ll> vl;
typedef vector< vl > vvl;
typedef pair< ll,ll> pll;
typedef map< ll,ll> mll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  ll t;
  cin >> t;
  
  while(t--){
      ll n ;
      cin >> n;
      multimap<int,int> ar;
      
      
      while(n--){
          ll f,s;
          cin >> f >> s;
          ar.insert(pair<int,int>(f,s));
      }
    multimap<int,int>::iterator itr;
    
    multimap<int,int> ar12;
    
    
    for(itr = ar.begin();itr!=ar.end();++itr){
        ll sum1=0;
        ll sum2=0;
        
        ll f =itr->first;
        while(f!=0){
          ll p = f%10;
          sum1+=p;
          f=f/10;
        }
        ll s =itr->second;
        while(s!=0){
          ll h=s%10;
          sum2+=h;
          s=s/10;
        }
        ar12.insert(pair<int,int>(sum1,sum2));
    }
    
    
    ll cpt=0;
    ll morpt=0;
    
    
    for(itr=ar12.begin();itr!=ar12.end();++itr){
      if(itr->first==itr->second){
        
        cpt++;
        morpt++;
      }
      else if(itr->first > itr->second){
        cpt+=1;
      }
      else {
        morpt+=1;
      }
   }
      if(cpt>morpt){
       cout << "0"<<" "<<cpt<<"\n";
      }
      else if(cpt<morpt){
       cout <<"1"<<" "<<morpt<<"\n";
      }
      else{
       cout <<"2"<<" "<<cpt<<"\n";
      }
 }
 
 
 return 0;
}
