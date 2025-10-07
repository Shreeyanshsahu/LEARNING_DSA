#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> ans;
    vector<int> vec1;
    vector<int> vec2;
    int x,y;
    cout<<"Enter length of first arrray:";cin>>x;
    cout<<"Enter length of second arrray:";cin>>y;
    for(int i=0;i<x;i++){
        int temp;
    cout<<"Enter element of first arrray:";cin>>temp;
    vec1.push_back(temp);
    }
    for(int i=0;i<y;i++){
        int temp;
    cout<<"Enter element of second arrray:";cin>>temp;
    vec2.push_back(temp);
    }


    int point1,point2;
    point1=0;
    point2=0;
    //sorter

    for(int i=0;i<x+y;i++){
    if(vec1[point1]<=vec2[point2] and point1<x){
    ans.push_back(vec1[point1]);
    point1++;
    }
    else{
    ans.push_back(vec2[point2]);
    point2++;
    }
    }
    cout<<" ans vector is {";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"  ";
    }
    cout<<"}";
}