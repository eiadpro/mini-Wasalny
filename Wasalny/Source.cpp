#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include "Graphh.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace sf;
Texture Background;
Texture Background1;
Texture Button1;
Texture Button2;
Texture Button3;
Texture Button4;
Texture Button5;
Texture Button6;
Texture Button7;
Texture Button8;
Texture Button9;
Texture Button10;
Texture Button11;
Texture Button12;
Texture Button13;
Texture Button14;
Texture Button15;
Texture wel;
Texture grayy;
Graph g;
Font f;
Text t1;
Text t2;
Text t3;
Text t4;
Text t5;
Text t6;
Text t7;
Text t8;
Text t9;
Text tgraph;
Text tdis;
Text tbfs;
Text tdfs;
Text tshort;
int run = 0;
int now=0;
bool graphtext=false;
bool city2text = false;
bool weightext = false;
bool b1;
bool b2=false;
bool b3 = false;
bool Dir = true;
int stringTointeger(string str)
{
	int temp = 0;
	for (int i = 0; i < str.length(); i++) {

		// Since ASCII value of character from '0'
		// to '9' are contiguous. So if we subtract
		// '0' from ASCII value of a digit, we get
		// the integer value of the digit.
		temp = temp * 10 + (str[i] - '0');
	}
	return temp;
}
int main()
{
	g.LoadGraphes(g.graph);
	g.loadCities(g.adjlist);
	g.loadEdges(g.adjlist);
	Font font;
	if (!font.loadFromFile("RobotoCondensed-Bold.ttf")) {
		std::cout << "Failed to load font!" << std::endl;
		return -1;
	}

	Text text;
	text.setFont(font);
	text.setCharacterSize(50);
	text.setFillColor(sf::Color::Black);
	Text text1;
	text1.setFont(font);
	text1.setCharacterSize(50);
	text1.setFillColor(sf::Color::Black);
	Text text2;
	text2.setFont(font);
	text2.setCharacterSize(50);
	text2.setFillColor(sf::Color::Black);
	string inputText;
	string inputText1;
	string inputText2;
	b1 = true;


	grayy.loadFromFile("gray1.jpg");
	Background.loadFromFile("taxi1.png");
	Background1.loadFromFile("taxi2.jpg");
	Button1.loadFromFile("button1.png");
	Button2.loadFromFile("button2.png");
	Button3.loadFromFile("button3.png");
	Button4.loadFromFile("button4.png");
	Button5.loadFromFile("button5.png");
	Button6.loadFromFile("button6.png");
	Button7.loadFromFile("button7.png");
	Button8.loadFromFile("button8.png");
	Button9.loadFromFile("button9.png");
	Button10.loadFromFile("button10.png");
	Button11.loadFromFile("button11.png");
	Button12.loadFromFile("button12.png");
	Button13.loadFromFile("button13.png");
	Button14.loadFromFile("button4.png");
	Button15.loadFromFile("button15.png");
	wel.loadFromFile("welcome.png");
	f.loadFromFile("RobotoCondensed-Bold.ttf");
	RectangleShape add_Graphbox(Vector2f(180, 40));
	RectangleShape mousebox(Vector2f(180, 40));
	RectangleShape Load_Graphbox(Vector2f(180, 40));
	RectangleShape Delete_Graphbox(Vector2f(180, 40));
	RectangleShape exitbox(Vector2f(180, 40));
	RectangleShape nextbox(Vector2f(180, 40));
	RectangleShape backbox(Vector2f(180, 40));
	RectangleShape add_citybox(Vector2f(180, 40));
	RectangleShape add_edgebox(Vector2f(180, 40));
	RectangleShape display_databox(Vector2f(180, 40));
	RectangleShape remove_citybox(Vector2f(180, 40));
	RectangleShape remove_edgebox(Vector2f(180, 40));
	RectangleShape shortest_pathbox(Vector2f(180, 40));
	RectangleShape apply_bfsbox(Vector2f(180, 40));
	RectangleShape apply_dfsbox(Vector2f(180, 40));
	RectangleShape exitsbox(Vector2f(180, 40));
	RectangleShape recbox(Vector2f(680, 60));
	RectangleShape recbox1(Vector2f(680, 60));
	RectangleShape recbox2(Vector2f(680, 60));
	CircleShape c1(100.f);
	c1.scale(0.2, 0.2);
	c1.setFillColor(sf::Color::Yellow);
	c1.setPosition(-1000, -1000);
	CircleShape c2(100.f);
	c2.scale(0.2, 0.2);
	c2.setFillColor(sf::Color::White);
	c2.setPosition(-1000, -1000);
	Sprite grays(grayy, IntRect(0, 0, 605, 127));
	Sprite welcome(wel, IntRect(0, 0, 605, 127));
	Sprite background1(Background, IntRect(0, 0, 1980, 1920));
	Sprite background2(Background1, IntRect(0, 0, 1076, 639));
	Sprite button1(Button1, IntRect(0, 0, 603, 127));
	Sprite button2(Button2, IntRect(0, 0, 603, 127));
	Sprite button3(Button3, IntRect(0, 0, 603, 127));
	Sprite button4(Button4, IntRect(0, 0, 603, 127));
	Sprite button5(Button5, IntRect(0, 0, 603, 127));
	Sprite button6(Button6, IntRect(0, 0, 603, 127));
	Sprite button7(Button7, IntRect(0, 0, 603, 127));
	Sprite button8(Button8, IntRect(0, 0, 603, 127));
	Sprite button9(Button9, IntRect(0, 0, 603, 127));
	Sprite button10(Button10, IntRect(0, 0, 603, 127));
	Sprite button11(Button11, IntRect(0, 0, 603, 127));
	Sprite button12(Button12, IntRect(0, 0, 603, 127));
	Sprite button13(Button13, IntRect(0, 0, 603, 127));
	Sprite button14(Button14, IntRect(0, 0, 603, 127));
	Sprite button15(Button15, IntRect(0, 0, 603, 127));
	background1.scale(1.33, 1);
	background2.scale(1.78, 1.68);
	welcome.setPosition(650, 50);
	button1.setPosition(100, 880);
	button1.scale(0.6, 0.6);
	button2.setPosition(550, 880);
	button2.scale(0.6, 0.6);
	button3.setPosition(1000, 880);
	button3.scale(0.6, 0.6);
	button4.setPosition(1450, 880);
	button4.scale(0.6, 0.6);
	button7.setPosition(1510, 60);
	button7.scale(0.6, 0.6);
	add_citybox.setScale(2.02, 1.89);
	add_citybox.setPosition(1510, 60);
	add_edgebox.setScale(2.02, 1.89);
	add_edgebox.setPosition(1510, 172);
	button8.setPosition(1510, 172);
	button8.scale(0.6, 0.6);
	remove_citybox.setScale(2.02, 1.89);
	remove_citybox.setPosition(1510, 284);
	button10.setPosition(1510, 284);
	button10.scale(0.6, 0.6);
	remove_edgebox.setScale(2.02, 1.89);
	remove_edgebox.setPosition(1510, 396);
	button15.setPosition(1510, 396);
	button15.scale(0.6, 0.6);
	display_databox.setScale(2.02, 1.89);
	display_databox.setPosition(1510, 508);
	button9.setPosition(1510, 508);
	button9.scale(0.6, 0.6);
	shortest_pathbox.setScale(2.02, 1.89);
	shortest_pathbox.setPosition(1510, 620);
	button11.setPosition(1510, 620);
	button11.scale(0.6, 0.6);
	apply_bfsbox.setScale(2.02, 1.89);
	apply_bfsbox.setPosition(1510, 732);
	button12.setPosition(1510, 732);
	button12.scale(0.6, 0.6);
	apply_dfsbox.setScale(2.02, 1.89);
	apply_dfsbox.setPosition(1510, 844);
	button13.setPosition(1510, 844);
	button13.scale(0.6, 0.6);
	exitsbox.setScale(2.02, 1.89);
	exitsbox.setPosition(1510, 956);
	button14.setPosition(1510, 956);
	button14.scale(0.6, 0.6);
	button5.scale(0.6, 0.6);

	button6.scale(0.6, 0.6);
	add_Graphbox.setFillColor(sf::Color::Yellow);
	add_Graphbox.setPosition(100, 880);
	add_Graphbox.setScale(2.02, 1.89);
	Load_Graphbox.setFillColor(sf::Color::Yellow);
	Load_Graphbox.setPosition(550, 880);
	Load_Graphbox.setScale(2.02, 1.89);
	Delete_Graphbox.setFillColor(sf::Color::Yellow);
	Delete_Graphbox.setPosition(1000, 880);
	Delete_Graphbox.setScale(2.02, 1.89);
	exitbox.setFillColor(sf::Color::Yellow);
	exitbox.setPosition(1450, 880);
	exitbox.setScale(2.02, 1.89);
	nextbox.setFillColor(sf::Color::Yellow);

	nextbox.setScale(2.02, 1.89);
	backbox.setFillColor(sf::Color::Yellow);
	backbox.setScale(2.02, 1.89);
	mousebox.setScale(0.05, 0.5);
	t1.setFont(f);
	t1.setCharacterSize(42);
	t1.setFillColor(sf::Color::Red);
	t1.setPosition(600, 1000);
	t1.setString("Warning  :  No Graph added ! ");
	t2.setFont(f);
	t2.setCharacterSize(64);
	t2.setFillColor(sf::Color::White);
	t2.setString("Enter Graph name : ");
	t5.setFont(f);
	t5.setCharacterSize(64);
	t5.setFillColor(sf::Color::White);
	t5.setString("Enter  name of the city :");
	t6.setFont(f);
	t6.setCharacterSize(64);
	t6.setFillColor(sf::Color::White);
	t6.setString("Enter the starting city :");
	t7.setFont(f);
	t7.setCharacterSize(64);
	t7.setFillColor(sf::Color::White);
	t7.setString("Enter source : ");
	t8.setFont(f);
	t8.setCharacterSize(64);
	t8.setFillColor(sf::Color::White);
	t8.setString("Enter destination : ");
	t9.setFont(f);
	t9.setCharacterSize(64);
	t9.setFillColor(sf::Color::White);
	t9.setString("Enter distance between cities : ");
	t3.setFont(f);
	t3.setCharacterSize(40);
	t3.setFillColor(sf::Color::Color(98, 52, 18));
	t3.setString("Directed ");
	t4.setFont(f);
	t4.setCharacterSize(40);
	t4.setFillColor(sf::Color::Color(98, 52, 18));
	t4.setString("Undirected ");
	tgraph.setFont(f);
	tgraph.setCharacterSize(36);
	tgraph.setFillColor(sf::Color::Black);
	tdis.setFont(f);
	tdis.setCharacterSize(36);
	tdis.setFillColor(sf::Color::Black);
	tbfs.setFont(f);
	tbfs.setCharacterSize(40);
	tbfs.setFillColor(sf::Color::Black);
	tdfs.setFont(f);
	tdfs.setCharacterSize(40);
	tdfs.setFillColor(sf::Color::Black);
	tshort.setFont(f);
	tshort.setCharacterSize(40);
	tshort.setFillColor(sf::Color::Black);

	grays.setPosition(0, 1080);
	grays.setScale(3.3, 7);
	RenderWindow window(VideoMode(1920, 1080), "Wasalny",Style::Fullscreen);


	while (window.isOpen())
	{
		run++;
		string totally;
		string totall;
		string tota="";
		b2 = false;
		b3 = false;

		for (auto it : g.graph)
		{
			totally += " ( " + it.first + " , ";
			if (it.second)
				totally += "Directed Graph )\n";
			else
			{
				totally += "Undirected Graph )\n";
			}
		}
		if (!g.isDirected) {
			int ii = 0;
			for (auto it : g.adjlist) {
				for (auto iti : it.second) {

					totall += it.first + "----- " + iti.first;
					totall +="  " + to_string(iti.second)+"    ";
					ii++;
					if (ii % 10 == 0)
						totall += "\n";
				}

			}
		}
		else
		{
			int ii = 0;
			for (auto it : g.adjlist) {
				for (auto iti : it.second) {
					totall+= it.first + "----> " + iti.first;

					totall+= "  " + to_string(iti.second) + "    ";
					ii++;
					if (ii % 10 == 0)
						totall += "\n";
				}

			}
		}
		totall += "\n";
		for (auto it : g.adjlist)
		{
			totall+= "\n City    :   "  + it.first ;
		}
		tgraph.setString("Graphes exist is : \n" + totally);
		tdis.setString(totall);
		if (Dir) {
			c1.setFillColor(Color::Yellow);
			c2.setFillColor(Color::White);
		}
		else {
			c2.setFillColor(Color::Yellow);
			c1.setFillColor(Color::White);
		}
		Event event;
		
		if (now == 1) {
			text.setPosition(600, 310);
			recbox.setPosition(grays.getPosition().x + 600, grays.getPosition().y + 115);
			recbox1.setPosition(-1000, -1000);
			recbox2.setPosition(-1000, -1000);
			c1.setPosition(grays.getPosition().x + 100, grays.getPosition().y + 300);
			c2.setPosition(grays.getPosition().x + 500, grays.getPosition().y + 300);
			t2.setPosition(grays.getPosition().x + 100, grays.getPosition().y + 100);
			t3.setPosition(grays.getPosition().x + 150, grays.getPosition().y + 295);
			t4.setPosition(grays.getPosition().x + 550, grays.getPosition().y + 295);
		}
		else if (now == 2 || now == 3) {
			t2.setPosition(grays.getPosition().x + 700, grays.getPosition().y + 100);
			recbox.setPosition(grays.getPosition().x + 1200, grays.getPosition().y + 115);
			recbox1.setPosition(-1000, -1000);
			recbox2.setPosition(-1000, -1000);
			tgraph.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 50);
			text.setPosition(1200, 310);
		}
		else if (now == 5) {
			text.setPosition(670, 310);
			t5.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 100);
			recbox.setPosition(grays.getPosition().x + 670, grays.getPosition().y + 115);
			recbox1.setPosition(-1000, -1000);
			recbox2.setPosition(-1000, -1000);
		}
		else if (now == 11) {
			text.setPosition(670, 310);
			t5.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 100);
			
			recbox.setPosition(grays.getPosition().x + 670, grays.getPosition().y + 115);
			recbox1.setPosition(-1000, -1000);
			recbox2.setPosition(-1000, -1000);
		}

		else if (now == 6) {
			tdis.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 50);
		}
		else if (now == 7) {
			text.setPosition(670, 310);
			tbfs.setPosition(grays.getPosition().x + 670, grays.getPosition().y + 200);
			t6.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 100);
			recbox.setPosition(grays.getPosition().x + 670, grays.getPosition().y + 115);
			recbox1.setPosition(-1000, -1000);
			recbox2.setPosition(-1000, -1000);
		}
		else if (now == 13) {
			text.setPosition(415, 310);
			text1.setPosition(525, 410);
			tshort.setPosition(grays.getPosition().x + 670, grays.getPosition().y + 200);
			t7.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 100);
			t8.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 200);
			recbox.setPosition(grays.getPosition().x + 415, grays.getPosition().y + 115);
			recbox1.setPosition(grays.getPosition().x + 525, grays.getPosition().y + 215);
			recbox2.setPosition(-1000, -1000);
		}
		else if (now == 12) {
			text.setPosition(415, 310);
			text1.setPosition(525, 410);
			text2.setPosition(845, 510);
			tshort.setPosition(grays.getPosition().x + 470, grays.getPosition().y + 200);
			t7.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 100);
			t8.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 200);
			t9.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 300);
			recbox.setPosition(grays.getPosition().x + 415, grays.getPosition().y + 115);
			recbox1.setPosition(grays.getPosition().x + 525, grays.getPosition().y + 215);
			recbox2.setPosition(grays.getPosition().x + 845, grays.getPosition().y + 315);
		}
		else if (now == 14) {
			text.setPosition(415, 310);
			text1.setPosition(525, 410);
			text2.setPosition(845, 510);
			tshort.setPosition(grays.getPosition().x + 470, grays.getPosition().y + 200);
			t7.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 100);
			t8.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 200);
			t9.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 300);
			recbox.setPosition(grays.getPosition().x + 415, grays.getPosition().y + 115);
			recbox1.setPosition(grays.getPosition().x + 525, grays.getPosition().y + 215);
			recbox2.setPosition(grays.getPosition().x + 845, grays.getPosition().y + 315);
		}
		else if (now == 8) {
			text.setPosition(670, 310);
			tdfs.setPosition(grays.getPosition().x + 670, grays.getPosition().y + 200);
			t6.setPosition(grays.getPosition().x + 50, grays.getPosition().y + 100);
			recbox.setPosition(grays.getPosition().x + 670, grays.getPosition().y + 115);
			recbox1.setPosition(-1000, -1000);
			recbox2.setPosition(-1000, -1000);
		}
		button5.setPosition(grays.getPosition().x + 100, grays.getPosition().y + 750);
		button6.setPosition(grays.getPosition().x + 1450, grays.getPosition().y + 750);
		nextbox.setPosition(grays.getPosition().x + 1450, grays.getPosition().y + 750);
		backbox.setPosition(grays.getPosition().x + 100, grays.getPosition().y + 750);
		if ((now!=0 && now !=4)&& grays.getPosition().y>200) {
			grays.move(0,-1.2);
		}
		if ( grays.getPosition().y < 1080) {
			grays.move(0, 0.6);
		}
		if (button1.getPosition().x > 100) {
			button1.move(-0.1, 0);
			add_Graphbox.move(-0.1, 0);
		}
		if (button2.getPosition().x > 550) {
			button2.move(-0.1, 0);
			Load_Graphbox.move(-0.1, 0);
		}
		if (button3.getPosition().x > 1000) {
			button3.move(-0.1, 0);
			Delete_Graphbox.move(-0.1, 0);
		}
	
		if (button4.getPosition().x > 1450) {
			button4.move(-0.1, 0);
			exitbox.move(-0.1, 0);
		}

		button1.setColor(Color::White);
		button2.setColor(Color::White);
		button3.setColor(Color::White);
		button4.setColor(Color::White);
		button5.setColor(Color::White);
		button6.setColor(Color::White);
		button7.setColor(Color::White);
		button8.setColor(Color::White);
		button9.setColor(Color::White);
		button10.setColor(Color::White);
		button11.setColor(Color::White);
		button12.setColor(Color::White);
		button13.setColor(Color::White);
		button14.setColor(Color::White);
		button15.setColor(Color::White);
		mousebox.setPosition(Mouse::getPosition().x, Mouse::getPosition().y);
	
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			else if (event.type == sf::Event::TextEntered&&grays.getPosition().y <= 203&&graphtext) {
				if (event.text.unicode < 128) {
					if (event.text.unicode == '\b' && !inputText.empty()) {
						// Handle backspace
						inputText.pop_back();
					}
					else if (event.text.unicode != '\b') {
						// Append entered character to inputText
						inputText += static_cast<char>(event.text.unicode);
					}
					text.setString(inputText);
					
				}
			}
			else if (event.type == sf::Event::TextEntered && grays.getPosition().y <= 203 && city2text) {
				if (event.text.unicode < 128) {
					if (event.text.unicode == '\b' && !inputText1.empty()) {
						// Handle backspace
						inputText1.pop_back();
					}
					else if (event.text.unicode != '\b') {
						// Append entered character to inputText
						inputText1 += static_cast<char>(event.text.unicode);
					}
					text1.setString(inputText1);

				}
			}
			else if (event.type == sf::Event::TextEntered && grays.getPosition().y <= 203 && weightext) {
				if (event.text.unicode < 128) {
					if (event.text.unicode == '\b' && !inputText2.empty()) {
						// Handle backspace
						inputText2.pop_back();
					}
					else if (event.text.unicode != '\b') {
						// Append entered character to inputText
						inputText2 += static_cast<char>(event.text.unicode);
					}
					text2.setString(inputText2);

				}
			}
	}
		if (mousebox.getGlobalBounds().intersects(add_Graphbox.getGlobalBounds()) && now == 0&& grays.getPosition().y >= 1079) {
			button1.setColor(Color::Color(255, 255, 20));
			if (button1.getPosition().x < 150) {
				button1.move(0.2, 0);
				add_Graphbox.move(0.2, 0);
			}
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				b1 = true;
				now=1;
			}
		}
		else if (mousebox.getGlobalBounds().intersects(Load_Graphbox.getGlobalBounds()) && now == 0 && grays.getPosition().y >= 1079) {
			button2.setColor(Color::Color(255, 255, 20));
			if (button2.getPosition().x < 600) {
				button2.move(0.2, 0);
				Load_Graphbox.move(0.2, 0);
			}
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				b1 = true;
				if (g.graph.empty()) {
					b1 = false;
					t1.setString("Warning  :  No Graph added ! ");
				}
				else {
					now = 2;
					g.LoadGraph();
				}
			}
		}

	   else	if (mousebox.getGlobalBounds().intersects(Delete_Graphbox.getGlobalBounds()) && now == 0 && grays.getPosition().y >= 1079) {
			button3.setColor(Color::Color(255, 255, 20));
			if (button3.getPosition().x < 1050) {
				button3.move(0.2, 0);
				Delete_Graphbox.move(0.2, 0);
			}
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				b1 = true;
				if (g.graph.empty()) {
					b1 = false;
					t1.setString("Warning  :  No Graph added ! ");
				}
				else {
					now = 3;
					//g.DeleteGraph();
				}
			}
		}
		else if (mousebox.getGlobalBounds().intersects(exitbox.getGlobalBounds())&&now==0 && grays.getPosition().y >= 1079 && run > 400) {
			button4.setColor(Color::Color(255, 255, 20));
			if (button4.getPosition().x < 1500) {
				button4.move(0.2, 0);
				exitbox.move(0.2, 0);
			}
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				g.SaveGraphes();
				window.close();
			}
		}
		if (mousebox.getGlobalBounds().intersects(add_citybox.getGlobalBounds()) && now == 4 && grays.getPosition().y >= 1079) {
			button7.setColor(Color::Color(255, 255, 20));
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				now = 5;
				b1 = true;
			}
		}
		else if (mousebox.getGlobalBounds().intersects(add_edgebox.getGlobalBounds()) && now == 4 && grays.getPosition().y >= 1079) {
			button8.setColor(Color::Color(255, 255, 20));
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				if (g.adjlist.size() < 2) {
					t1.setString("Warning  :  Cities is less than 2 !");
						b1 = false;
				}
				else
				{
					now = 12;
					b1 = true;
				}
			}
		}
		else if (mousebox.getGlobalBounds().intersects(display_databox.getGlobalBounds()) && now == 4 && grays.getPosition().y >= 1079) {
			button9.setColor(Color::Color(255, 255, 20));
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				if (g.adjlist.size() < 1) {
					t1.setString("Warning  :  No city added ! ");
					b1 = false;
				}
				else
				{
					now = 6;
					b1 = true;
				}
			}
		}
		else if (mousebox.getGlobalBounds().intersects(remove_citybox.getGlobalBounds()) && now == 4 && grays.getPosition().y >= 1079) {
			button10.setColor(Color::Color(255, 255, 20));
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				if (g.adjlist.size() < 1) {
					t1.setString("Warning  :  No city added ! ");
					b1 = false;
				}
				else
				{
					now = 11;
					b1 = true;
				}
			}
		}
		else if (mousebox.getGlobalBounds().intersects(remove_edgebox.getGlobalBounds()) && now == 4 && grays.getPosition().y >= 1079) {
			button15.setColor(Color::Color(255, 255, 20));
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				bool isExist = false;
				for (auto it :g. adjlist) {
					if (!g.adjlist[it.first].empty()) {
						isExist = true;
						break;
					}
				}
				if (!isExist) {
					t1.setString("There is no edge to delete ! ");
					b1 = false;
				}
				else
				{
					now = 14;
					b1 = true;
				}
			}
		}
		else if (mousebox.getGlobalBounds().intersects(shortest_pathbox.getGlobalBounds()) && now == 4 && grays.getPosition().y >= 1079) {
			button11.setColor(Color::Color(255, 255, 20));
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				if (g.adjlist.size() < 1) {
					t1.setString("Warning  :  No city added ! ");
					b1 = false;
				}
				else
				{
					now = 13;
					b1 = true;
				}
			}
		}
		else if (mousebox.getGlobalBounds().intersects(apply_bfsbox.getGlobalBounds()) && now == 4 && grays.getPosition().y >= 1079) {
			button12.setColor(Color::Color(255, 255, 20));
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				if (g.adjlist.size() < 1) {
					t1.setString("Warning  :  No city added ! ");
					b1 = false;
				}
				else
				{
					now = 7;
					b1 = true;
				}
			}
		}
		else if (mousebox.getGlobalBounds().intersects(apply_dfsbox.getGlobalBounds()) && now == 4 && grays.getPosition().y >= 1079) {
			button13.setColor(Color::Color(255, 255, 20));
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				if (g.adjlist.size() < 1) {
					t1.setString("Warning  :  No city added ! ");
					b1 = false;
				}
				else
				{
					now = 8;
					b1 = true;
				}
			}
		}
		else if (mousebox.getGlobalBounds().intersects(exitsbox.getGlobalBounds()) && now == 4 &&run>400 && grays.getPosition().y >= 1079) {
			button14.setColor(Color::Color(255, 255, 20));
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				b1 = true;
				g.savecities();
				g.save();
				g.SaveGraphes();
				stack<string> del;
				for (auto it : g.adjlist) {
					del.push(it.first);
				}
				while (!del.empty())
				{
					g.adjlist.erase(del.top());
					del.pop();
				}
				grays.setPosition(0, 1080);
				now = 0;
				run = 0;

			}
		}
		if (mousebox.getGlobalBounds().intersects(backbox.getGlobalBounds())) {
			button5.setColor(Color::Color(255, 255, 20));
			if (Mouse::isButtonPressed(Mouse::Button::Left) && grays.getPosition().y <= 202) {
				text.setString("");
				inputText = "";
				text1.setString("");
				inputText1 = "";
				text2.setString("");
				inputText2 = "";
				b1 = true;
				 graphtext = false;
				 city2text = false;
				 weightext = false;
				 if(now < 4)
				 now = 0;
				 if (now >4)
					 now = 4;
			}
		}
			else if (mousebox.getGlobalBounds().intersects(nextbox.getGlobalBounds())) {
				button6.setColor(Color::Color(255, 255, 20));
				if (Mouse::isButtonPressed(Mouse::Button::Left) && grays.getPosition().y <= 202) {
					graphtext = false;
					city2text = false;
					weightext = false;
					if (now == 1) {
						if (text.getString() == "") {
							t1.setString("Warning : enter the data!\n\n");
							b1 = false;
						}
						else
						{
							b1 = true;

							for (auto it : g.graph) {
								if (text.getString() == it.first) {

									t1.setString("Warning : This graph is already exist ! load it\n\n");
									b1 = false;
									break;
								}
							}
							if (b1) {
								g.gr = text.getString();
								g.isDirected = Dir;
								text.setString("");
								inputText = "";
								g.AddGraph();
								run = 0;
								now = 4;
							}
						}
					}
					else if (now == 2) {
						if (text.getString() == "") {
							t1.setString("Warning : enter the data!\n\n");
							b1 = false;
						}
						else
						{
							for (auto it : g.graph) {
								if (text.getString() == it.first) {
									g.isDirected = it.second;
									g.gr = text.getString();
									stack<string> del;
									for (auto it : g.adjlist) {
										del.push(it.first);
									}
									while (!del.empty())
									{
										g.adjlist.erase(del.top());
										del.pop();
									}
									g.loadCities(g.adjlist);
									g.loadEdges(g.adjlist);

									text.setString("");
									inputText = "";
									b2 = true;
									run = 0;
									now = 4;

									break;
								}

							}

							if (!b2) {
								t1.setString("Warning : This graph is not exist !add it \n\n");
								b1 = false;
							}
							else
							{
								b1 = true;
							}
						}
					}
					else if (now == 3) {
						if (text.getString() == "") {
							t1.setString("Warning :  enter the data!\n\n");
							b1 = false;
						}
						else
						{
							for (auto it : g.graph)
							{
								if (text.getString() == it.first) {
									g.graph.remove(make_pair(text.getString(), it.second));
									text.setString("");
									inputText = "";
									b3 = true;
									now = 0;
									break;
								}

							}
							if (!b3) {
								t1.setString("Warning : This graph is not exist !\n\n");
								b1 = false;
							}
							else
							{
								b1 = true;
							}
						}
					}
					else if (now == 5) {
						if (text.getString() == "") {
							t1.setString("Warning :  enter the data!\n\n");
							b1 = false;
						}
						else
						{
							if (g.adjlist.find(text.getString()) != g.adjlist.end()) {
								t1.setString("Warning : This city is already exist!");
								b1 = false;
							}
							else
							{
								g.adjlist[text.getString()];
								b1 = true;
								text.setString("");
								inputText = "";
								now = 4;
							}
						}
					}
					else if (now == 11) {
						if (text.getString() == "") {
							t1.setString("Warning :  enter the data!\n\n");
							b1 = false;
						}
						else
						{
							if (g.adjlist.find(text.getString()) == g.adjlist.end()) {
								t1.setString("Warning : This city is not exist ! ");
								b1 = false;
							}
							else
							{
								if (g.adjlist.find(text.getString()) != g.adjlist.end()) {
									g.adjlist.erase(text.getString());
									cout << "Deleted\n\n";
									for (auto it : g.adjlist) {

										for (auto iti : it.second) {
											if (iti.first == text.getString()) {
												g.adjlist[it.first].remove(make_pair(iti.first, iti.second));

											}
										}
									}
								}
								b1 = true;
								text.setString("");
								inputText = "";
								now = 4;
							}
						}
					}
					else if (now == 7) {
						if (text.getString() == "") {
							t1.setString("Warning :  enter the data!\n\n");
							b1 = false;
						}
						else
						{
							if (g.adjlist.find(text.getString()) == g.adjlist.end())
							{
								t1.setString("Warning : This city is not found!");
								b1 = false;
							}
							else
							{
								if (g.isDirected) {
									for (auto it : g.adjlist) {
										g.adjlist2[it.first];
										for (auto iti : it.second) {
											g.adjlist2[it.first].push_back(make_pair(iti.first, iti.second));
											g.adjlist2[iti.first].push_back(make_pair(it.first, iti.second));
										}

									}
								}
								else
								{
									for (auto it : g.adjlist) {
										g.adjlist2[it.first];
										for (auto iti : it.second) {
											g.adjlist2[it.first].push_back(make_pair(iti.first, iti.second));
										}

									}
								}
								queue <string>queue;
								unordered_map<string, bool>visited;
								queue.push(text.getString());
								visited[text.getString()] = true;
								tota += "Following is Breadth First Traversal (starting from  \" " + text.getString() + " \" ) \n";
								while (!queue.empty()) {
									string temp = queue.front();
									queue.pop();
									tota += temp + " \n";
									for (auto it : g.adjlist2[temp])
									{
										if (!visited[it.first])
										{
											queue.push(it.first);
											visited[it.first] = true;
										}
									}
								}
								stack<string> dell;
								for (auto it : g.adjlist2) {
									dell.push(it.first);
								}
								while (!dell.empty())
								{
									g.adjlist2.erase(dell.top());
									dell.pop();
								}
								tbfs.setString(tota);
								b1 = true;
								text.setString("");
								inputText = "";
								now = 10;
							}
						}
					}
					else if (now == 8) {
						if (text.getString() == "") {
							t1.setString("Warning :  enter the data!\n\n");
							b1 = false;
						}
						else
						{
							if (g.adjlist.find(text.getString()) == g.adjlist.end())
							{
								t1.setString("Warning : This city is not found!");
								b1 = false;
							}
							else
							{
								if (g.isDirected) {
									for (auto it : g.adjlist) {
										g.adjlist2[it.first];
										for (auto iti : it.second) {
											g.adjlist2[it.first].push_back(make_pair(iti.first, iti.second));
											g.adjlist2[iti.first].push_back(make_pair(it.first, iti.second));
										}

									}
								}
								else
								{
									for (auto it : g.adjlist) {
										g.adjlist2[it.first];
										for (auto iti : it.second) {
											g.adjlist2[it.first].push_back(make_pair(iti.first, iti.second));
										}

									}
								}
								unordered_map<string, bool>visited;
								stack<string> stack,dell;
								stack.push(text.getString());
								tota += "Following is Depth First Traversal (starting from  \" " + text.getString() + " \" ) \n";
								while (!stack.empty())
								{
									string temp = stack.top();
									stack.pop();

									if (!visited[temp])
									{
										tota += temp + " \n";
										visited[temp] = true;
									}
									for (auto it : g.adjlist2[temp])
									{
										if (!visited[it.first])
										{
											stack.push(it.first);
										}
									}
								}
								for (auto it : g.adjlist2) {
									dell.push(it.first);
								}
								while (!dell.empty())
								{
									g.adjlist2.erase(dell.top());
									dell.pop();
								}
								tdfs.setString(tota);
								b1 = true;
								text.setString("");
								inputText = "";
								now = 9;
							}
						}

					}
					else if (now == 13) {
					if (text.getString() == ""|| text1.getString() == "") {
						t1.setString("Warning :  enter the data!\n\n");
						b1 = false;
					}
					else
					{
						if (g.adjlist.find(text.getString()) == g.adjlist.end()|| g.adjlist.find(text1.getString()) == g.adjlist.end())
						{
							t1.setString("Warning : This city is not found!");
							b1 = false;
						}
						else
						{
							g.dijkstra(g.adjlist, text.getString(), text1.getString());
							tshort.setString(g.tot);
							g.tot = "";
							b1 = true;
							text.setString("");
							inputText = "";
							text1.setString("");
							inputText1 = "";

							now = 15;
						}
					}
					}
					else if (now == 12) {
						if (text.getString() == "" || text1.getString() == "" || text2.getString() == "") {
							t1.setString("Warning :  enter the data!\n\n");
							b1 = false;
						}
						else
						{
							int weigh = stringTointeger(text2.getString());
							if (text.getString() == text1.getString()) {
								t1.setString("You can not enter same source and destination!!\n\n");
								b1 = false;
							}
							else if (g.adjlist.find(text.getString()) == g.adjlist.end() || g.adjlist.find(text1.getString()) == g.adjlist.end())
							{
								t1.setString("Warning : This city is not found!");
								b1 = false;
							}
							else if (weigh <= 0) {
								t1.setString("Warning : You must enter postive value!\n\n");
								b1 = false;
							}
							else
							{
								bool check = true;
								if (!g.isDirected) {
									for (auto it : g.adjlist) {


										for (auto iti : it.second) {

											if ((it.first == text.getString() && iti.first == text1.getString() && iti.second == weigh) ||
												(it.first == text1.getString() && iti.first == text.getString() && iti.second == weigh)) {
												check = false;
												break;
											}
										}
									}
									if (check) {
										g.adjlist[text.getString()].push_back(make_pair(text1.getString(), weigh));
										g.adjlist[text1.getString()].push_back(make_pair(text.getString(), weigh));
										cout << " Added \n\n";
										b1 = true;
										text.setString("");
										inputText = "";
										text1.setString("");
										inputText1 = "";
										text2.setString("");
										inputText2 = "";
										now = 4;
									}
									else {
										t1.setString("This data is already added !! \n\n");
										b1 = false;
									}
								}
								else
								{
									for (auto it : g.adjlist) {


										for (auto iti : it.second) {

											if ((it.first == text.getString() && iti.first == text1.getString() && iti.second == weigh)) {
												check = false;
												break;
											}
										}
									}
									if (check) {
										g.adjlist[text.getString()].push_back(make_pair(text1.getString(), weigh));
										cout << " Added \n\n";
										b1 = true;
										text.setString("");
										inputText = "";
										text1.setString("");
										inputText1 = "";
										text2.setString("");
										inputText2 = "";
										now = 4;
									}
									else {
										t1.setString("This data is already added !! \n\n");
										b1 = false;
									}
								}
							}

						}

					}
					else if (now == 14) {
						if (text.getString() == "" || text1.getString() == "" || text2.getString() == "") {
							t1.setString("Warning :  enter the data!\n\n");
							b1 = false;
						}
						else
						{
							int weigh = stringTointeger(text2.getString());
							if (text.getString() == text1.getString()) {
								t1.setString("You can not enter same source and destination!!\n\n");
								b1 = false;
							}
							else if (g.adjlist.find(text.getString()) == g.adjlist.end() || g.adjlist.find(text1.getString()) == g.adjlist.end())
							{
								t1.setString("Warning : This city is not found!");
								b1 = false;
							}
							else if (weigh <= 0) {
								t1.setString("Warning : You must enter postive value!\n\n");
								b1 = false;
							}
							else
							{
								bool check = false;
								if (!g.isDirected) {
									for (auto it : g.adjlist) {
										for (auto iti : it.second) {

											if ((it.first == text.getString() && iti.first == text1.getString() && iti.second == weigh) ||
												(it.first == text1.getString() && iti.first == text.getString() && iti.second == weigh)) {
												check = true;
												break;
											}
										}


									}
									if (check) {
										g.adjlist[text.getString()].remove(make_pair(text1.getString(), weigh));
										g.adjlist[text1.getString()].remove(make_pair(text.getString(), weigh));
										cout << " Deleted \n\n";
										b1 = true;
										text.setString("");
										inputText = "";
										text1.setString("");
										inputText1 = "";
										text2.setString("");
										inputText2 = "";
										now = 4;
									}
									else
									{
										t1.setString("This edge is not exist to remove ! \n\n");
										b1 = false;
									}
								}
								else
								{
									for (auto it : g.adjlist) {
										for (auto iti : it.second) {

											if ((it.first == text.getString() && iti.first == text1.getString() && iti.second == weigh)) {
												check = true;
												break;
											}
										}


									}
									if (check) {
										g.adjlist[text.getString()].remove(make_pair(text1.getString(), weigh));
										cout << " Deleted \n\n";
										b1 = true;
										text.setString("");
										inputText = "";
										text1.setString("");
										inputText1 = "";
										text2.setString("");
										inputText2 = "";
										now = 4;
									}
									else
									{
										t1.setString("This edge is not exist to remove ! \n\n");
										b1 = false;
									}
								}
							}
						
						}
					}
				}


			}
		if (mousebox.getGlobalBounds().intersects(c1.getGlobalBounds()) && (now == 1 || now == 2 || now == 3)) {
			c1.setFillColor(Color::Color(205, 255, 20));
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				Dir = true;

			}
		}
		else if (mousebox.getGlobalBounds().intersects(c2.getGlobalBounds()) && (now == 1 || now == 2 || now == 3)) {
			c2.setFillColor(Color::Color(205, 255, 20));
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				Dir = false;
	
			}
		}
		if (mousebox.getGlobalBounds().intersects(recbox.getGlobalBounds())) {
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				graphtext = true;
				city2text = false;
				weightext = false;
			}
		}
		if (mousebox.getGlobalBounds().intersects(recbox1.getGlobalBounds())) {
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				graphtext = false;
				city2text = true;
				weightext = false;
				
			}
		}
		if (mousebox.getGlobalBounds().intersects(recbox2.getGlobalBounds())) {
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				graphtext = false;
				city2text = false;
				weightext = true;

			}
		}
		window.clear();
		if (now <= 3) {
			window.draw(background1);
			window.draw(button1);
			window.draw(button2);
			window.draw(button3);
			window.draw(button4);
	

			window.draw(grays);
			if (now != 0) {
				window.draw(recbox);
				window.draw(t2);
			}
			if (now == 2||now==3)
				window.draw(tgraph);
			window.draw(button5);
			window.draw(button6);
			if(now != 0)
			window.draw(text);
			if (now == 1) {
				window.draw(t3);
				window.draw(t4);
				window.draw(c1);
				window.draw(c2);

			}
		}
		if (now >= 4) {
			window.draw(background2);
			window.draw(button7);
			window.draw(button8);
			window.draw(button9);
			window.draw(button10);
			window.draw(button15);
			window.draw(button11);
			window.draw(button12);
			window.draw(button13);
			window.draw(button14);
		
		}
		window.draw(welcome);
		if (now == 5|| now == 7||now==8||now == 11||now==13||now==12|| now == 14) {
			window.draw(grays);
			window.draw(recbox);
			window.draw(text);
			window.draw(button5);
			window.draw(button6);
			if(now == 5||now==11)
			window.draw(t5);
			else if(now == 7 || now == 8)
				window.draw(t6);
		}
		if (now == 9 || now == 10||now == 15) {
			window.draw(grays);
			window.draw(button5);
		}
		if (now == 13||now==12||now==14) {
			window.draw(recbox1);
			window.draw(text1);
			window.draw(t7);
			window.draw(t8);
		}
		if (now == 12|| now == 14) {
			window.draw(recbox2);
			window.draw(text2);
			window.draw(t9);
		}
		if(now==4)
			window.draw(grays);
		if (!b1)
			window.draw(t1);
		if (now == 6) {
			window.draw(grays);
			window.draw(tdis);
			window.draw(button5);

		}
		if(now==10)
			window.draw(tbfs);
		if (now == 9)
			window.draw(tdfs);
		if (now == 15)
			window.draw(tshort);

			//window.draw(mousebox);
			//window.draw(add_Graphbox);
			//window.draw(Load_Graphbox);
			//window.draw(Delete_Graphbox);
			//window.draw(exitbox);
			window.display();
	}
	return 0;
}