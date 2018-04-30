#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int choice,num,n,sum=0;
    string name;
    map<string,int>m;
    map<string,int>::iterator it;
     std::pair<std::map<string,int>::iterator,bool> ret;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>choice;
        switch(choice){
            case 1:
                cin>>name>>num;
                ret=m.insert(make_pair(name,num));
                if(ret.second==false){//element alread present
                    it=m.find(name);//find value
                sum=num+it->second;//update it
                    m.erase(it);
                    m.insert(make_pair(name,sum));
                }
                break;
            case 2:
                cin>>name>>num;
                m.erase(name);
                break;
            case 3:
                cin>>name;
                it=m.find(name);
                if(it!=m.end())
                    cout<<it->second<<endl;
                else
                    cout<<"0"<<endl;
                break;
            default:
                break;
                
        }
    }
    return 0;
}

