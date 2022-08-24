/**
 * @file Machine1Factory.h
 * @author Zhendong Chen
 *
 * Factory that put components together to make the machine
 */

#ifndef CANADIANEXPERIENCE_MACHINE1FACTORY_H
#define CANADIANEXPERIENCE_MACHINE1FACTORY_H

class WorkingMachine;

/**
 * Factory that put components together to make the machine
 */
class Machine1Factory {
private:

public:
    std::shared_ptr<WorkingMachine> Create(std::wstring imagesDir);



};

#endif //CANADIANEXPERIENCE_MACHINE1FACTORY_H
