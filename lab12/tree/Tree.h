#ifndef JIMP_EXERCISES_TREE_H
#define JIMP_EXERCISES_TREE_H
#include <memory>
#include <iostream>

using namespace std;
namespace tree {
    template<class T>
    class Tree {
    private:
        int size_;
        int depth_;
        T value_;
        Tree* root_;
        unique_ptr<Tree> left_;
        unique_ptr<Tree> right_;


    public:
        Tree(){}
        Tree(T value) {
            size_=1;
            depth_=1;
            value_=value;
            left_= nullptr;
            right_= nullptr;
            root_=this;
        }

        void Insert(T value);
        size_t Depth();

        T Value(){return value_;}
        int Size(){return size_;}

        Tree* Left(){ return left_.get() ;}
        Tree* Right(){ return right_.get() ;}
        Tree* Root(){ return root_;}


    };


    template<class T>
    void Tree<T>::Insert(T value) {
        if (value > value_) {
            if (right_)
                right_->Insert(value);
            else
                right_ = make_unique<Tree<T>>(value);
        }else {
            if (left_)
                left_->Insert(value);
            else
                left_ = make_unique<Tree<T>>(value);
        }
        size_++;
    }


    template <class T>
    size_t Tree<T>::Depth(){
        if(!root_){ return 0;} // jeśli nic nie ma
        if(left_ && right_) // są oba poddrzewa
            return 1+max(left_->Depth(),right_->Depth());
        else{
            if(left_)  //jest tylko lewe
                return 1+left_->Depth();
            if(right_)
                return 1+right_->Depth(); //jest tylko prawe
            else{ return 1;} // jesli jest tylko root

        }
    };
}
#endif //JIMP_EXERCISES_TREE_H