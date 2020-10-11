template<typename T>
void f(T = "") {

}

int main() {

	f(1);	// T 를 int로 연역한다. 따라서 f<int>(1)을 호출한다.
	f()		// 오류: T를 연혁할 수 없다.
}