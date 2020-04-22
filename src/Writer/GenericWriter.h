/*
 * GenericWriter.h
 *
 * Created on: Apr 21, 2020
 *     Author: Zack Mattor
 */

#ifndef _VIS_GENERIC_WRITER_H
#define _VIS_GENERIC_WRITER_H

#include "Domain/ColorDefinition.h"

namespace vis
{

class GenericWriter
{
  public:
    GenericWriter();

    GenericWriter(const GenericWriter &) = delete;

    GenericWriter(const GenericWriter &&) = delete;

    GenericWriter &operator=(const GenericWriter &) = delete;

    GenericWriter &operator=(const GenericWriter &&) = delete;

    virtual ~GenericWriter() = default;

    virtual void write(int32_t row, int32_t column, ColorDefinition color,
                       const std::wstring &msg, wchar_t character);

    virtual void clear();

    /**
     * A scaling function for coloring. For numbers 0 to max this function
     * returns a coloring from the lowest color to the highest. If "wrap" is set
     * to true, colors will not loop from 0 to max. If "wrap" is set to true
     * then colors will wrap.
     */
    virtual ColorDefinition to_color_pair(int32_t number, int32_t max,
                                          std::vector<ColorDefinition> colors,
                                          bool wrap) const;
    /**
     * Initialize color pairs for ncurses
     */
    virtual void setup_colors(bool is_override_terminal_colors,
                      const std::vector<ColorDefinition> &colors);

    virtual void flush();
};
} // namespace vis

#endif
