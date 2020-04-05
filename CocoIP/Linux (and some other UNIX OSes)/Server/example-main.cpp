#define bufflen 512  //buffer lenght for ipConnection class
#define debugOutput

#include "ipConnection.h"

#ifndef debugOutput
#include <iostream>
#endif

#define controlPortNo 31079
#define espPortNo 30053

//using namespace std;

char buffer[512];

int main() {

    //TODO- have a permanat listner so diconnects can be
    // handled and re connections can update the
    // socket filedescriptor and program can continue

    std::cout<<"Hello!"<<std::endl;

    ipConnection controller;

    bool proceed = false;
    while (!proceed){
        controller.listenAndAcceptClient(controlPortNo);
        controller.readData(buffer);        //TODO- Hnadle read/write fail
        if ((buffer[0]=='c')&&(buffer[1]=='t')){
            proceed = true;
            controller.sendData("afirm",6);
        }
        else{
            std::cout<<"invalid connection: controller ident values mismatch"<<std::endl<<"Retrying"<<std::endl;
            controller.cleanUp();
            proceed=false;
        }
    }

    std::cout<<"Control device connected"<<std::endl;

    ipConnection esp;

    proceed = false;
    while (!proceed){
        esp.listenAndAcceptClient(espPortNo);
        esp.readData(buffer);        //TODO- Hnadle read/write fail
        if ((buffer[0]=='e')&&(buffer[1]=='s')&&(buffer[2]=='p')){
            proceed = true;
            esp.sendData("afirm",6);
        }
        else{
            std::cout<<"invalid connection: esp ident values mismatch"<<std::endl<<"Retrying"<<std::endl;
            esp.cleanUp();
            proceed=false;
        }
    }

    controller.cleanUp();
    esp.cleanUp();
    return 0;
}
