#include "tree.hpp"
#include "string_set.hpp"


int main(int argc, char **argv)
{
    if(argc==1){
        cerr<<"Need to specify which set to use."<<endl;
        exit(1);
    }

    cerr<<"Creating string set of type "<<argv[1]<<endl;
    StringSet *s=create_string_set(argv[1]);

    string v;
    while( cin >> v ){
        s->insert(v);
    }

    s->optimise();

    const tree_node *r = s->root();

    cout << "digraph G { "<<endl;

    // TODO: render the links between nodes

    cout << "}" << endl;
}
