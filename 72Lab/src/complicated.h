#ifndef COMPLICATED_H
#define COMPLICATED_H

#include <vector>
#include <iostream>

/*
This is a rather contrived example. The idea is a ComplicatedExample
is a container of ImportantInfo. WE DO NOT WANT ANYONE TO BE ABLE TO
CHANGE THE IMPORTANT INFO!
 */

class ImportantInfo{
public:
    int a;

    ImportantInfo(int b) {a=b;};
};

class ComplicatedExample{
private:
    std::vector<ImportantInfo*> stuff;

public:
    ComplicatedExample();
    const std::vector<ImportantInfo*> & getStuff();
    bool isChanged();
};

#endif
