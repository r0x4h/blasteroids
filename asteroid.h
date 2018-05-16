typedef struct {
	float sx;
	float sy;
	float heading;
	float twist;
	float speed;
	float rot_velocity;
	float scale;
	int gone;
	ALLEGRO_COLOR color;
} Asteroid;

void asteroid_init (Asteroid *ast);
void asteroid_draw (Asteroid *ast);
