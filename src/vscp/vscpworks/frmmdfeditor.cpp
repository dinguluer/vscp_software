/////////////////////////////////////////////////////////////////////////////
// Name:        frmmdfeditor.cpp
// Purpose:     
// Author:      Ake Hedman
// Modified by: 
// Created:     09/04/2009 11:05:11
// RCS-ID:      
// Copyright:   (C) 2009-2014 
// Ake Hedman, Grodans Paradis AB, <akhe@grodansparadis.com>
// Licence:     
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version
// 2 of the License, or (at your option) any later version.
// 
// This file is part of the VSCP (http://can.sourceforge.net) 
// 
// This file is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this file see the file COPYING.  If not, write to
// the Free Software Foundation, 59 Temple Place - Suite 330,
//  Boston, MA 02111-1307, USA.
// 
//  As a special exception, if other files instantiate templates or use macros
//  or inline functions from this file, or you compile this file and link it
//  with other works to produce a work based on this file, this file does not
//  by itself cause the resulting work to be covered by the GNU General Public
//  License. However the source code for this file must still be made available
//  in accordance with section (3) of the GNU General Public License.
// 
//  This exception does not invalidate any other reasons why a work based on
//  this file might be covered by the GNU General Public License.
// 
//  Alternative licenses for VSCP & Friends may be arranged by contacting 
//  Grodans Paradis AB at info@grodansparadis.com, http://www.grodansparadis.com
/////////////////////////////////////////////////////////////////////////////

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
#pragma implementation "frmmdfeditor.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"
#endif

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
#include "wx/imaglist.h"
////@end includes

#include <wx/stdpaths.h>
#include "frmmdfeditor.h"

////@begin XPM images
/* XPM */
static char *deffile_xpm[] = {
/* columns rows colors chars-per-pixel */
"16 16 32 1",
"= c #97C4E7",
": c #72A8D2",
"1 c #FFFFFF",
"w c #839CB5",
"X c #6B98B8",
". c #5A89A6",
"@ c #3A749C",
", c #D1E5F5",
"< c #67A1CF",
"> c #F1F4F7",
"e c #85A7BC",
"% c #C3DDF1",
"0 c #749BB4",
"2 c #7EA6C0",
"; c #5F9BC8",
"  c None",
"O c #538DB3",
"- c #85BBE2",
"$ c #D6DFE7",
"9 c #EFF6FC",
"o c #6591AE",
"4 c #F7FBFD",
"8 c #FAFCFE",
"6 c #DAEAF7",
"7 c #E9F3FA",
"q c #FDFDFE",
"3 c #E2EFF8",
"# c #8EA9BC",
"& c #B6D5EE",
"* c #A5CCEA",
"5 c #F4F9FD",
"+ c #4581AA",
/* pixels */
"  ..XooO+@#$    ",
"  .%%&*=-;:;>   ",
"  .,,%&*=<1=X>  ",
"  #%%%%&*211=X  ",
"  #3-----<oXoO  ",
"  #3456,%&*=-O  ",
"  #3--------=O  ",
"  #355736,%&*o  ",
"  #3--------&o  ",
"  #38459736,%X  ",
"  #3--------,0  ",
"  #31q84597360  ",
"  #3--------3w  ",
"  #3111q84597e  ",
"  ##########e#  ",
"                "
};

/* XPM */
static char *open_xpm[] = {
/* columns rows colors chars-per-pixel */
"16 15 5 1",
"  c None",
". c Black",
"X c Yellow",
"o c Gray100",
"O c #bfbf00",
/* pixels */
"                ",
"          ...   ",
"         .   . .",
"              ..",
"  ...        ...",
" .XoX.......    ",
" .oXoXoXoXo.    ",
" .XoXoXoXoX.    ",
" .oXoX..........",
" .XoX.OOOOOOOOO.",
" .oo.OOOOOOOOO. ",
" .X.OOOOOOOOO.  ",
" ..OOOOOOOOO.   ",
" ...........    ",
"                "
};

/* XPM */
static char *save_xpm[] = {
/* columns rows colors chars-per-pixel */
"16 15 4 1",
"  c None",
". c Black",
"X c #808000",
"o c #808080",
/* pixels */
"                ",
" .............. ",
" .X.        . . ",
" .X.        ... ",
" .X.        .X. ",
" .X.        .X. ",
" .X.        .X. ",
" .X.        .X. ",
" .XX........oX. ",
" .XXXXXXXXXXXX. ",
" .XX.........X. ",
" .XX......  .X. ",
" .XX......  .X. ",
" .XX......  .X. ",
"  ............. "
};

/* XPM */
static char *filesaveas_xpm[] = {
/* columns rows colors chars-per-pixel */
"16 15 23 1",
"X c Black",
"+ c #FFFFFF",
"< c #D5D6D8",
"> c #446A8C",
"3 c #CAD2DC",
", c #C0C7D1",
"  c #5F666D",
"* c #A5B0BA",
"O c #65839D",
"1 c #DCE2EA",
"2 c #C3C5C8",
": c #E1E6EE",
". c #FFFF00",
"- c #C6CCD3",
"@ c None",
"& c #305F81",
"4 c #D6DFE7",
"; c #D2D9E0",
"= c #B7BFC7",
"o c #1B4467",
"$ c #BCBDBE",
"# c #7A90AC",
"% c #5D7C93",
/* pixels */
"         .X .XX.",
" oO+++++++.X.X.@",
" #O+$$$$$XX...XX",
" #O++++++.......",
" #O+$$$$$XX...XX",
" #O+++++++.X.X.@",
" ##%%%%%%.X%.X .",
" ############# @",
" ###&&&&&&&&## @",
" ##&***=-;:+&# @",
" ##&*o>>-;:+&# @",
" ##&*o>>,<1+&# @",
" ##&*o>>234+&# @",
" ##&224+++++&# @",
"@             @@"
};

/* XPM */
static char *redo_xpm[] = {
/* width height num_colors chars_per_pixel */
"    16    15        3            1",
/* colors */
". c #000080",
"# c None",
"a c #808080",
/* pixels */
"################",
"################",
"################",
"################",
"###a....########",
"##a.####..###.##",
"##.#######.#..##",
"##.########...##",
"##.#######....##",
"##a.#####.....##",
"###.a###########",
"################",
"################",
"################",
"################"
};

