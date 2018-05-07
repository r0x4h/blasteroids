#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "spaceship.h"

void init_ship (Spaceship *ship) {
	ship->sx = 100;
	ship->sy = 100;
	ship->heading = 0;
	ship->speed = 0;
	ship->gone = 0;
	ship->color = al_map_rgb(0, 255, 0);
}

void draw_ship (Spaceship *ship) {
	ALLEGRO_TRANSFORM transform;
	al_identity_transform (&transform);
	al_rotate_transform (&transform, ship->heading);
	al_translate_transform (&transform, ship->sx, ship->sy);
	al_use_transform (&transform);

	al_draw_line (-8, 9, 0, -11, ship->color, 3.0f);
	al_draw_line (0, -11, 8, 9, ship->color, 3.0f);
	al_draw_line (-6, 4, -1, 4, ship->color, 3.0f);
	al_draw_line (6, 4, 1, 4, ship->color, 3.0f);
}

void rotate_left (Spaceship *ship) {
	ship->heading -= 0.1;
}

void rotate_right (Spaceship *ship) {
	ship->heading += 0.1;
}

void speed_up (Spaceship *ship) {
	ship->speed++;
}

void slow_down (Spaceship *ship) {
	if (ship->speed > 0) {
		ship->speed--;
	}
}
