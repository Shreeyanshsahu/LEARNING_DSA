//order should be same of 2 matrix  
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int arr1[4][4]={230,20,20,210,90,23,9,12,78,32,2,89,23,54,96};
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){ 
          cout<<arr1[i][j]<<"  ";
        } 
        cout<<endl;
    }
    int maxc= 3;
    int maxr= 3;
    vector<int> arr(maxc+1*maxr+1);
    int minc=0;
    int minr=0;
    int j=0;
    int count=16;
    cout<<count<<endl;
    while(count>=0){ 
        for(int i=minc; i<=maxc; i++){
            arr[j]=arr1[minr][i];
            j++;count--;
        }
        minr++;
        for(int i=minr; i<=maxr; i++){
            arr[j]=arr1[i][maxc];
            j++;count--;
        }
        maxc--;
        for(int i=maxc; i>=minc; i--){
            arr[j]=arr1[maxr][i];
            j++;count--;
        }
        maxr--;
        for(int i=maxr; i>=minr; i--){
            arr[j]=arr1[i][minc];
            j++;count--;
        }
        minc++;
    }

    for(int i=0; i<12; i++){
        cout<<arr[i]<<"  "; 
    }
   
}