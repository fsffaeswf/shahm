#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
const float WINDOOW_WIDTH = 800;
const float WINDOOW_HEIGHT = 600;
const std::string WINDOOW_TITLE = "SFML Lesson2";
int main()
{

	RenderWindow window(VideoMode(WINDOOW_WIDTH, WINDOOW_HEIGHT), WINDOOW_TITLE);
	//создание массива квадратов
	const int size = 8;



	RectangleShape arr_rect[48];
	RectangleShape arr_rect1[48];

	const float a = 50.f;

	
	int y = 0,y1 = 0;
	//заполнение массивов квадратов
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < size; j++) {

			arr_rect[y].setSize(Vector2f(a, a));
			arr_rect[y].setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
			arr_rect[y].setPosition((a + a) * j, (a+a)*i);
			
			y++;
		}
		for (int k = 0; k < size; k++) {
			arr_rect1[y1].setSize(Vector2f(a, a));
			arr_rect1[y1].setFillColor(Color{ (Uint8)(rand() % 256),(Uint8)(rand() % 256),(Uint8)(rand() % 256) });
			arr_rect1[y1].setPosition(
				(a + a) * k + a, (a+a) * i +a
			);
			y1++;
		}
	}
		while (window.isOpen())
		{
			Event event;
			while (window.pollEvent(event))
			{
		
				if (event.type == Event::Closed)
					
					window.close();
			}
			//отрисовка квадратов
			int y = 0;
			int y1 = 0;
			for (int i = 0; i < 6; i++) {
				
				for (int j = 0; j < size; j++) {
					window.draw(arr_rect[y]);
					y++;
				}
			
				for (int k = 0; k < size; k++) {
					window.draw(arr_rect1[y1]);
					y1++;
				}
			
				
			}
			window.display();
		}

	return 0;
}
