typedef struct{
	Vector2 pos;
	Vector2 current_pos;
	Vector2 direction;
	Vector2 output;
	Rectangle area;
	float distance;
	float angle;
	char isactive;
	int size_a;
	int size_b;
	int touchid;
	int ada;
}JoyStick;

void JoyStick_init(JoyStick *stick){
	stick->size_a = 50;
	stick->size_b = 30;
	stick->area = (Rectangle) {0,screenHeight/2,screenWidth/3,screenHeight};
	stick->pos = (Vector2) {stick->area.width/2,stick->area.height-150};
	stick->output = (Vector2) {0,0};
}

void JoyStick_update(JoyStick *stick,Touch touches[]){
	//char buff[16];
	//float angle;
	//sprintf(buff,"id: %d",stick->touchid);
	//DrawText(buff,350,50,20,RED);
	
	
	stick->ada = 0;
	for (int i=0; i<10; i++){
		if (stick->isactive == 0 && touches[i].istap == 1 && CheckCollisionPointRec(touches[i].pos,stick->area)){
  		  stick->current_pos = touches[i].pos;
  		  stick->isactive = 1;
  		  stick->touchid = touches[i].id;
		}
	}
	for (int i=0; i<10; i++){
		if (touches[i].id == stick->touchid){
			stick->ada = 1;
		}
	}
	if (!stick->ada){
		stick->current_pos = stick->pos;
		stick->direction = stick->pos;
		stick->isactive = 0;
		stick->touchid = -2;
		stick->output = (Vector2) {0,0};
	}
	if (stick->isactive){
		stick->direction = touches[stick->touchid].pos;
 	   stick->distance = Vector2Distance(stick->current_pos,stick->direction);
 	   stick->output = Vector2Subtract(stick->direction,stick->current_pos);
 	   stick->angle = atan2f(stick->output.y,stick->output.x);
 	   if (stick->distance > stick->size_a) stick->distance = stick->size_a;
 	   stick->output.x = stick->distance*cosf(stick->angle);
 	   stick->output.y = stick->distance*sinf(stick->angle);
 	   stick->direction = Vector2Add(stick->current_pos,stick->output);
	}
}

void JoyStick_draw(JoyStick *stick){
	DrawCircleV(stick->current_pos,stick->size_a,(Color){255,255,255,50});
	DrawCircleV(stick->direction,stick->size_b,(Color){255,255,255,150});
}
