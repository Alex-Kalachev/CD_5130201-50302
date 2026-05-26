#include "notification_class.hpp"
#include <iostream>

void SystemNotification::Print_sms() const{
    
    std::tm tm = get_m_t();
    std::cout <<  tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << "\n";
    
    std::cout << "Тип уведомления: " << "SYSTEM" << "\n";
    std::cout << "Текст сообщения: " << m_message << "\n";
    if (m_severity == STANDART){
        std::cout << "Cрочность сообщения: " << "STANDART" << "\n\n";
    }
    else{
        std::cout << "Cрочность сообщения: " << "FAST" << "\n\n";
    }
    
}

void FastMessageNotification::Print_sms() const{
    std::tm tm = get_m_t();
    std::cout <<  tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << "\n";

    std::cout << "Тип уведомления: " << "FAST_MESSAGE" << "\n";
    std::cout << "Имя отправителя: " << m_name << "\n";
    std::cout << "Текст сообщения: " << m_message << "\n\n";

}

void AppNotification::Print_sms() const{
    std::tm tm = get_m_t();
    std::cout <<  tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << "\n";

    std::cout << "Тип уведомления: " << "APP" << "\n";
    std::cout << "Название приложения: " << m_name_app << "\n";
    std::cout << "Текст заголовка: " << m_head << "\n";
    std::cout << "Текст сообщения: " << m_text << "\n\n";

}

int Count_Type(Notification_Class* arr[], const int size, TYPE type){
    CountVisitor visitor(type);
    for (int i = 0; i < size; i++){
        if (arr[i]) { arr[i]->accept(visitor); } 
    }
    return visitor.get();

}