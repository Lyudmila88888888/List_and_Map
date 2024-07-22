#include <iostream>
#include <string>
#include <list> //библиотека, хранящая в себе реализаци. 
//класса лист (список)
#include <map>// ассоциативная коллекция



int main() {
	setlocale(LC_ALL, "Russian");

	//Класс List (Список)
	std::list<int> list1; // работает бысторо, но не работает арифметика указателей
	list1.push_back(7);
	list1.push_back(105);
	list1.push_back(42);
	list1.push_front(555); // добавляет элемент в начало
	//list1.pop_back(); // удаляет последний элемент
	//list1.pop_front();// удаляет первый элемент

	//list1.back(); //возвращает ссылку на последний элемент

	//for (std::list<int>::const_iterator it = list1.cbegin(); it != list1.cend(); ++it)
		//for (auto it = list1.cbegin(); it != list1.cend(); ++it) // короче так
			//std::cout << *it << ' ';
	for (auto el : list1) //еще короче с помощью foreach
		std::cout << el << ' ';
	std::cout << std::endl;

	auto place = list1.begin(); 
	std::advance(place, 3);// куда нужно сдвинуть позицию для вставления элемента
	std::cout << *place << std::endl; // узнать какое значение в элементе 3 (std::advance(place, 3))
	list1.insert(place, 1000); // добавить новый элемент в любое место

	place = list1.begin();// указатель ставим в начало
	++place; // с помощью итератора направляем на второй элемент
	list1.erase(place);// удаляем элемент

	for (auto el : list1) //foreach
		std::cout << el << ' ';
	std::cout << std::endl;


	// Класс Map
	std::pair<int, std::string> pair(11, "Hello");// структура pair(пара) это основа для работы с классом Map
	//Map это массив пар
	std::cout << pair.first << std::endl;//первый элемент пары - 11
	std::cout << pair.second << std::endl;//второй элемент пары - Hello
	
	//методы
	std::map<std::string, int> map1;
	map1.insert(std::pair<std::string, int>("Tom", 18));//1 способ создания элемента Map
	map1.insert(std::make_pair("Bob", 25));//2 способ создания элемента Map
	map1.emplace("Elisa", 23);//3 способ создания элемента Map
	map1["Mike"] = 50;//4 способ создания элемента Map

	std::cout << map1["Bob"] << std::endl;//25

	std::cout << map1["Mike"] << std::endl; // найти элемент и получить пару этого объекта
	std::cout << map1.find("Mike")->second << std::endl;// или first. найти элемент и получить пару этого объекта

	map1.erase("Bob");// Удаление элемента

	map1.emplace("Tom", 20); // Таким способом возраст Замена значения пары коллекции не работает
	map1["Tom"] = 21; // Замена значения пары коллекции

	//auto para = map1.find("Hello");// Итератор на пару(на бинарное дерево)

	for (auto key : map1) // изначальеый вариант
		std::cout << key.first << " is " << key.second << 
		" years old" << std::endl;
	//first - первый элемент пары, second - второй элемент пары
	
	//for (const auto& [name, age] : map1) 
		//std::cout << key.first << " is " << key.second <<
		//" years old" << std::endl;
		
	return 0;

}
