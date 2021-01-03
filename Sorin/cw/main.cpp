#include <string>
#include "hesh.h"

// ���������� ����� �� ������ 
std::stringstream GetLine(void) {
	std::string Str;
	if (!std::getline(std::cin, Str))
		throw std::runtime_error("Error while reading from stream");
	std::stringstream Stream(Str);
	return Stream;
}

// ���������� ��������� ������ ��� ������ ���-�������
std::ostream& operator<<(std::ostream& os, hesh_table& HT) {
	// ����� ������� ��������
	os << "Index table:\n\n";
	os << '|';
	for (int it = 0; it < HT.HeshTableSize; it++) {
		os.width(2);
		os << HT.HeshTable[it] << '|';
	}
	os << "\n\n";
	// ����� ������� � ������� � ���������
	os << "Data table:\n|chain|key|Data|\n\n";
	for (int it = 0; it < HT.KeyTable.size(); it++) {
		os << '|';
		os.width(2);
		os << HT.KeyTable[it].Chain;
		os << '|';
		std::string s = HT.KeyTable[it].Name;
		os.width(HT.KeySize);
		os << s;
		os << '|';
		os << HT.KeyTable[it].Data;
		os << '|';
		os << '\n';
	}
	return os << '\n';
}

int main() {
	try
	{
		// ������ ������� �������� � ������������ ������ �����
		unsigned int HTS = 5, MKS = 10;
		
		// �������� ������ �������
		hesh_table HT(HTS, MKS);
		int Res = 0;
		std::string Key;
		
		// �������� ����������
		std::cout << "1)Press enter to exit\n";
		std::cout << "2)To delete or add an element, enter the key and press enter\n";
		std::cout << "3)To delete an element, press enter after entering the key\n";
		std::cout << "3)To add an element, enter the data after entering the key. Press enter\n\n";

		std::cout << "The key consists of characters '0'...'9', 'a'...'z' or 'A'...'Z' \n";
		std::cout << "The data consists of any characters\n\n";

		while (1) {
			Key = "";
			std::cout << "1)";
			std::stringstream Stream = GetLine();
			char C = 0;
			// ���������� �����
			HT.ReadKey(Key, Stream);
			// ���������� ������
			std::cout << "2)";
			std::stringstream Stream2 = GetLine();
			if (Stream2.get(C).eof()) {
				// ������ ������
				std::cout << "\x1B[2J\x1B[H";
				// ����� ����� �������
				std::cout << HT;
				// �������� �������� �� �������
				Res = HT.DelFromHeshTable(Key);
			}
			else {
				std::string Data;
				Data = Stream2.str();// .erase(0, 2);
				// ������ ������
				std::cout << "\x1B[2J\x1B[H";
				// ����� ����� �������
				std::cout << HT;
				// ���������� �������� � �������
				Res = HT.AddToHeshTable(Key, Data);
			}
			// ���������� � ����������� ����������� ���������
			std::cout << "Number of element meetings: " << Res << "\n\n";
			// ����� ����� �������
			std::cout << HT;
		}

	}
	catch (const std::exception& Error) // ������������ ������
	{
		// ����� ���������� �� ������
		std::cout << Error.what();
	}
	return 0;
}
