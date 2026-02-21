#include "header/Session.h"

// Конструктор для инициализации сокета клиента
Session::Session(int clientSocket)
	: clientSocket(clientSocket), isConnected(true)
{
}

// Деструктор для очистки ресурсов
Session::~Session()
{
	stopSession(); // Останавливаем сессию и освобождаем ресурсы
}
// Метод для получения данных от клиента
void Session::receiveData()
{
	// Код для получения данных от клиента
	char buffer[1024];
	ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
	if (bytesRead > 0)
	{
		buffer[bytesRead] = '\0'; // Добавляем нулевой терминатор
		std::cout << "Received data from client: " << buffer << std::endl;
		messageHandler.handleMessage(std::string(buffer)); // Обрабатываем сообщение от клиента
	}
	else if (bytesRead == 0)
	{
		std::cout << "Client disconnected." << std::endl;
	}
	else
	{
		std::cerr << "Failed to receive data from client. Error: " << strerror(errno) << std::endl;
	}
}

// Метод для отправки данных клиенту
size_t Session::sendData(const char* data)
{
	// Код для отправки данных клиенту
	ssize_t bytesSent = send(clientSocket, data, strlen(data), 0);
	if (bytesSent == -1)
	{
		std::cerr << "Failed to send data to client. Error: " << strerror(errno) << std::endl;
		return 0;
	}
	else
	{
		std::cout << "Sent data to client: " << data << std::endl;
		return static_cast<size_t>(bytesSent);
	}
}

void Session::stopSession()
{
	// Код для остановки сессии (например, при отключении клиента)
	isConnected = false;
	if (clientSocket != -1)
	{
		close(clientSocket);
		clientSocket = -1;
	}
}
