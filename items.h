#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>

// items class
class items {
public:
	items();
    items(std::string name);

    std::string name;

	~items();
};

#endif
