#include "complicated.h"
using namespace std;

ComplicatedExample::ComplicatedExample(){
    for(int i=0; i<10; i++)
        stuff.push_back(new ImportantInfo(i));
}

const vector<ImportantInfo*> & ComplicatedExample::getStuff(){
    return stuff;
}

bool ComplicatedExample::isChanged(){
    if(stuff.size() != 10) return true;
    for(int i=0;i<stuff.size();i++)
        if(stuff[i]->a != i) return true;
    return false;
}
