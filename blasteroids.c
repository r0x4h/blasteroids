#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "spaceship.h"
#include "asteroid.h"

enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE };

const float FPS = 60;
Spaceship ship;

void error (char *msg) {
   fprintf (stderr, "%s: %s\n", msg, strerror(errno));
   exit (1);
}

void redraw () {
	al_clear_to_color (al_map_rgb(0, 0, 0));
	ship_draw (&ship);
	al_flip_display();
}

int main (int argc, char **argv) {
	bool key[5] = { false, false, false, false, false };

	// init
	if (!al_init()) {
		error ("failed to init allegro");
	}

	if (!al_install_keyboard()) {
	   error ("failed to init keyboard");
	}

	// create display
	ALLEGRO_DISPLAY *display = al_create_display (640, 480);
	if (!display) {
		error ("failed to create display");
	}

	// setup timer
	ALLEGRO_TIMER *timer = al_create_timer (1.0 / FPS);
	if (!timer) {
		error ("failed to create timer");
	}

	// setup event queue
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	if (!event_queue) {
		error ("failed to create event queue");
	}

	// register event sources
	al_register_event_source (event_queue, al_get_display_event_source (display));
	al_register_event_source (event_queue, al_get_timer_event_source (timer));
	al_register_event_source (event_queue, al_get_keyboard_event_source ());

	ship_init (&ship);

	// start timer
	al_start_timer (timer);

	// game loop
	bool needs_redraw = true;
	bool running = true;
	while (running)
	{
		// setup event listener timeout
		ALLEGRO_TIMEOUT timeout;
		al_init_timeout (&timeout, 0.06);

		// process events
		ALLEGRO_EVENT event;
		bool got_event = al_wait_for_event_until (event_queue, &event, &timeout);
		if (!got_event)
			continue;

		if (event.type == ALLEGRO_EVENT_TIMER) {
			if (key[UP]) {
				ship_accelerate (&ship);
			}

			if (key[DOWN]) {
				ship_brake (&ship);
			}
			
			if (key[LEFT]) {
				ship_turn_left (&ship);
			}
			
			if (key[RIGHT]) {
				ship_turn_right (&ship);
			}
			
			if (key[SPACE]) {
				// fire
			}
			
			needs_redraw = true;
		}
		else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			running = false;
		}
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
				switch (event.keyboard.keycode) {
					case ALLEGRO_KEY_UP:
						key[UP] = true;
						break;
					case ALLEGRO_KEY_DOWN:
						key[DOWN] = true;
						break;
					case ALLEGRO_KEY_LEFT:
						key[LEFT] = true;
						break;
					case ALLEGRO_KEY_RIGHT:
						key[RIGHT] = true;
						break;
					case ALLEGRO_KEY_SPACE:
						key[SPACE] = true;
						break;
				}
		}
		else if (event.type == ALLEGRO_EVENT_KEY_UP) {
				switch (event.keyboard.keycode) {
					case ALLEGRO_KEY_UP:
						key[UP] = false;
						break;
					case ALLEGRO_KEY_DOWN:
						key[DOWN] = false;
						break;
					case ALLEGRO_KEY_LEFT:
						key[LEFT] = false;
						break;
					case ALLEGRO_KEY_RIGHT:
						key[RIGHT] = false;
						break;
					case ALLEGRO_KEY_SPACE:
						key[SPACE] = false;
						break;
				}
		}

		// repaint if needed
		if (needs_redraw) {
			redraw ();
			needs_redraw = false;
		}
	}

	// clean up
	al_destroy_timer (timer);
	al_destroy_display (display);
	al_destroy_event_queue (event_queue);

	return 0;
}
