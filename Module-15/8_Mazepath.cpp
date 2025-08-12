
#include <iostream>
//only down or right can be chossen 
#include <string>
using namespace std;
int maze(int col,int row,int sum){
    if (col==1 and row ==1) return sum + 1;
    if (col==0 or row ==0) return sum + 0;
    return maze(col-1,row,sum) + maze(col,row-1,sum);
}
void mazeprint(int col,int row, string sum){
    if (col==1 and row ==1){ cout<<sum<<endl;
    return;}
    if (col==0 or row ==0) return;
    mazeprint(col-1,row,sum +'R');
    mazeprint(col,row-1,sum +'D');
}

int main(){
    cout<<"Welcome to the maze!"<<maze(3,3,0)<<endl;
    mazeprint(3,3,"");
}