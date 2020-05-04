#include "string_set.hpp"
#include "unbalanced_string_set.hpp"
#include "random_balance_string_set.hpp"

StringSet *create_string_set(const string &name)
{
    if(name=="UnbalancedStringSet"){
        return new UnbalancedStringSet();
    }else if(name=="RandomBalanceStringSet"){
        return new RandomBalanceStringSet();
    }else{
        cerr<<"Unknown string set "<<name<<endl;
    }
}
