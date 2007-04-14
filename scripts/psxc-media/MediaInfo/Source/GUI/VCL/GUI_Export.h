//---------------------------------------------------------------------------

#ifndef GUI_ExportH
#define GUI_ExportH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <TntComCtrls.hpp>
#include <TntStdCtrls.hpp>
#include <Dialogs.hpp>
#include "TntDialogs.hpp"
#ifdef MEDIAINFO_DLL
    #include "MediaInfoDLL/MediaInfoDLL_Static.h"
#else
    #include "MediaInfo/MediaInfoList.h"
#endif
#include <ZenLib/Ztring.h>
//---------------------------------------------------------------------------
class TExportF : public TForm
{
__published:    // IDE-managed Components
    TTntButton *Cancel;
    TTntButton *OK;
    TGroupBox *Export_Choose;
    TTntPageControl *Export;
    TTntTabSheet *Export_CSV;
    TTntTabSheet *Export_Text;
    TTntTabSheet *Export_HTML;
    TTntTabSheet *Export_Custom;
    TTntGroupBox *Name_Choose;
    TTntEdit *Name;
    TTntButton *Name_FileSelect;
    TTntLabel *CSV_Stream_Video_Caption;
    TTntComboBox *CSV_Stream_Video;
    TTntLabel *CSV_Stream_Audio_Caption;
    TTntComboBox *CSV_Stream_Audio;
    TTntLabel *CSV_Stream_Text_Caption;
    TTntComboBox *CSV_Stream_Text;
    TTntLabel *CSV_Stream_Chapters_Caption;
    TTntComboBox *CSV_Stream_Chapters;
    TTntLabel *CSV_Stream_Video_Warning;
    TTntLabel *CSV_Stream_Audio_Warning;
    TTntLabel *CSV_Stream_Text_Warning;
    TTntLabel *CSV_Stream_Chapters_Warning;
    TTntCheckBox *Text_Advanced;
    TTntCheckBox *HTML_Advanced;
    TTntLabel *CSV_Quote_Caption;
    TTntLabel *CSV_Separator_Col_Caption;
    TTntComboBox *CSV_Quote;
    TTntComboBox *CSV_Separator_Col;
    TTntLabel *CSV_Separator_Line_Caption;
    TTntComboBox *CSV_Separator_Line;
    TTntCheckBox *CSV_Advanced;
    TTntCheckBox *Custom_One;
    TTntTabSheet *Export_Sheet;
    TTntLabel *Sheet_Quote_Caption;
    TTntComboBox *Sheet_Quote;
    TTntLabel *Sheet_Separator_Col_Caption;
    TTntComboBox *Sheet_Separator_Col;
    TTntLabel *Sheet_Separator_Line_Caption;
    TTntComboBox *Sheet_Separator_Line;
    TTntCheckBox *File_Append;
    TTntLabel *CSV_Decimal_Caption;
    TTntComboBox *CSV_Decimal;
    TTntSaveDialog *SaveDialog1;
    void __fastcall Name_FileSelectClick(TObject *Sender);
    void __fastcall ExportChange(TObject *Sender);
    void __fastcall OKClick(TObject *Sender);
    void __fastcall CSV_Stream_VideoChange(TObject *Sender);
    void __fastcall CSV_Stream_AudioChange(TObject *Sender);
    void __fastcall CSV_Stream_TextChange(TObject *Sender);
    void __fastcall CSV_Stream_ChaptersChange(TObject *Sender);
private:    // User declarations
    void Name_Adapt();
    void Export_Run();
    void CSV_Stream_Change (TTntComboBox* Box, TTntLabel* Label, MediaInfoLib::stream_t Stream);
    void GUI_Configure();
    MediaInfoLib::MediaInfoList *ToExport;
public:        // User declarations
    __fastcall TExportF(TComponent* Owner);
    int Run(MediaInfoLib::MediaInfoList &MI, ZenLib::Ztring DefaultFolder);
};
//---------------------------------------------------------------------------
extern PACKAGE TExportF *ExportF;
//---------------------------------------------------------------------------
#endif
