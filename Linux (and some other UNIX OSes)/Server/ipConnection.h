//
// Created by thari on 4/3/2020.
//

//#define debugOutput

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include<strings.h>
#include<unistd.h>

#ifdef debugOutput
    #include <iostream>
#endif

#ifndef bufflen
    #define bufflen 512
#endif

class ipConnection {
private:
    int listenSock, connSock;     //init file descriptors for sockets
    int clilen, n;        //init some variables

    struct sockaddr_in serv_addr, cli_addr;

public:
    int listenAndAcceptClient(int port);
    int cleanUp();
    int sendData(char buff[bufflen], int len);
    int readData(char data[bufflen]);


};
