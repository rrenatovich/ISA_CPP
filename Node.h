//
// Created by rsali on 13.09.2025.
//

#ifndef ISA_CPP_NODE_H
#define ISA_CPP_NODE_H
#include "Request.h"


class Node {
private:
    int nodeID;
    PoissonFunction *serviceTimeFunc;
    std::vector<Request> requests;
    public:
    Node(int id, float param) {
        nodeID = id;
        std::cout << "Node " << nodeID << " created" << std::endl;
        serviceTimeFunc = new PoissonFunction(param);
    };
    void addRequest() {
        double dur = serviceTimeFunc->getValue();
        requests.push_back(Request(dur));
        std::cout << "Requset added to node "<< nodeID <<" duration"<< dur<< std::endl;
    }
};



#endif //ISA_CPP_NODE_H