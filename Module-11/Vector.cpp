//not fixed size like array 
#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);//piche se add kardo 
    cout<<v.capacity()<<" "<<v.size()<<endl;
    v[1]= 1;//will not change index 2 
    v.push_back(2);// isse capacity badti hai vector ki 
    cout<<v.capacity()<<" "<<v.size()<<endl;
    //v[1]= 1;//will change index 1 after adding capacity of index 1 
    v.push_back(3);
    cout<<v.capacity()<<" "<<v.size()<<endl; //double the capacity of the vector

    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
    v.pop_back(); //last element delete karana hai
    // Pop back karne se capcity nahi kam hoti
    
    cout<<v[0]<<" "<<v[1]<<endl;
    return 0;
}  