#include "network.hpp"

istream &operator>>(istream &src, Network &c)
{
    c.value=0;
    c.parts.clear();

    src>>c.type;
    if(src.fail()){
        return src;
    }

    if(c.type=='R' || c.type=='C' || c.type=='L'){
        src>>c.value;
    }else if(c.type=='('){
        c.type=0;
        c.value=0;

        Network x;
        char seperator;
        src>>x>>seperator;
        assert(!src.fail());
        c.parts.push_back(x);

        while(seperator!=')'){
            assert( seperator=='&' || seperator=='|' );
            assert( c.type==0 || c.type==seperator );
            c.type=seperator;
            src>>x>>seperator;
            assert(!src.fail());

            c.parts.push_back(x);
        }

        if(c.parts.size()==1){
            c.type='&';
        }
    }

    return src;
}


ostream &operator<<(ostream &dst, const Network &c)
{
    // TODO
    return dst;
}

vector<Network> create_test_networks()
{
    return {
        R(1),
        C(1),
        L(1)
        // TODO Make sure there are at least ten test-cases
    };
}
