
#include "tensor.hpp"

#include "matrix_tensor.hpp"






bool is_scalar(const Tensor *x)
{
    const vector<size_t> &d=x->size();
    for(size_t i=0; i<d.size(); i++){
        if(d[i]>1){
            return false;
        }
    }
    return true;
}

bool is_vector(const Tensor *x)
{
    // TODO
    const vector<size_t>& d = x->size();
    if (d.size() == 2)
    {
        if ((d[0] == 1 && d[1] > 1) || (d[0] > 1 && d[1] == 1))
        {
            return true;
        }
    }

    return false;
}

bool is_Matrix(const Tensor* x)
{
    const vector<size_t>& dim = x->size();
    
    if (dim.size() == 2 && dim[0] > 1 && dim[1] > 1)
        return true;

    return false;
}

size_t volume(const vector<size_t> &dims)
{
    size_t total=1;
    for(int i=0; i<dims.size(); i++){
        assert(dims[i]>0);
        total *= dims[i];
    }
    return total;
}

size_t index_to_offset(const vector<size_t> &size, const vector<size_t> &index, bool allow_broadcast)
{
    int offset=0;
    int prev_length=1;

    for(int i=0; i<size.size(); i++){
        size_t dim_length=size[i];
        size_t dim_offset=0;

        // Handle the various kinds of implicit extension and broadcasting
        if(i < index.size()){
            dim_offset=index[i];
            if( dim_offset >= dim_length){
                assert(allow_broadcast);
                dim_offset=0;
            }
        }

        offset = offset * prev_length + dim_offset;
        prev_length=dim_length;
    }
    for(int i=size.size(); i<index.size(); i++){
        assert(index[i]==0 || allow_broadcast);
    }
    return offset;
}

//
vector<size_t> offset_to_index(const vector<size_t> &size, size_t offset)
{
    vector<size_t> res(size.size(), 0);

    // 2d case
    if (size.size() == 2)
    {
        // How many lines befere
        size_t i = offset / size[0];
        size_t j = offset - i * size[0];

        res[0] = j;
        res[1] = i;
    }

    // 3d case
    if (size.size() == 3)
    {
        size_t tier = size[0] * size[1];

        size_t i = offset / tier;
        size_t j = (offset - i * tier) / size[1];
        size_t k = offset - i * tier - j * size[1];

        res[0] = k;
        res[1] = j;
        res[2] = i;
    }

    // Other
    return res;
}

void first_index(const vector<size_t> &size, vector<size_t> &index)
{
    index.resize(size.size(), 0);
}

bool next_index(const vector<size_t> &size, vector<size_t> &index)
{
    bool carry=true;
    for(int i=0; i<size.size(); i++){
        if(carry){
            if( index[i]+1 < size[i] ){
                index[i] += 1;
                carry=false;
            }else{
                index[i] = 0;
            }
        }
    }
    return !carry;
}


Tensor *create_tensor(const std::vector<size_t> &size)
{
    assert(size.size() >= 2); // We do not support order-0 or order-1 for simplicity

    if(size.size() == 2){
        return new MatrixTensor(size);
    }else{
        // TODO
        assert(false);
    }
}




size_t Tensor::order() const
{
    return this->m_size.size();
}

size_t Tensor::volume() const
{
    return ::volume(this->m_size);
}