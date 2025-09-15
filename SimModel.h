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
    std::vector<Request> requests;
    std::vector<int> times;
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
    double getInputFlowValue() {
        return poisson->getValue();
    }

    void Simulate() {
        int numberOfSimulations = 10;
        double inputTime = getInputFlowValue();
        while (numberOfSimulations > 0) {
            if (requests.size() == 0){
                std::cout << "Requests list is empty. Generate new Request" << std::endl;
                requests.push_back(Request(getInputFlowValue()));
                inputTime = getInputFlowValue();
            }
            else {
                double minimalTimeRequest = requests[0].getDuration();
                int idOfMinimalRequest = 0;
                for (int i = 0; i < requests.size(); i++) {
                    if (requests[i].getDuration() < minimalTimeRequest) {
                        idOfMinimalRequest = i;
                        minimalTimeRequest = requests[i].getDuration();
                    }
                }
                if (std::min(minimalTimeRequest, inputTime)==inputTime) {
                    std::cout <<"InputFlow"<<std::endl;
                    for (int j = 0; j < requests.size(); j++) {
                        requests[j].changeDuration(inputTime);
                    }
                    requests.push_back(Request(getInputFlowValue()));
                    }
                    else {
                        std::cout <<"Requset is servicied"<<std::endl;
                        for (int j = 0; j < requests.size(); j++) {
                            if (j!=idOfMinimalRequest) {
                                requests[j].changeDuration(minimalTimeRequest);
                            }
                        }
                    if (requests[idOfMinimalRequest].changeNodeID() == 3) {
                        std::cout <<"Request leave the system" << std::endl;
                        std::swap(requests[idOfMinimalRequest], requests.back());
                        requests.pop_back();
                        numberOfSimulations = numberOfSimulations - 1;

                    }
                    }
                }

            }
        }
    };


#endif //ISA_CPP_SIMMODEL_H