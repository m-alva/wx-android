#include "jni.h"
#include <stack>

#ifndef __WX_APP
#define __WX_APP

class wxApp {
	public:
		virtual void OnInit() = 0;
};

namespace wxAndroidApp
{
	extern JNIEnv* JNIEnv;
	extern jobject Activity;
	extern jobject OptionsMenuClick;

	extern wxApp* Application;
	extern std::stack<jobject*> ActivityStack;
};

#endif // __WX_APP