#include "header/Server.h"
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
	if (!createServerSocket())
	{
		std::cerr << "Failed to create server socket. Server cannot start." << std::endl;
		return;
	}

	std::cout << "Binding server socket to port..." << std::endl;
	if (!bindServerSocket())
	{
		std::cerr << "Failed to bind server socket. Server cannot start." << std::endl;
		return;
	}

	if (!listenForClients())
	{
		std::cerr << "Failed to listen for clients. Server cannot start." << std::endl;
		return;
	}
	std::cout << "Starting to listen for clients..." << std::endl;
	


	

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
	while(isRunning)
	{

		struct sockaddr_in clientAddr;					// структура для хранения адреса клиента
		socklen_t clientAddrLen = sizeof(clientAddr);	// размер структуры адреса клиента

		// Принятие входящего соединения от клиента
		clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientAddrLen);

		// Создание нового потока для обработки клиента
		clientThreads()
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

// Метод для начала прослушивания входящих соединений
bool Server::listenForClients() 
{
	// Начинаем прослушивание входящих соединений
	// SOMAXCONN - это максимальное количество ожидающих соединений, которое может быть поставлено в очередь

	if (listen(serverSocket, SOMAXCONN) == -1)
	{
		std::cerr << "Failed to listen for clients. Error: " << strerror(errno) << std::endl;
		return false;
	}
	else {
		std::cout << "Server is now listening for clients." << std::endl;
		return true;
	}
}

void Server::handleClient(int clientSocket)
{
	// Код для обработки клиента (например, чтение данных, отправка ответа)
	std::cout << "Handling client with socket: " << clientSocket << std::endl;
	while(isRunning)
	{

	}
}


