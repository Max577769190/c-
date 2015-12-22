#ifndef SCREEN_H
#define SCREEN_H

#include<string>
#include<iostream>

class Screen
{
	friend void Window_mgr::clear(ScreenIndex);
public:
	typedef std::string::size_type pos;
	Screen() = default;
	Screen(pos ht, pos wd): height(ht), width0(wd), contents(ht*wd, ' ') {  };
	Screen(pos ht, pos wd, char c): height(ht), width0(wd), contents(ht * wd, c) {  };

	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	inline Screen &move(pos r, pos c);
	void some_member() const;
	inline Screen &set(char);
	inline Screen &set(pos, pos, char);
	Screen &display(std::ostream &os) { do_display(os); return *this; };
	const Screen &display(std::ostream &os) const { do_display(os); return *this; }
private:
	mutable size_t access_ctr;
	void do_display(std::ostream &os) const { os << contents; }
	pos cursor = 0;
	pos height = 0, width0 = 0;
	std::string contents;
};
#endif

inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width0;
	cursor = row + c;
	return *this;
}

inline char Screen::get(pos r, pos c) const
{
	pos row = r * width0;
	return contents[row + c];
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width0 + col] = ch;
	return *this;
}
