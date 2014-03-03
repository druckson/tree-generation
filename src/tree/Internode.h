#ifndef INTERNODE_H
#define INTERNODE_H

#include <memory>
#include "ITreePart.h"
using namespace std;

struct Internode : public ITreePart {
    unique_ptr<ITreePart> child;

    ITreePart* grow();
    void draw();
    void print();
};
#endif
