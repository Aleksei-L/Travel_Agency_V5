#include "Class.h"

int main() {
	int size, code, position, begin, end, left, right;
	std::cout << "Enter Table's size: ";
	std::cin >> size;
	Table myT(size);
	Client first, second;
	Client F("a", "s", 2, 2), S("a", "s", 3, 2), Th("a", "s", 4, 2);
	Client* arr[3] = { &F, &S ,&Th };
	while (true) {
		std::cout << "Select the program operation mode:" << std::endl;
		std::cout << "1) Input table" << std::endl;
		std::cout << "2) Output table" << std::endl;
		std::cout << "3) Sort table" << std::endl;
		std::cout << "4) Search client in table" << std::endl;
		std::cout << "5) Erase client from table" << std::endl;
		std::cout << "6) Remove client from table" << std::endl;
		std::cout << "7) Replace client in table" << std::endl;
		std::cout << "8) Insert clients to table from array" << std::endl;
		std::cout << "11) Erase clients from left to right" << std::endl;
		std::cout << "12) Replace client in table from left to right" << std::endl;
		std::cout << "13) Sort table from left to right" << std::endl;
		std::cout << "14) Exit" << std::endl;
		std::cin >> code;
		switch (code) {
		case 1:
			std::cout << std::endl;
			myT.Input(&first);
			std::cout << std::endl;
			break;
		case 2:
			std::cout << std::endl;
			myT.Output();
			std::cout << std::endl;
			break;
		case 3:
			std::cout << std::endl;
			myT.Sort();
			std::cout << std::endl;
			break;
		case 4:
			std::cout << std::endl;
			std::cout << "Enter client for Search:" << std::endl;
			first.input();
			std::cout << "Client's index: " << myT.Search(&first) << " (-1 if not founded)" << std::endl;
			std::cout << std::endl;
			break;
		case 5:
			std::cout << std::endl;
			std::cout << "Enter position(client's number) for Erase:" << std::endl;
			std::cin >> position;
			myT.Erase(myT.Begin() + position - 1);
			std::cout << std::endl;
			break;
		case 6:
			std::cout << std::endl;
			std::cout << "Enter client for Remove:" << std::endl;
			first.input();
			myT.Remove(&first);
			std::cout << std::endl;
			break;
		case 7:
			std::cout << std::endl;
			std::cout << "Enter old client for Replace:" << std::endl;
			first.input();
			std::cout << "Enter new client for Replace:" << std::endl;
			second.input();
			myT.Replace(&first, &second);
			std::cout << std::endl;
			break;
		case 8:
			std::cout << std::endl;
			myT.Insert(myT.GetPntr(0), &arr[0], &arr[2]);
			std::cout << std::endl;
			break;
		case 11:
			std::cout << std::endl;
			do {
				std::cout << "Enter left position (from 0 to " << myT.Length() - 1 << "): ";
				std::cin >> left;
				std::cout << "Enter right position: (from 0 to " << myT.Length() - 1 << "): ";
				std::cin >> right;
			} while (left < 0 || left > myT.Length() - 1 || right < 0 || right > myT.Length() - 1);
			myT.Erase(myT.GetPntr(left), myT.GetPntr(right));
			std::cout << std::endl;
			break;
		case 12:
			std::cout << std::endl;
			std::cout << "Enter old client for Replace:" << std::endl;
			first.input();
			std::cout << "Enter new client for Replace:" << std::endl;
			second.input();
			do {
				std::cout << "Enter left position (from 0 to " << myT.Length() - 1 << "): ";
				std::cin >> left;
				std::cout << "Enter right position: (from 0 to " << myT.Length() - 1 << "): ";
				std::cin >> right;
			} while (left < 0 || left > myT.Length() - 1 || right < 0 || right > myT.Length() - 1);
			myT.Replace(myT.GetPntr(left), myT.GetPntr(right), &first, &second);
			std::cout << std::endl;
			break;
		case 13:
			std::cout << std::endl;
			std::cout << "Input first and last index: ";
			std::cin >> begin >> end;
			myT.Sort(begin, end);
			std::cout << std::endl;
			break;
		case 14:
			return 0;
		default:
			std::cout << std::endl;
			std::cout << "Unknown command" << std::endl;
			std::cout << std::endl;
		}
	}
}