/* XPM */
static char *new_xpm[] = {
/* columns rows colors chars-per-pixel */
"16 15 31 1",
". c #7198D9",
"2 c #DCE6F6",
", c #FFFFFF",
"= c #9AB6E4",
"6 c #EAF0FA",
"w c #6992D7",
"0 c #5886D2",
"7 c #F7F9FD",
"5 c #F0F5FC",
"* c #A8C0E8",
"  c None",
"8 c #FDFEFF",
"% c #C4D5F0",
"3 c #E2EAF8",
"+ c #4377CD",
"O c #487BCE",
"; c #6B94D7",
"- c #89A9DF",
": c #5584D1",
"# c #3569BF",
"@ c #3A70CA",
"1 c #D2DFF4",
"> c #3366BB",
"$ c #2E5CA8",
"9 c #FAFCFE",
"4 c #F5F8FD",
"q c #638ED5",
"o c #5282D0",
"& c #B8CCEC",
"X c #376EC9",
"< c #ACE95B",
/* pixels */
"   .XoO+@#$.    ",
"   .%%&*=-O;:   ",
"  >>>>%&*=O,=o  ",
"  ><<>%%&*O,,=o ",
">>><<>>>%&OOo+@ ",
"><<<<<<>1%&*=-@ ",
"><<<<<<>21%&*=@ ",
">>><<>>>321%&*+ ",
"  ><<>456321%&O ",
"  >>>>7456321%o ",
"   .,8974563210 ",
"   .,,897456320 ",
"   .,,,8974563q ",
"   .,,,,897456w ",
"   ............ "
};

/* XPM */
static char * delete_xpm[] = {
"16 16 107 2",
"    c None",
".   c #1B0202",
"+   c #51758F",
"@   c #5A89A6",
"#   c #6B98B8",
"$   c #6591AE",
"%   c #538DB3",
"&   c #4581AA",
"*   c #3A749C",
"=   c #8EA9BC",
"-   c #D6DFE7",
";   c #2B232B",
">   c #C3DDF1",
",   c #B6D5EE",
"'   c #A5CCEA",
")   c #97C4E7",
"!   c #85BBE2",
"~   c #5F9BC8",
"{   c #72A8D2",
"]   c #F1F4F7",
"^   c #47667C",
"/   c #3B2A2D",
"(   c #888B94",
"_   c #67A1CF",
":   c #FFFFFF",
"<   c #A69FA1",
"[   c #64626A",
"}   c #4F444A",
"|   c #BED7EA",
"1   c #7EA6C0",
"2   c #8AAFCE",
"3   c #2D232A",
"4   c #E2EFF8",
"5   c #2E2229",
"6   c #53687E",
"7   c #7EAED3",
"8   c #57768D",
"9   c #5D809A",
"0   c #383B47",
"a   c #3D5C74",
"b   c #C0BCBE",
"c   c #605051",
"d   c #9498A1",
"e   c #D1E5F5",
"f   c #A1B9CE",
"g   c #6C788A",
"h   c #4E5261",
"i   c #434C5C",
"j   c #515F73",
"k   c #3E3E4A",
"l   c #6C95B4",
"m   c #6689A5",
"n   c #6A8CAA",
"o   c #3C3B47",
"p   c #577189",
"q   c #8BB1D0",
"r   c #F4F9FD",
"s   c #72676A",
"t   c #463537",
"u   c #443538",
"v   c #3D2C30",
"w   c #72747E",
"x   c #8FA0B3",
"y   c #27161A",
"z   c #31272F",
"A   c #668CA8",
"B   c #81B5DB",
"C   c #FAFCFE",
"D   c #DCDCDE",
"E   c #726465",
"F   c #9F9B9F",
"G   c #433032",
"H   c #8D8D91",
"I   c #B6C3CE",
"J   c #7AA8CC",
"K   c #3B3A46",
"L   c #7CAED2",
"M   c #4A5466",
"N   c #414453",
"O   c #5B768F",
"P   c #749BB4",
"Q   c #635151",
"R   c #5F4E4F",
"S   c #DFE1E3",
"T   c #F7FBFD",
"U   c #B5B3B8",
"V   c #594A4C",
"W   c #594C4F",
"X   c #9FA4AD",
"Y   c #8AA4B6",
"Z   c #89868C",
"`   c #332D36",
" .  c #77A3C5",
"..  c #5E768F",
"+.  c #5D5053",
"@.  c #595E6D",
"#.  c #616B77",
"$.  c #594C4E",
"%.  c #FDFDFE",
"&.  c #D3D5DA",
"*.  c #868083",
"=.  c #362D32",
"-.  c #1D0303",
";.  c #463F46",
">.  c #717F8D",
",.  c #7995A8",
"'.  c #768D9D",
"  . + @ # $ $ % & * = -         ",
"  . ; > > , ' ) ! ~ { ~ ]     . ",
"    ^ / ( > , ' ) _ : ) # <     ",
"    = [ } | > , ' 1 : : 2 3     ",
"    = 4 5 6 7 ! ! _ 8 9 0 a     ",
"    = 4 b c d e > f g h i %     ",
"    = 4 ! j k l m n o p q %     ",
"    = 4 r r s t u v w x ' $     ",
"    = 4 ! ! 7 y z A B ! , $     ",
"    = 4 C D E F G H I e > #     ",
"    = 4 J 5 K L M N O B e P     ",
"    = 4 Q R S T r U V W X P     ",
"    Y Z ` L ! ! ! !  ...+.@.    ",
"    #.$.: : : %.C T r &.*.=.-.  ",
"    ;.>.= = = = = = = Y ,.'.  -.",
"                                "};

////@end XPM images


/* XPM */
static char *copy_xpm[] = {
/* columns rows colors chars-per-pixel */
"16 15 4 1",
"  c None",
". c Black",
"X c Gray100",
"o c #000080",
/* pixels */
"                ",
" ......         ",
" .XXXX..        ",
" .XXXX.X.       ",
" .X..X.oooooo   ",
" .XXXXXoXXXXoo  ",
" .X....oXXXXoXo ",
" .XXXXXoX..Xoooo",
" .X....oXXXXXXXo",
" .XXXXXoX.....Xo",
" ......oXXXXXXXo",
"       oX.....Xo",
"       oXXXXXXXo",
"       ooooooooo",
"                "
};


