#pragma once
#include "SortedBag.h"

class SortedBag;

class SortedBagIterator
{
	friend class SortedBag;

private:
	const SortedBag& bag;
	SortedBagIterator(const SortedBag& b);

	//TODO - Representation
    int position;
    int frequency;

    struct TComp {
        int value;
    };

public:
	int getCurrent();
	bool valid();
	void next();
	void first();

    bool valid() const;
};

