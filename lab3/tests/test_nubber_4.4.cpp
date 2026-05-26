#include <iostream>
#include <cassert>
#include "notification_queue.hpp"

int main() {
    // проверка бытрого системного уведомления
    NotificationPriorityQueue q;

    q.push(new AppNotification("App", "h1", "text1"));
    q.push(new SystemNotification("sys normal", STANDART));
    q.push(new FastMessageNotification("user", "msg"));
    q.push(new SystemNotification("sys FAST", FAST));

    Notification_Class* n1 = q.pop();

    assert(n1->getType() == SYSTEM);
    assert(n1->getSeverity() == FAST);

    delete n1;

    // проверка времени 
    NotificationPriorityQueue q2;

    auto a = new AppNotification("A", "h", "1");
    auto b = new AppNotification("B", "h", "2");

    q2.push(a);
    q2.push(b);

    Notification_Class* n2 = q2.pop();

    assert(n2 != b);

    delete n2;

    // проверка иерархии уведомлений
    NotificationPriorityQueue q3;

    q3.push(new AppNotification("App", "h", "text"));
    q3.push(new SystemNotification("sys", STANDART));
    q3.push(new FastMessageNotification("user", "msg"));

    Notification_Class* n3 = q3.pop();

    assert(n3->getType() == FAST_MESSAGE);

    delete n3;

    // при полном равенстве
    NotificationPriorityQueue q4;

    auto x1 = new AppNotification("A", "h", "1");
    auto x2 = new AppNotification("A", "h", "1");

    q4.push(x1);
    q4.push(x2);

    Notification_Class* n4 = q4.pop();

    assert(n4 == x1);
    
    delete n4;

    // пустая очередь
    NotificationPriorityQueue q5;

    assert(q5.pop() == nullptr);

    std::cout << "Test_number_4.4 passed\n";

    return 0;
}
