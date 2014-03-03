#include <iostream>
#include <memory>
#include "Bud.h"
#include "Node.h"
#include "Internode.h"
using namespace std;

Bud::Bud() {}

Bud::Bud(BudFate fate) {
    this->fate = Branch;
}

ITreePart* Bud::grow() {
    auto internode = new Internode(); 
    auto node = new Node(new Bud(), new Bud()); 
    //node->parent = internode;
    internode->child.reset(node);
    //internode->parent = parent;
    return internode;
}

void Bud::draw() {

}

void Bud::print() {
    cout << "Bud: " << sizeof(*this) << endl;
}
