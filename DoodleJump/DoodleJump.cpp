#include <string>
#include <string.h>

#include "Game.h"
#include "DefaultGameValues.h"
#include "EnemyService.h"

int main(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i], "-window") == 0 && argc - 1 != i)
		{
			std::string size = argv[i + 1];
			std::string width;
			std::string height;
			
			size_t delimiterPosition = size.find("x");
			if (delimiterPosition != std::string::npos) 
			{
				width = size.substr(0, delimiterPosition);
				height = size.substr(delimiterPosition + 1);
			}
			else {
				throw new std::runtime_error("Wrong window size format.");
			}

			DGV::Window::CurrentWidth = std::stoi(width.c_str());
			DGV::Window::CurrentHeight = std::stoi(height.c_str());
		}
	}

	return run(new Game);
}