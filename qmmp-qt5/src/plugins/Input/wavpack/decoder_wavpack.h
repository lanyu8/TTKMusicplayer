/***************************************************************************
 *   Copyright (C) 2008-2019 by Ilya Kotov                                 *
 *   forkotov02@ya.ru                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#ifndef DECODER_WAVPACK_H
#define DECODER_WAVPACK_H

extern "C"{
#include <wavpack/wavpack.h>
}
#include <qmmp/decoder.h>

class CUEParser;

class DecoderWavPack : public Decoder
{
public:
    DecoderWavPack(const QString &);
    virtual ~DecoderWavPack();

    // Standard Decoder API
    virtual bool initialize() override;
    virtual qint64 totalTime() const override;
    virtual int bitrate() const override;
    virtual qint64 read(unsigned char *data, qint64 maxSize) override;
    virtual void seek(qint64 time) override;
    virtual const QString nextURL() const override;
    virtual void next() override;

private:
    // helper functions
    void deinit();
    qint64 wavpack_decode(unsigned char *data, qint64 size);
    ChannelMap findChannelMap(int channels);
    WavpackContext *m_context;
    int32_t *m_output_buf; // output buffer
    int m_chan;
    qint64 m_totalTime;
    qint64 m_length_in_bytes;
    qint64 m_totalBytes;
    qint64 m_offset;
    qint64 m_length;
    QString m_path;
    CUEParser *m_parser;
    int m_track;
    int m_bps;
    qint64 m_frame_size; //frame size
};

#endif // DECODER_WAVPACK_H
