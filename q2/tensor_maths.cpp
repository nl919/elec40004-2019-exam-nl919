
#include "tensor.hpp"

Tensor* innerProduct(const Tensor* a, const Tensor* b)
{
    float sum = 0;
    int i;
    vector<size_t> ia;
    ia.resize(a->size().size(), 0);
    first_index(a->size(), ia);
    vector<size_t> ib;
    ib.resize(b->size().size());
    first_index(b->size(), ib);

    for (i = 0; i < a->volume(); i++)
    {
        sum += a->read(ia) * b->read(ib);
        next_index(a->size(), ia);
        next_index(b->size(), ib);
    }

    vector<size_t> dim;
    dim.push_back(1);
    dim.push_back(1);

    Tensor* res = create_tensor(dim);

    vector<size_t> ir;
    ir.resize(dim.size(), 0);
    first_index(res->size(), ir);
    res->write(ir, sum);

    return res;
}

Tensor* multiplyWithBroadcast(const Tensor* a, const Tensor* s)
{
    // a is a tensor, s is a scalar
    Tensor* res = create_tensor(a->size());

    vector<size_t> index;
    first_index(s->size(), index);
    float scalar = s->read(index);

    index.resize(a->size().size(), 0);
    first_index(a->size(), index);

    do
    {
        float tmp = a->read(index) * scalar;
        res->write(index, tmp);
    } while (next_index(a->size(), index));

    return res;

}

Tensor *multiply(const Tensor *a, const Tensor *b)
{
    // a or b is a scalar, use broadcast
    if (::is_scalar(a))
    {
        return multiplyWithBroadcast(b, a);
    }

    if (::is_scalar(b))
    {
        return multiplyWithBroadcast(a, b);
    }

    // a and b are vectors
    if (is_vector(a) && is_vector(b) && a->volume() == b->volume())
    {   
        return innerProduct(a, b);
    }

    // a and b are both matrix
    vector<size_t> dimA = a->size();
    vector<size_t> dimB = b->size();
    if (is_Matrix(a) && is_Matrix(b) && dimA[0] == dimB[1])
    {
        vector<size_t> dimRes;
        dimRes.push_back(dimB[0]);
        dimRes.push_back(dimA[1]);
        Tensor* res = create_tensor(dimRes);

        vector<size_t> index;
        index.resize(2, 0);
        first_index(res->size(), index);

        do
        {
            float sum = 0;
            size_t k;
            vector<size_t> ia;
            vector<size_t> ib;

            ia.push_back(0);
            ia.push_back(index[1]);

            ib.push_back(index[0]);
            ib.push_back(0);
            for (k = 0; k < dimA[0]; k++)
            {
                sum += a->read(ia) * b->read(ib);
                ia[0]++;
                ib[1]++;
            }

            res->write(index, sum);
        } while (next_index(res->size(), index));

        return res;
    }

    return 0;
}


bool isDimensionMatch(const Tensor* a, const Tensor* b)
{
    if (a->size().size() != b->size().size())
        return false;

    size_t i;
    const vector<size_t>& dimA = a->size();
    const vector<size_t>& dimB = b->size();
    for (i = 0; i < a->size().size(); i++)
    {
        if (dimA[i] != dimB[i])
            return false;
    }

    return true;
}

Tensor* addWithScalar(const Tensor* a, const Tensor* s)
{
    Tensor* res = create_tensor(a->size());

    vector<size_t> index;
    first_index(s->size(), index);
    float scalar = s->read(index);

    index.resize(a->size().size(), 0);
    first_index(a->size(), index);

    do
    {
        float tmp = a->read(index) + scalar;
        res->write(index, tmp);
    } while (next_index(a->size(), index));

    return res;
}

Tensor *add(const Tensor *a, const Tensor *b)
{
    // Use read and write defined in Tensor, the base class
    if (isDimensionMatch(a, b))
    {
        Tensor* res = create_tensor(a->size());

        vector<size_t> index;
        index.resize(a->size().size(), 0);
        first_index(a->size(), index);

        do
        {
            float tmp = a->read(index) + b->read(index);
            res->write(index, tmp);
        } while (next_index(a->size(), index));

        return res;
    }
    else
    {
        // If one tensor is a scalar, use broadcast
        if (::is_scalar(a))
        {
            return addWithScalar(b, a);
        }

        // If one tensor is a vector, use broadcase and add line by line
        if (::is_scalar(b))
        {
            return addWithScalar(a, b);
        }
    }

    return create_tensor({1,1});
}
