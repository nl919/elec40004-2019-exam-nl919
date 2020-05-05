#include "network.hpp"

complex<float> impedance(const Network& c, float omega)
{
    if (c.type == 'R')
        return { c.value, 0 };

    else if (c.type == 'C')
        return { 0, -1 / (omega * c.value) };

    else if (c.type == 'L')
        return { 0, omega * c.value };

    else if (c.type == '|')
    {
        complex<float> sum = { 0,0 };
        for (int i = 0; i < c.parts.size(); i++)
            sum += impedance(c.parts[i], omega);

        return sum;
    }

    else if (c.type == '|')
    {
        complex<float> sum = { 1,0 };
        for (int i = 0; i < c.parts.size(); i++)
            sum += complex<float>(1, 0) / impedance(c.parts[i], omega);

        return complex<float>(1, 0) / sum;
    }
}

vector<complex<float>> transfer_function(const Network &v1, const Network &v2, const vector<float> &omega)
{
    vector<complex<float>> res;

    for (int i = 0; i < omega.size(); i++)
        res.insert(res.begin(),
            impedance(v2, omega[i]) / (impedance(v1, omega[i]) + impedance(v2, omega[i])));

    return res;
}

vector<float> make_log10_space(float xLo, float xHi, int points)
{
    vector<float> res;

    // TODO

    return res;
}
