typedef struct {
	float sx;
	float sy;
	float heading;
	float speed;
	int gone;
	ALLEGRO_COLOR color;
} Asteroid;

void asteroid_init (Asteroid *ast);
void asteroid_draw (Asteroid *ast);
