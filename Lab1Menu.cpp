//
// Created by ddf19 on 05.10.2017.
//

#include "Lab1Menu.h"

void Lab1Menu::showSizeOfSequence(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::tma(inputStream);
    auto objPtr = objPtrMap.find(nameOfSequence);
    if (objPtr != objPtrMap.end()) {
        outputStream << objPtr -> second -> getLength() << std::endl;
    } else {throw std::logic_error("sequence doesn't exist");}
}

void Lab1Menu::createNewSequence(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence;
    std::string typeOfSequence;
    Lab1Menu::nea(inputStream);
    inputStream >> typeOfSequence;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::tma(inputStream);
    Sequence<int>* newObject = nullptr;
    if (typeOfSequence == "ArraySequence") {newObject = new ArraySequence<int>;}
    else if (typeOfSequence == "ListSequence") {newObject = new ListSequence<int>;}
    else {throw std::logic_error("incorrect type");}
    objPtrMap[nameOfSequence].reset(newObject);
    outputStream << "new sequence of type " << typeOfSequence
                 << " named " << nameOfSequence << " added\n";
}

void Lab1Menu::appendElement(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence, intString;
    Lab1Menu::nea(inputStream);
    inputStream >> intString;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::tma(inputStream);
    int intToAppend = std::stoi(intString);
    auto objPtr = objPtrMap.find(nameOfSequence);
    if (objPtr != objPtrMap.end()) {
        objPtr -> second -> append(intToAppend);
        outputStream << "value " << intToAppend
                     << " appended to sequence "
                     << nameOfSequence << std::endl;
    } else {throw std::logic_error("sequence doesn't exist");}

}

void Lab1Menu::prependElement(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence, intString;
    Lab1Menu::nea(inputStream);
    inputStream >> intString;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::tma(inputStream);
    int intToAppend = std::stoi(intString);
    auto objPtr = objPtrMap.find(nameOfSequence);
    if (objPtr != objPtrMap.end()) {
        objPtr -> second -> prepend(intToAppend);
        outputStream << "value " << intToAppend
                     << " prepended to sequence "
                     << nameOfSequence << std::endl;
    } else {throw std::logic_error("sequence doesn't exist");}
}

void Lab1Menu::getSubsequence(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence, leftEdgeString, rightEdgeString, nameOfDestSequence;
    inputStream >> leftEdgeString;
    Lab1Menu::nea(inputStream);
    inputStream >> rightEdgeString;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfDestSequence;
    Lab1Menu::tma(inputStream);
    int leftEdge = std::stoi(leftEdgeString);
    int rightEdge = std::stoi(rightEdgeString);
    auto objPtr = objPtrMap.find(nameOfSequence);
    if (objPtr != objPtrMap.end()) {
        auto newObjPtr = objPtr -> second -> getSubsequence(leftEdge, rightEdge);
        objPtrMap[nameOfDestSequence].reset(newObjPtr);
        outputStream << "subsequence of" << nameOfSequence
                     << " named " << nameOfDestSequence
                     << " created\n";
    } else {throw std::logic_error("sequence doesn't exist");}
}

void Lab1Menu::getElement(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence, elementIndexString;
    Lab1Menu::nea(inputStream);
    inputStream >> elementIndexString;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::tma(inputStream);
    int index = std::stoi(elementIndexString);
    auto objPtr = objPtrMap.find(nameOfSequence);
    if (objPtr != objPtrMap.end()) {
        outputStream << objPtr -> second -> getConst(index) << std::endl;
    } else {throw std::logic_error("sequence doesn't exist");}
}

void Lab1Menu::showSequence(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::tma(inputStream);
    auto objPtr = objPtrMap.find(nameOfSequence);
    if (objPtr != objPtrMap.end()) {
        auto size = objPtr -> second -> getLength();
        for (auto i = 0; i < size; ++i) {
            outputStream << objPtr -> second -> getConst(i) << " ";
        }
        outputStream << std::endl;
    } else {throw std::logic_error("sequence doesn't exist");}

}

