// TCP Client source file
#include "Client.h"

using namespace std;

int main() {
	// Locals
	long SUCCESSFUL;
	WSAData winSockData;
	WORD DLLVERSION;
	DLLVERSION = MAKEWORD(2, 1);
	SUCCESSFUL = WSAStartup(DLLVERSION, &winSockData);

	// Purpose use
	string RESPONE;
	string CONVERTER;
	char MESSAGE[200];

	SOCKADDR_IN ADDRESS;
	SOCKET sock;
	sock = socket(AF_INET, SOCK_STREAM, NULL);
	ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
	ADDRESS.sin_family = AF_INET;
	ADDRESS.sin_port = htons(444);

	cout << "\n\tCLIENT: Do you want to connect ot this SERVER(Y/N)";
	cin >> RESPONE;
	if (RESPONE == "n") {
		cout << "\n\tOK.Quitting instead.";
	}
	else if (RESPONE == "y") {
		connect(sock, (SOCKADDR *)& ADDRESS, sizeof(ADDRESS));
		SUCCESSFUL = recv(sock, MESSAGE, sizeof(MESSAGE), NULL);
		CONVERTER = MESSAGE;
		cout << "\n\tMessage from SERVER: \n\n\t" << CONVERTER << endl;
	}
	else {
		cout << "\n\tThat was an inappropriate RESPONES!";

	}
	cout << "\n\n\t";
	system("pause");
	return 0;
}