#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

//complexity: Theta(1)
SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
	//TODO - Implementation
    this->position = 0;
}

//complexity: Theta(1)
TComp SortedBagIterator::getCurrent() {
	//TODO - Implementation
    if(this->position>=this->bag.nrElems)
        throw exception();
    else{
        return this->bag.elements[this->position];
    }
    return NULL_TCOMP;

}

//complexity: Theta(1)
bool SortedBagIterator::valid() const {
	//TODO - Implementation
    return position < bag.nrElems;

}

//complexity: Theta(1)
void SortedBagIterator::next() {
	//TODO - Implementation
    if (valid()) {
        position += 1;
    } else {
        throw std::exception();
    }
}

//complexity: Theta(1)
void SortedBagIterator::first() {
	//TODO - Implementation
    this->position = 1; //0

}

