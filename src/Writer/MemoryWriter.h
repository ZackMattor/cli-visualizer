/*
 * MemoryWriter.h
 *
 * Created on: Apr 21, 2020
 *     Author: Zack Mattor
 */

#ifndef _MEMORY_WRITER_H
#define _MEMORY_WRITER_H

#ifdef NCURSESW
#include <ncursesw/ncurses.h>
#else
#include <ncurses.h>
#endif

#include "Writer/GenericWriter.h"

namespace vis
{

class MemoryWriter : public GenericWriter
{
  public:
    explicit MemoryWriter();

    MemoryWriter(const MemoryWriter &) = delete;

    MemoryWriter(const MemoryWriter &&) = delete;

    MemoryWriter &operator=(const MemoryWriter &) = delete;

    MemoryWriter &operator=(const MemoryWriter &&) = delete;

    ~MemoryWriter() override;

    void write(int32_t row, int32_t column, ColorDefinition color,
                       const std::wstring &msg, wchar_t character);

    void clear();

    /**
     * A scaling function for coloring. For numbers 0 to max this function
     * returns a coloring from the lowest color to the highest. If "wrap" is set
     * to true, colors will not loop from 0 to max. If "wrap" is set to true
     * then colors will wrap.
     */
    ColorDefinition to_color_pair(int32_t number, int32_t max,
                                          std::vector<ColorDefinition> colors,
                                          bool wrap) const;
    /**
     * Initialize color pairs for ncurses
     */
    void setup_colors(bool is_override_terminal_colors,
                      const std::vector<ColorDefinition> &colors);

    void flush();
};
} // namespace vis

#endif
