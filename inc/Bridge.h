/***
 * Created by: Amaresh
 * Description:
 * Bridge design pattern implementation
 * Bridge.h
 * Date: October 14th 2019
*/
#include <iostream>
using namespace std; 

/*
* Implementation
*/

class MoveLogic {
public:
    virtual void move()=0;
};

class Swim : public MoveLogic {
public:
    void move (){
        cout << " by using tails" << endl;
    }
};

class Walk : public MoveLogic {
public:
    void move (){
        cout << " Move alternating legs" << endl;
    }
};

class Fly : public MoveLogic {
public:
    void move (){
        cout << " by flipping wings" << endl;
    }
};

/*
* Abstraction
*/

class Animal {
public:
    virtual void howDoIMove() = 0;
};

class Person: public Animal {
private:
    MoveLogic* _movelogic; 
public:
    // Constructor receives the MoveLogic object to be initialized
    Person (MoveLogic *obj): _movelogic (obj) {}
    void howDoIMove () {
        _movelogic->move();
    }
};

class Bird : public Animal {
    MoveLogic* _movelogic;
public:
    Bird(MoveLogic *obj) :_movelogic(obj){}
    void howDoIMove() {
        _movelogic->move();
    }
};

class Fish : public Animal {
    MoveLogic* _movelogic;
public:
    Fish(MoveLogic *obj) :_movelogic(obj){}
    void howDoIMove() {
        _movelogic->move();
    }
};