/* XPM */
static char *Home_xpm[] = {
/* columns rows colors chars-per-pixel */
"32 32 167 2",
"r  c #B98C8D",
"o  c #B52E2E",
"D  c #A99C9F",
">  c #C43D3D",
"Z. c #CD7B27",
"B. c #D9DCE5",
"@. c #DEE0E6",
"-. c #DEE0E7",
"e  c #B83838",
"J. c #8E7C68",
"T. c #828387",
"h  c #DF4848",
"1  c #B83535",
"m  c #A48F91",
";. c #87878B",
"y. c #87878C",
"t. c #D4BDA5",
"K  c #A7999C",
"<  c #E75656",
"U  c #B82F2F",
"   c #FFFFFF",
"<. c #D7C7AB",
"0  c #A1797A",
"Y  c #C42E2E",
"w  c #E75353",
"|  c #CDB386",
"P. c #A15509",
"3  c #CBCBCC",
"i. c #DADDE5",
"n. c #D2BAA4",
"(  c #9E2828",
"a. c #D5C4AA",
":. c #929397",
"L  c #9F3B3B",
"6. c #88888C",
"+  c #A82A2A",
"*. c #B27815",
"l  c #CA3636",
"C. c #B66C19",
"@  c #BE3434",
"$. c #D8C8AB",
"9  c #A27A7B",
"a  c #A58789",
"u. c #909095",
"d  c #D1D3D6",
"s  c #D1D3D7",
"8. c #DBDEE6",
"!  c #E0E2E8",
"w. c #D08D2B",
"b  c #F4F5FA",
"h. c #D3BBA5",
"q  c #BA3A3A",
"b. c #B96D1A",
"Z  c #C83030",
"D. c #848589",
"I. c #A05308",
"2  c #9C4E4F",
"M  c #A73737",
"U. c #8B7460",
"_  c #A23030",
"V  c #982525",
"Q  c #F2F5FA",
"5  c #B52D2D",
"[  c #E8E4DD",
"~  c #A7A1A5",
"t  c #5C5052",
"x. c #D4C2AA",
"+. c #919195",
"7. c #919196",
")  c #962525",
"K. c #A15A09",
"f. c #D38828",
">. c #DCDFE6",
"E  c #E1E3E9",
"#  c #E25151",
"z. c #EBEEF7",
"#. c #F0F2F9",
"C  c #B82E2E",
"{  c #CDB586",
"k  c #992C2C",
"/  c #B82B2B",
"6  c #C73A3A",
" . c #CDB286",
"v. c #D38228",
"V. c #C8B49D",
"l. c #DADCE5",
"B  c #BB3232",
"p  c #B93B3B",
"1. c #B97E19",
".  c #9E2727",
"s. c #AF7F3E",
"M. c #8D8E92",
"3. c #B97B1A",
"T  c #A44142",
"Y. c #838388",
"*  c #BFBFC0",
"5. c #DDE0E6",
"n  c #D8D9DE",
"p. c #ECEFF8",
"]  c #F1F3F9",
":  c #E85656",
"L. c #A25809",
"^  c #913B3B",
"P  c #C52E2E",
"7  c #E85353",
"%  c #A12828",
"g  c #B03738",
"G. c #8B8B90",
"$  c #B73232",
"g. c #B9721A",
"O. c #892121",
"&  c #7B6063",
"X  c #B72F2F",
"d. c #C68A3E",
"R  c #A9A3A7",
"q. c #B57B1F",
"R. c #757579",
"N  c #D23A3A",
"k. c #8E8F94",
"j  c #BA3636",
"=. c #D6C1A6",
"o. c #8A2E2F",
"N. c #CFD2DA",
"v  c #D9DADE",
"9. c #EDF0F8",
"W  c #F2F4FA",
"e. c #D38D28",
"=  c #5F5F62",
"S  c #AF4142",
"A. c #B76919",
"z  c #D53B3B",
"A  c #CB3030",
"&. c #C0871F",
"J  c #DCDEE3",
";  c #C23838",
"}  c #CDB486",
"F. c #808185",
"x  c #B43C3D",
"m. c #85858A",
"c. c #B87019",
",. c #EEF1F8",
"G  c #F3F5FA",
"-  c #AF2C2C",
"%. c #B27C14",
"8  c #BE3B3B",
"u  c #CA3A3A",
"4. c #D5BFA5",
"X. c #747073",
"F  c #DDDFE4",
",  c #C33C3C",
"r. c #B9771A",
"S. c #C6AD98",
".. c #E7E1DA",
"4  c #59595B",
"`  c #7E7579",
"j. c #86868B",
"'  c #D6D8DD",
"H  c #F4F6FB",
"y  c #B72E2E",
"0. c #D6C6AB",
"f  c #A38587",
"O  c #9F2727",
"c  c #A69294",
"H. c #898A8F",
"2. c #D39228",
"I  c #BC2C2C",
"i  c #E14848",
/* pixels */
"                        . . X X o o O O                         ",
"                        . . X X o o O O                         ",
"                    + + @ @ # # # # $ $ % % & & * * = =         ",
"                    + + @ @ # # # # $ $ % % & & * * = =         ",
"                - - ; ; : : > > , , < < 1 1 2 2 3 3 4 4         ",
"                - - ; ; : : > > , , < < 1 1 2 2 3 3 4 4         ",
"            5 5 6 6 7 7 8 8 9 9 0 0 q q w w e e r r t t         ",
"            5 5 6 6 7 7 8 8 9 9 0 0 q q w w e e r r t t         ",
"        y y u u i i p p a a s s d d f f g g h h j j k k         ",
"        y y u u i i p p a a s s d d f f g g h h j j k k         ",
"    y y l l z z x x c c v v b b b b n n m m M M N N B B V V     ",
"    y y l l z z x x c c v v b b b b n n m m M M N N B B V V     ",
"C C Z Z A A S S D D F F G G H H H H G G J J K K L L P P I I V V ",
"C C Z Z A A S S D D F F G G H H H H G G J J K K L L P P I I V V ",
"U U Y Y T T R R E E W W Q Q Q Q Q Q Q Q W W ! ! ~ ~ ^ ^ / / ( ( ",
"U U Y Y T T R R E E W W Q Q Q Q Q Q Q Q W W ! ! ~ ~ ^ ^ / / ( ( ",
") ) _ _ ` ` ' ' ] ] [ [ { { } } | |  . .....] ] ' ' X.X.o.o.O.O.",
") ) _ _ ` ` ' ' ] ] [ [ { { } } | |  . .....] ] ' ' X.X.o.o.O.O.",
"        +.+.@.@.#.#.$.$.%.%.&.&.&.&.*.*.=.=.#.#.-.-.;.;.        ",
"        +.+.@.@.#.#.$.$.%.%.&.&.&.&.*.*.=.=.#.#.-.-.;.;.        ",
"        :.:.>.>.,.,.<.<.1.1.2.2.2.2.3.3.4.4.,.,.5.5.6.6.        ",
"        :.:.>.>.,.,.<.<.1.1.2.2.2.2.3.3.4.4.,.,.5.5.6.6.        ",
"        7.7.8.8.9.9.0.0.q.q.w.w.e.e.r.r.t.t.9.9.>.>.y.y.        ",
"        7.7.8.8.9.9.0.0.q.q.w.w.e.e.r.r.t.t.9.9.>.>.y.y.        ",
"        u.u.i.i.p.p.a.a.s.s.d.d.f.f.g.g.h.h.p.p.8.8.j.j.        ",
"        u.u.i.i.p.p.a.a.s.s.d.d.f.f.g.g.h.h.p.p.8.8.j.j.        ",
"        k.k.l.l.z.z.x.x.c.c.v.v.v.v.b.b.n.n.z.z.i.i.m.m.        ",
"        k.k.l.l.z.z.x.x.c.c.v.v.v.v.b.b.n.n.z.z.i.i.m.m.        ",
"        M.M.N.N.B.B.V.V.C.C.Z.Z.Z.Z.A.A.S.S.B.B.N.N.D.D.        ",
"        M.M.N.N.B.B.V.V.C.C.Z.Z.Z.Z.A.A.S.S.B.B.N.N.D.D.        ",
"        F.F.G.G.H.H.J.J.K.K.L.L.P.P.I.I.U.U.Y.Y.T.T.R.R.        ",
"        F.F.G.G.H.H.J.J.K.K.L.L.P.P.I.I.U.U.Y.Y.T.T.R.R.        "
};


