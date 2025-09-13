//
// Created by rsali on 13.09.2025.
//
#include  <random>
#ifndef ISA_CPP_MATHFUNCTION_H
#define ISA_CPP_MATHFUNCTION_H


class MathFunction {
protected:
    std::mt19937 generator;
    public:
    MathFunction(): generator(std::random_device()()) {};
    virtual ~MathFunction() = default;

    virtual double getValue()=0;
};

class PoissonFunction final  : public MathFunction {
    private:
    std::uniform_real_distribution<double> dist;
    double param;
    public:
    explicit PoissonFunction(float p) : dist(0,1) { param = p; }
    double getValue() override {
        return  -std::log(dist(generator)/param);
    };
};

#endif //ISA_CPP_MATHFUNCTION_H