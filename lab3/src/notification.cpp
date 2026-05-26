#include "notification.hpp"
#include "iostream"

SNotification Make_System(const char* message, enum LEVEL severity){
    SNotification sms;
    sms.type = SYSTEM; 
    sms.specific.system.message = message; 
    sms.specific.system.severity = severity;
    sms.timestamp = std::time(nullptr);
    return sms;
}


SNotification Make_Fast_Message(const char* name, const char* message){
    SNotification sms;
    sms.type = FAST_MESSAGE;
    sms.specific.fast_message.name = name; 
    sms.specific.fast_message.message = message; 
    sms.timestamp = std::time(nullptr);
    return sms;
}

SNotification Make_App(const char* name_app, const char* head, const char* text){
    SNotification sms;
    sms.type = APP;
    sms.specific.app.name_app = name_app; 
    sms.specific.app.head = head; 
    sms.specific.app.text = text;
    sms.timestamp = std::time(nullptr);
    return sms;
}

void Print_sms(const SNotification& sms){

    std::tm* t = std::localtime(&sms.timestamp);

    std::cout << t->tm_hour << ":" << t->tm_min << ":" << t->tm_sec << std::endl;

    if (sms.type == SYSTEM){
        std::cout << "Тип уведомления: " << "SYSTEM" << "\n";
        std::cout << "Текст сообщения: " << sms.specific.system.message << "\n";
        if (sms.specific.system.severity == STANDART){
            std::cout << "Cрочность сообщения: " << "STANDART" << "\n\n";
        }
        else{
            std::cout << "Cрочность сообщения: " << "FAST" << "\n\n";
        }
    }

    else if (sms.type == FAST_MESSAGE){
        std::cout << "Тип уведомления: " << "FAST_MESSAGE" << "\n";
        std::cout << "Имя отправителя: " << sms.specific.fast_message.name << "\n";
        std::cout << "Текст сообщения: " << sms.specific.fast_message.message << "\n\n";
    }

    else if (sms.type == APP){
        std::cout << "Тип уведомления: " << "APP" << "\n";
        std::cout << "Название приложения: " << sms.specific.app.name_app << "\n";
        std::cout << "Текст заголовка: " << sms.specific.app.head << "\n";
        std::cout << "Текст сообщения: " << sms.specific.app.text << "\n\n";
    }

    else {
        std::cout << "Ошибка\n";
    }

    return;
}

int Count_sms_this_type(const SNotification sArr[], const int size , TYPE type){

    int count = 0;

    for (int i = 0; i < size; i++){
        if (sArr[i].type == type){
            count += 1;
        }
    }

    return count;
}