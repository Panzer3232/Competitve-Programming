

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        long long int y=coordinates[0][1];
       long long int x=coordinates[0][0];
      long long int  dy=coordinates[1][1]-coordinates[0][1];
       long long int dx=coordinates[1][0]-coordinates[0][0];
        if(dx==0){
            return false;
        }
       long long int  m=dy/dx;
      long long int c=y-(m*x);
        for(int i=2;i<coordinates.size();i++){
           long long int  ny=coordinates[i][1];
           long long int  nx=coordinates[i][0];
            long long int rhs =(nx*m)+c;
            if(ny!=rhs){
                return false;
            break;}
        }
        return true;
    }
};
