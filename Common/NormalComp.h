#ifndef NORMALCOMP_H
#define NORMALCOMP_H
class NormalComp{
    public:
        template<class E>
        static bool prior(const E& e1,const E& e2){return e1>e2;}
};
#endif