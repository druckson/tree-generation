#ifndef BUD_H
#define BUD_H

//  Bud options:
//      Branch
//      Flower
//      Dormant
//      Die
#include <memory>
#include "ITreePart.h"
#include "Node.h"
#include "Internode.h"
using namespace std;

class Bud : public ITreePart {
    ITreePart *parent;

public:
    Bud();
    ITreePart* grow();
    void draw();
    void print();
};

#endif
