/****************************************************************\
*                                                                *
* Copyright (C) 2007 by Markus Duft <markus.duft@ssi-schaefer.com>
* Copyright (C) 2019 by Michaek Haubenwallner <michael.haubenwallner@ssi-schaefer.com>
*                                                                *
* This file is part of parity.                                   *
*                                                                *
* parity is free software: you can redistribute it and/or modify *
* it under the terms of the GNU Lesser General Public License as *
* published by the Free Software Foundation, either version 3 of *
* the License, or (at your option) any later version.            *
*                                                                *
* parity is distributed in the hope that it will be useful,      *
* but WITHOUT ANY WARRANTY; without even the implied warranty of *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  *
* GNU Lesser General Public License for more details.            *
*                                                                *
* You should have received a copy of the GNU Lesser General      *
* Public License along with parity. If not,                      *
* see <http://www.gnu.org/licenses/>.                            *
*                                                                *
\****************************************************************/


#ifdef __PCRT_INTERNAL_STDIO_H_NEED_PREAMBLE
#undef __PCRT_INTERNAL_STDIO_H_NEED_PREAMBLE

#define __PCRT_INTERNAL_COREIO_H_NEED_PREAMBLE
#include "pcrt-coreio.h"

#undef  tempnam
#undef _tempnam

#endif // __PCRT_INTERNAL_STDIO_H_NEED_PREAMBLE


#ifdef __PCRT_INTERNAL_STDIO_H_NEED_POSTAMBLE
#undef __PCRT_INTERNAL_STDIO_H_NEED_POSTAMBLE


#define __PCRT_INTERNAL_COREIO_H_NEED_POSTAMBLE
#include "pcrt-coreio.h"


#ifndef __PCRT_INTERNAL_STDIO_H_IMPL
#define __PCRT_INTERNAL_STDIO_H_IMPL
//
// redefine io.h functions which work with files to be able
// of parsing non-native paths.
//
PCRT_BEGIN_C

static PCRT_INLINE char * pcrt_tempnam(const char* dir, const char *prefix)
{
  return _tempnam(PCRT_CONV(dir), prefix);
}

PCRT_END_C

#endif // __PCRT_INTERNAL_STDIO_H_IMPL


#define  tempnam pcrt_tempnam
#define _tempnam pcrt_tempnam

#endif // __PCRT_INTERNAL_STDIO_H_NEED_POSTAMBLE