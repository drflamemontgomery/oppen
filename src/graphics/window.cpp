#include "graphics/window.h"
#include "oppen_internal.h"
#include <stdio.h>

OPPENAPI int oppen_create_window(oppen_window* win, unsigned width, unsigned height, const char* name, GLFWmonitor *monitor, GLFWwindow *share) {

  if(!oppen_initialized) {
    oppen_init();
  }
  
  win->_window = glfwCreateWindow(width, height, name, monitor, share);
  if(win->_window == NULL) {
    fprintf(stderr, "Failed to open GLFW window.\n");
    return -1;
  }
  
  glfwMakeContextCurrent(win->_window);

  win->_width = width;
  win->_height = height;
  win->_name = name;
  win->_render = NULL;
  return 0;
}

OPPENAPI void oppen_set_window_render_func(oppen_window* win, void (*render_func)(void)) {
  win->_render = render_func;
}

OPPENAPI void oppen_window_render(oppen_window* win, GLclampf r, GLclampf g, GLclampf b, GLclampf a, GLbitfield clearMask) {
  glClearColor(r, g, b, a);
  glClear(clearMask);
  
  if(win->_render != NULL) {
    win->_render();
  }

  glfwSwapBuffers(window);
}
