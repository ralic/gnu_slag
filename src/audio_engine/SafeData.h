/*
 *      Copyright (C) 2004-2008 Alex Marandon
 *
 *  This file is part of slag, a pattern-based audio sequencer.
 *
 *  slag is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  slag is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with slag; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */
// 
// $Id: SafeData.h,v 1.4 2007/01/26 07:39:55 rhizome Exp $
//

#ifndef SAFEDATA_H
#define SAFEDATA_H

#include <qmutex.h>

#include "../common.h"

template <class T>
class SafeData {
    QMutex mutex;
    T value;
public:
    inline SafeData() {}
    inline SafeData(T new_value) {
	mutex.lock();
	value = new_value;
	mutex.unlock();
    }
    inline void setValue(T new_value) {
	mutex.lock();
	value = new_value;
	mutex.unlock();
    }
    inline T getValue() { 
	mutex.lock();
	T retval = value; 
	mutex.unlock();
	return retval;
    }
};

#endif
