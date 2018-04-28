#ifndef STREET_H
#define STREET_H

//#include "Road.h"
#include "GameObject.h"
#include "Vehicle.h"
#include <sstream>

class Cross;
class Vehicle;
//class GameObject;
class Simulator;
//void Simulator::registerObject(GameObject *go);

class Road : public GameObject
{
public:

    std::queue<Vehicle*> vehiclesBeg;
    std::queue<Vehicle*> vehiclesEnd;

    Vec3 begPos;
    Vec3 endPos;

    float length;
    Vec3 direction;

    Vec3 normal;

    virtual float freeSpace(bool dir);

    Cross* crossBeg;
    Cross* crossEnd;
};

class Street : public Road
{
public:
    Street(Cross *begCross, Cross *endCross);

    void draw();

private:
    //Vec3 begPos;
    //Vec3 endPos;




};

/*class StreetOneDir : Street
{
private:
    vector<Vehicle> vehicles;
};

class StreetTwoDir : Street
{
private:
    vector<Vehicle> vehicles1;
    vector<Vehicle> vehicles2;
};*/

class Cross : public Road
{
    //std::vector<Street> streets;
    //std::vector<std::vector<Vehicle>>
public:
    Cross(Vec3 position);

    struct OneStreet
    {
        Road *street;
        std::vector<Vehicle*> vehicles;
        bool enabled = true;
        bool direction;
        Vec3 jointPos;

        std::vector<std::vector<int> > yield;
    };
    std::vector<OneStreet> streets;

    void setDefaultPriority(Road *s0, Road *s1, Road *s2, Road *s3);

    int allowedVeh;

    void update(float delta);

    void draw();
};

class Garage : public Road
{
public:
    Garage(Simulator *engine, Vec3 p, Cross *c);

    //Cross *cross;
    //std::queue<Vehicle*> vehicles;
    //std::queue<Vehicle*> toDelete;

    float frec;
    float curTime;

    void draw();
    void update(float delta);
    std::string itos(int x);
    void spotCar();
};

#endif // STREET_H
