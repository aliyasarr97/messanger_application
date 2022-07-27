#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc ,char const* argv[])
{
    int sockD = socket (AF_INET , SOCK_STREAM,0);

    struct sockaddr_in servAddr;

    servAddr.sin_family      = AF_INET;     //Domain: IPv4 (AF_INET)
    servAddr.sin_port        = htons(9001); //Type of socket: TCP/UDP (SOCK_STREAM)
    servAddr.sin_addr.s_addr = INADDR_ANY;  //Protocol: IP (0)

    int connectStatus = connect(sockD, (struct sockaddr*)&servAddr, sizeof(servAddr));

    if(connectStatus == -1)
    {
        printf("error...\n");
    }
    else
    {
        char strData[255];
        recv(sockD,strData,sizeof(strData),0);
        printf("Message:%s\n",strData);
    }

    return 0;
}

