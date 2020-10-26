#pragma once

struct Database
{
protected:
	Database() {}

public:
	static Database& get() {
		
		// C++11 �̻� ���������� ������ ������ ��
		static Database database;
		return database;
	}

	Database(Database const&) = delete;
	Database(Database&&) = delete;
	Database& operator=(Database const&) = delete;
	Database& operator=(Database&&) = delete;
	// ������ ���� ����/�̵� ������/������ ����
};

/* C++ 11 ���� ���� */
class Database_c11
{
public:
	static Database_c11& get() {

		// C++11 �̻� ���������� ������ ������ ��
		static Database_c11 database;
		return database;
	}

private:
	Database_c11() { ; }
	Database_c11(Database_c11 const&) {;}
	Database_c11(Database_c11&&) {;}
	Database_c11& operator=(Database_c11 const&) {;}
	Database_c11& operator=(Database_c11&&) {;}
};