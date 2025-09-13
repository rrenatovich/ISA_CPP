//
// Created by rsali on 13.09.2025.
//

#ifndef ISA_CPP_SIMMODEL_H
#define ISA_CPP_SIMMODEL_H
#include <vector>

#include "MathFunction.h"
#include "Node.h"


class SimModel {
    private:
    float inpuIntensity; // Интенсивность входящего потока (пуассон)
    std::vector<Node> nodes; // коллекция узлов/фаз
    int nodesCount; // Общее число фаз
    int finishParam{}; // Необходимое число выполненных заявок
    PoissonFunction *poisson;

    public:
    SimModel(float lambda, int numberOfNodes) {
        std::cout << "Starting sim model" << std::endl;
        inpuIntensity = lambda;
        nodesCount = numberOfNodes;
        for (int i = 0; i < numberOfNodes; i++) {
            nodes.emplace_back(i,23);
        }
        poisson=new PoissonFunction(lambda);
    } ;
    void getValue() {
        for (int i = 0; i < 10; i++) {
            std::cout << poisson->getValue()<< std::endl;
        }
    }
};


#endif //ISA_CPP_SIMMODEL_H