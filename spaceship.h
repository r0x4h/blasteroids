typedef struct {
	float sx;
	float sy;
	float heading;
	float speed;
	int gone;
	ALLEGRO_COLOR color;
} Spaceship;

void ship_init (Spaceship *ship);
void ship_draw (Spaceship *ship);
void ship_turn_left (Spaceship *ship);
void ship_turn_right (Spaceship *ship);
void ship_accelerate (Spaceship *ship);
void ship_brake (Spaceship *ship);
