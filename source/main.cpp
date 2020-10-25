#include <iostream>
using namespace std;

#include "Monostate.h"
#include "HtmlBuilder.h"
#include "EmailBuilder.h"

int main()
{
    Email mail = Email::make().from("me@mail.com")
        .to("you@mail.com")
        .subject("C++ builders")
        .body("I like this API, don't you?");

    cout << mail << endl;
	return 0;
}