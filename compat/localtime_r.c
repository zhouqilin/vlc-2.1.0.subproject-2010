/*****************************************************************************
 * localtime_r.c: POSIX localtime_r() replacement
 *****************************************************************************
 * Copyright © 1998-2008 VLC authors and VideoLAN
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include "stdafx.h"

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <time.h>

/* If localtime_r() is not provided, we assume localtime() uses
 * thread-specific storage. */
struct tm *localtime_r (const time_t *timep, struct tm *result)
{
    struct tm *s = localtime (timep);
    if (s == NULL)
        return NULL;

    *result = *s;
    return result;
}
