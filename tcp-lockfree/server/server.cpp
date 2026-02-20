#include "server.h"
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <errno.h>


// Конструктор для инициализации порта и других переменных
Server::Server(int p)
	: port(p), isRunning(false), serverSocket(-1)
{
}
// Деструктор для очистки ресурсов
Server::~Server()
{
	// Очистка ресурсов
	stop();	
}

// Метод для запуска сервера
void Server::start()
{
	// Код для запуска сервера (например, привязка сокета, начало прослушивания)
	isRunning = true;
	std::cout << "Server started on port " << port << std::endl;

	std::cout << "Creating server socket..." << std::endl;
	createServerSocket();





	

}

// Метод для остановки сервера
void Server::stop()
{
	// Код для остановки сервера (например, закрытие сокета, остановка всех клиентских потоков)
	isRunning = false;
	std::cout << "Server stopped." << std::endl;
	// Здесь можно добавить код для закрытия сокета и остановки всех клиентских потоков
}

// Метод для принятия клиентов
void Server::acceptClients()
{
	// Код для принятия клиентов (например, цикл для принятия входящих соединений и создания потоков для обработки клиентов)
	while (isRunning)
	{
		// Здесь можно добавить код для принятия входящих соединений и создания потоков для обработки клиентов
	}
}

// Метод для создания серверного сокета
bool Server::createServerSocket()
{
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == -1)
	{
		std::cerr << "Failed to create server socket." << std::endl;
		return false;
	}
	else {
		std::cout << "Server socket created successfully." << std::endl;
		return true;
	}
}

bool Server::bindServerSocket()
{
	struct sockaddr_in serverAddr;	// структура для хранения адреса сервера

	// Настройка структуры адреса сервера
	memset(&serverAddr, 0, sizeof(serverAddr));	// обнуляем структуру

	// Устанавливаем семейство адресов (IPv4)
	serverAddr.sin_family = AF_INET; // IPv4
	serverAddr.sin_port = htons(port); // порт, преобразованный в сетевой порядок байтов
	serverAddr.sin_addr.s_addr = INADDR_ANY; // слушать на всех интерфейсах	

	// Привязываем сокет к адресу и порту
	if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1)
	{
		std::cerr << "Failed to bind server socket to port " << port << ". Error: " << strerror(errno) << std::endl;
		return false;
	}
	else {
		std::cout << "Server socket bound to port " << port << " successfully." << std::endl;
		return true;
	}
}


bool Server::setupServerSocket()
{
	
	return false;
}
