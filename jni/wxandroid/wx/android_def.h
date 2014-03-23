#include <jni.h>
#include <wxandroid/wx/app.h>

#ifndef __android_def
#define __android_def


// Android class binds

// activity
#define BIND_ACTIVITY			"android/app/Activity"

// parents
#define BIND_LINEAR_LAYOUT 	"android/widget/LinearLayout"

// child components
#define BIND_BUTTON 			"android/widget/Button"

#define BIND_BUTTON_CONSTRUCTOR_ARGS "(Landroid/content/Context;)V"
#endif // __android_def