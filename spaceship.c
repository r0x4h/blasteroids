#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "spaceship.h"
#include "util.h"

const int MAX_SPEED = 4;
const int TURN_ANGLE = 4;
const float DRAG = 0.02;

void ship_init (Spaceship *ship) {
	ship->sx = 320;
	ship->sy = 240;
	ship->heading = 0;
	ship->speed = 0;
	ship->gone = 0;
	ship->color = al_map_rgb(0, 255, 0);
}

void ship_turn_left (Spaceship *ship) {
	ship->heading -= TURN_ANGLE;

	if (ship->heading == -4)
		ship->heading = 356;
}

void ship_turn_right (Spaceship *ship) {
	ship->heading += TURN_ANGLE;

	if (ship->heading == 360)
		ship->heading = 0;
}

void ship_accelerate (Spaceship *ship) {
	if (ship->speed < MAX_SPEED)
		ship->speed += 0.1;
}

void ship_brake (Spaceship *ship) {
	if (ship->speed > 0)
		ship->speed -= 0.1;
}

void ship_draw_path ( Spaceship *ship) {
	al_draw_line (-11, 8, 8, 0, ship->color, 2.0f);
	al_draw_line (8, 0, -11, -8, ship->color, 2.0f);
	al_draw_line (-11, 8, -11, -8, ship->color, 3.0f);
}

void ship_transform ( Spaceship *ship) {
	ALLEGRO_TRANSFORM transform;
	al_identity_transform (&transform);
	al_rotate_transform (&transform, to_radians (ship->heading));
	al_translate_transform (&transform, ship->sx, ship->sy);
	al_use_transform (&transform);
}

void apply_drag (Spaceship *ship) {
	if (ship->speed > 0)
		ship->speed -= DRAG;
}

void ship_move (Spaceship *ship) {
	if (ship->speed > 0) {
		double heading_rads = to_radians (ship->heading);
		ship->sx += ship->speed * cos(heading_rads);
		ship->sy += ship->speed * sin(heading_rads);
	}
}

void ship_draw (Spaceship *ship) {
	ship_transform (ship);
	ship_draw_path (ship);
	ship_move (ship);
	apply_drag (ship);
}
