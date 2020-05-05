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

    for (int i = 0; i < min(a.parts.size(), b.parts.size()); i++)
    {
        if (a.parts[i] == b.parts[i])
            continue;

        return a.parts[i] < b.parts[i];
    }

    return a.parts.size() < b.parts.size();
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
    for (int i = 0; i < x.parts.size(); i++)
        parts[i] = canonicalise(parts[i]);

    parts = flatten(x.type, parts);
    parts = sort(parts);

    return {x.type, x.value, parts};
}

vector<Network> flatten(char type, vector<Network> parts)
{
    vector<Network> result;

    for (int i = 0; i < parts.size(); i++)
    {
        if (is_primitive(parts[i]))
            result.insert(result.end, parts[i]);

        vector<Network> temp;
        {
            auto subNetwork = parts[i];

            if (is_composite(subNetwork) && subNetwork.type == type)
                temp.insert(temp.end(), subNetwork.parts.begin(), subNetwork.parts.end());
        }

        parts.insert(parts.end(), temp.begin(), temp.end());
        for (vector<Network>::iterator itor = temp.begin(); itor != temp.end(); ++itor)
        {
            parts.erase(itor);
        }
    }
    
    return result;
}

vector<Network> sort(vector<Network> parts)
{
    if (parts.size < 2 )
        return parts;

    for (int i = parts.size() - 1; i > 0; i--)
        for (int j = i; j >= 0; i--)
        {
            if (parts[i] < parts[i - 1])
            {
                auto temp = parts[i];
                parts[i] = parts[i - 1];
                parts[i - 1] = temp;
            }
        }

    return parts;
}