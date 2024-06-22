typedef struct map{
	Vector2 pos;
	Texture2D tile[8];
	//Texture2D tile_1;
}map;

char level2[] = {
	0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,
	0,0,5,5,0,0,0,0,0,0,
	0,1,0,6,6,0,0,0,0,0,
	0,0,2,0,6,6,0,0,0,0,
	0,0,0,2,0,6,6,0,0,0,
	0,0,0,0,2,0,6,6,0,0,
	0,0,0,0,0,2,0,7,7,0,
	0,0,0,0,0,0,3,4,4,0,
	0,0,0,0,0,0,0,4,4,0
	};
	
void map_int(map *m){
	//m->tile[0] = LoadTexture("up0.png");
	m->tile[1] = LoadTexture("up1.png");
	m->tile[2] = LoadTexture("up2.png");
	m->tile[3] = LoadTexture("up3.png");
	m->tile[4] = LoadTexture("tile_1.png");
	m->tile[5] = LoadTexture("xup1.png");
	m->tile[6] = LoadTexture("xup2.png");
	m->tile[7] = LoadTexture("xup3.png");
	m->pos = (Vector2){700,0};
}

void map_draw(map *m){
	for(int row=0; row < 10; row++){
		for(int col=0; col < 10; col++){
			int tx = ((row-col)*30)+m->pos.x;
			int ty = ((row+col)*15)+m->pos.y;
			int in = (col*10)+row;
			if(level2[in] != 0){
				DrawTexture(m->tile[level2[in]],tx,ty,WHITE);
			}
		}
	}
}

void map_unload(map *m){
	UnloadTexture(m->tile[0]);
	UnloadTexture(m->tile[1]);
	UnloadTexture(m->tile[2]);
	UnloadTexture(m->tile[3]);
	UnloadTexture(m->tile[4]);
	UnloadTexture(m->tile[5]);
	UnloadTexture(m->tile[6]);
	UnloadTexture(m->tile[7]);
}