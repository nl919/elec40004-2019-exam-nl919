#ifndef string_set_hpp
#define string_set_hpp

#include "tree.hpp"

/* Represents a set of strings.*/
class StringSet
{
public:
    virtual ~StringSet()
    {}

    // Insert the given string. Does nothing if it already exists
    virtual void insert(const string &x) =0;

    // Checks whether the given string exists in the set
    virtual bool contains(const string &x) const =0;

    // Attempt to optimise the structure to improve performance
    /*! May do nothing. */
    virtual void optimise() =0;

    // Return a read-only view on the root of the underlying tree
    virtual const tree_node *root() const=0;
};

/* Create a StringSet based on the given implementation name */
StringSet *create_string_set(const string &name);

#endif
