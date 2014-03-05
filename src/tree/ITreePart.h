#ifndef ITREEPART_H
#define ITREEPART_H
#include "../display/MeshCollection.h"
#include <Eigen/Geometry>
using namespace Eigen;

class ITreePart {
    ITreePart *parent;
    Vector3f position;
public:
    virtual ~ITreePart() {}
    virtual ITreePart* grow() = 0;
    virtual void draw(MeshCollection *mesh) = 0;
    virtual void print() = 0;

    void SetParent(ITreePart *parent) {
        this->parent = parent;
    }
};

#endif
