#include <stdio.h>
#include <math.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "asteroid.h"
#include "util.h"

void asteroid_init (Asteroid *ast) {
	ast->sx = 320;
	ast->sy = 240;
	ast->heading = 0;
	ast->twist = 0;
	ast->speed = 0;
	ast->rot_velocity = 0;
	ast->scale = 1;
	ast->gone = 0;
	ast->color = al_map_rgb(255, 0, 0);
}

void asteroid_draw_path (Asteroid *ast) {
	al_draw_line (-20, 20, -25, 5, ast->color, 2.0f);
	al_draw_line (-25, 5, -25, -10, ast->color, 2.0f);
	al_draw_line (-25, -10, -5, -10, ast->color, 2.0f);
	al_draw_line (-5, -10, -10, -20, ast->color, 2.0f);
	al_draw_line (-10, -20, 5, -20, ast->color, 2.0f);
	al_draw_line (5, -20, 20, -10, ast->color, 2.0f);
	al_draw_line (20, -10, 20, -5, ast->color, 2.0f);
	al_draw_line (20, -5, 0, 0, ast->color, 2.0f);
	al_draw_line (0, 0, 20, 10, ast->color, 2.0f);
	al_draw_line (20, 10, 10, 20, ast->color, 2.0f);
	al_draw_line (10, 20, 0, 15, ast->color, 2.0f);
	al_draw_line (0, 15, -20, 20, ast->color, 2.0f);
}

void asteroid_transform (Asteroid *ast) {
	ALLEGRO_TRANSFORM transform;
	al_identity_transform (&transform);
	al_rotate_transform (&transform, to_radians (ast->heading));
	al_translate_transform (&transform, ast->sx, ast->sy);
	al_use_transform (&transform);
}

void asteroid_move (Asteroid *ast) {
	// do some movement
}

void asteroid_draw (Asteroid *ast) {
	asteroid_draw_path (ast);
	asteroid_transform (ast);
	asteroid_move (ast);
}
