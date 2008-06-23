/*
 *   $Id: RtAudioDriver.h,v 1.2 2007/01/26 07:39:55 rhizome Exp $
 *
 *      Copyright (C) 2004-2007 Alex Marandon
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

#ifndef RT_AUDIO_DRIVER_H
#define RT_AUDIO_DRIVER_H

#include "AudioDriver.h"

class RtAudio;

class RtAudioDriver : public AudioDriver {
	RtAudio* rtAudio;
public:
	RtAudioDriver(ProcessCallback, const int buffer_n_samples);
	~RtAudioDriver();
	void connectDriver();
	void disconnect();
};

#endif

//EOF
