template<typename T>
void f(T = "") {

}

int main() {

	f(1);	// T �� int�� �����Ѵ�. ���� f<int>(1)�� ȣ���Ѵ�.
	f()		// ����: T�� ������ �� ����.
}