#include <bits/stdc++.h>
#include <windows.h>
#include <thread>
#incude "connectServer.h"

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

void connecting() {
	getConnecting();
}

int main() {
	system("title 모의주식 v1.0");
	cout << "준비중\n";
	
	
	thread sock(&connecting);
	sock.join();

	

	system("cls");
	thread inpt(&inputThread);
	inpt.join();
	
	
	closeCon();	

	return 0;
}
