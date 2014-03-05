#ifndef TREE_H
#define TREE_H

#include <memory>
#include "Bud.h"
#include "ITreePart.h"
using namespace std;

class Tree {
    unique_ptr<ITreePart> shoot;
    unique_ptr<ITreePart> root;
public:
    Tree();
    void grow();
    void draw(MeshCollection *meshes);
    void print();
};

#endif
