#ifndef NODE_H
#define NODE_H

#include <memory>
#include "ITreePart.h"
#include "Internode.h"
using namespace std;

class Node : public ITreePart {
public:
    Internode *parent;
    unique_ptr<ITreePart> primary;
    unique_ptr<ITreePart> secondary;

    Node();
    ITreePart* grow();
    void draw();
    void print();
};

#endif
