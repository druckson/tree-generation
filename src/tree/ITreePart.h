#ifndef ITREEPART_H
#define ITREEPART_H

class ITreePart {
    //ITreePart(ITreePart const &) = delete;
    //ITreePart &operator=(ITreePart const &) = delete;

    ITreePart *parent;
public:
    //ITreePart();
    virtual ~ITreePart() {}
    virtual ITreePart* grow() = 0;
    virtual void draw() = 0;
    virtual void print() = 0;

    void SetParent(ITreePart *parent) {
        this->parent = parent;
    }
};

#endif
