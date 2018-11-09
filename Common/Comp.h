#ifndef COMP_H
#define COMP_H
template<class E>
class HuffTree;
class MinHeapComp{
    public:
        template<class E>
        static bool prior(const HuffTree<E>*,const HuffTree<E>*);
};
class MaxHeapComp{
    public:
        template<class E>
        static bool prior(const E& e1,const E& e2){return e1>e2;}
};

#endif