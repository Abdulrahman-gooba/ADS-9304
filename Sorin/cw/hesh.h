#ifndef __HESH_H
#define __HESH_H

#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

// ����� - ���� ������� �� ������� � �������
class key_line {
public:
	// ������������
	key_line();
	key_line(std::string NewName, std::string NewData);
	key_line(std::string NewName, std::string NewData, int NewChain);
	// ����
	std::string Name;
	// ������
	std::string Data;
	// �������
	int Chain = -1;
};

// ����� - ���-�������
class hesh_table {
public:
	// ������ ������� ��������
	unsigned int HeshTableSize = 11;
	// ������������ ������ �����
	unsigned int KeySize = 8;
	// ������� � �������
	std::vector<key_line> KeyTable;
	// ������� ��������
	std::unique_ptr<int[]> HeshTable;
	// �����������
	hesh_table(unsigned int HTS, unsigned int KS);
	// ���������� �������� � ���-�������
	int AddToHeshTable(std::string NewName, std::string NewData);
	// �������� �������� �� ���-�������
	int DelFromHeshTable(std::string DelName);
	// ���������� ����� �������
	int Ord(char C);
	// ���-�������
	int H(std::string Name);
	// ���������� �����
	void ReadKey(std::string& Key, std::stringstream& Stream);
};

#endif // __HESH_H
