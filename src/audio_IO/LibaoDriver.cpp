/*
 *   $Id: LibaoDriver.cpp,v 1.13 2007/01/26 07:39:55 rhizome Exp $
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

#include "LibaoDriver.h"
#include "WavFileOutput.h"

LibaoDriver::LibaoDriver(ProcessCallback processCallback, const int buffer_n_samples) 
  : AudioDriver(processCallback, buffer_n_samples),
    audio_buffer(new sample_t[buffer_n_samples]),
    active(false)
{ }

LibaoDriver::~LibaoDriver() {
    delete[] audio_buffer;
}

void LibaoDriver::run() {
    while (active) {
        audioProcessCallback(audio_buffer);
        recording_mutex.lock();
        if(recording()) {
            file_output->write(audio_buffer, buffer_n_samples);
        }
        recording_mutex.unlock();
        ao_wrapper.play(audio_buffer, buffer_n_samples / 2);
    }
}

void LibaoDriver::connectDriver() {
    active = true;
    start(QThread::TimeCriticalPriority);
}

void LibaoDriver::disconnect() {
    active = false;
    wait();
}


//EOF