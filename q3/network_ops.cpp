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


Network canonicalise(const Network &x)
{
    // TODO
}
