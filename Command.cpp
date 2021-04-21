#include <iostream>
#include <string>
#include <Windows.h>


using namespace std;

constexpr unsigned int HC(const char* str)
{
	return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * HC(str + 1) : 8603;
}

void executeCommand(string name, char* args[], int len) {
	/*
	switch (HC(name.c_str())) {
	case HC("도움말"):
		helpCommand(); 
		break;
		
	case HC("msg"):
		if (args[0] == NULL || args[1] == NULL) {
			cout << "잘못 입력하였습니다. \"help\"를 입력하여 커맨드를 확인하세요" << endl;
			break; 
		}
		exeMessage(args[0], args, len);
		break;
	default:
		cout << "알 수 없는 명령어 입니다. \"도움말\"를 입력하여 커맨드를 확인하세요" << endl;
		break;
	}
	*/
}
void findCommands(string command) {
	char temp[1000];
	strcpy(temp, command.c_str());
	char* ptr = strtok(temp, " ");

	char* name = ptr;
	char* args[1000];

	int i = 0, n;
	while (ptr != NULL) {
		ptr = strtok(NULL, " ");
		args[i++] = ptr;
	}
	
	n = i - 1;
	
	/*
	for (i = 0; i < n; i++) {
		cout << args[i] << endl;
	}
	*/

	string namestr = name;
	for (i = 0; i < namestr.size(); i++) namestr[i] = tolower(namestr[i]);

	
	executeCommand(namestr, args, n);
}

void cmdInit() {

}