void Lab1Menu::showAllObjects(std::istream& inputStream, std::ostream& outputStream) {
    Lab1Menu::tma(inputStream);
    for (auto& couple : objPtrMap) {
        outputStream << couple.first << " ";
    }
    outputStream << std::endl;
}

void Lab1Menu::copySequence(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence;
    std::string nameOfCopySequence;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfCopySequence;
    Lab1Menu::tma(inputStream);
    auto objPtr = objPtrMap.find(nameOfSequence);
    if (objPtr != objPtrMap.end()) {
        auto newObjPtr = objPtr -> second -> copy();
        objPtrMap[nameOfCopySequence].reset(newObjPtr);
        outputStream << "copy of" << nameOfSequence
                     << " named " << nameOfCopySequence
                     << " created\n";
    } else {throw std::logic_error("sequence doesn't exist");}
}

void Lab1Menu::removeSequence(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::tma(inputStream);
    auto count = objPtrMap.erase(nameOfSequence);
    if (count) {
        outputStream << "sequence named " << nameOfSequence
                     << " removed\n";
    } else {outputStream << "sequence doesn't exist\n";}
}

void Lab1Menu::clearSequence(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    if (nameOfSequence.empty()) {throw std::logic_error("not enough arguments");}
    Lab1Menu::tma(inputStream);
    auto objPtr = objPtrMap.find(nameOfSequence);
    if (objPtr != objPtrMap.end()) {
        objPtr -> second -> clear();
        outputStream << "sequence " << nameOfSequence << " cleared\n";
    } else {throw std::logic_error("sequence doesn't exist");}
}

void Lab1Menu::insertElement(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence, elementIndexString, intString;
    Lab1Menu::nea(inputStream);
    inputStream >> intString;
    Lab1Menu::nea(inputStream);
    inputStream >> elementIndexString;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::tma(inputStream);
    int index = std::stoi(elementIndexString);
    int intToAppend = std::stoi(intString);
    auto objPtr = objPtrMap.find(nameOfSequence);
    if (objPtr != objPtrMap.end()) {
        objPtr -> second -> insertAt(index, intToAppend);
        outputStream << "value " << intToAppend
                     << " insertet to position "
                     << index << " to sequence "
                     << nameOfSequence << std::endl;
    } else {throw std::logic_error("sequence doesn't exist");}

}

void Lab1Menu::compareSorts(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::tma(inputStream);
    auto objPtr = objPtrMap.find(nameOfSequence);
    if (objPtr != objPtrMap.end()) {
        auto srcObjPtr = (objPtr -> second).get();

        auto shellTime1 = std::time(nullptr);
        std::unique_ptr<Sequence<int>> shellSorted(SequenceSorts<int>::shellSort(srcObjPtr, exampleFunctionsForSort::cmp,
                                                             exampleFunctionsForSort::stepFunc));
        auto shellTime2 = std::time(nullptr);


        auto shakerTime1 = std::time(nullptr);
        std::unique_ptr<Sequence<int>> shakerSorted(SequenceSorts<int>::shakerSort(srcObjPtr, exampleFunctionsForSort::cmp));
        auto shakerTime2 = std::time(nullptr);

        auto countingTime1 = std::time(nullptr);
        std::unique_ptr<Sequence<int>> countingSorted(SequenceSorts<int>::countingSort(srcObjPtr));
        auto countingTime2 = std::time(nullptr);

        outputStream << "shaker sort : " << shakerTime2 - shakerTime1 << std::endl
                     << "counting sort : " << countingTime2 - countingTime1 << std::endl
                     << "shell sort : " << shellTime2 - shakerTime1 << std::endl;

    } else {throw std::logic_error("sequence doesn't exist");}
}

