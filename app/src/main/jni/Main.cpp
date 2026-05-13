#include <list>
#include <vector>
#include <string.h>
#include <pthread.h>
#include <cstring>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include "Includes/Logger.h"
#include "Includes/obfuscate.h"
#include "Includes/Utils.h"
#include "KittyMemory/MemoryPatch.h"
#include "Includes/MonoString.h"
#include "Menu/Register.h"
#include "AutoHook/AutoHook.h"
#include "Includes/Strings.h"
#include "And64InlineHook/And64InlineHook.hpp"
//@liyaharuno
//@CheatCodeRevo
//Target lib here
#define targetLibName OBFUSCATE("libil2cpp.so")

#include "Includes/Macros.h"

//---👇🏻PUT YOUR BOOL&FLOAT HERE👇🏻---

bool Ismod1 = false;
bool Ismod2 = false;
bool Ismod3 = false;
bool Ismod4 = false;
bool Ismod5 = false;
bool Ismod6 = false;
bool Ismod7 = false;
bool Ismod8 = false;
bool Ismod9 = false;

//---👇🏻PUT YOUR HOOKS HERE 👇🏻---

int (*old_mod1)(void *instance);
int mod1(void *instance) {
    if (instance != NULL && Ismod1) {
          return 5;
    }
    return old_mod1(instance);
}

int (*old_mod2)(void *instance);
int mod2(void *instance) {
    if (instance != NULL && Ismod2) {
          return 999999;
    }
    return old_mod2(instance);
}

int (*old_mod3)(void *instance);
int mod3(void *instance) {
    if (instance != NULL && Ismod3) {
          return 999999;
    }
    return old_mod3(instance);
}

int (*old_mod4)(void *instance);
int mod4(void *instance) {
    if (instance != NULL && Ismod4) {
          return 999999;
    }
    return old_mod4(instance);
}

int (*old_mod5)(void *instance);
int mod5(void *instance) {
    if (instance != NULL && Ismod5) {
          return 999999;
    }
    return old_mod5(instance);
}

int (*old_mod6)(void *instance);
int mod6(void *instance) {
    if (instance != NULL && Ismod6) {
          return 999999;
    }
    return old_mod6(instance);
}

float (*old_mod7)(void *instance);
float mod7(void *instance) {
    if (instance != NULL && Ismod7) {
          return 0;
    }
    return old_mod7(instance);
}

void (*old_mod8)(void *instance, bool value);
void mod8(void *instance, bool value) {
    if (instance != NULL && Ismod8) {
        old_mod8(instance, false);
        return;
    }
    return old_mod8(instance, value);
}

void (*old_mod9)(void *instance, bool value);
void mod9(void *instance, bool value) {
    if (instance != NULL && Ismod9) {
        old_mod9(instance, false);
        return;
    }
    return old_mod9(instance, value);
}

ProcMap il2cppMap;
void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));
    
    do {
        il2cppMap = KittyMemory::getLibraryMap("libil2cpp.so");
         sleep(5); // Don't Increase
    } while (!il2cppMap.isValid());


/*void *hack_thread(void *) {
    LOGI(OBFUSCATE("pthread created"));

    do {
        sleep(25);
    } while (!isLibraryLoaded("libil2cpp.so"));

    do {
        sleep(5);
    } while (!isLibraryLoaded("MyLibName.so"));
	
	*/
    
    
    LOGI(OBFUSCATE("%s has been loaded"), (const char *) targetLibName);


//👇🏻---IF YOUR HOOK 64BIT THEN PUT HERE👇🏻---
#if defined(__aarch64__)

auto Playermod1 = new LoadClass("", OBFUSCATE("VIPUtils"));

DWORD Getmod1 = Playermod1->GetMethodOffsetByName(OBFUSCATE("GetVIPLevel"), 0);

A64HookFunction((void *)Getmod1, (void *)mod1, (void **) &old_mod1);

auto Playermod2 = new LoadClass("", OBFUSCATE("Mercenarios"));

DWORD Getmod2 = Playermod2->GetMethodOffsetByName(OBFUSCATE("monedas"), 0);

A64HookFunction((void *)Getmod2, (void *)mod2, (void **) &old_mod2);

auto Playermod3 = new LoadClass("", OBFUSCATE("Mercenarios"));

DWORD Getmod3 = Playermod3->GetMethodOffsetByName(OBFUSCATE("gold"), 0);

A64HookFunction((void *)Getmod3, (void *)mod3, (void **) &old_mod3);

auto Playermod4 = new LoadClass("", OBFUSCATE("Mercenarios"));

DWORD Getmod4 = Playermod4->GetMethodOffsetByName(OBFUSCATE("get_player_energy"), 0);

