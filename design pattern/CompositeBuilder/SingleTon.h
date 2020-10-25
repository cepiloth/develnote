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

/*
struct Database
{
	
public:
	static Database& get() {

		// C++11 이상 버전에서는 스레드 세이프 함
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