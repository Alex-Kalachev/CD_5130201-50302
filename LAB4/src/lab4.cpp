#include <iostream>
#include "list.hpp" 

int main() {
    std::cout << "Запуск программы\n\n";

    List l;

    std::cout << "Добавление элементов\n";
    l.add_end(Circle(0, 0, 5));
    l.add_end(Circle(1, 2, 3));
    l.add_first(Circle(-1, -1, 7));

    std::cout << l << "\n";

    std::cout << "Размер списка: " << l.size() << "\n";
    std::cout << (l.empty() ? "Список пуст" : "Список не пуст") << "\n\n";

    std::cout << "Поиск элемента (Тест возврата Итератора)\n";
    Circle target(1, 2, 3);

    List::Iterator found = l.find(target); 

    if (found != l.end()) { 
        std::cout << "Элемент найден: радиус = " << (*found).get_radius() << "\n\n";
    } else {
        std::cout << "Элемент не найден\n\n";
    }

    std::cout << "Удаление одного элемента\n";
    l.delete_one_element(target);
    std::cout << l << "\n";

    std::cout << "Тест Итератора через цикл for\n";
    std::cout << "Проход по элементам списка с помощью begin() и end():\n";
    for (List::Iterator it = l.begin(); it != l.end(); ++it) {
        std::cout << "Круг: радиус " << (*it).get_radius() << "\n";
    }
    std::cout << "\n";

    std::cout << "Добавление дубликатов\n";
    l.add_end(Circle(2, 2, 4));
    l.add_end(Circle(2, 2, 4));
    l.add_end(Circle(2, 2, 4));
    std::cout << l << "\n";

    std::cout << "Удаление всех совпадающих элементов\n";
    size_t removed = l.delete_all_elements(Circle(2, 2, 4));
    std::cout << "Удалено: " << removed << "\n";
    std::cout << l << "\n";

    std::cout << "Сортировка\n";
    l.add_end(Circle(0, 0, 10));
    l.add_end(Circle(0, 0, 2));
    l.add_end(Circle(0, 0, 6));

    std::cout << "До сортировки:\n" << l << "\n";
    l.upsort();
    std::cout << "После сортировки:\n" << l << "\n";

    std::cout << "1. Конструктор копирования (List l2 = l):\n";
    List l2 = l;
    std::cout << "Список l2:\n" << l2 << "\n";

    std::cout << "2. Оператор присваивания (l3 = l2):\n";
    List l3;
    l3.add_end(Circle(99, 99, 99)); 
    l3 = l2;
    std::cout << "Список l3:\n" << l3 << "\n";

    std::cout << "Запись в файл (Методом класса)\n";
    std::cout << "Enter Output File Name - ";
    char ar1[80];
    std::cin >> ar1;
    
    if (l.write_to_file(ar1)) {
        std::cout << "Данные успешно записаны в " << ar1 << "\n\n";
    } else {
        std::cout << "Ошибка при записи в файл.\n\n";
    }

    std::cout << "Очистка списка\n";
    l.clear();
    std::cout << "После очистки:\n" << l;
    std::cout << "Size: " << l.size() << "\n";
    std::cout << (l.empty() ? "Список пуст\n" : "Список не пуст\n") << "\n";

    std::cout << "Чтение из файла (Методом класса)\n";
    std::cout << "Enter Input File Name - ";
    char ar2[80];
    std::cin >> ar2;
    
    if (l.read_from_file(ar2)) {
        std::cout << "Список, прочитанный из файла:\n" << l;
    } else {
        std::cout << "Ошибка открытия или чтения файла.\n";
    }

    return 0;
}