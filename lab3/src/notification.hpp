#pragma once
#include "dop.hpp"
#include <ctime>


union UNotification{
    System system;
    Fast_Message fast_message;
    App app;
};

struct SNotification
{
    TYPE type;
    UNotification specific;
    std::time_t timestamp;

};

SNotification Make_System(const char* , enum LEVEL );
SNotification Make_Fast_Message(const char* , const char* );
SNotification Make_App(const char* , const char* , const char* );

void Print_sms(const SNotification& );

int Count_sms_this_type(const SNotification sArr[], const int size, TYPE type);