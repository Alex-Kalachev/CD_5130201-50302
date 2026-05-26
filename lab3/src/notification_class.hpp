#pragma once
#include <ctime>
#include "visitor.hpp"
#include "dop.hpp"

// TO_DO: узнать про паттерн проектирования visitor и использовать его тут вместо явной передачи типа
// TO_DO: функцию подсчета тоже сделать с помощью этого паттерна

class Notification_Class
{
    private:
        std::tm m_t;

    public:

        Notification_Class(){
            std::time_t timestamp = std::time(nullptr);
            m_t = *(std::localtime(&timestamp));
        };

        virtual ~Notification_Class() = default;

        const std::tm& get_m_t() const{
            return m_t;
        }


        virtual void Print_sms() const = 0;
        virtual LEVEL getSeverity() const = 0;
        virtual void accept(Visitor& v) = 0;



};

class SystemNotification : public Notification_Class{

    private:
        const char* m_message;
        LEVEL m_severity;

    public:

    SystemNotification(const char* message, LEVEL severity) : Notification_Class(){
        m_message = message;
        m_severity = severity;
    }

    LEVEL getSeverity() const override { return m_severity; }
    void Print_sms() const override;
    void accept(Visitor& v) override {
        v.visit(*this);
    }


    
};

class FastMessageNotification : public Notification_Class{

    private:
        const char* m_name;
        const char* m_message;

    public:

    FastMessageNotification(const char* name, const char* message) : Notification_Class(){
        m_name = name;
        m_message = message;
    }
    LEVEL getSeverity() const override { return STANDART; }
    void Print_sms() const override;
    void accept(Visitor& v) override {
        v.visit(*this);
    }
};

class AppNotification : public Notification_Class{

    private:
        const char* m_name_app;
        const char* m_head;
        const char* m_text;

    public:

    AppNotification(const char* name_app, const char* head, const char* text) : Notification_Class(){
        m_name_app = name_app;
        m_head = head;
        m_text = text;
    }
    
    LEVEL getSeverity() const override { return STANDART; }
    void Print_sms() const override;
    void accept(Visitor& v) override {
        v.visit(*this);
    }
};

int Count_Type(Notification_Class* arr[], const int size, TYPE type);