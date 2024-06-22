typedef struct{
	int id;
	int intouch;
	size_t istap;
	Vector2 pos;
}Touch;

void Touches_update(Touch touches[]){
	int i;
	int id;
	for (i=0; i<10; i++){
		touches[i].id = -1;
		touches[i].intouch = 0;
		touches[i].pos = (Vector2) {0,0};
	}
	for (i=0; i<GetTouchPointCount(); i++){
		id = GetTouchPointId(i);
		touches[id].id = id;
		touches[id].pos = GetTouchPosition(i);
		touches[id].intouch = 1;
		touches[id].istap += 1;
	}
	for (i=0; i<10; i++){
		if (touches[i].intouch == 0){
			touches[i].istap = 0;
		}
	}
}