float getMag(Vector2 v){
	float mag = sqrt(v.x*v.x+v.y*v.y);
	return mag;
}

Vector2 setMag(Vector2 v,float m){
	float mag = getMag(v);
	v = Vector2Scale(v,m/mag);
	return v;
}

Vector2 setLimit(Vector2 v,float l){
	float mag = getMag(v);
	if(mag > l) mag = l;
	v = Vector2Scale(v,mag);
	return v;
}