#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include<string>
using std::string;

class Window_mgr{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
	ScreenIndex addScreen(const Screen);
private:
	std::vector<Screen> screens{ Screen(24, 80, ' ') };
};
#endif

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];
	s.contents = string(s.height * s.width0, ' ');
}

Window_mgr::ScreenIndex
Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size() - 1;
}
