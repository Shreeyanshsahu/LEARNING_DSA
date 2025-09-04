#include<iostream>
#include<string.h>

using namespace std;
//we proved that class is a user defined data type
class Hospital{
    private:
        int health;
        string name;
    public:
    void setvalues(int health,string name){
        this->health = health;
        this->name = name;
    }
    int gethealth(){
        return health;
    }
    string getname(){
        return name;
    }
};
Hospital max_health(Hospital a,Hospital b){
    if(a.gethealth()>b.gethealth()){
        return a;
    }
    else return b;
}

int main(){
    Hospital Alpha;
    Alpha.setvalues(200,"Rayn");
    Hospital Morph;
    Morph.setvalues(300,"Heli");
    
    Hospital Swift = max_health(Alpha,Morph);
    cout<< Swift.gethealth()<<" : "<<Swift.getname()<<endl;


}