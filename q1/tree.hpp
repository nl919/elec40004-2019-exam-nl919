#ifndef tree_hpp
#define tree_hpp

#include <string>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <cassert>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <utility>

using namespace std;

struct tree_node
{
    string value;
    tree_node *left;
    tree_node *right;
};

// Recursively free all nodes pointed to by node.
void tree_free(tree_node *root);

// Return the total number of nodes in the tree
int tree_size(const tree_node *node);

// Return the height from the root to the furthest branch.
// An empty tree has height 0, a single node has height 1, ...
int tree_height(const tree_node *node);

// Calculate the balance property, based on node count and height
float tree_balance(const tree_node *node);

// Return true if the tree contains the given value
bool tree_contains(const tree_node *root, const string &value);

// Insert the given node into the tree if it does not already exist
tree_node *tree_insert(tree_node *root_node, const string &value);

// Insert the node into the tree based on the nodes value. If the
// value already exists, then free the new_node.
tree_node *tree_insert(tree_node *root_node, tree_node *new_node);

// Add nodes in the tree to vector. The nodes could appear any order
void tree_collect_nodes(vector<tree_node*> &nodes, tree_node *root);

// Add nodes in the tree to vector, storing nodes in value order
void tree_collect_nodes_in_order(vector<tree_node*> &nodes, tree_node *root);

// Return true if the vector of node pointers is sorted according to the node values
bool are_nodes_ordered(const vector<tree_node*> &nodes);

// Rebuild tree by inserting nodes in a random order.
tree_node *tree_rebuild_random(tree_node *root, mt19937 &rng);

// Rebuild tree by extracing in-order nodes then reconstructing a balanced tree
tree_node *tree_rebuild_balanced(tree_node *root);

#endif
