#include <iostream>
#include <fstream>
#include "list.hpp"

int main() {

    std::cout << "Запуск через make\n";

    List l;

    std::cout << "Добавление элементов\n";
    l.add_end(Circle(0, 0, 5));
    l.add_end(Circle(1, 2, 3));
    l.add_first(Circle(-1, -1, 7));

    std::cout << l << "\n";

    std::cout << "Размер списка\n";
    std::cout << "Size: " << l.size() << "\n\n";

    std::cout << "Проверка метода empty\n";
    std::cout << (l.empty() ? "Список пуст\n" : "Список не пуст\n") << "\n";

    std::cout << "Поиск элемента\n";
    Circle target(1, 2, 3);
    Node* found = l.find(target);

    if (found)
        std::cout << "Элемент найден\n\n";
    else
        std::cout << "Элемент не найден\n\n";

    std::cout << "Удаление одного элемента\n";
    l.delete_one_element(target);
    std::cout << l << "\n";

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

    std::cout << "До сортировки:\n";
    std::cout << l << "\n";

    l.upsort();

    std::cout << "После сортировки:\n";
    std::cout << l << "\n";
    std::cout << "Запись в файл\n";
	std::cout<<"Enter Output File Name  - " ;
	char ar1[80];
	std::cin>>ar1;
	std::ofstream fout(ar1);
	fout.close();

    std::cout << "Данные записаны в " << ar1 << "\n\n";

    std::cout << "Очистка списка\n";
    l.clear();
    std::cout << "После очистки:\n";
    std::cout << l;

    std::cout << "Size: " << l.size() << "\n";
    std::cout << (l.empty() ? "Список пуст\n" : "Список не пуст\n");

    std::cout<<"Enter Input File Name  - " ;
	char ar2[80];
	std::cin>>ar2;
    std::ifstream fin(ar2);
    if (fin){
        double x, y, r;

        while ( fin >> x >> y >> r ) {
            l.add_end(Circle(x,y,r));
        }
    }

    else{
        std::cout << "Ошибка открытия файла.\n";
    }

    std::cout << "Список прочитанный из файла\n" << l;

    return 0;
}