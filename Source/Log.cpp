#include<thread>>
#include<fstream>
#include"WindowsIsAMeme.h"
#include"Log.h"

//Static variable definations =>
char LiveLog::lastKeyPressed;
int LiveLog::mousePos::x;
int LiveLog::mousePos::y;
bool LiveLog::lmb = false;
bool LiveLog::rmb = false;
bool LiveLog::mmb = false;
float LiveLog::scrollClimb;
int LiveLog::wholeScrolls;

void Log::startLog(unsigned int var) noexcept {
	this->startTime = std::chrono::high_resolution_clock::now();
	while (this->logStatus) {
		if ((var >> 2) == 1) {
			//Record Keyboard
			std::ofstream file("Keyboard_Log.txt");
			file << LiveLog::lastKeyPressed;
			file.close();
		}
		if ((var >> 1) == 1) {
			//Record Mouse
			this->eta = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float, std::milli> diff = this->eta - this->startTime;
			std::ofstream file("Mouse_Log.txt");
			if (LiveLog::lmb) {
				file << "| Mouse Button Pressed: " << "Left   |" << "Mouse pos: (" << LiveLog::mousePos::x << "," << LiveLog::mousePos::y << ")" << "  Elapsed Time:" << diff.count() << "ms" << std::endl;
				LiveLog::lmb = !LiveLog::lmb;
			}
			else if (LiveLog::rmb) {
				file << "| Mouse Button Pressed: " << "Right  |" << "Mouse pos: (" << LiveLog::mousePos::x << "," << LiveLog::mousePos::y << ")" << "  Elapsed Time:" << diff.count() << "ms" << std::endl;
				LiveLog::rmb = !LiveLog::rmb;
			}
			else if (LiveLog::mmb) {
				file << "| Mouse Button Pressed: " << "Middle |" << "Mouse pos: (" << LiveLog::mousePos::x << "," << LiveLog::mousePos::y << ")" << "  Elapsed Time:" << diff.count() << "ms" << std::endl;
				LiveLog::mmb = !LiveLog::mmb;
			}
			file.close();
		}
		if ((var >> 0) == 1) {
			//Record Mouse Pos
			this->eta = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float, std::milli> diff = this->eta - this->startTime;
			std::ofstream file("Mouse_Pos.txt");
			file << "Mouse pos: (" << LiveLog::mousePos::x << "," << LiveLog::mousePos::y << ")" << "  Elapsed Time:" << diff.count() <<"ms"<< std::endl;
			Sleep(1000);
			file.close();
		}
	}
	this->logStatus = true;
}
void Log::endLog() noexcept {
	this->logStatus = false;
	this->endTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float, std::milli> diff = this->endTime - this->startTime; 
	this->duration = diff.count();
}
