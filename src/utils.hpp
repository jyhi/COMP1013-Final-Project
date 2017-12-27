/**
 * @file utils.hpp
 * @version 0.1
 *
 * This file contains userful utilities.
 */

#ifndef _UTILS_HPP
#define _UTILS_HPP

/**
 * Macro STR is used to change something into a string.
 *
 * @see https://stackoverflow.com/questions/25410690/scanf-variable-length-specifier
 */
#undef _STR
#undef STR
#define _STR(s) #s
#define STR(s) _STR(s)

#endif /* end of include guard: _UTILS_HPP */
