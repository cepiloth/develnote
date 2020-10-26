#pragma once
// 2020-10-11

template<typename T>
T max(T a, T b)
{
	// b < a 라면 a를 반환하고 아니라면 b를 반환한다.
	return b > a ? a : b;
}

/*
역사적인 이유로 형식 파라미터를 저으이할 때 typenmae 대신 class 사용할 수도 있다.
typename이라는 키워드는 C++98 표준을 만드는 중 상당히 늦게 도입됐다.
그 전에는 형식 파라미터를 키워드 class로 도입해야 했기 때문에 여전히 typename 대신 class를 사용할 수 있다.

그래서 템플릿 max()는 다음처럼 정의해도 된다.

template<class T>
T max(T a, T b)
{
	return b > a ? a : b;
}

의미상 두 함수는 다를 게 전혀 없다. 따라서 여기서 class를 사용하더라도 템플릿 인자로 어떠한 형식이든 사용할 수 있다.
하지만 class를 사용하면 오해할 수 있으므로(T로 클래스형만을 쓸 수 있는 게 아닌데도) typename을 사용하는 편이 좋다.
클래스형 선언과 달리 typename  대신 키워드 struct 는 쓸 수 없다.
*/