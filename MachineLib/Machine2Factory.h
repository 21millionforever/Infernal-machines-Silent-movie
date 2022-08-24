/**
 * @file Machine2Factory.h
 * @author Zhendong Chen
 *
 * Factory that put components together to make the machine
 */

#ifndef CANADIANEXPERIENCE_MACHINE2FACTORY_H
#define CANADIANEXPERIENCE_MACHINE2FACTORY_H

class WorkingMachine;

/**
 * Factory that put components together to make the machine
 */
class Machine2Factory {
private:

public:
    std::shared_ptr<WorkingMachine> Create(std::wstring imagesDir);

};

#endif //CANADIANEXPERIENCE_MACHINE2FACTORY_H
