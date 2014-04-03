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
#include <wx/wxjni.h>

void setApp(wxApp* application) {
	wxAndroidApp::Application = application;
}

jint
Java_com_example_hellojni_wxJNI_wxStart( JNIEnv* env,
													  jobject thiz ,jstring label)
{
	wxAndroidApp::JNIEnv = env;
	wxAndroidApp::Activity = env->NewGlobalRef(thiz);
	wxAndroidApp::OptionsMenuClick = NULL;

	if(wxAndroidApp::ActivityStack.size() == 0) {
		if(wxAndroidApp::Application) {
			wxAndroidApp::Application->OnInit();
		}
	}
	else {

	}

	wxAndroidApp::ActivityStack.push(&thiz);
	return wxAndroidApp::ActivityStack.size();
}

void
Java_com_example_hellojni_wxJNI_handleEvent( JNIEnv* env,jobject thiz,
													  jint code,jobject obj)
{
}

void
Java_com_example_hellojni_wxJNI_onCreateOMenu( JNIEnv* env,jobject thiz,
													  jobject obj)
{
}