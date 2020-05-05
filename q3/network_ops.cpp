#include "network.hpp"
#include "algorithm"

Network R(float v)
{
    return {'R', v, {} };
}

Network C(float v)
{
    return {'C', v, {} };
}

Network L(float v)
{
    return {'L', v, {} };
}


bool operator==(const Network &a, const Network &b)
{
    if(a.type != b.type) return false;
    if(a.value != b.value) return false;
    return a.parts == b.parts;
}

bool operator<(const Network& a, const Network& b)
{
    if (a.type != b.type)
        return a.type < b.type;
    
    if (is_primitive(a))
        return a.value < b.value;

    for (int i = 0; i < min(a.parts.size, b.parts.size); i++)
    {
        if (a.parts[i] == b.parts[i])
            continue;

        return a.parts[i] < b.parts[i];
    }

    return a.parts.size < b.parts.size;
}

Network operator|(const Network &a, const Network &b)
{
    return Network{'|', 0, {a,b} };
}

Network operator&(const Network &a, const Network &b)
{
    return Network{'&', 0, {a,b} };
}

bool is_primitive(const Network& a)
{
    switch (a.type)
    {
    case 'R':
    case 'L':
    case 'C':
        return true;
    default:
        return false;
    }
}

bool is_composite(const Network &a)
{
    return !is_primitive(a);
}


Network canonicalise(Network &x)
{
    if (is_primitive(x))
        return x;

    auto parts = x.parts;
    for (int i = 0; i < *x.parts.size; i++)
        parts[i] = canonicalise(parts[i]);

    parts = flatten(x);
    parts = sort(x);

    return x;
}

vector<Network> flatten(Network& network)
{
    vector<Network> result;
    if (is_primitive(network))
        return { network };

    for (int i = 0; i < network.parts.size; i++)
    {
        auto subNetwork = network.parts[i];
        if (is_composite(subNetwork) && subNetwork.type == network.type)
        {
            for (int i = 0; i < subNetwork.parts.size; i++)
            {
                if (is_primitive(subNetwork.parts[i]))
                {
                    network.parts.insert(network.parts.end, subNetwork.parts[i]);
                    subNetwork.parts.
                }
                else
                    flatten(subNetwork);
            }
        }
    }
}

vector<Network> sort(Network& network)
{
    if (is_primitive(network))
        return network.parts;

    for (int i = network.parts.size - 1; i > 0; i--)
        for (int j = i; j >= 0; i--)
        {
            if (network.parts[i] < network.parts[i - 1])
            {
                auto temp = network.parts[i];
                network.parts[i] = network.parts[i - 1];
                network.parts[i - 1] = temp;
            }
        }

    return network.parts;
}