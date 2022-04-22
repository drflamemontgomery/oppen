#pragma once

#ifdef __cplusplus
extern "C" {
#ifdef REMOVE_EMACS_TABBING
}
#endif
#endif

#include "oppen.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>

OPPENAPI typedef struct oppen_window {
  GLFWwindow* _window;

  unsigned _width, _height;
  const char* _name;

  void (*_render)(void);
} oppen_window_t;

OPPENAPI int oppen_create_window(oppen_window* win, unsigned width, unsigned height, const char* name, GLFWmonitor *monitor, GLFWwindow *share);

OPPENAPI void oppen_set_window_render_func(oppen_window* win, void (*render_func)(void));

OPPENAPI void oppen_window_render(oppen_window* win, GLclampf r, GLclampf g, GLclampf b, GLclampf a, , GLbitfield clearMask);

#ifdef __cplusplus
}
#endif

