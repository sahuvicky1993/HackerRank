#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {

        map<string,int> m;
        std::map<string,int>::iterator it;
        vector<string>::const_iterator i;

        for(i=magazine.begin();i!=magazine.end();++i){
            it = m.find(*i);
            if(it!=m.end())
            it->second++;
            else
            m.insert(make_pair(*i,1));
        }

        //std::vector<string>::iterator mi;
        for(i=ransom.begin();i!=ransom.end();++i)
        {
            if(m.find(*i)!=m.end())
            m.find(*i)->second--;
            if(!( m.find(*i)->second==0))
                return false;
        }
        return true;

}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
