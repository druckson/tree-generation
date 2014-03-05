#ifndef ITREEPART_H
#define ITREEPART_H
#include "../display/MeshCollection.h"
#include "../Vec3.h"

class ITreePart {
    ITreePart *parent;
    Vec3 position;
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
