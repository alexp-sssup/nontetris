#ifndef _INPUT_HANDLER
#define _INPUT_HANDLER

#include <functional>


class InputHandler
{
	#ifdef __DUETTO__
	static bool k_down;
	static bool k_left;
	static bool k_right;
	static bool k_z;
	static bool k_x;
	#endif
public:
	InputHandler();
	void process_input(const std::function<void()> & exit, const std::function<void()> & left, const std::function<void()> & right, const std::function<void()> & down, const std::function<void()> & z, const std::function<void()> & x);
	#ifdef __DUETTO__
	static void keydown(client::KeyboardEvent * _e);
	static void keyup(client::KeyboardEvent * _e);
	#endif
};

#endif //_INPUT_HANDLER
