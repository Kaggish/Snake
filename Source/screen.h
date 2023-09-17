#pragma once
#include <string>

enum class Button
{
	Left,
	Right,
};

enum class Key
{
	Left,
	Right,
	Up,
	Down,
	Space,
	Escape,
	Return,
};

struct Color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a = 255;
};

class Screen
{
public:
	Screen(unsigned int windowWidth = 1280, unsigned int windowHeight = 720, std::string windowTitle = "");
	~Screen();

	bool IsOpen() const;
	int GetMouseX() const;
	int GetMouseY() const;
	bool IsKeyDown(const Key key) const;
	bool IsButtonDown(const Button button) const;
	int GetWindowWidth() const;
	int GetWindowHeight() const;
	void Clear();
	void SetClearColor(unsigned char r, unsigned char g, unsigned char b);
	void SetClearColor(Color color);
	void DrawPixel(int x, int y);
	void DrawPixel(int x, int y, Color color);
	void DrawPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	void DrawRectangle(int x, int y, int width, int height);
	void DrawRectangle(int x, int y, int width, int height, Color color);
	void DrawRectangle(int x, int y, int width, int height, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	void DrawCircle(int x, int y, int radius);
	void DrawCircle(int x, int y, int radius, Color color);
	void DrawCircle(int x, int y, int radius, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	void DrawText(int x, int y, unsigned char r, unsigned char g, unsigned char b, unsigned char a, const std::string &text);
	void DrawText(int x, int y, Color color, const std::string &text);
	void Display();
};