A64HookFunction((void *)Getmod4, (void *)mod4, (void **) &old_mod4);

auto Playermod5 = new LoadClass("", OBFUSCATE("Mercenarios"));

DWORD Getmod5 = Playermod5->GetMethodOffsetByName(OBFUSCATE("get_player_tickets"), 0);

A64HookFunction((void *)Getmod5, (void *)mod5, (void **) &old_mod5);

auto Playermod6 = new LoadClass("", OBFUSCATE("Mercenarios"));

DWORD Getmod6 = Playermod6->GetMethodOffsetByName(OBFUSCATE("get_player_eventtickets"), 0);

A64HookFunction((void *)Getmod6, (void *)mod6, (void **) &old_mod6);

auto Playermod7 = new LoadClass("", OBFUSCATE("PlayerWeapon"));

DWORD Getmod7 = Playermod7->GetMethodOffsetByName(OBFUSCATE("CalculateReloadTime"), 0);

A64HookFunction((void *)Getmod7, (void *)mod7, (void **) &old_mod7);

auto Playermod8 = new LoadClass("", OBFUSCATE("PlayerControl"));

DWORD Getmod8 = Playermod8->GetMethodOffsetByName(OBFUSCATE("ApplyDamage"), 7);

A64HookFunction((void *)Getmod8, (void *)mod8, (void **) &old_mod8);

auto Playermod9 = new LoadClass("", OBFUSCATE("PlayerControl"));

DWORD Getmod9 = Playermod9->GetMethodOffsetByName(OBFUSCATE("ApplyDirectDamage"), 4);

A64HookFunction((void *)Getmod9, (void *)mod9, (void **) &old_mod9);

//👇🏻---IF YOUR HOOK 32BIT THEN PUT HERE👇🏻---
#else

auto Playermod1 = new LoadClass("", OBFUSCATE("VIPUtils"));

DWORD Getmod1 = Playermod1->GetMethodOffsetByName(OBFUSCATE("GetVIPLevel"), 0);

MSHookFunction((void *)Getmod1, (void *)mod1, (void **) &old_mod1);

auto Playermod2 = new LoadClass("", OBFUSCATE("Mercenarios"));

DWORD Getmod2 = Playermod2->GetMethodOffsetByName(OBFUSCATE("monedas"), 0);

MSHookFunction((void *)Getmod2, (void *)mod2, (void **) &old_mod2);

auto Playermod3 = new LoadClass("", OBFUSCATE("Mercenarios"));

DWORD Getmod3 = Playermod3->GetMethodOffsetByName(OBFUSCATE("gold"), 0);

MSHookFunction((void *)Getmod3, (void *)mod3, (void **) &old_mod3);

auto Playermod4 = new LoadClass("", OBFUSCATE("Mercenarios"));

DWORD Getmod4 = Playermod4->GetMethodOffsetByName(OBFUSCATE("get_player_energy"), 0);

MSHookFunction((void *)Getmod4, (void *)mod4, (void **) &old_mod4);

auto Playermod5 = new LoadClass("", OBFUSCATE("Mercenarios"));

DWORD Getmod5 = Playermod5->GetMethodOffsetByName(OBFUSCATE("get_player_tickets"), 0);

MSHookFunction((void *)Getmod5, (void *)mod5, (void **) &old_mod5);

auto Playermod6 = new LoadClass("", OBFUSCATE("Mercenarios"));

DWORD Getmod6 = Playermod6->GetMethodOffsetByName(OBFUSCATE("get_player_eventtickets"), 0);

MSHookFunction((void *)Getmod6, (void *)mod6, (void **) &old_mod6);

auto Playermod7 = new LoadClass("", OBFUSCATE("PlayerWeapon"));

DWORD Getmod7 = Playermod7->GetMethodOffsetByName(OBFUSCATE("CalculateReloadTime"), 0);

MSHookFunction((void *)Getmod7, (void *)mod7, (void **) &old_mod7);

auto Playermod8 = new LoadClass("", OBFUSCATE("PlayerControl"));

DWORD Getmod8 = Playermod8->GetMethodOffsetByName(OBFUSCATE("ApplyDamage"), 7);

MSHookFunction((void *)Getmod8, (void *)mod8, (void **) &old_mod8);

auto Playermod9 = new LoadClass("", OBFUSCATE("PlayerControl"));

DWORD Getmod9 = Playermod9->GetMethodOffsetByName(OBFUSCATE("ApplyDirectDamage"), 4);

MSHookFunction((void *)Getmod9, (void *)mod9, (void **) &old_mod9);

    LOGI(OBFUSCATE("Done"));
#endif



    return NULL;
}


