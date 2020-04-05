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
        return -1;
    }

    std::cout<<"waiting for other client device"<<std::endl;

    bool proceed = false;
    while (!proceed){
            server.readData(buffr);
        if (buffr[0]=='r'){
            proceed=true;
        }
    }

    std::cout<<"Second client device connected"<<std::endl;

    bool quit=false;
    while(!quit) {
        char input;
        std::cout << "What data do you want? (l -location h -current heading b -battery s -status g -gyro data q -to quit): ";
        std::cin >> input;
        switch (input) {
            case 'l':
                server.sendData("slx"); // request gps data from server- x axis
                server.readData(buffr);
                std::cout<<"X: "<<buffr<<std::endl;
                server.sendData("sly"); // request gps data from server- y axis
                server.readData(buffr);
                std::cout<<"Y: "<<buffr<<std::endl;
                break;

            case 'q':
                server.sendData("q");
                quit=true;
                break;
                
            default:
                std::cout<<"Not supported yet"<<std::endl;
                break;
        }
    }


    std::cout << "Done!" << std::endl;
    server.cleanUp();
    return 0;
}
