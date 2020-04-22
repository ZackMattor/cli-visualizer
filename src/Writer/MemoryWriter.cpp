/*
 * MemoryWriter.h
 *
 * Created on: Apr 21, 2020
 *     Author: Zack Mattor
 */

#include <cmath>

#include "Domain/VisConstants.h"
#include "Utils/Logger.h"
#include "Writer/MemoryWriter.h"

#ifdef _LINUX
/* Ncurses version 6.0.20170401 introduced an issue with COLOR_PAIR which broke
 * setting more than 256 color pairs. Specifically it uses an A_COLOR macro
 * which uses a 8 bit mask. This will work for colors since only 256 colors are
 * supported but it breaks color pairs since 2^16 color pairs are supported.
 */
#define VIS_A_COLOR (NCURSES_BITS(((1U) << 16) - 1U, 0))
#define VIS_COLOR_PAIR(n) (NCURSES_BITS((n), 0) & VIS_A_COLOR)
#else
#define VIS_COLOR_PAIR(n) (COLOR_PAIR(n))
#endif

vis::MemoryWriter::MemoryWriter()
{

}

void vis::MemoryWriter::setup_colors(
    bool is_override_terminal_colors,
    const std::vector<ColorDefinition> &colors)
{
}

void vis::MemoryWriter::write(const int32_t row, const int32_t column,
                               const vis::ColorDefinition color,
                               const std::wstring &msg, const wchar_t character)
{
}

void vis::MemoryWriter::clear()
{
}

void vis::MemoryWriter::flush()
{
}

vis::ColorDefinition
vis::MemoryWriter::to_color_pair(int32_t number, int32_t max,
                                  std::vector<ColorDefinition> colors,
                                  bool wrap) const
{
  return vis::ColorDefinition{0, 0, 0, 0};
}

vis::MemoryWriter::~MemoryWriter()
{
}
