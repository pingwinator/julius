#include "vita.h"

#include "core/file.h"
#include "game/system.h"
#include "graphics/screen.h"
#include "input/mouse.h"
#include "input/touch.h"

#include <vita2d.h>
#include <vitasdk.h>

#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "SDL.h"

#define PREPEND_PATH_OFFSET 17

static char prepended_path[2 * FILE_NAME_MAX * sizeof(char)];

// max heap size is approx. 330 MB with -d ATTRIBUTE2=12, otherwise max is 192
int _newlib_heap_size_user = 300 * 1024 * 1024;

static void center_mouse_cursor(void)
{
    int x = screen_width() / 2;
    int y = screen_height() / 2;
    system_set_mouse_position(&x, &y);
    mouse_set_position(x, y);
}

void platform_init_callback(void)
{
    touch_set_mode(TOUCH_MODE_TOUCHPAD);
    center_mouse_cursor();
}

int chdir(const char *path)
{
    return 0;
}

const char *vita_prepend_path(const char *path)
{
    if (!prepended_path[0]) {
        memcpy(prepended_path, VITA_PATH_PREFIX, strlen(VITA_PATH_PREFIX));
    }
    strncpy(prepended_path + PREPEND_PATH_OFFSET, path, 2 * FILE_NAME_MAX * sizeof(char) - PREPEND_PATH_OFFSET - 1);
    return prepended_path;
}
