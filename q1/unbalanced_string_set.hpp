#ifndef tree_string_set_hpp
#define tree_string_set_hpp

#include "string_set.hpp"

struct UnbalancedStringSet
    : public StringSet
{
    tree_node *m_root;
    int m_size;
    int m_added;

    UnbalancedStringSet()
    {
        m_root=nullptr;
        m_size=0;
        m_added=0;
    }

    ~UnbalancedStringSet() override
    {
        tree_free(m_root);
    }

    void insert(const string &x) override
    {
        m_root = tree_insert(m_root, x);
        m_size++;
        m_added++;
        if( 2*m_added >= m_size ){
            optimise();
        }
    }

    bool contains(const string &x) const override
    {
        return tree_contains(m_root, x);
    }

    virtual void optimise()
    {
        // Does nothing for this class
    }

    const tree_node *root() const
    {
        return m_root;
    }
};

#endif
