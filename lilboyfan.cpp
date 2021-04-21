#include <iostream>
#include <windows.h>
#include <thread>
#include "ConnectServer.h"
#include "Command.h"

using namespace std;

void inputThread() {
	string line;

	while (true) {
		cout << "입력창 : ";
		getline(cin, line);
		if (line == "\0") {
			cout << endl;
			continue;
		}
		findCommands(line);
		cout << endl;

	}
}

void connecting(string ip, int port) {
	getConnecting(ip, port);
}

int main() {
	string ip;
	int port;

	system("title 모의주식 v1.0");
	cout << "준비중\n";

	cout << "아이피(내부)를 입력해주세요 : ";
	cin >> ip;
	cout << "포트를 입력해주세요 : ";
	cin >> port;

	thread sock(&connecting, ip, port);
	sock.join();



	system("cls");
	thread inpt(&inputThread);
	inpt.join();


	//closeConnect();

	return 0;
}
