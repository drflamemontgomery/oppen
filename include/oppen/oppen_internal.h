#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "oppen.h"
#include <stdbool.h>
  OPPENAPI extern bool oppen_initialized;

  OPPENAPI int oppen_init(void);
  
#ifdef __cplusplus
}
#endif