/* XPM */
static char *Folder_Add_xpm[] = {
/* columns rows colors chars-per-pixel */
"32 32 223 2",
"n. c #72CD43",
"#. c #CF6C07",
"OX c #58D247",
"4  c #F89905",
"4X c #FDF09B",
"7X c #F39819",
"=. c #D1983B",
";. c #EC9D26",
"{. c #FDF3B5",
"G. c #84E96F",
"9  c #F3E8AB",
";  c #FBE470",
"@. c #F9A307",
"[  c #E2D073",
"8  c #F3E5A9",
"p. c #FDFB59",
"4. c #FCAD0D",
"6X c #F08205",
"A  c #EFE582",
"1  c #F6990F",
"*  c #F4AB36",
"+  c #FFFFFF",
"L  c #FBE47C",
"-X c #FDF0BA",
"7  c #F3E2A6",
"D  c #EFE27D",
"(. c #6ED04A",
"5  c #F6E697",
"+X c #6BC64D",
"b. c #7DDC57",
"G  c #EFDC77",
"'  c #E2C76D",
"+. c #FBC938",
"_  c #E2C465",
"{  c #DBC96E",
"k  c #FFFE95",
"o. c #70BE38",
"}  c #D0A549",
"W. c #FEF7B8",
"1X c #4DCB3D",
"x  c #FFFB91",
"j  c #FFFB93",
"U  c #FCEE8A",
"j. c #FCD332",
"B. c #FCD947",
"2X c #69C34C",
"c  c #FFF88E",
",  c #F4930F",
"U. c #FCE26C",
"7. c #F9CC44",
"v  c #FFF58A",
".X c #FEFDDC",
"t  c #FDFB8B",
"p  c #FAA40F",
"C  c #F0E683",
"h. c #FCCD2F",
"s  c #FEDF80",
"#  c #F2E9A9",
"_. c #6CC442",
"<X c #6CC74E",
"f. c #FCCA2D",
"g. c #FCCA2E",
"L. c #50CC3F",
"%  c #F5ED9B",
"!  c #EADBB0",
"E  c #D4B95F",
"I. c #EF860F",
"@  c #F5EA99",
"8X c #F59D1C",
"q. c #FCE8A0",
".. c #71BF37",
"s. c #EF830C",
",. c #74CC42",
"X  c #EF830F",
"*X c #FCEEB9",
"wX c #FBAE1C",
"5. c #EF800A",
"0. c #FAD045",
"Z. c #FDD438",
"Y  c #FBF28C",
"a  c #FDE67E",
"]. c #FDEF9F",
"k. c #FDEC97",
"}. c #FDF5B7",
"v. c #89EF73",
"9X c #F6A11C",
"'. c #F08A12",
"d. c #FBD742",
"X. c #6BC844",
"eX c #FCB21C",
";X c #FDF2BB",
"$. c #D19134",
"J. c #71E25E",
"%. c #D19137",
"3. c #FDFA5B",
"   c #ED7705",
"=X c #FDEFB9",
"T  c #EADD7D",
"g  c #FEF08B",
"F. c #78DD65",
"r. c #FEF39C",
"F  c #EFDE7B",
":. c #FCE14D",
"N  c #FEED8A",
"m. c #6EC940",
"=  c #F1EDC9",
"R  c #DBC86D",
"S. c #FEF09D",
"u. c #78D149",
"z  c #FFFD93",
"`  c #E2C36A",
"M  c #FEE785",
"%X c #F18B11",
"H  c #EDDB72",
"9. c #F9CE45",
"a. c #FDB00D",
"r  c #FDFD8C",
"i. c #FFFDA2",
"e  c #FDFD8D",
"2  c #F79C0F",
"@X c #FEFCDA",
" X c #FEFCDB",
"T. c #FCE16C",
"m  c #FEE181",
"y  c #FDFA89",
"yX c #64B22D",
"C. c #FCCF34",
"I  c #FCE786",
"u  c #FDF787",
",X c #FEF9DC",
"W  c #EADDB1",
"V. c #FCCC33",
"b  c #FDF483",
"J  c #EE9E0D",
"M. c #69B02A",
"~  c #EADAAF",
"&X c #FCEA9F",
"P  c #FCE181",
":  c #F29214",
"N. c #EF850D",
"z. c #74CE43",
"l. c #6FC739",
"|  c #F3A82C",
"`. c #69AD28",
"E. c #FDEB73",
"0X c #F8A61C",
"!. c #79D24F",
"~. c #79D250",
"<  c #F5960F",
".  c #EF820F",
"$X c #FED888",
"uX c #5EBE38",
"<. c #72D75F",
"&  c #F3A229",
"y. c #81E66D",
"O. c #FCE198",
"5X c #FEB10F",
"V  c #FBF48E",
"n  c #FBA70F",
"(  c #D88B0A",
"/. c #6EE05B",
"aX c #FEAB06",
"Q. c #72CB48",
"w. c #FDEEA2",
"*. c #D1963A",
")  c #DC790C",
"q  c #FEF890",
"qX c #F9AA1C",
">X c #FDF4BB",
":X c #FDF4BC",
"[. c #FDF1B3",
"c. c #7FDD58",
"H. c #82ED6D",
"2. c #FEFBA3",
"&. c #D19339",
"Z  c #EFE682",
">  c #F3900F",
"1. c #75CF47",
" . c #FADB97",
"tX c #FFDF99",
"S  c #EFE380",
"6  c #F3E0A5",
"l  c #FFFF95",
"|. c #FEF8B8",
"e. c #FEEF9A",
"K  c #EE830F",
">. c #FEEF9B",
"f  c #FEE987",
"O  c #EE8311",
"K. c #5ED54C",
"-. c #D29A3C",
"D. c #6CCE48",
"/  c #D3B051",
"R. c #FCE66F",
"6. c #F9D048",
"#X c #FEFBCD",
"rX c #FDB51C",
"8. c #F9CD44",
"XX c #FEFEDC",
"^. c #7BDA56",
"d  c #FEE383",
"w  c #FDFC8D",
"t. c #76D045",
"0  c #F7EEA2",
"x. c #76D046",
"h  c #FFF690",
"i  c #FDF682",
"B  c #FFF38E",
"$  c #F2EAAA",
"). c #6CC544",
"Y. c #FCDD69",
"3X c #FEF8DB",
"oX c #71CC53",
"]  c #E3CC71",
"Q  c #EADCB0",
"^  c #EAD9AD",
"A. c #FDDB3C",
"-  c #F2EDCA",
"o  c #EF840F",
"iX c #62AE2C",
"pX c #FEB618",
"3  c #F89F0F",
"P. c #5EBD37",
/* pixels */
"    . . . . . . . . X X o o O O + + + + + + + + + + + + + + + + ",
"    . . . . . . . . X X o o O O + + + + + + + + + + + + + + + + ",
". . @ @ # # # # # # $ $ % % & & * * + + + + + + + + + + + + + + ",
". . @ @ # # # # # # $ $ % % & & * * + + + + + + + + + + + + + + ",
". . = = + + + + + + + + - - ; ; : : > > , , < < 1 1 2 2 3 3 4 4 ",
". . = = + + + + + + + + - - ; ; : : > > , , < < 1 1 2 2 3 3 4 4 ",
". . 5 5 6 6 7 7 8 8 9 9 0 0 q q w w e e r r t t y y u u i i p p ",
". . 5 5 6 6 7 7 8 8 9 9 0 0 q q w w e e r r t t y y u u i i p p ",
". . a a s s d d f f g g h h j j k k l l z z x x c c v v b b n n ",
". . a a s s d d f f g g h h j j k k l l z z x x c c v v b b n n ",
". . a a m m M M N N B B V V C C Z Z A A S S D D F F G G H H J J ",
". . a a m m M M N N B B V V C C Z Z A A S S D D F F G G H H J J ",
"K K L L P P I I U U Y Y T T R R E E W W Q Q ! ! ~ ~ ^ ^ / / ( ( ",
"K K L L P P I I U U Y Y T T R R E E W W Q Q ! ! ~ ~ ^ ^ / / ( ( ",
") ) _ _ ` ` ' ' ] ] [ [ { { } } | |  . .....X.X.o.o.O.O.+.+.@.@.",
") ) _ _ ` ` ' ' ] ] [ [ { { } } | |  . .....X.X.o.o.O.O.+.+.@.@.",
"#.#.$.$.%.%.&.&.*.*.=.=.-.-.;.;.:.:.>.>.,.,.<.<.1.1.2.2.3.3.4.4.",
"#.#.$.$.%.%.&.&.*.*.=.=.-.-.;.;.:.:.>.>.,.,.<.<.1.1.2.2.3.3.4.4.",
"5.5.6.6.7.7.8.8.9.9.0.0.q.q.w.w.e.e.r.r.t.t.y.y.u.u.i.i.p.p.a.a.",
"5.5.6.6.7.7.8.8.9.9.0.0.q.q.w.w.e.e.r.r.t.t.y.y.u.u.i.i.p.p.a.a.",
"s.s.d.d.f.f.g.g.h.h.j.j.k.k.l.l.z.z.x.x.c.c.v.v.b.b.n.n.m.m.M.M.",
"s.s.d.d.f.f.g.g.h.h.j.j.k.k.l.l.z.z.x.x.c.c.v.v.b.b.n.n.m.m.M.M.",
"N.N.B.B.V.V.C.C.Z.Z.A.A.S.S.D.D.F.F.G.G.v.v.H.H.J.J.K.K.L.L.P.P.",
"N.N.B.B.V.V.C.C.Z.Z.A.A.S.S.D.D.F.F.G.G.v.v.H.H.J.J.K.K.L.L.P.P.",
"I.I.U.U.Y.Y.T.T.R.R.E.E.W.W.Q.Q.!.!.~.~.^.^././.(.(.).)._._.`.`.",
"I.I.U.U.Y.Y.T.T.R.R.E.E.W.W.Q.Q.!.!.~.~.^.^././.(.(.).)._._.`.`.",
"'.'.].].[.[.{.{.}.}.|.|. X X.X.X.X.XXXXXoXoXOXOX+X+X@X@X#X#X$X$X",
"'.'.].].[.[.{.{.}.}.|.|. X X.X.X.X.XXXXXoXoXOXOX+X+X@X@X#X#X$X$X",
"%X%X&X&X*X*X=X=X-X-X;X;X;X;X:X:X>X>X,X,X<X<X1X1X2X2X3X3X4X4X5X5X",
"%X%X&X&X*X*X=X=X-X-X;X;X;X;X:X:X>X>X,X,X<X<X1X1X2X2X3X3X4X4X5X5X",
"6X6X7X7X8X8X9X9X0X0XqXqXwXwXeXeXrXrXtXtXyXyXuXuXiXiXtXtXpXpXaXaX",
"6X6X7X7X8X8X9X9X0X0XqXqXwXwXeXeXrXrXtXtXyXyXuXuXiXiXtXtXpXpXaXaX"
};


