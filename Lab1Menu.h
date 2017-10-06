//
// Created by ddf19 on 05.10.2017.
//

#ifndef LAB1_BACKEND_LAB1MENU_H
#define LAB1_BACKEND_LAB1MENU_H


#include <iostream>
#include <cstdlib>
#include <sstream>
#include <map>
#include <memory>
#include <ctime>
#include <limits>
#include "Sequence.h"
#include "ListSequence.h"
#include "ArraySequence.h"
#include "SequenceSorts.h"

class Lab1Menu {
private:
    typedef void (Lab1Menu::*menuFuncType)(std::istream&, std::ostream&);

    std::map<std::string, menuFuncType> funcMap;
    std::map<std::string, std::unique_ptr<Sequence<int>>> objPtrMap;

    void createRandomSequence(std::istream&, std::ostream&);

    void createNewSequence(std::istream&, std::ostream&);

    void appendElement(std::istream&, std::ostream&);

    void prependElement(std::istream&, std::ostream&);

    void getSubsequence(std::istream&, std::ostream&);

    void getElement(std::istream&, std::ostream&);

    void showSequence(std::istream&, std::ostream&);

    void showAllObjects(std::istream&, std::ostream&);

    void showSizeOfSequence(std::istream&, std::ostream&);

    void copySequence(std::istream&, std::ostream&);

    void removeSequence(std::istream&, std::ostream&);

    void clearSequence(std::istream&, std::ostream&);

    void insertElement(std::istream&, std::ostream&);

    void compareSorts(std::istream&, std::ostream&);

    void sortSequence(std::istream&, std::ostream&);

    void compareSequencesBySort(std::istream&, std::ostream&);

    void help(std::istream&, std::ostream&);

    void nea(std::istream &inputStream);

    void tma(std::istream &inputStream);

public:

    Lab1Menu();

    void menuCycle(std::istream&, std::ostream&);

};


#endif //LAB1_BACKEND_LAB1MENU_H
