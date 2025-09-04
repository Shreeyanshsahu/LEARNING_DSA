#include<iostream>
#include<string.h>
#include<vector>

using namespace std;
class Cricketer{
    private:
        string name;
        int age;
        int test_match;
        int avg_run;
    public:
        void setter(string name,int age,int test_match,int avg_run){
            this->name=name;
            this->age=age;
            this->test_match=test_match;
            this->avg_run=avg_run;
        }
        vector<int> gettedata(){
            vector<int>ans ={age,test_match,avg_run};
            return ans;
        }
        string getname(){
            return this->name;
        }
        
};

int main(){
     vector<Cricketer> team;
     for(int i=0;i<11;i++){
        string name;
        int age;int testmatch;int avg_run;
        cout<<"Enter details for player no:"<<i+1;
        cout<<"Give player name: ";
        cin>>name;
        cout<<"Give player age: ";
        cin>>age;
        cout<<"Give player no of testmatch: ";
        cin>>testmatch;
        cout<<"Give player avg run : ";
        cin>>avg_run;
        Cricketer obj;
        obj.setter(name,age,testmatch,avg_run);
        team.push_back(obj);
     }
    cout << "\n--- Team Details ---\n";
    for (int i = 0; i < team.size(); i++) {
        cout << "Player " << i + 1 <<team[i].getname()<< "\n ";
        cout<< "Age: " << team[i].gettedata()[0]
             << ", Matches: " << team[i].gettedata()[1]
             << ", Avg Run: " << team[i].gettedata()[2]
             << endl;

    }

}