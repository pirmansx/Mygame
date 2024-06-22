typedef struct{
	Texture2D kanan;
	Texture2D kiri;
	Texture2D atas;
	Texture2D bawah;
	Texture2D serong_atas_kanan;
	Texture2D serong_atas_kiri;
	Texture2D serong_bawah_kanan;
	Texture2D serong_bawah_kiri;
	Vector2 pos;
	float frame;
	Image image_buff;
	char arah;
	float speed;
	Vector2 acc;
	Vector2 vel;
	float angle;
}Player;

void Player_init(Player *player){
	player->kanan = LoadTexture("kanan.png");
	player->bawah = LoadTexture("bawah.png");
	player->atas = LoadTexture("atas.png");
	player->image_buff = LoadImageFromTexture(player->kanan);
	ImageFlipHorizontal(&player->image_buff);
	player->kiri = LoadTextureFromImage(player->image_buff);
	player->serong_atas_kanan = LoadTexture("serong_atas.png");
	player->image_buff = LoadImageFromTexture(player->serong_atas_kanan);
	ImageFlipHorizontal(&player->image_buff);
	player->serong_atas_kiri = LoadTextureFromImage(player->image_buff);
	player->serong_bawah_kanan = LoadTexture("serong_bawah.png");
	player->image_buff = LoadImageFromTexture(player->serong_bawah_kanan);
	ImageFlipHorizontal(&player->image_buff);
	player->serong_bawah_kiri = LoadTextureFromImage(player->image_buff);
	player->pos = (Vector2){0,0};
	player->acc = (Vector2){0,0};
	player->vel = (Vector2){0,0};
	player->frame = 0;
	player->arah = 0;
	UnloadImage(player->image_buff);
	//sleep(10);
}
void Player_update(Player *player,JoyStick *stick){
	player->acc = Vector2Add(player->acc,setLimit(stick->output,0.002));

	player->vel = Vector2Add(player->vel,player->acc);
	player->vel = Vector2Scale(player->vel,0.95);
	player->pos = Vector2Add(player->pos,player->vel);
	player->speed = getMag(player->vel)/5;
	player->acc = (Vector2){0,0};
	
	if (stick->angle < 0){
		player->angle = Remap(stick->angle,-PI,0,PI,6);
	}else{
		player->angle = stick->angle;
	}
	if (player->angle > 5.7 || player->angle < 0.2) player->arah = 0;
	if (player->angle > 0.2 && player->angle < 1.2) player->arah = 1;
	if (player->angle > 1.2 && player->angle < 1.9) player->arah = 2;
	if (player->angle > 1.9 && player->angle < 2.9) player->arah = 3;
	if (player->angle > 2.9 && player->angle < 3.4) player->arah = 4;
	if (player->angle > 3.4 && player->angle < 4.2) player->arah = 5;
	if (player->angle > 4.2 && player->angle < 4.8) player->arah = 6;
	if (player->angle > 4.8 && player->angle < 5.7) player->arah = 7;
}

void Player_draw(Player *player){
	//char buff[16];
	//float angle;
	//sprintf(buff,"x : %f",player->vel.x);
	//DrawText(buff,350,50,20,RED);
	//sprintf(buff,"y : %f",player->vel.y);
	//DrawText(buff,350,70,20,RED);
    
    float fr;
    
	switch (player->arah){
		case 0:
            fr = (float)((int)player->frame%16);
			DrawTextureRec(
                player->kanan,
                (Rectangle){46*fr,0,46,54},
			    player->pos,WHITE);
           	player->frame += player->speed;
			break;
		case 1:
            fr = (float)((int)player->frame%16);
			DrawTextureRec(player->serong_bawah_kanan,(Rectangle){52 * fr,0,52,62},
			player->pos,WHITE);
			player->frame += player->speed;
			break;
		case 2:
            fr = (float)((int)player->frame%16);
			DrawTextureRec(player->bawah,(Rectangle){36 * fr,0,36,62},
			player->pos,WHITE);
			player->frame += player->speed;
			break;
		case 3:
            fr = (float)((int)player->frame%16);
			DrawTextureRec(player->serong_bawah_kiri,(Rectangle){52 * fr,0,52,62},
			player->pos,WHITE);
			player->frame -= player->speed;
			break;
		case 4:
            fr = (float)((int)player->frame%16);
			DrawTextureRec(
                player->kiri,
                (Rectangle){46 *fr,0,46,54},
			    player->pos,WHITE);
			player->frame -= player->speed;
			break;
		case 5:
            fr = (float)((int)player->frame%16);
			DrawTextureRec(
                player->serong_atas_kiri,
                (Rectangle){42 * fr,0,42,62},
			    player->pos,WHITE);
			player->frame -= player->speed;
			break;
		case 6:
            fr = (float)((int)player->frame%16);
			DrawTextureRec(
                player->atas,
                (Rectangle){36 * fr,0,36,66},
			    player->pos,WHITE);
			player->frame += player->speed;
			break;
		case 7:
            fr = (float)((int)player->frame%16);
			DrawTextureRec(    
                player->serong_atas_kanan,
                (Rectangle){42 * fr,0,42,62},
			    player->pos,
                WHITE);
			player->frame += player->speed;
			break;
	}
	DrawCircleV(player->pos,3,BLUE);
}

void Player_unload(Player *p){
	UnloadTexture(p->kanan);
	UnloadTexture(p->kiri);
	UnloadTexture(p->atas);
	UnloadTexture(p->bawah);
	UnloadTexture(p->serong_atas_kanan);
	UnloadTexture(p->serong_atas_kiri);
	UnloadTexture(p->serong_bawah_kanan);
	UnloadTexture(p->serong_bawah_kiri);
}
