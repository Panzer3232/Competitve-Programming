class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int i;
        for( i=1;i<=num;i++){
            if(i*i==num){
                return true ;
              break;}
            if(i*i>num)
                break;
        }
        return false;
    }
};