/* XPM */
static char *Info_xpm[] = {
/* columns rows colors chars-per-pixel */
"32 32 157 2",
"z  c #002479",
"E  c #3264D5",
"V  c #577DEB",
"I  c #EDEFF6",
"N  c #667DC7",
"e  c #6680D4",
"Q  c #356BD5",
"c. c #1C51BE",
"@. c #738FDB",
"q  c #FAFBFC",
"   c #FFFFFF",
"y. c #5D7FCD",
":  c #2650B8",
"-  c #3F6AD1",
"Z. c #295DC3",
"H  c #3953C8",
"<  c #344CC0",
"n. c #154AB9",
"8. c #6787D4",
"$  c #3058C1",
"%. c #2459CA",
"x. c #295DCE",
"F  c #012E94",
"C  c #537DEC",
"o  c #012E95",
"]  c #3D6DDC",
"t  c #587EED",
"t. c #4271E0",
"s  c #3750C5",
"m. c #2253BA",
"A. c #0E3DA3",
"Y  c #567BDA",
"h. c #3660B6",
"p. c #0E3DA4",
"f  c #5D73C9",
"l  c #1341A7",
".. c #09369C",
",. c #4F74C6",
"G  c #4265D1",
"P  c #5B79D7",
"#. c #597CCD",
"'  c #6384D4",
"c  c #3159C2",
"&  c #4262D1",
"{  c #255ACB",
"$. c #2F62D2",
"f. c #3466D6",
"U  c #EAEDF5",
"R  c #3E6EDE",
"j. c #235AC9",
"M. c #0F3EA4",
"r. c #5C86F0",
"D. c #002C91",
"O  c #0A379D",
"G. c #00206A",
"3. c #002C92",
"+  c #0A379E",
"9. c #466DBF",
"x  c #002C93",
".  c #002375",
"v. c #738EC6",
"r  c #577CEB",
"d. c #507EEA",
"i. c #2B62CE",
"C. c #3066D0",
"2. c #3066D1",
"*  c #486AD8",
"%  c #3E5FCD",
"9  c #364EC4",
"Z  c #4B77E6",
"S  c #3567D7",
"/  c #4360D3",
"1. c #1A50C2",
"y  c #5883EF",
";  c #1543A9",
"b. c #6F8BC4",
"n  c #415DD1",
"5. c #587DEB",
"|  c #2C63CF",
"B. c #3167D1",
"D  c #3164CA",
"4  c #5376E6",
"j  c #4C78E7",
",  c #2D44BA",
"u  c #3161C6",
"5  c #5B84EE",
">  c #3552C3",
"~  c #09359C",
"w  c #FBFBFC",
"_  c #567AE9",
"+. c #567AEA",
"*. c #164DBF",
"w. c #2A5DC4",
"&. c #1B51C3",
")  c #5173E3",
"3  c #4C6CDC",
" . c #07359C",
"s. c #2F5EC4",
"h  c #547DEC",
"6  c #3462C7",
"B  c #6881CA",
"#  c #113DA4",
"J  c #425ED2",
"X. c #4F73DF",
"V. c #2D64D0",
"7. c #4D79E8",
"a  c #2E45BB",
"!  c #002E95",
"z. c #4174DF",
"@  c #002579",
"S. c #001F66",
"i  c #002270",
"a. c #002271",
"u. c #4168BA",
"K  c #4A69DB",
"1  c #5468BF",
"e. c #001F68",
"k  c #4B7CE6",
"d  c #405BCF",
";. c #577BEA",
"v  c #3149BE",
"O. c #5274E4",
"}  c #1C52C4",
"^  c #4869D8",
"l. c #2B5BC0",
">. c #6E8CD9",
"6. c #557EEC",
":. c #557EED",
"g  c #6985D9",
"4. c #3F6BD1",
"7  c #2F49BC",
"T  c #4976E5",
"2  c #5A70C7",
"=. c #537BE5",
"F. c #06339A",
"(  c #4B6ADC",
"p  c #3754C5",
"0  c #5569C1",
"g. c #4C71C4",
"q. c #184FC0",
"N. c #2C5FC5",
"k. c #2254BA",
"-. c #5375E5",
"<. c #2257C9",
"8  c #2D43BA",
"W  c #275BCC",
"[  c #3163D4",
"m  c #4967DA",
"`  c #748EDB",
"A  c #406FDF",
"L  c #5172E2",
"o. c #4C6BDD",
"=  c #4F75DF",
"b  c #3852C7",
"0. c #1950C1",
"M  c #4F6FDF",
"X  c #002D94",
/* pixels */
"                . . X X o o O O + + o o X X @ @                 ",
"                . . X X o o O O + + o o X X @ @                 ",
"            X X # # $ $ % % & & * * = = - - ; ; X X             ",
"            X X # # $ $ % % & & * * = = - - ; ; X X             ",
"        X X : : > > , , < < 1 1 2 2 3 3 4 4 5 5 6 6 X X         ",
"        X X : : > > , , < < 1 1 2 2 3 3 4 4 5 5 6 6 X X         ",
"    X X : : 7 7 8 8 9 9 0 0 q q w w e e r r t t y y u u X X     ",
"    X X : : 7 7 8 8 9 9 0 0 q q w w e e r r t t y y u u X X     ",
"i i # # p p a a s s d d f f w w w w g g t t h h j j k k l l z z ",
"i i # # p p a a s s d d f f w w w w g g t t h h j j k k l l z z ",
"x x c c v v b b n n m m M M N N B B V V C C Z Z A A S S D D X X ",
"x x c c v v b b n n m m M M N N B B V V C C Z Z A A S S D D X X ",
"F F G G H H J J K K L L P P I I U U Y Y T T R R E E W W Q Q ! ! ",
"F F G G H H J J K K L L P P I I U U Y Y T T R R E E W W Q Q ! ! ",
"~ ~ ^ ^ / / ( ( ) ) _ _ ` `         ' ' ] ] [ [ { { } } | |  . .",
"~ ~ ^ ^ / / ( ( ) ) _ _ ` `         ' ' ] ] [ [ { { } } | |  . .",
"....X.X.o.o.O.O.+.+.t t @.@.        #.#.$.$.%.%.&.&.*.*.| |  . .",
"....X.X.o.o.O.O.+.+.t t @.@.        #.#.$.$.%.%.&.&.*.*.| |  . .",
"X X =.=.-.-.;.;.t t :.:.>.>.        ,.,.<.<.1.1.*.*.*.*.2.2.X X ",
"X X =.=.-.-.;.;.t t :.:.>.>.        ,.,.<.<.1.1.*.*.*.*.2.2.X X ",
"3.3.4.4.5.5.t t 6.6.7.7.8.8.        9.9.0.0.*.*.*.*.q.q.w.w.X X ",
"3.3.4.4.5.5.t t 6.6.7.7.8.8.        9.9.0.0.*.*.*.*.q.q.w.w.X X ",
"e.e.l l r.r.h h j j t.t.y.y.        u.u.*.*.*.*.*.*.i.i.p.p.a.a.",
"e.e.l l r.r.h h j j t.t.y.y.        u.u.*.*.*.*.*.*.i.i.p.p.a.a.",
"    3.3.s.s.d.d.A A f.f.g.g.        h.h.*.*.*.*.j.j.k.k.x x     ",
"    3.3.s.s.d.d.A A f.f.g.g.        h.h.*.*.*.*.j.j.k.k.x x     ",
"        X X l.l.z.z.x.x.c.c.v.v.b.b.n.n.q.q.i.i.m.m.X X         ",
"        X X l.l.z.z.x.x.c.c.v.v.b.b.n.n.q.q.i.i.m.m.X X         ",
"            3.3.M.M.N.N.B.B.V.V.V.V.C.C.Z.Z.A.A.x x             ",
"            3.3.M.M.N.N.B.B.V.V.V.V.C.C.Z.Z.A.A.x x             ",
"                S.S.D.D.X X F.F.F.F.X X 3.3.G.G.                ",
"                S.S.D.D.X X F.F.F.F.X X 3.3.G.G.                "
};



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// frmMDFEditor type definition
//

