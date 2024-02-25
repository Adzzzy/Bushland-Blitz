#include <iostream>
#include "items.h"

// generic move functions
items::items() {
    std::string name = "NULL";
}

items::items(std::string name) {
    this->name = name;
}

items::~items() {

}
