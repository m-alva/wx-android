/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef __WX_JNI
#define __WX_JNI

#include <jni.h>

#include <stdio.h>
#include <string.h>

#include <wx/app.h>

#include <android/log.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(__arm__)
	#if defined(__ARM_ARCH_7A__)
		#if defined(__ARM_NEON__)
			#define ABI "armeabi-v7a/NEON"
		#else
		  	  #define ABI "armeabi-v7a"
		#endif
	#else
	   	#define ABI "armeabi"
	#endif
#elif defined(__i386__)
	#define ABI "x86"
#elif defined(__mips__)
	#define ABI "mips"
#else
	#define ABI "unknown"
#endif

#define WXDLLEXPORT _declspec(dllexport)

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "native-activity", __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, "native-activity", __VA_ARGS__))

jint load(JavaVM* vm, void* reserved)
{
	JNIEnv* env;
	if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
		return -1;
	}
	return JNI_VERSION_1_6;
}

void setApp(wxApp* application);


jint
Java_org_wxwidgets_MainActivity_wxStart( JNIEnv* env,
													  jobject thiz);


void
Java_org_wxwidgets_MainActivity_handleEvent( JNIEnv* env,
													  jobject thiz,
													  jint code,
													  jobject obj);

void
Java_org_wxwidgets_MainActivity_onCreateOMenu( JNIEnv* env,jobject thiz,
													  jobject obj);

#ifdef __cplusplus
}
#endif
#endif // __WX_JNI