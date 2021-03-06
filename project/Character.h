// Christopher Syers, Mason Prosser, Lucas Unruh, and Time Chagn
// Fundametals of computing II Final Project	April 1, 2015

// Character.h
// Interface of the Character class. Derives from GamePiece, and so has inherentented a xpos and ypos. 
// This is the parent class of a variety of characters in the game, including Hero, Archer... etc.
// Has functionality to draw to a renderer, and check a map for valid move locaions. Has data of 
// character stats.

#ifndef CHARACTER_H
#define CHARACTER_H
#include<string>
//#include<SDL2/SDL.h>
//#include<SDL2/SDL_image.h>
//#include<SDL.h>
//#include<SDL_image.h>
#include "GamePiece.h"
#include "Valid_board.h"
#include <vector>
using namespace std;
class Character: public GamePiece {
	public:
		Character();						// default constructor
		Character(string, string, int, int, SDL_Renderer*,vector<vector <int> >);	// non-default constructor
		~Character();						// deconstructor
		void draw(SDL_Renderer*);			// draw function
		void change_direction(int);			// changes the direction of the sprite. 0 up, 1 right... 3 left
		int get_phase();					// returns the current phase of the sprite
		void next_phase();					// changes the phase of the sprite
		void check_valid_move(int, int, int, vector<Character *> *);	// modifies a vector of vectors to contain valid move
		void update();
		int getCurrentHitpoints();			// returns character's hitpoints
		void setCurrentHitpoints(int);			// set character's hitpoints
		int getMaxHitpoints();				// returns the character's max hitpoints
		string getName();				// returns character's name
		int getAttack();				// returns character's attack
		int getDefence();				// returns character's defence
		int getMobility();				// gets the character's movement
		int getPlayer();				// returns the character's team
		int get_terrain_effect(int);		// returns the mobility required to move on a certain tile
		void select();						// changes value of selected data member
		void unselect();					// changes selected to 0
	        int get_select();				// returns if the character is selected
		void move(int,int,int);				// moves the character
		void process_move_vector(int,int);	// moves a series of steps as per the vector passed in
	        void add_move(int);                 // pushes a value into the moves vector
       		void clear_move();                  // clears the move vector
       		int size_move();                    // return moves size
	        int get_tile(int,int);           //returns the vb value at specified location
	        int get_vb_width();              //gets vb width
       		int get_vb_height();             //gets vb height
		void setMove();			// changes canMove to 1
		void takeMove();		// changes canMove to 0
                int getMove();			// return a 1 or 0 that corresponds to the variable canMove:
                int isAlive();			// tells if the character's health is 0
 		int getAttacking();             //returns attacking flag
       		void setAttacking(int);         //sets attacking flag
       		void attack_phase(vector<Character *> *, Character *);  //handles attacking phase.a
		string getClass();
	protected:
		int player;						// 1 or 2 depending on the player
		int direction;						// direction the sprite is facing
		int phase;                      			// what foot the sprite is on
		SDL_Texture* character_texture;				// the image .png file of the sprite sheet
		int attack;                        			// attack stat
		int defence;						// defence stat
		int current_hitpoints;					// curent HP
                int max_hitpoints;					// maximum hitpoints
		int mobility;						// max tiles the Character can move
		vector<int> terrain_effect;				// effect each terrain has on mobility
		int attack_range;					// range of attack
		int counter;						// variable to count clock cycles
		int alive;              			        // if the character has any hitpoints left
		int selected;						// if the character has been selected
		Valid_board vb;						// a 2d array of possible move places and attack spaces
		vector<vector <int> > tile_properties;  		// an array of tile properties
       		vector<int> moves;               	   		// stores moves.
		string name;						// holds the name of the Character	
		int canMove;						// indicates if a character can move (0 if the have already taken a turn)
		string class_name;		// string to hold the Character's class
        int attacking;                      //indicates if character is attacking.
};
#endif
