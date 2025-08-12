#include<iostream>
#include<algorithm>

using namespace std;
bool sqrtu(int x){
    int root = sqrt(x);
    if(x == root*root){
        return true;
    }
    else{
        return false;
    }
}

bool judgeSquareSum(int c){
      int x = 0;
      int y = c;
      while(x<=y){
        if(sqrtu(x)&&sqrtu(y)) return true;
        if(sqrtu(x)){
            y = sqrt(y)*sqrt(y);
        }

        else if(!sqrtu(y)){
            y= (int)sqrt(y)*(int)sqrt(y);
            x=c-y;
        }
        
        else{
            x = (int)sqrt(x)*(int)sqrt(x); 
            y = c-x;
        }
      } 
      return false;
}

int main(){
    cout<<"a2 + b2 exist if = 1: "<<judgeSquareSum(10000);
}