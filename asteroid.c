#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "asteroid.h"
#include "util.h"

void asteroid_init (Asteroid *ast) {

}

void asteroid_transform (Asteroid *ast) {
	ALLEGRO_TRANSFORM transform;
	al_identity_transform (&transform);
	al_rotate_transform (&transform, to_radians (ast->heading));
	al_translate_transform (&transform, ast->sx, ast->sy);
	al_use_transform (&transform);
}

void asteroid_move (Asteroid *ast) {

}

void asteroid_draw (Asteroid *ast) {
	//draw (ast);
	asteroid_transform (ast);
	asteroid_move (ast);
}
