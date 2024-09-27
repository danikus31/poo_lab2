#pragma once
#include "connection.cpp"

class factory{
    struct lineSturct {
        string name;
        int limit;
        int free;
        int total_volume;
        int total_surface;
    };

    struct object {
        int height;
        int width;
        int depth;
        int lineID;
    };

private:
    vector<lineSturct> queues;
    vector<object> boxes;
public :
    void showQueues();
    void showBoxes();
    void addQueue();
    void addBox();
    void pop();

};

