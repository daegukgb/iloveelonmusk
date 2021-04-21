#pragma comment(lib, "ws2_32.lib") 
#include <iostream>
#include <thread>
#include <winsock2.h>
#include <string>

using namespace std;

extern WSADATA wsaData;
extern SOCKET hSocket;
extern SOCKADDR_IN servAddr;

void ErrorHandling(char* message);


void ShowErrorMessage(string message)
{
	cout << "[error]: " << message << '\n';
	system("pause");
	exit(1);
}

//void listener()

void getConnecting(string ip, int port) {
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN servAddr;

	char message[30];
	int strLen;


	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ShowErrorMessage("WSAStartup() error!");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);
	if (hSocket == INVALID_SOCKET)
		ShowErrorMessage("socket() error");

	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("192.168.2.14");
	servAddr.sin_port = htons(5012);

	if (connect(hSocket, (SOCKADDR*)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		ShowErrorMessage("connect() error!");
	
	strLen = recv(hSocket, message, sizeof(message) - 1, 0);
	if (strLen == -1)
		ShowErrorMessage("read() error!");
	cout << "Message from server: %s "<< '\n'<< message << '\n';
	const char* test = "test";
	send(hSocket, test, sizeof(test), 0);

	closesocket(hSocket);
	WSACleanup();

}
