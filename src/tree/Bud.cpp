#include <iostream>
#include <memory>
#include "Bud.h"
#include "Node.h"
#include "Internode.h"
using namespace std;

Bud::Bud() {}

Bud::Bud(BudFate fate) {
    this->fate = fate;
}

ITreePart* Bud::grow() {
    if (this->fate == Branch) {
        auto internode = new Internode(); 

        BudFate fate1;
        if (rand() % 100 < 100) {
            fate1 = Branch;
        } else {
            fate1 = Dormant;
        }

        BudFate fate2;
        if (rand() % 100 < 1) {
            fate2 = Branch;
        } else {
            fate2 = Dormant;
        }

        auto node = new Node(new Bud(fate1), new Bud(fate2)); 
        //node->parent = internode;
        internode->child.reset(node);
        //internode->parent = parent;
        return internode;
    } else {
        return this;
    }
}

void Bud::draw() {}

void Bud::print() {
    cout << "Bud: " << sizeof(*this) << endl;
}
