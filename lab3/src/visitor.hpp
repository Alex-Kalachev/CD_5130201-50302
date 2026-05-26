#pragma once
#include "dop.hpp"

class SystemNotification;
class FastMessageNotification;
class AppNotification;

struct PriorityData {
    int typeWeight = 0;
    bool isUrgentSystem = false;
};

class Visitor {
public:
    virtual void visit(SystemNotification&) = 0;
    virtual void visit(FastMessageNotification&) = 0;
    virtual void visit(AppNotification&) = 0;
    virtual ~Visitor() = default;
};

class CountVisitor : public Visitor {
    private:

        TYPE m_type;
        int m_count;

    public:
        CountVisitor(TYPE t) : m_type(t), m_count(0) {}
        void visit(SystemNotification&)  { if (m_type == SYSTEM) m_count++; }
        void visit(FastMessageNotification&)  { if (m_type == FAST_MESSAGE) m_count++; }
        void visit(AppNotification&)  { if (m_type == APP) m_count++; }
        int get() const { return m_count; }
        
};

class PriorityVisitor : public Visitor {

    private:
        PriorityData m_data;

    public:

        void visit(SystemNotification& sn) {
            if (sn.getSeverity() == FAST) {
                m_data.isUrgentSystem = true;
                m_data.typeWeight = 4; 
            } else {
                m_data.isUrgentSystem = false;
                m_data.typeWeight = 2; 
            }
        }

        void visit(FastMessageNotification&)  {
            m_data.isUrgentSystem = false;
            m_data.typeWeight = 3; 
        }

        void visit(AppNotification&)  {
            m_data.isUrgentSystem = false;
            m_data.typeWeight = 1; 
        }

        PriorityData getData() const { return m_data; }
};