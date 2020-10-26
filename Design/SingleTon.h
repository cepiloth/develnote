#pragma once

struct Database
{
protected:
	Database() {}

public:
	static Database& get() {
		
		// C++11 이상 버전에서는 스레드 세이프 함
		static Database database;
		return database;
	}

	Database(Database const&) = delete;
	Database(Database&&) = delete;
	Database& operator=(Database const&) = delete;
	Database& operator=(Database&&) = delete;
	// 생성자 은닉 복제/이동 생성자/연산자 삭제
};

/* C++ 11 이하 버전 */
class Database_c11
{
public:
	static Database_c11& get() {

		// C++11 이상 버전에서는 스레드 세이프 함
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