
#include "tensor.h"

#include "matrix_tensor.h"


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


vector<size_t> offset_to_index(const vector<size_t> &size, int offset)
{
vector<size_t> res(size.size(), 0);

    // TODO

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
