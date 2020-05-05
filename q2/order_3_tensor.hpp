#pragma once

#include "tensor.hpp"
#include "matrix_tensor.hpp"

class Order3Tensor :
	public Tensor
{
protected:
	vector<size_t> m_size;
	vector<MatrixTensor> data;

public: 
	Order3Tensor(vector<size_t> dim)
	{	

	}

	const vector<size_t>& size() const override
	{
		return m_size;
	}


};

