// TCP SERVER source file
#include "Server.h"

using namespace std;
int main() {
	// main locals
	long SUCCESSFUL;
	WSAData winSockData;
	WORD DLLVERSION;

	//WORDS = objects of a data size that a processor naturraly handles (such as 16 bit or 32 bit )
	DLLVERSION = MAKEWORD(2, 1);
    
	// Start Winsock DLL
	SUCCESSFUL = WSAStartup(DLLVERSION,&winSockData);

	//Create Socket Structure 
	SOCKADDR_IN ADDRESS;
	int AddressSize = sizeof(ADDRESS);

	//Create Sockets
	SOCKET sock_LISTEN;      //listen for incoming connection
	SOCKET sock_CONNECTION;  // activate if connection found

	//socket Arguments: AF_INET = internet domain (not Unix domain),
	//SOCKET_STREAM = connection oriented TCP (not SOCK_DGRAM)
	sock_CONNECTION = socket(AF_INET, SOCK_STREAM, NULL);
	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1"); // Set IP
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444); // port number

	sock_LISTEN = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sock_LISTEN, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
	listen(sock_LISTEN, SOMAXCONN); // listen without limits

	//If connection found
	for (;;) {
		cout << "\n\tSERVER: Waiting for incoming connection...";
		if (sock_CONNECTION = accept(sock_LISTEN, (SOCKADDR *)&ADDRESS, &AddressSize)) {
			cout << "\n\tA connection was found!" << endl;
			SUCCESSFUL = send(sock_CONNECTION, "Welcome! You have connected to the server", 46, 0);
		}
	}
	return 0;
}

