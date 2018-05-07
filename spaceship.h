typedef struct {
	float sx;
	float sy;
	float heading;
	float speed;
	int gone;
	ALLEGRO_COLOR color;
} Spaceship;

void init_ship (Spaceship *ship);
void draw_ship (Spaceship *ship);
void rotate_left (Spaceship *ship);
void rotate_right (Spaceship *ship);
void speed_up (Spaceship *ship);
void slow_down (Spaceship *ship);
