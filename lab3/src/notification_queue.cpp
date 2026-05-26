#include "notification_queue.hpp"


// TO_DO: сделать операции эффективнее
// Для решения этой задачи был реализован кольцевой буфер, с его помощью мы получаем данные c  O(1)
Notification_Class* NotificationQueue::pop(){

    if (m_size == 0) { return nullptr; }

    Notification_Class* sms = m_data[m_get];

    m_data[m_get] = nullptr;

    m_get = (m_get + 1) % m_capacity;

    m_size--;

    return sms;
} 

void NotificationQueue::push(Notification_Class* sms){
    
    if (sms == nullptr){
        return;
    }

    if (m_size == m_capacity) {
        size_t old_capacity = m_capacity; 
        m_capacity *= 2;
        Notification_Class** buffer = new Notification_Class*[m_capacity];

        for (size_t i = 0; i < m_size; i++) {
            buffer[i] = m_data[(m_get + i) % old_capacity]; 
        }

        delete[] m_data;
        m_data = buffer;

        m_get = 0;
        m_put = m_size;
    }

    m_data[m_put] = sms;
    
    m_put = (m_put + 1) % m_capacity;

    m_size++;
} // Если не использыем увеличение буфера, то сложность алгоритма O(1), иначе O(n), но так как с каждым увеличением мы геометрически увеличиваем массив, то общая сложнасть стремится к O(1)

bool Time_min(Notification_Class* sms1, Notification_Class* sms2){

    std::tm t1 = sms1->get_m_t();
    std::time_t time1 = std::mktime(&t1);

    std::tm t2 = sms2->get_m_t();
    std::time_t time2 = std::mktime(&t2);

    return (time1 < time2); 

}

bool IsBetter(Notification_Class* a, Notification_Class* b) {
    if (!a || !b) return a != nullptr;

    PriorityVisitor vA, vB;
    a->accept(vA);
    b->accept(vB);

    PriorityData dataA = vA.getData();
    PriorityData dataB = vB.getData();


    if (dataA.isUrgentSystem != dataB.isUrgentSystem) {
        return dataA.isUrgentSystem; 
    }


    if (Time_min(a, b)) return true;
    if (Time_min(b, a)) return false;


    return dataA.typeWeight > dataB.typeWeight;
}

// TO_DO: узнать как можно сделать лучше (через дерево или кучу)
Notification_Class* NotificationPriorityQueue::pop() {
    if (m_size == 0) return nullptr;

    Notification_Class* res = m_data[0];

    m_data[0] = m_data[m_size - 1];
    m_data[m_size - 1] = nullptr;
    m_size--;

    size_t parent = 0;
    while (true) {
        size_t left = 2 * parent + 1;
        size_t right = 2 * parent + 2;
        size_t better = parent;

        if (left < m_size && IsBetter(m_data[left], m_data[better])) {
            better = left;
        }

        if (right < m_size && IsBetter(m_data[right], m_data[better])) {
            better = right;
        }

        if (better == parent) break;

        Notification_Class* temp = m_data[parent];
        m_data[parent] = m_data[better];
        m_data[better] = temp;
        parent = better;
    }

    return res;
} // Сложность алгоритма  O(log2N)

void NotificationPriorityQueue::push(Notification_Class* sms) {
    if (sms == nullptr) return;

    if  (m_size == m_capacity){
        m_capacity*=2;
        Notification_Class** buffer = new Notification_Class*[m_capacity];

        for (size_t i = 0; i < m_size; i++){
            buffer[i] == m_data[i];
        }

        delete[] m_data;
        m_data = buffer;
    }

    m_data[m_size] = sms;
    size_t son = m_size;
    m_size++;

    while (son > 0) {
        size_t parent = (son - 1) / 2;
        if (IsBetter(m_data[son], m_data[parent])) {
            Notification_Class* temp = m_data[son];
            m_data[son] = m_data[parent];
            m_data[parent] = temp;
            son = parent;
        } else {
            break;
        }
    }
} // Аналогично и прошлому TO_DO сложность алгоритма стремится к  O(log2N)
