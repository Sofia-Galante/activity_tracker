//
// Created by Sofia Galante on 30/06/19.
//

#ifndef ACTIVITYTRACKER_COLORSANDFONTS_H
#define ACTIVITYTRACKER_COLORSANDFONTS_H

#include <wx/wx.h>
#include <wx/colour.h>
#include <wx/font.h>

struct Colors {

    wxColour *lightestYellow = new wxColour(255, 255, 204);
    wxColour *lightYellow = new wxColour(255, 255, 153);

};

struct Fonts{
    wxFont * title = new wxFont(wxFontInfo().Bold());
};
#endif //ACTIVITYTRACKER_COLORSANDFONTS_H
