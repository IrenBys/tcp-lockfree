#pragma once


class Session
{
public:
	Session(int clientSocket);	// конструктор с параметром для сокета клиента
	~Session();					// деструктор для очистки ресурсов
	void receiveData();			// метод для получения данных от клиента
	size_t sendData(const char* data);	// метод для отправки данных клиенту
private:
	int clientSocket;			// сокет для клиента

}