jobjectArray GetFeatureList(JNIEnv *env, jobject context) {
    jobjectArray ret;

    const char *features[] = {
    //👇🏻---YOUR MENU---👇🏻
            OBFUSCATE("Category_CoverFire All Mod"),
            OBFUSCATE("1_Toggle_👉 VIP Level 5 Activated"),
			OBFUSCATE("2_Toggle_👉 For Unlimited Cash"),
			OBFUSCATE("3_Toggle_👉 For Unlimited Gold"),
			OBFUSCATE("4_Toggle_👉 For Unlimited Energy"),
			OBFUSCATE("5_Toggle_👉 For Unlimited Battle Tickets"),
			OBFUSCATE("6_Toggle_👉 For Unlimited Event Tickets"),
			OBFUSCATE("7_Toggle_👉 For Instant Reload"),
			OBFUSCATE("8_Toggle_👉 For Unlimited Health"),
    OBFUSCATE("9_Toggle_👉 No Direct Damage"),
			
    };

    //MODDED BY LIYA HACK
    int Total_Feature = (sizeof features / sizeof features[0]);
    ret = (jobjectArray)
            env->NewObjectArray(Total_Feature, env->FindClass(OBFUSCATE("java/lang/String")),
                                env->NewStringUTF(""));

    for (int i = 0; i < Total_Feature; i++)
        env->SetObjectArrayElement(ret, i, env->NewStringUTF(features[i]));

    return (ret);
}

void Changes(JNIEnv *env, jclass clazz, jobject obj,
                                        jint featNum, jstring featName, jint value,
                                        jboolean boolean, jstring str) {

    LOGD(OBFUSCATE("Feature name: %d - %s | Value: = %d | Bool: = %d | Text: = %s"), featNum,
         env->GetStringUTFChars(featName, 0), value,
         boolean, str != NULL ? env->GetStringUTFChars(str, 0) : "");
		 
		 
		 
    switch (featNum) {
    case 1:
    Ismod1 = boolean;
    break;
	case 2:
	Ismod2 = boolean;
    break;
	case 3:
	Ismod3 = boolean;
    break;
	case 4:
	Ismod4 = boolean;
	break;
	case 5:
	Ismod5 = boolean;
	break;
	case 6:
	Ismod6 = boolean;
	break;
	case 7:
    Ismod7 = boolean;
    break;
	case 8:
    Ismod8 = boolean;
    break;
 case 9:
    Ismod9 = boolean;
    break;
    }
}


__attribute__((constructor))
void lib_main() {
    pthread_t ptid;
    pthread_create(&ptid, NULL, hack_thread, NULL);
}

extern "C"
JNIEXPORT jint JNICALL
JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;

    vm->GetEnv((void **) &env, JNI_VERSION_1_6);

    static const JNINativeMethod menuMethods[] = {
            {OBFUSCATE("Icon"), OBFUSCATE("()Ljava/lang/String;"), reinterpret_cast<void *>(Icon)},
            {OBFUSCATE("IconWebViewData"),  OBFUSCATE("()Ljava/lang/String;"), reinterpret_cast<void *>(IconWebViewData)},
            {OBFUSCATE("IsGameLibLoaded"),  OBFUSCATE("()Z"), reinterpret_cast<void *>(isGameLibLoaded)},
            {OBFUSCATE("Init"),  OBFUSCATE("(Landroid/content/Context;Landroid/widget/TextView;Landroid/widget/TextView;)V"), reinterpret_cast<void *>(Init)},
            {OBFUSCATE("SettingsList"),  OBFUSCATE("()[Ljava/lang/String;"), reinterpret_cast<void *>(SettingsList)},
            {OBFUSCATE("GetFeatureList"),  OBFUSCATE("()[Ljava/lang/String;"), reinterpret_cast<void *>(GetFeatureList)},
    };

    if (Register(env, "com/android/support/Menu", menuMethods, sizeof(menuMethods) / sizeof(JNINativeMethod)) != 0)
        return JNI_ERR;

    static const JNINativeMethod prefMethods[] = {
            { OBFUSCATE("Changes"), OBFUSCATE("(Landroid/content/Context;ILjava/lang/String;IZLjava/lang/String;)V"), reinterpret_cast<void *>(Changes)},
    };

    if (Register(env, "com/android/support/Preferences",
                 prefMethods, sizeof(prefMethods) / sizeof(JNINativeMethod)) != 0)
        return JNI_ERR;

    static const JNINativeMethod mainMethods[] = {
            { OBFUSCATE("CheckOverlayPermission"), OBFUSCATE("(Landroid/content/Context;)V"), reinterpret_cast<void *>(CheckOverlayPermission)},
    };

    if (Register(env, "com/android/support/Main", mainMethods, sizeof(mainMethods) / sizeof(JNINativeMethod)) != 0)
        return JNI_ERR;

    return JNI_VERSION_1_6;
}