void Lab1Menu::sortSequence(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence;
    std::string typeOfSort;
    std::string nameOfDestSequence;
    Lab1Menu::nea(inputStream);
    inputStream >> typeOfSort;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfDestSequence;
    Lab1Menu::tma(inputStream);
    Sequence<int>* newObject = nullptr;
    auto objPtr = objPtrMap.find(nameOfSequence);
    if (objPtr != objPtrMap.end()) {
        if (typeOfSort == "shell") {
            newObject = SequenceSorts<int>::shellSort((objPtr -> second).get(),
                                                      exampleFunctionsForSort::cmp,
                                                      exampleFunctionsForSort::stepFunc);

        } else if (typeOfSort == "shaker") {
            newObject = SequenceSorts<int>::shakerSort((objPtr -> second).get(),
                                                      exampleFunctionsForSort::cmp);
        } else if (typeOfSort == "counting") {
            newObject = SequenceSorts<int>::countingSort((objPtr -> second).get());
        } else {throw std::logic_error("type of sort doesn't implemented");}
        objPtrMap[nameOfDestSequence].reset(newObject);
        outputStream << "sorted sequence " << nameOfSequence
                     << " by " << typeOfSort << " sort named "
                     << nameOfDestSequence << " added\n";
    } else {throw std::logic_error("sequence doesn't exist");}
}

void Lab1Menu::compareSequencesBySort(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence;
    std::string typeOfSort;
    Lab1Menu::nea(inputStream);
    inputStream >> typeOfSort;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::tma(inputStream);
    std::unique_ptr<Sequence<int>> tempArraySequencePtr;
    std::unique_ptr<Sequence<int>> tempListSequencePtr;
    std::unique_ptr<Sequence<int>> tempSortedSequencePtr;
    auto objPtr = objPtrMap.find(nameOfSequence);
    if (objPtr != objPtrMap.end()) {
        auto size = objPtr -> second -> getLength();
        tempArraySequencePtr.reset(new ArraySequence<int>);
        tempListSequencePtr.reset(new ListSequence<int>);
        for (auto i = 0; i < size; ++i) {
            int tempObj = objPtr -> second -> get(i);
            tempArraySequencePtr -> append(tempObj);
            tempListSequencePtr -> append(tempObj);
        }
        if (typeOfSort == "shell") {
            auto listTime1 = std::time(nullptr);
            tempSortedSequencePtr.reset(SequenceSorts<int>::shellSort(tempListSequencePtr.get(),
                                                                      exampleFunctionsForSort::cmp,
                                                                      exampleFunctionsForSort::stepFunc));
            auto listTime2 = std::time(nullptr);
            tempSortedSequencePtr.reset(nullptr);
            auto arrayTime1 = std::time(nullptr);
            tempSortedSequencePtr.reset(SequenceSorts<int>::shellSort(tempArraySequencePtr.get(),
                                                                      exampleFunctionsForSort::cmp,
                                                                      exampleFunctionsForSort::stepFunc));
            auto arrayTime2 = std::time(nullptr);
            outputStream << "ListSequence : " << listTime2 - listTime1 << std::endl
                         << "ArraySequence : " << arrayTime2 - arrayTime1 << std::endl;

        } else if (typeOfSort == "shaker") {
            auto listTime1 = std::time(nullptr);
            tempSortedSequencePtr.reset(SequenceSorts<int>::shakerSort(tempListSequencePtr.get(),
                                                                      exampleFunctionsForSort::cmp));
            auto listTime2 = std::time(nullptr);
            tempSortedSequencePtr.reset(nullptr);
            auto arrayTime1 = std::time(nullptr);
            tempSortedSequencePtr.reset(SequenceSorts<int>::shakerSort(tempArraySequencePtr.get(),
                                                                      exampleFunctionsForSort::cmp));
            auto arrayTime2 = std::time(nullptr);
            outputStream << "ListSequence : " << listTime2 - listTime1 << std::endl
                         << "ArraySequence : " << arrayTime2 - arrayTime1 << std::endl;
        } else if (typeOfSort == "counting") {
            auto listTime1 = std::time(nullptr);
            tempSortedSequencePtr.reset(SequenceSorts<int>::countingSort(tempListSequencePtr.get()));
            auto listTime2 = std::time(nullptr);
            tempSortedSequencePtr.reset(nullptr);
            auto arrayTime1 = std::time(nullptr);
            tempSortedSequencePtr.reset(SequenceSorts<int>::countingSort(tempArraySequencePtr.get()));
            auto arrayTime2 = std::time(nullptr);
            outputStream << "ListSequence : " << listTime2 - listTime1 << std::endl
                         << "ArraySequence : " << arrayTime2 - arrayTime1 << std::endl;
        } else {throw std::logic_error("type of sort doesn't implemented");}
    } else {throw std::logic_error("sequence doesn't exist");}
}

