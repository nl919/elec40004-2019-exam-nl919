#include "network.hpp"

complex<float> impedance(const Network &c, float omega)
{
    if(c.type=='R'){
        return {c.value, 0};

    }else if(c.type=='C'){
        return {0, -1/(omega*c.value) };

    }else{
        assert(false);
    }
}

vector<complex<float>> transfer_function(const Network &v1, const Network &v2, const vector<float> &omega)
{
    vector<complex<float>> res;

    // TODO

    return res;
}

vector<float> make_log10_space(float xLo, float xHi, int points)
{
    vector<float> res;

    // TODO

    return res;
}
