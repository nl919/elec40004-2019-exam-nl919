#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <unordered_set>

using namespace std;

int main(int argc, char **argv)
{
    int n=1000;
    float swap_ratio=0.25;

    if(argc>1){
        n=stoi(argv[1]);
    }
    if(argc>2){
        swap_ratio=stod(argv[2]);
    }

    cerr<<"Generating "<<n<<" nodes with skew "<<swap_ratio<<endl;

    int swaps=n*swap_ratio;


    mt19937 rng;

    /* Generate a vector of sorted data. */
    vector<string> res;
    for(int i=0; i<n; i++){
        char tmp[16];
        sprintf(tmp, "i%08x", i);
        res.push_back(tmp);
    }


    /* Move random sub-ranges of data around. */
    for(int i=0; i<swaps; i++){
        unsigned a=(rng()%(res.size()-2))+1;
        unsigned b=(rng()%(res.size()-2))+1;
        unsigned aa=min(a,b);
        unsigned bb=max(a,b);

        for(int i=aa; i<bb; i++){
            res.push_back(res[i]);
        }
        res.erase(res.begin()+aa, res.begin()+bb);
    }

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<endl;
    }
}
