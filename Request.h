//
// Created by rsali on 14.09.2025.
//

#ifndef ISA_CPP_REQUEST_H
#define ISA_CPP_REQUEST_H


class Request {
    private:
    float duration;
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
};


#endif //ISA_CPP_REQUEST_H