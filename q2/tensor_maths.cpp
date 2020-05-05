
#include "tensor.hpp"

Tensor *multiply(const Tensor *a, const Tensor *b)
{
    // Use read and write defined in Tensor, the base class
    return create_tensor({1,1});
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

Tensor *add(const Tensor *a, const Tensor *b)
{
    // Use read and write defined in Tensor, the base class
    if (isDimensionMatch(a, b))
    {
        Tensor* res = create_tensor(a->size());

        size_t i;
        for (i = 0; i < a->volume(); i++)
        {
            // we need the loop
            //float tmp = a->read()
        }
    }
    else
    {

    }

    return create_tensor({1,1});
}
