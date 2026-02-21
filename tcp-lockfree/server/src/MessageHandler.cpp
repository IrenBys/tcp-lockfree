#include "MessageHandler.h"

// Метод для обработки входящих сообщений от клиентов
std::string MessageHandler::handleMessage(const std::string& message)
{
	// Пока просто выводим сообщение и возвращаем его обратно	
	if (message.empty())
	{
		std::cerr << "Received empty message." << std::endl;
		return std::string();
	}
	else
	{
		std::cout << "Handling message: " << message << std::endl;
		return "Message handled: " + message; // Пример обработки сообщения
	}	
}
