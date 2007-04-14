// File_Amr - Info for AMR files
// Copyright (C) 2007-2007 Jerome Martinez, Zen@MediaArea.net
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
//
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//---------------------------------------------------------------------------
// Compilation condition
#include <MediaInfo/Setup.h>
#if defined(MEDIAINFO_AMR_YES)
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#include "MediaInfo/Audio/File_Amr.h"
#include <ZenLib/Utils.h>
using namespace ZenLib;
//---------------------------------------------------------------------------

namespace MediaInfoLib
{

//***************************************************************************
// Format
//***************************************************************************

//---------------------------------------------------------------------------
void File_Amr::Read_Buffer_Continue()
{
    //Integrity
    if (Buffer_Size<=16)
        return;

    //Header
    if (!(CC5(Buffer)==CC5("#!AMR")))
    {
        File_Offset=File_Size;
        return;
    }

    //Filling
    Stream_Prepare(Stream_General);
    Fill("Format", "AMR");

    Stream_Prepare(Stream_Audio);
    Fill("Codec", "AMR");

    //No need of more
    File_Offset=File_Size;
}

//***************************************************************************
// Information
//***************************************************************************

//---------------------------------------------------------------------------
void File_Amr::HowTo(stream_t StreamKind)
{
        if (StreamKind==Stream_General)
    {
        General[0](_T("Format"), Info_HowTo)=_T("R");
    }
    else if (StreamKind==Stream_Audio)
    {
        Audio[0](_T("Codec"), Info_HowTo)=_T("R");
    }
}

} //NameSpace

#endif //MEDIAINFO_AMR_YES

