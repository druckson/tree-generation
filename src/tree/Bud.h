#ifndef BUD_H
#define BUD_H

//  Bud options:
//      Branch
//      Flower
//      Dormant
//      Die
#include <memory>
#include "ITreePart.h"
using namespace std;

enum BudFate {
    Branch,
    Flower,
    Dormant
};

class Bud : public ITreePart {
    BudFate fate;
public:
    Bud();
    Bud(BudFate fate);
    ITreePart* grow();
    void draw();
    void print();
};

#endif
