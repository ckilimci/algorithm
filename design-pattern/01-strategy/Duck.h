#ifndef DUCK_H
#define DUCK_H

class Duck {
public:
    std::string name;
    Duck(std::string);
    void quack();
    void swim();
    void fly();
    virtual void display();
};

#endif
