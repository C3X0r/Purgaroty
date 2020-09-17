#pragma once
#include<chrono>
#include"WindowsIsAMeme.h"
#define RECORD_KEYBOARD 4
#define RECORD_MOUSE 2
#define RECORD_MOUSE_POS 1

typedef struct LiveLog {
	static char lastKeyPressed;
	typedef struct mousePos {
		static int x;
		static int y;
	};
	static bool rmb;
	static bool lmb;
	static bool mmb;
	static float scrollClimb;
	static int wholeScrolls;
};


class Log {
public:
	void startLog(unsigned int var) noexcept;
	void endLog() noexcept;
private:
	std::chrono::steady_clock::time_point startTime;
	std::chrono::steady_clock::time_point eta;
	std::chrono::steady_clock::time_point endTime;
	float duration;
	bool logStatus = true;
};
