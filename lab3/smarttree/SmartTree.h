//
// Created by Joanna on 06.04.2018.
//



#ifndef JIMP_EXERCISES_SMARTTREE_H
#define JIMP_EXERCISES_SMARTTREE_H

#include <ostream>
#include <string>
#include <memory>

namespace datastructures{

    struct SmartTree{
        int value;
        std::unique_ptr<SmartTree> left;
        std::unique_ptr<SmartTree> right;
        SmartTree(int v):left(nullptr),right(nullptr),value(v){}
        SmartTree():SmartTree(0){}
        std::string getStr();
    };

    std::unique_ptr <SmartTree> CreateLeaf(int value);
    std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree);
    std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree);
    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out);
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree);
    std::unique_ptr <SmartTree> RestoreTree(const std::string &tree);

}
#endif //JIMP_EXERCISES_SMARTTREE_H