IMPLEMENT_CLASS( frmMDFEditor, wxFrame )


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// frmMDFEditor event table definition
//

BEGIN_EVENT_TABLE( frmMDFEditor, wxFrame )

////@begin frmMDFEditor event table entries
  EVT_MENU( ID_MENUITEM_EXIT, frmMDFEditor::OnMenuitemExitClick )

  EVT_MENU( ID_TOOL_NEW, frmMDFEditor::OnToolNewClick )

  EVT_MENU( ID_TOOL_LOAD, frmMDFEditor::OnToolLoadClick )

  EVT_MENU( ID_TOOL_SAVE, frmMDFEditor::OnToolSaveClick )

  EVT_MENU( ID_TOOL_DOWNLOAD, frmMDFEditor::OnToolDownloadClick )

  EVT_MENU( ID_TOOL_REMOVE_ITEM, frmMDFEditor::OnToolRemoveItemClick )

  EVT_TREE_SEL_CHANGED( ID_TREECTRL, frmMDFEditor::OnTreectrlSelChanged )

////@end frmMDFEditor event table entries

END_EVENT_TABLE()


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// frmMDFEditor constructors
//

frmMDFEditor::frmMDFEditor()
{
  Init();
}

frmMDFEditor::frmMDFEditor( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
  Init();
  Create( parent, id, caption, pos, size, style );
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// frmMDFEditor creator
//

bool frmMDFEditor::Create( wxWindow* parent, wxWindowID id, const wxString& caption, const wxPoint& pos, const wxSize& size, long style )
{
////@begin frmMDFEditor creation
  wxFrame::Create( parent, id, caption, pos, size, style );

  CreateControls();
  Centre();
////@end frmMDFEditor creation
  return true;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// frmMDFEditor destructor
//

frmMDFEditor::~frmMDFEditor()
{
////@begin frmMDFEditor destruction
////@end frmMDFEditor destruction
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Member initialisation
//

void frmMDFEditor::Init()
{
////@begin frmMDFEditor member initialisation
  m_mdfTree = NULL;
  m_htmlInfoWnd = NULL;
////@end frmMDFEditor member initialisation
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Control creation for frmMDFEditor
//

void frmMDFEditor::CreateControls()
{    
////@begin frmMDFEditor content construction
  frmMDFEditor* itemFrame1 = this;

  wxMenuBar* menuBar = new wxMenuBar;
  wxMenu* itemMenu3 = new wxMenu;
  itemMenu3->Append(ID_MENUITEM_NEW, _("Create New MDF File"), wxEmptyString, wxITEM_NORMAL);
  itemMenu3->AppendSeparator();
  itemMenu3->Append(ID_MENUITEM_OPEN, _("Open MDF file..."), wxEmptyString, wxITEM_NORMAL);
  itemMenu3->Append(ID_MENUITEM_SAVE, _("Save MDF File..."), wxEmptyString, wxITEM_NORMAL);
  itemMenu3->AppendSeparator();
  itemMenu3->Append(ID_MENUITEM_DOWNLOAD, _("Download MDF file..."), wxEmptyString, wxITEM_NORMAL);
  itemMenu3->Append(ID_MENUITEM_UPLOAD, _("Upload MDF file..."), wxEmptyString, wxITEM_NORMAL);
  itemMenu3->AppendSeparator();
  itemMenu3->Append(ID_MENUITEM_EXIT, _("Exit"), wxEmptyString, wxITEM_NORMAL);
  menuBar->Append(itemMenu3, _("File"));
  wxMenu* itemMenu13 = new wxMenu;
  itemMenu13->Append(ID_MENUITEM_ADD, _("Add MDF Item..."), wxEmptyString, wxITEM_NORMAL);
  itemMenu13->Append(ID_MENUITEM_REMOVE, _("Remove MDF Item..."), wxEmptyString, wxITEM_NORMAL);
  menuBar->Append(itemMenu13, _("Edit"));
  itemFrame1->SetMenuBar(menuBar);

  wxPanel* itemPanel16 = new wxPanel;
  itemPanel16->Create( itemFrame1, ID_PANEL, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER|wxTAB_TRAVERSAL );

  wxBoxSizer* itemBoxSizer17 = new wxBoxSizer(wxVERTICAL);
  itemPanel16->SetSizer(itemBoxSizer17);

  wxToolBar* itemToolBar18 = new wxToolBar;
  itemToolBar18->Create( itemPanel16, ID_TOOLBAR3, wxDefaultPosition, wxDefaultSize, wxTB_FLAT|wxTB_HORIZONTAL );
  wxBitmap itemtool19Bitmap(itemFrame1->GetBitmapResource(wxT("deffile.xpm")));
  wxBitmap itemtool19BitmapDisabled;
  itemToolBar18->AddTool(ID_TOOL_NEW, wxEmptyString, itemtool19Bitmap, itemtool19BitmapDisabled, wxITEM_NORMAL, _("Create new MDF file"), wxEmptyString);
  wxBitmap itemtool20Bitmap(itemFrame1->GetBitmapResource(wxT("open.xpm")));
  wxBitmap itemtool20BitmapDisabled;
  itemToolBar18->AddTool(ID_TOOL_LOAD, wxEmptyString, itemtool20Bitmap, itemtool20BitmapDisabled, wxITEM_NORMAL, _("Load MDF file"), wxEmptyString);
  wxBitmap itemtool21Bitmap(itemFrame1->GetBitmapResource(wxT("save.xpm")));
  wxBitmap itemtool21BitmapDisabled;
  itemToolBar18->AddTool(ID_TOOL_SAVE, wxEmptyString, itemtool21Bitmap, itemtool21BitmapDisabled, wxITEM_NORMAL, _("Save MDF file"), wxEmptyString);
  wxBitmap itemtool22Bitmap(itemFrame1->GetBitmapResource(wxT("filesaveas.xpm")));
  wxBitmap itemtool22BitmapDisabled;
  itemToolBar18->AddTool(ID_TOOL_UPLOAD, wxEmptyString, itemtool22Bitmap, itemtool22BitmapDisabled, wxITEM_NORMAL, _("Upload MDF file"), wxEmptyString);
  wxBitmap itemtool23Bitmap(itemFrame1->GetBitmapResource(wxT("redo.xpm")));
  wxBitmap itemtool23BitmapDisabled;
  itemToolBar18->AddTool(ID_TOOL_DOWNLOAD, wxEmptyString, itemtool23Bitmap, itemtool23BitmapDisabled, wxITEM_NORMAL, _("Upload MDF file"), wxEmptyString);
  itemToolBar18->AddSeparator();
  wxBitmap itemtool25Bitmap(itemFrame1->GetBitmapResource(wxT("New1.xpm")));
  wxBitmap itemtool25BitmapDisabled;
  itemToolBar18->AddTool(ID_TOOL_ADD_ITEM, wxEmptyString, itemtool25Bitmap, itemtool25BitmapDisabled, wxITEM_NORMAL, _("Add MDF item"), wxEmptyString);
  wxBitmap itemtool26Bitmap(itemFrame1->GetBitmapResource(wxT("delete.xpm")));
  wxBitmap itemtool26BitmapDisabled;
  itemToolBar18->AddTool(ID_TOOL_REMOVE_ITEM, wxEmptyString, itemtool26Bitmap, itemtool26BitmapDisabled, wxITEM_NORMAL, _("Remove MDF item"), wxEmptyString);
  itemToolBar18->Realize();
  itemBoxSizer17->Add(itemToolBar18, 0, wxGROW|wxALL, 5);

  m_mdfTree = new wxTreeCtrl;
  m_mdfTree->Create( itemPanel16, ID_TREECTRL, wxDefaultPosition, wxSize(400, 300), wxTR_HAS_BUTTONS |wxTR_FULL_ROW_HIGHLIGHT|wxTR_LINES_AT_ROOT|wxTR_ROW_LINES|wxTR_SINGLE );
  itemBoxSizer17->Add(m_mdfTree, 0, wxGROW|wxALL, 2);

  m_htmlInfoWnd = new wxHtmlWindow;
  m_htmlInfoWnd->Create( itemPanel16, ID_HTMLWINDOW2, wxDefaultPosition, wxSize(200, 150), wxHW_SCROLLBAR_AUTO|wxSUNKEN_BORDER|wxHSCROLL|wxVSCROLL );
  m_htmlInfoWnd->SetPage(_("<html><h4>No data</h4></html>"));
  itemBoxSizer17->Add(m_htmlInfoWnd, 0, wxGROW|wxALL, 5);

  // Connect events and objects
  m_mdfTree->Connect(ID_TREECTRL, wxEVT_LEFT_DOWN, wxMouseEventHandler(frmMDFEditor::OnLeftDown), NULL, this);
  m_mdfTree->Connect(ID_TREECTRL, wxEVT_LEFT_DCLICK, wxMouseEventHandler(frmMDFEditor::OnLeftDClick), NULL, this);
////@end frmMDFEditor content construction

    wxImageList* itemImageList = new wxImageList(16, 16, true, 5);
    {
        wxIcon Icon0( Home_xpm );
        itemImageList->Add( Icon0 );
        wxIcon Icon1( Folder_Add_xpm );
        itemImageList->Add( Icon1 );
        wxIcon Icon2( Info_xpm );
        itemImageList->Add( Icon2 );
        wxIcon Icon3( copy_xpm );
        itemImageList->Add( Icon3 );
        wxIcon Icon4( copy_xpm );
        itemImageList->Add( Icon4 );
    }

    m_mdfTree->AssignImageList( itemImageList );
    addDefaultContent();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Should we show tooltips?
//

bool frmMDFEditor::ShowToolTips()
{
  return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Get bitmap resources
//

wxBitmap frmMDFEditor::GetBitmapResource( const wxString& name )
{
  // Bitmap retrieval
////@begin frmMDFEditor bitmap retrieval
  wxUnusedVar(name);
  if (name == _T("deffile.xpm"))
  {
    wxBitmap bitmap(deffile_xpm);
    return bitmap;
  }
  else if (name == _T("open.xpm"))
  {
    wxBitmap bitmap(open_xpm);
    return bitmap;
  }
  else if (name == _T("save.xpm"))
  {
    wxBitmap bitmap(save_xpm);
    return bitmap;
  }
  else if (name == _T("filesaveas.xpm"))
  {
    wxBitmap bitmap(filesaveas_xpm);
    return bitmap;
  }
  else if (name == _T("redo.xpm"))
  {
    wxBitmap bitmap(redo_xpm);
    return bitmap;
  }
  else if (name == _T("New1.xpm"))
  {
    wxBitmap bitmap(new_xpm);
    return bitmap;
  }
  else if (name == _T("delete.xpm"))
  {
    wxBitmap bitmap(delete_xpm);
    return bitmap;
  }
  return wxNullBitmap;
////@end frmMDFEditor bitmap retrieval
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Get icon resources
//

wxIcon frmMDFEditor::GetIconResource( const wxString& name )
{
  // Icon retrieval
////@begin frmMDFEditor icon retrieval
  wxUnusedVar(name);
  return wxNullIcon;
////@end frmMDFEditor icon retrieval
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_NEW
//

void frmMDFEditor::OnToolNewClick( wxCommandEvent& event )
{
////@begin wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_NEW in frmMDFEditor.
  // Before editing this code, remove the block markers.
  event.Skip();
////@end wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_NEW in frmMDFEditor. 
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_LOAD
//

void frmMDFEditor::OnToolLoadClick( wxCommandEvent& event )
{
    wxString localMDF;
    //wxStandardPaths stdpaths;
    
    // Load MDF from local file
    wxFileDialog dlg( this,
                        _("Choose file to load MDF from "),
                        wxStandardPaths::Get().GetUserDataDir(),
                        _(""),
                        _("MSF Files (*.mdf)|*.mdf|XML Files (*.xml)|*.xml|All files (*.*)|*.*") );
    if ( wxID_OK == dlg.ShowModal() ) {
    
        localMDF = dlg.GetPath();
       
        if ( m_mdfTree->GetCount() ) {
        
            if ( wxYES != wxMessageBox( _("Should the old MDF data be removed and lost"), 
                                            _("Delete MDF data?"),
                                            wxYES_NO | wxCANCEL ) ) {
                event.Skip( false );
                return;
            }
            
            m_mdfTree->DeleteAllItems();
            
        }       
       
        if ( !m_mdf.parseMDF( localMDF ) ) {
            wxMessageBox( _("Failed to parse MDF.") );
            event.Skip( false );
            return;
        }
        
        
    
        // Fill up the TreeControl with data from the MDF
        
    }
    else {
        event.Skip( false );
        return;
    }
        
    
    event.Skip( false );  
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_SAVE
//

void frmMDFEditor::OnToolSaveClick( wxCommandEvent& event )
{

  event.Skip();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_DOWNLOAD
//

void frmMDFEditor::OnToolDownloadClick( wxCommandEvent& event )
{

  event.Skip();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// wxEVT_COMMAND_MENU_SELECTED event handler for ID_TOOL_REMOVE_ITEM
//

void frmMDFEditor::OnToolRemoveItemClick( wxCommandEvent& event )
{

  event.Skip();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// wxEVT_COMMAND_TREE_SEL_CHANGED event handler for ID_TREECTRL
//

void frmMDFEditor::OnTreectrlSelChanged( wxTreeEvent& event )
{
    wxString strPage;
    strPage = _("<html><body><h3>");
    wxTreeItemId itemID = event.GetItem();
    //MyTreeItemData *item = itemId.IsOk() ? (MyTreeItemData *)GetItemData(itemId)
    //                                     : NULL;
    if ( itemID.IsOk() ) {
        strPage += m_mdfTree->GetItemText( itemID );
        strPage += event.GetLabel();
    }
    else {
        strPage += _("????");
    }
    strPage += _("</h3></body></html>");
    m_htmlInfoWnd->SetPage( strPage );
    event.Skip();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// wxEVT_LEFT_DOWN event handler for ID_TREECTRL
//

void frmMDFEditor::OnLeftDown( wxMouseEvent& event )
{

  event.Skip(); 
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// wxEVT_LEFT_DCLICK event handler for ID_TREECTRL
//

void frmMDFEditor::OnLeftDClick( wxMouseEvent& event )
{

  event.Skip(); 
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// addDefaultContent
//

void frmMDFEditor::addDefaultContent( void )
{
    m_rootItem = m_mdfTree->AddRoot( _("mdf"), MDF_EDITOR_TOP_ITEM );
    m_moduleItem = m_mdfTree->AppendItem( m_rootItem, _("module"), MDF_EDITOR_MAIN_ITEM );

    m_mdfTree->AppendItem( m_moduleItem, _("Name"), MDF_EDITOR_SUB_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("Model"), MDF_EDITOR_SUB_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("Version"), MDF_EDITOR_SUB_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("Description"), MDF_EDITOR_SUB_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("URL for full module information"), MDF_EDITOR_SUB_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("Last date changed"), MDF_EDITOR_SUB_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("Buffersize"), MDF_EDITOR_SUB_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("Location of MDF file"), MDF_EDITOR_SUB_ITEM );

    m_mdfTree->AppendItem( m_moduleItem, _("Manufacturer"), MDF_EDITOR_MAIN_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("Driver"), MDF_EDITOR_MAIN_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("Abstractions"), MDF_EDITOR_MAIN_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("Registers"), MDF_EDITOR_MAIN_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("Decision Matrix"), MDF_EDITOR_MAIN_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("Events"), MDF_EDITOR_MAIN_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("Alarm"), MDF_EDITOR_MAIN_ITEM );
    m_mdfTree->AppendItem( m_moduleItem, _("Boot"), MDF_EDITOR_MAIN_ITEM );
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// wxEVT_COMMAND_MENU_SELECTED event handler for ID_MENUITEM_EXIT
//

void frmMDFEditor::OnMenuitemExitClick( wxCommandEvent& event )
{
    Close();
    event.Skip();
}

