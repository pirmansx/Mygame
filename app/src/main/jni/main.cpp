#define screenWidth 1560 //1560//2400
#define screenHeight 720 //720//1080

#include <stdio.h>
#include "include/raylib.h"
#include "include/raymath.h"
#include "prx/util.h"
#include "prx/touches.h"
#include "prx/joystick.h"
#include "prx/player.h"
#include "prx/map.h"


int main(){
	InitWindow(screenWidth, screenHeight,"");
	SetTargetFPS(60);
	
	Touch touches[10];
	JoyStick j, *stick = &j;
	JoyStick_init(stick);
	Player p, *player = &p;
	Player_init(player);
	
	map m,*lvl = &m;
	map_int(lvl);
	
	while (!WindowShouldClose()){
		Player_update(player,stick);
		JoyStick_update(stick,touches);
		Touches_update(touches);
		
		
		
		BeginDrawing();
			ClearBackground(BLACK);
			
			map_draw(lvl);
			
			DrawLineEx(player->pos,Vector2Add(player->pos,setMag(stick->output,50)),5,WHITE);
			
			
			Player_draw(player);
			JoyStick_draw(stick);
		EndDrawing();
	}
	CloseWindow();
	map_unload(lvl);
	Player_unload(player);
	return 0;
}
