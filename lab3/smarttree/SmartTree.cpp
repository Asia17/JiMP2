//
// Created by Joanna on 06.04.2018.
//

#include "SmartTree.h"

#include <iostream>
#include <regex>
#include <string>
#include <iterator>
#include <memory>
#include "SmartTree.h"
namespace datastructures{
    std::unique_ptr<SmartTree> CreateLeaf(int value) {
        return  std::make_unique<SmartTree>(value);
    }

    std::unique_ptr<SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree) {
        tree->left=move(left_subtree);
        return move(tree);
    }
    std::unique_ptr<SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree) {
        tree->right=move(right_subtree);
        return move(tree);
    }


    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out) {
        if((unique_ptr->left)!= nullptr)
            PrintTreeInOrder(unique_ptr->left,out);
        *out<<unique_ptr->value<<", ";
        if((unique_ptr->right)!= nullptr)
            PrintTreeInOrder(unique_ptr->right,out);
    }

    std::unique_ptr<SmartTree> RestoreTree(const std::string &tree) {
        std::regex pattern {R"(\[(-?\d+)\s(.*)\])"};
        std::smatch matches;
        if (regex_match(tree, matches, pattern)) {
            int val = stoi(matches[1]);//wybranie numeru

            auto c = CreateLeaf(val); //utworzenie node

            bool found = false;//poszukiewnie nawiazu zamykającego pierwszy node
            int bracketC=0;
            int f=0;
            std::string s =matches[2];
            for(char c:s){
                f++;
                if(c=='[')
                    bracketC++;//zwiększenie licznika nawiasów

                if(c==']'){
                    bracketC--;//zmniejszenie licznika nawiasów
                    if(bracketC==0)//jeżeli jest to ostatnie zamkniecie przerywamy
                        break;
                }
            }

            c->left=RestoreTree(s.substr(0,f));//susbstring opisujący lewy node
            c->right=RestoreTree(s.substr(f+1));//susbstring opisujący lewy node

            return move(c);
        }
        return nullptr;
    }
    std::string DumpTree(const std::unique_ptr<SmartTree> &tree) {
        return tree->getStr();
    }


    std::string SmartTree::getStr() {
        std::string s = "[";
        s+=std::to_string(value);
        s+=" ";
        if(left == nullptr)
            s+="[none]";
        else
            s+=left->getStr();
        s+=" ";
        if(right == nullptr)
            s+="[none]";
        else
            s+=right->getStr();
        s+="]";
        return s;
    }
}
