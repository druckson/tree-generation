#ifndef NODE_H
#define NODE_H

#include <memory>
#include "ITreePart.h"
#include "Internode.h"
#include "Bud.h"
using namespace std;

class Node : public ITreePart {
    Internode *parent;
    unique_ptr<ITreePart> primary;
    unique_ptr<ITreePart> secondary;
public:
    Node();
    Node(ITreePart *branch1, ITreePart *branch2);
    ITreePart* grow();
    void draw(Affine3f transform, MeshCollection *meshes);
    void print();
};

#endif
