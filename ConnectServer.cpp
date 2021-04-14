#include <bits/stdc++.h>
#include <thread>
#include <winsock2.h>
#include "Commands.h"

using namespace std;

extern WSADATA wsaData;
extern SOCKET clientSocket;
extern SOCKADDR_IN serverAddress;

void ShowErrorMessage(string message)
{
	cout << "[오류발생]: " << message << '\n';
	system("pause");
	exit(1);
}

void receiveData() {
	char received[256];
	string sent;
	while (1) {
		int length = recv(clientSocket, received, sizeof(received), 0);
		received[length] = '\0';
		if (strcmp(received, "[exit]") == 0) {
			break;
		}
		cout << "[서버메시지]: " << received << '\n';
	}
}

void sendData(string sent) {
	while (1) { 
		send(clientSocket, sent.c_str(), sent.length(), 0);
	}
	
}

void closeConnect() {
	closesocket(clientSocket);
	WSACleanup();
}
 
void getConnecting() {
	
	int serverPort = 9876;
	char received[256];
	string sent;
	
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) // Winsock을초기화합니다.
		ShowErrorMessage("WSAStartup()");
	clientSocket = socket(PF_INET, SOCK_STREAM, 0); // TCP 소켓을생성합니다.
	if (clientSocket == INVALID_SOCKET)
		ShowErrorMessage("socket()");
	
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1"); // 문자열IP를네트워크바이트형식으로
	serverAddress.sin_port = htons(serverPort); // 2바이트정수네트워크바이트형식으로
	
	if (connect(clientSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
		ShowErrorMessage("connect()");
	cout << "연결됨\n"; 
	thread iThread(&receiveData);
	thread oThread(&sendData);
	iThread.join();
	oThread.join(); 
	
}
