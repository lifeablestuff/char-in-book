#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool mycomp(pair <char, int> x, pair <char, int> y){
    return (x.second > y.second);
}

int main(){
    unordered_map <char, int> count;
    vector <pair <char, int> >  pv;
    pair <char, int> p;
    char c;

    ifstream f("bigbook.txt");
    f.seekg(0,ios::beg);

    while(f.get(c)){
        c = tolower(c);
        if(count.find(c) != count.end()){
                count[c] += 1;
        }
        else{
            count[c] = 1;
        }
    }

    for(auto i=count.begin(); i!=count.end(); i++){
        p.first = i->first;
        p.second = i->second;
        pv.push_back(p);
    }

    sort(pv.begin(),pv.end(), mycomp);

    for(int x = 0; x<10; x++){
        pair <char, int> a = pv.at(x);
        cout << a.first << ": " << a.second << endl;
    }

    f.close();
    return 0;
}
