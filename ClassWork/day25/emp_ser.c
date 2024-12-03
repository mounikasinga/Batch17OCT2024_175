#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#define MAXBUFF 1024
#define PORTNO 4003
typedef struct emp
{
	int id;
	int phno;
	int sal;
	char Name[50];
	char g;
}EMP;
int main()
{
	int sfd = 0, retValue=0, csfd=0;
	int clientAddlen = 0;

	struct sockaddr_in serv_address, client_address;
	EMP employee;
	char msg[MAXBUFF] = {0,};

	sfd = socket(AF_INET,SOCK_STREAM,0);

	if(sfd < 0)
	{
		perror("socket() ");
		exit(EXIT_FAILURE);
	}
	printf("\nSocket created with sockfd : %d\n",sfd);



	//reset/set address of server 

	memset(&serv_address,'\0',sizeof(serv_address));

	serv_address.sin_family = AF_INET;
	serv_address.sin_port = htons(PORTNO);
	serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");

	retValue = bind(sfd, (struct sockaddr *)&serv_address,sizeof(serv_address));
	if(retValue < 0)
	{
		perror("bind()");
		exit(EXIT_FAILURE);
	}

	printf("\nBinded the server to the ipaddress with portno\n");
	
	retValue = listen(sfd, 5);
	if(retValue < 0)
	{
		perror("listen() ");
		exit(EXIT_FAILURE);
	}
	printf("\nListening to the clients now\n");

	while(1){
		csfd = accept(sfd,(struct sockaddr *)&client_address,&clientAddlen);
		employee.id = 101;
        	employee.phno = 9876543210;
        	employee.sal = 50000;
        	strcpy(employee.Name, "Mounika");
        	employee.g = 'F';
        // Send employee data to the client
        	retValue = send(csfd, &employee, sizeof(employee), 0);
        	if (retValue < 0) {
            		perror("send() ");
        	} else {
            		printf("Sent employee details to client\n");
        	}

        // Receive data from the client
        	while (1) {
            		retValue = recv(csfd, &employee, sizeof(employee), 0);
            		if (retValue <= 0) {
                		printf("Client disconnected or error in receiving\n");
                		break;
            		}

            // Print received employee details from the client
                printf("\nReceived employee details from client:\n");
                printf("ID: %d\n", employee.id);
                printf("Phone Number: %d\n", employee.phno);
           	printf("Salary: %d\n", employee.sal);
            	printf("Name: %s\n", employee.Name);
            	printf("Gender: %c\n", employee.g);
            	if (strcmp(employee.Name, "bye") == 0) {
                	close(csfd);
                	break;
            	}
            	memset(&employee, 0, sizeof(employee));  // Reset the structure for next use
        }
    }
    close(sfd); // Close server socket
    return 0;
}
