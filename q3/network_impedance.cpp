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
    float begin = log10(xLo);
    float end = log10(xHi);
    float h = (end - begin) / (points - 1);

    vector<float> pts;
    pts.push_back(xLo);

    for (int i = 1; i < points - 1; i++)
    {
        float tmp = begin + i * h;
        tmp = powf(10, tmp);
        pts.push_back(tmp);
    }

    pts.push_back(xHi);
    return pts;
}
