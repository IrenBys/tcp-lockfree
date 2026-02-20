#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>


class Server
{
public:
	Server(int p = 8080);	// конструктор с параметром для порта (по умолчанию 8080)
	~Server();				// деструктор для очистки ресурсов
	void start();			// метод для запуска сервера
	void stop();			// метод для остановки сервера
	void acceptClients();	// метод для принятия клиентов

private:
	int serverSocket;		// сокет сервера
	int clientSocket;		// сокет для клиента (можно использовать для каждого клиента в отдельном потоке)
	int port;				// порт, на котором работает сервер
	bool isRunning;			// флаг для контроля работы сервера

	// Вспомогательные методы для управления серверным сокетом
	bool createServerSocket();				// метод для создания серверного сокета	
	bool bindServerSocket();				// метод для привязки серверного сокета к порту
	bool listenForClients();				// метод для начала прослушивания входящих соединений
	void handleClient(int clientSocket);	// метод для обработки клиента (может быть запущен в отдельном потоке)
	
	std::vector<std::thread> clientThreads; // хранит потоки для каждого клиента
	std::mutex clientThreadsMutex;			// для синхронизации доступа к вектору clientThreads
};