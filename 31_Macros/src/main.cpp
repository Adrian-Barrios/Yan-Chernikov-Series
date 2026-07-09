#include <iostream>
#include <string>

#define ACTIVATE_MACROS 1

#if ACTIVATE_MACROS == 1

#define WAIT std::cin.get() // This can be in another file as well
#define OPEN_CURLY {
#define CLOSE_CURLY }

#ifdef PR_DEBUG // We dont want logging in our release mode
#define LOG(x) std::cout << x << std::endl
#elif defined(PR_RELEASE)
#define LOG(x)
#endif

#endif

int main()
OPEN_CURLY
int x  = 10;
LOG(x);
	WAIT; // Not ideal. You should write std::cin.get(). Other programers may not know what WAIT is.
CLOSE_CURLY

/* 

Macros are all about using the preprocessor. (Happens before compilation, there is really nothing you cant replace)

Macros can be used to replace text in our code with something else.
 
*/