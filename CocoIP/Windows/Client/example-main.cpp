#define debugOutput
#define bufflen 512

#include "serverCon.h"

#ifndef debugOutput         //servercon.h internally includes iostream if debug output is enabled
#include <iostream>
#endif

#define servPort "31079"

char buffr[bufflen]={0};

int main() {

    std::cout << "Heloo!" << std::endl;

    serverCon server;
    server.connectTo("192.168.1.7",servPort);

    server.sendData("ct");

    server.readData(buffr);
    if((buffr[0]!='a')||(buffr[1]!='f')||(buffr[4]!='m')){
        std::cout<<"hmmm... thats odd, wrong ack"<<std::endl;
    }


    std::cout << "Done!" << std::endl;
    server.cleanUp();
    return 0;
}
