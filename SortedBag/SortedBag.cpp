#include "SortedBag.h"
#include "SortedBagIterator.h"

//complexity: Theta(1)
SortedBag::SortedBag(Relation r) {
	//TODO - Implementation
    this->rel = r;
    this->capacity = 10;
    this->nrElems= 0;
    this->elements= new TComp[this->capacity];
}
//complexity: Theta(n)
void SortedBag::add(TComp e) {
	//TODO - Implementation
    if(this->nrElems == this->capacity){
        this->capacity *=2;
        TElem * newElem = new TComp[this->capacity];
        for(int i=0; i< this->nrElems; i++){
            newElem[i] = this->elements[i];
        }
        delete[] this->elements;
        this-> elements= newElem;
    }
    int index = 0;
    while (index < this->nrElems && this->rel(this-> elements[index],e)){
        index++;
    }
    for (int i = this->nrElems; i > index; i--) {
        this->elements[i] = this->elements[i - 1];
    }
    this->elements[index] = e;
    this->nrElems++;

}

//Comlexity: Theta(n)
bool SortedBag::remove(TComp e) {
	//TODO - Implementation
    for(int i=0;i<this->nrElems;i++){
        if(this->elements[i]==e){
            for(int j=i;j<this->nrElems-1;j++){
                this->elements[j]=this->elements[j+1];
            }
            this->nrElems--;
            return true;
        }
    }
    return false;
}

//complexity: best:Theta(1), worst: Theta(n), avg: Theta(n)
bool SortedBag::search(TComp elem) const {
	//TODO - Implementation
    for(int i = 0; i < this->nrElems; i++){
        if(this->elements[i] == elem){
            return true;
        }
    }
    return false;

}

//complexity: Theta(n)
int SortedBag::nrOccurrences(TComp elem) const {
	//TODO - Implementation
    int nr=0;
    for(int i=0;i<this->nrElems;i++){
        if(this->elements[i]==elem){
            nr++;
        }
    }
    return nr;
}


//complexity: Theta(1)
int SortedBag::size() const {
	//TODO - Implementation
    return this->nrElems;
}

//complexity: Theta(1)
bool SortedBag::isEmpty() const {
	//TODO - Implementation
    if(this->nrElems==0){
        return true;
    }
    return false;
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}

//complexity: Theta(1)
SortedBag::~SortedBag() {
	//TODO - Implementation
    delete [] this->elements;

}
