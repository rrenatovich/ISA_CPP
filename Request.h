//
// Created by rsali on 14.09.2025.
//

#ifndef ISA_CPP_REQUEST_H
#define ISA_CPP_REQUEST_H


class Request {
    private:
    double duration;
    int nodeID =0;
public:
    explicit Request(double duration) {
        this->duration = duration;
    };
    void changeDuration(double delta) {
        duration -= delta;
    };
    double getDuration() {
        return duration;
    }
    int changeNodeID() {
        this->nodeID = nodeID+1;
        return nodeID;
    }
};


#endif //ISA_CPP_REQUEST_H