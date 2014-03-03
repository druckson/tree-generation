#ifndef ITREEPART_H
#define ITREEPART_H

class ITreePart {
    //ITreePart(ITreePart const &) = delete;
    //ITreePart &operator=(ITreePart const &) = delete;
public:
    //ITreePart();
    virtual ~ITreePart() {}
    virtual ITreePart* grow() = 0;
    virtual void draw() = 0;
    virtual void print() = 0;
};

#endif
