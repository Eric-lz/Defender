#include "Render.h"

Render::Render()
{
	system(windowSize);
}

void Render::drawMap(vector<string>& map, int frame_start)
{
	// framebuffer
	string frame;

	// read every line and add to framebuffer
	for (auto& line : map) {
		// loop the map back around when it reaches the end
		if ((frame_start + frame_width) > line.length()) {
			// copy from frame_start to end of string
			frame += line.substr(frame_start);
			// append from start of string
			frame += line.substr(0, (frame_start + frame_width - line.length()));
		}
		else {
			frame += line.substr(frame_start, frame_width);
		}

		frame += '\n'; // add line break to framebuffer
	}

	// move cursor to top left
	Goto::gotoxy(0, 0);
	// print framebuffer
	std::cout << frame << std::endl;
}

void Render::drawPlayer(int x, int y)
{
	Goto::gotoxy(x, y);
	std::cout << "@";
	Goto::gotoxy(x, y + 1);
	std::cout << "@@@@";
}