Lab1Menu::Lab1Menu() {

    funcMap["get_size"] = &Lab1Menu::showSizeOfSequence;
    funcMap["new"] = &Lab1Menu::createNewSequence;
    funcMap["append"] = &Lab1Menu::appendElement;
    funcMap["prepend"] = &Lab1Menu::prependElement;
    funcMap["subsequence"] = &Lab1Menu::getSubsequence;
    funcMap["show"] = &Lab1Menu::showSequence;
    funcMap["show_all"] = &Lab1Menu::showAllObjects;
    funcMap["copy"] = &Lab1Menu::copySequence;
    funcMap["remove"] = &Lab1Menu::removeSequence;
    funcMap["clear"] = &Lab1Menu::clearSequence;
    funcMap["insert"] = &Lab1Menu::insertElement;
    funcMap["compare_sorts"] = &Lab1Menu::compareSorts;
    funcMap["sort"] = &Lab1Menu::sortSequence;
    funcMap["compare_sequences_by_sorts"] = &Lab1Menu::compareSequencesBySort;
    funcMap["get_element"] = &Lab1Menu::getElement;
    funcMap["help"] = &Lab1Menu::help;
    funcMap["random_sequence"] = &Lab1Menu::createRandomSequence;
}

void Lab1Menu::menuCycle(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfCommand;
    do {
        inputStream >> nameOfCommand;
        if(nameOfCommand == "exit") {
            outputStream << "goodbye\n";
            break;
        }
        auto commandPtr = funcMap.find(nameOfCommand);
        if (commandPtr != funcMap.end()) {
            menuFuncType currentFunc = commandPtr->second;
            try {
                (this ->* currentFunc)(inputStream, outputStream);
            } catch(std::exception& expt) {outputStream << expt.what() << std::endl;}
        }  else {outputStream << "command doesn't exist\n"; }
        inputStream.ignore(std::numeric_limits<std::streamsize>::max(), inputStream.widen('\n'));

    } while(true);
}

void Lab1Menu::help(std::istream& inputStream, std::ostream& outputStream) {
    Lab1Menu::tma(inputStream);
    for (auto& couple : funcMap) {
        outputStream << couple.first << " ";
    }
    outputStream << std::endl;

}

void Lab1Menu::nea(std::istream& inputStream) {
    while (inputStream.peek() == ' ') {inputStream.get();}
    if (inputStream.peek() == '\n') {throw std::logic_error("not enough arguments");}
}

void Lab1Menu::tma(std::istream& inputStream) {
    while (inputStream.peek() == ' ') {inputStream.get();}
    if (inputStream.peek() != '\n') {throw std::logic_error("too many arguments");}
}

void Lab1Menu::createRandomSequence(std::istream& inputStream, std::ostream& outputStream) {
    std::string nameOfSequence;
    std::string typeOfSequence;
    std::string sizeString;
    Lab1Menu::nea(inputStream);
    inputStream >> sizeString;
    Lab1Menu::nea(inputStream);
    inputStream >> typeOfSequence;
    Lab1Menu::nea(inputStream);
    inputStream >> nameOfSequence;
    Lab1Menu::tma(inputStream);
    int size = std::stoi(sizeString);
    if (size < 0) {throw std::logic_error("negative size");};
    Sequence<int>* newObject = nullptr;
    if (typeOfSequence == "ArraySequence") {newObject = new ArraySequence<int>;}
    else if (typeOfSequence == "ListSequence") {newObject = new ListSequence<int>;}
    else {throw std::logic_error("incorrect type");}
    std::srand(std::time(nullptr));
    for (auto i = 0; i < size; ++i) {
        newObject -> append(std::rand()%std::numeric_limits<int>::max());
    }
    objPtrMap[nameOfSequence].reset(newObject);
    outputStream << "new sequence of type " << typeOfSequence
                 << " named " << nameOfSequence << " added\n";
}


