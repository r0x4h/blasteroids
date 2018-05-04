#include <stdio.h>
#include <allegro5/allegro.h>

const float FPS = 60;

void error (char *msg)
{
   fprintf (stderr, "%s: %s\n", msg, strerror(errno));
   exit (1);
}

void draw () {
	// clear background with color
	al_clear_to_color (al_map_rgb(124, 158, 186));
	al_flip_display();
	
	// draw other stuff
}

int main (int argc, char **argv)
{
	// init
	if (!al_init()) {
		error ("failed to init allegro");
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
	
	draw ();
	
	// start timer
	al_start_timer (timer);

	// game loop
	bool redraw = true;
	bool running = true;
	while (running)
	{
		// setup event listener timeout
		ALLEGRO_TIMEOUT timeout;
		al_init_timeout (&timeout, 0.06);
	
		// process events
		ALLEGRO_EVENT event;
		bool got_event = al_wait_for_event_until (event_queue, &event, &timeout);
		if (got_event) {
			switch (event.type) {
				case ALLEGRO_EVENT_TIMER:
					redraw = true;
					break;
				case ALLEGRO_EVENT_DISPLAY_CLOSE:
					running = false;
					break;
				default:
					fprintf (stderr, "unsupported event received: %d\n", event.type);
					break;
			}
		}
		
		// repaint if needed
		if (redraw) {
			draw ();
			redraw = false;
		}
	}
	
	// clean up
	al_destroy_display (display);
	al_destroy_event_queue (event_queue);
	
	return 0;
}
