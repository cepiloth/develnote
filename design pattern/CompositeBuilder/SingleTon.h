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

/*
struct Database
{
	
public:
	static Database& get() {

		// C++11 �̻� ���������� ������ ������ ��
		static Database database;
		return database;
	}

private:
	Database() {;}
	Database(Database const&) {;}
	Database(Database&&) {;}
	Database& operator=(Database const&) {;}
	Database& operator=(Database&&) {;}
};

*/