#ifndef ITREEPART_H
#define ITREEPART_H

class ITreePart {
    //ITreePart(ITreePart const &);
    //ITreePart &operator=(ITreePart const &);
public:
    //ITreePart();
    virtual ITreePart* grow() = 0;
    virtual void draw() = 0;
    virtual void print() = 0;
};

#endif
