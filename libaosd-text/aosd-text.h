/* aosd -- OSD with transparency, cairo, and pango.
 *
 * Copyright (C) 2007,2010 Eugene Paskevich <eugene@raptor.kiev.ua>
 */

#ifndef __AOSD_TEXT_H__
#define __AOSD_TEXT_H__

#include <aosd.h>

#include "pango/pangocairo.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Tiny Pango API augmentation
// Way more convenient for aosd.
PangoLayout* pango_layout_new_aosd(void);
void pango_layout_unref_aosd(PangoLayout* lay);

void pango_layout_get_size_aosd(PangoLayout* lay,
    unsigned* width, unsigned* height, int* lbearing);

// Converts all \n occurrences into U+2028 symbol
void pango_layout_set_text_aosd(PangoLayout* lay, const char* text);
void pango_layout_set_attr_aosd(PangoLayout* lay, PangoAttribute* attr);
void pango_layout_set_font_aosd(PangoLayout* lay, const char* font_desc);

typedef struct
{
  PangoLayout* lay;

  int lbearing;

  struct
  {
    guint8 x_offset;
    guint8 y_offset;
  } geom;

  struct
  {
    const char* color;
    guint8 opacity;
  } back;

  struct
  {
    const char* color;
    guint8 opacity;
    gint8 x_offset;
    gint8 y_offset;
  } shadow;

  struct
  {
    const char* color;
    guint8 opacity;
  } fore;
} TextRenderData;

void aosd_text_renderer(cairo_t* cr, void* TextRenderData_ptr);
void aosd_text_get_size(TextRenderData* trd, unsigned* width, unsigned* height);
int aosd_text_get_screen_wrap_width(Aosd* aosd, TextRenderData* trd);
int aosd_text_get_screen_wrap_width_xinerama(Aosd* aosd, int output, TextRenderData* trd);

#ifdef __cplusplus
}
#endif

#endif /* __AOSD_TEXT_H__ */

/* vim: set ts=2 sw=2 et : */
