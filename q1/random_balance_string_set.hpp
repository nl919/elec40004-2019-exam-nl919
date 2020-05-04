#ifndef random_balance_string_set_hpp
#define random_balance_string_set_hpp

#include "string_set.hpp"

#include <random>

struct RandomBalanceStringSet
    : public UnbalancedStringSet
{
    mt19937 rng;

    RandomBalanceStringSet()
    {
        rng.seed(time(0));
    }

    void optimise() override
    {
        m_root=tree_rebuild_random(m_root, rng);
    }
};

#endif
