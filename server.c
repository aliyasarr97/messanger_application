#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc , char const*  argv[])
{
    //create server socket
    int servSockD = socket(AF_INET, SOCK_STREAM, 0);

    //string store data to send to client
    char serMsg[255] = "Message from the server to the "
                       "client \'Hello Client\' ";

    //server address
    struct sockaddr_in servAddr;

    servAddr.sin_family      = AF_INET;
    servAddr.sin_port        = htons(9001);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    //socket port
    bind(servSockD,(struct sockaddr*)&servAddr,sizeof(servAddr));

    // listen for connections
    listen(servSockD,1);

    //integer to hold client socket
    int clientSocket = accept(servSockD,NULL,NULL);

    // send's messages to client socket
    send(clientSocket,serMsg,sizeof(serMsg),0);

}
