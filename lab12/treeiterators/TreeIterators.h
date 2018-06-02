//
// Created by Joanna on 02.06.2018.
//

#ifndef JIMP_EXERCISES_TREEITERATORS_H
#define JIMP_EXERCISES_TREEITERATORS_H
#include <memory>
#include <iostream>
#include <vector>

using namespace std;
namespace tree {
    template<class T>
    class Tree {
    private:
        int size_;
        int depth_;
        T value_;
        Tree *root_;
        unique_ptr<Tree> left_;
        unique_ptr<Tree> right_;


    public:
        Tree() {}

        Tree(T value) {
            size_ = 1;
            depth_ = 1;
            value_ = value;
            left_ = nullptr;
            right_ = nullptr;
            root_ = this;
        }

        void Insert(T value);

        size_t Depth();

        T Value() { return value_; }

        int Size() { return size_; }

        Tree *Left() { return left_.get(); }

        Tree *Right() { return right_.get(); }

        Tree *Root() { return root_; }


    };


    template<class T>
    void Tree<T>::Insert(T value) {
        if (value > value_) {
            if (right_)
                right_->Insert(value);
            else
                right_ = make_unique<Tree<T>>(value);
        } else {
            if (left_)
                left_->Insert(value);
            else
                left_ = make_unique<Tree<T>>(value);
        }
        size_++;
    }


    template<class T>
    size_t Tree<T>::Depth() {
        if (!root_) { return 0; } // jeśli nic nie ma
        if (left_ && right_) // są oba poddrzewa
            return 1 + max(left_->Depth(), right_->Depth());
        else {
            if (left_)  //jest tylko lewe
                return 1 + left_->Depth();
            if (right_)
                return 1 + right_->Depth(); //jest tylko prawe
            else { return 1; } // jesli jest tylko root

        }
    };




    template <class T>
    void InOrderVector(Tree<T> *tree, std::vector<Tree<T> *> &vector){
        if(tree->Left()) InOrderVector(tree->Left(),vector);
        vector.push_back(tree);
        if(tree->Right()) InOrderVector(tree->Right(),vector);
    }

    template<class T>
    class InOrderTreeIterator;

    template <class T>
    class InOrderTreeView{
        Tree<T> *tree_;
    public:
        InOrderTreeView(Tree<T> *tree) : tree_(tree) {};
        InOrderTreeIterator<T> begin(){
            InOrderTreeIterator<T> new_it(tree_->Root());
            return new_it;
        }
        InOrderTreeIterator<T> end(){
            InOrderTreeIterator<T> new_it(tree_->Root());
            new_it.ToEnd();
            return new_it;
        }
    };

    template<class T>
    InOrderTreeView<T> InOrder(Tree<T> *tree);

    template<class T>
    InOrderTreeView<T> InOrder(Tree<T> *tree) {
        return InOrderTreeView<T>(tree);
    }

    template <class T>
    class InOrderTreeIterator{
        void ToEnd(){
            it_ = (int) vector_.size();
        }
        vector<Tree<T> *> vector_;
        int it_;
    public:
        InOrderTreeIterator(Tree<T> *tree) : it_(0) {
            InOrderVector<T>(tree, vector_);
        }
        T operator*(){
            return vector_[it_]->Value();
        }
        InOrderTreeIterator<T> &operator++() {
            ++it_;
            return *this;
        }
        bool operator!=(const InOrderTreeIterator<T> &one) const{
            return it_ != one.it_;
        }
        friend class InOrderTreeView<T>;
    };

}
#endif //JIMP_EXERCISES_TREEITERATORS_H
