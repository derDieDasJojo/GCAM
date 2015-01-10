/**
 *  gcam_icon.h
 *  Source code file for G-Code generation, simulation, and visualization
 *  library.
 *
 *  Copyright (C) 2006 - 2010 by Justin Shumaker
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GCAM_ICON_H
#define _GCAM_ICON_H

/* *INDENT-OFF* */

/* XPM */
const char *gcam_icon_xpm[] = {
"128 128 232 2",
"   c None",
".  c #E6E6E6",
"+  c #AEAEAE",
"@  c #C0C0C0",
"#  c #CFCFCF",
"$  c #DEDEDE",
"%  c #999999",
"&  c #B3B3B3",
"*  c #D2D2D2",
"=  c #DBDBDB",
"-  c #C4C4C4",
";  c #A3A3A3",
">  c #989898",
",  c #CECECE",
"'  c #BEBEBE",
")  c #DCDCDC",
"!  c #A1A1A1",
"~  c #888888",
"{  c #B9B9B9",
"]  c #D0D0D0",
"^  c #C8C8C8",
"/  c #979797",
"(  c #DADADA",
"_  c #D6D6D6",
":  c #A8A8A8",
"<  c #A0A0A0",
"[  c #8A8A8A",
"}  c #8C8C8C",
"|  c #D1D1D1",
"1  c #AAAAAA",
"2  c #909090",
"3  c #D3D3D3",
"4  c #BABABA",
"5  c #9A9A9A",
"6  c #7C7C7C",
"7  c #C3C3C3",
"8  c #898989",
"9  c #8F8F8F",
"0  c #D7D7D7",
"a  c #ACACAC",
"b  c #A2A2A2",
"c  c #9F9F9F",
"d  c #9E9E9E",
"e  c #9B9B9B",
"f  c #8B8B8B",
"g  c #969696",
"h  c #CBCBCB",
"i  c #ADADAD",
"j  c #A5A5A5",
"k  c #9D9D9D",
"l  c #919191",
"m  c #7A7A7A",
"n  c #717171",
"o  c #C7C7C7",
"p  c #868686",
"q  c #959595",
"r  c #D9D9D9",
"s  c #BCBCBC",
"t  c #A4A4A4",
"u  c #797979",
"v  c #5B5B5B",
"w  c #D4D4D4",
"x  c #8D8D8D",
"y  c #E5E5E5",
"z  c #B6B6B6",
"A  c #7B7B7B",
"B  c #5A5A5A",
"C  c #777777",
"D  c #878787",
"E  c #E3E3E3",
"F  c #B8B8B8",
"G  c #C1C1C1",
"H  c #E4E4E4",
"I  c #DFDFDF",
"J  c #B7B7B7",
"K  c #5F5F5F",
"L  c #4A4A4A",
"M  c #C6C6C6",
"N  c #858585",
"O  c #E0E0E0",
"P  c #B0B0B0",
"Q  c #B5B5B5",
"R  c #ABABAB",
"S  c #808080",
"T  c #7E7E7E",
"U  c #838383",
"V  c #AFAFAF",
"W  c #C2C2C2",
"X  c #DDDDDD",
"Y  c #8E8E8E",
"Z  c #818181",
"`  c #4D4D4D",
" . c #3C3C3C",
".. c #BDBDBD",
"+. c #B4B4B4",
"@. c #444444",
"#. c #595959",
"$. c #727272",
"%. c #737373",
"&. c #707070",
"*. c #6D6D6D",
"=. c #A6A6A6",
"-. c #393939",
";. c #323232",
">. c #BBBBBB",
",. c #D5D5D5",
"'. c #363636",
"). c #303030",
"!. c #373737",
"~. c #7F7F7F",
"{. c #939393",
"]. c #767676",
"^. c #6B6B6B",
"/. c #686868",
"(. c #636363",
"_. c #BFBFBF",
":. c #B1B1B1",
"<. c #2C2C2C",
"[. c #2B2B2B",
"}. c #353535",
"|. c #9C9C9C",
"1. c #CDCDCD",
"2. c #E2E2E2",
"3. c #4E4E4E",
"4. c #3A3A3A",
"5. c #262626",
"6. c #616161",
"7. c #6C6C6C",
"8. c #6E6E6E",
"9. c #656565",
"0. c #6A6A6A",
"a. c #A9A9A9",
"b. c #545454",
"c. c #232323",
"d. c #222222",
"e. c #282828",
"f. c #606060",
"g. c #CCCCCC",
"h. c #494949",
"i. c #3B3B3B",
"j. c #2D2D2D",
"k. c #272727",
"l. c #212121",
"m. c #1A1A1A",
"n. c #1F1F1F",
"o. c #424242",
"p. c #646464",
"q. c #666666",
"r. c #5E5E5E",
"s. c #696969",
"t. c #A7A7A7",
"u. c #101010",
"v. c #151515",
"w. c #1D1D1D",
"x. c #828282",
"y. c #848484",
"z. c #525252",
"A. c #404040",
"B. c #2F2F2F",
"C. c #242424",
"D. c #181818",
"E. c #171717",
"F. c #2E2E2E",
"G. c #747474",
"H. c #6F6F6F",
"I. c #5D5D5D",
"J. c #0F0F0F",
"K. c #0B0B0B",
"L. c #0A0A0A",
"M. c #C5C5C5",
"N. c #5C5C5C",
"O. c #4B4B4B",
"P. c #333333",
"Q. c #1B1B1B",
"R. c #141414",
"S. c #121212",
"T. c #1E1E1E",
"U. c #555555",
"V. c #535353",
"W. c #4C4C4C",
"X. c #3E3E3E",
"Y. c #080808",
"Z. c #070707",
"`. c #787878",
" + c #949494",
".+ c #191919",
"++ c #131313",
"@+ c #111111",
"#+ c #161616",
"$+ c #676767",
"%+ c #434343",
"&+ c #0D0D0D",
"*+ c #040404",
"=+ c #060606",
"-+ c #7D7D7D",
";+ c #292929",
">+ c #505050",
",+ c #3D3D3D",
"'+ c #050505",
")+ c #090909",
"!+ c #757575",
"~+ c #E1E1E1",
"{+ c #929292",
"]+ c #515151",
"^+ c #0E0E0E",
"/+ c #CACACA",
"(+ c #2A2A2A",
"_+ c #202020",
":+ c #0C0C0C",
"<+ c #414141",
"[+ c #3F3F3F",
"}+ c #030303",
"|+ c #C9C9C9",
"1+ c #575757",
"2+ c #474747",
"3+ c #313131",
"4+ c #1C1C1C",
"5+ c #626262",
"6+ c #585858",
"7+ c #343434",
"8+ c #252525",
"9+ c #383838",
"0+ c #484848",
"a+ c #B2B2B2",
"b+ c #4F4F4F",
"c+ c #464646",
"d+ c #D8D8D8",
"e+ c #454545",
"f+ c #565656",
"g+ c #020202",
"h+ c #010101",
"i+ c #000000",
"                                                                                                                                                                                                                                                                ",
"                                                                                                                                                                                                                                                                ",
"                                                                                                                                                                                                                                                                ",
"                                                                                                                                                                                                                                                                ",
"                                                                                                                                                                                                                                                                ",
"                                                                                                                                        .                                                                                                                       ",
"                                                                                                                                      + @ # $                                                                                                                   ",
"                                                                                                                                      % & * # =                                                                                                                 ",
"                                                                                                                                    - ; > , * ' )                                                                                                               ",
"                                                                                                                                    + ! ~ { ] ^ / (                                                                                                             ",
"                                                                                                                                  _ : < [ } | | 1 2 3                                                                                                           ",
"                                                                                                                                  4 ! ; 5 6 - ] 7 8 9 0                                                                                                         ",
"                                                                                                                                  a b c 9 6 d # 3 e f g =                                                                                                       ",
"                                                                                                                                h i j k l m n o * 4 p } q r                                                                                                     ",
"                                                                                                                                s a t k l u v i w # l f x % y                                                                                                   ",
"                                                                                                                              . z a t d } A B C ] 3 : 8 D x <                                   r   E                                                           ",
"                                                                                    E F G ) H I H                             3 J + ; e [ p K L J 3 M D D N 9 :                                 O   ,                                                           ",
"                                                                                  @ P Q { { R S T U x 5 V W X                 M Q + t / Y Z `  .N 3 | e N ~ f } ..                            I H   +.                                                          ",
"                                                                              H m @.#.c Q F z i D $.%.$.C &.*.N R _         . W Q i =.g 9 m -.;.` M * >.~ D p 8 2 ,.                          ,     j ]                                                         ",
"                                                                            - C @.'.).!.~.+.F { F {.].&.n ^./.^.(./.p @     _ _.:.1 ; % p ~.<.[.}.|.] , Y p p ~ 8 >                           1.  2.|.P                                                         ",
"                                                                          j 3.@.4.;.[.5.5.6.a J F { d ].7.&.8.9.6.K /.0.S J s Q :.a.< % 7.b.c.d.e.f.^ g.1 Z ~ ~ D [ +                       E w   w q %                                                         ",
"                                                                        g h. .i.}.j.k.l.m.n.o.5 J J +.R p $.n 0.p.(.p.q.p.r.s.9 t.=.t D $.[.u.v.w.[.a.# G U x.y.U N ~ ,                     0 _   ^ 2 q |                                                       ",
"                                                                      =.z.A.}.B.<.k.C.n.D.E.E.F.U +.& z & 2 G.0.H.H.H.$./.r.I.B n g g S f.J.K.L.u.m.7.# 1.> 6 x.x.~.T 2                     , r   +.Y l &                                                       ",
"                                                                    M.N.O.4.P.j.k.d.l.Q.v.R.S.R.T.(.+ +.F z |.G.%.G.H.&.q.q.K K U.V.W.X.S.Y.Y.Z.K.v.;.' # & ].m ~.S A `...                O s I   a {. +k                                                       ",
"                                                                  I G.v @.}.B.<.5.l.T..+++J.@+S.S.#+h.k +.z F t A G.8.0.p.$+K N.6.V.%+e.&+*+Z.=+=+&+R.y.1.M S %.~.-+A ].T                 w P 2.H < {.q  +O                                                     ",
"                                                                  < $+V.A.'.<.;+c.T.m.v.@+u.S.++#+J.S.[.N F { { i p m n /./.$+p.(.I.>+,+n.K.'+Y.'+)+@+i.o # k !+].-+`.].&.Q               >.R ~+X g 2 / {+M.                                                    ",
"                                                                = m 9.]+A.-.B.k.c.T.m.v.@+u.u.++E.^+^+@+n.0.:.F J a.f !+8././.s.f.6.r.` '.v.Y.Z.'+'+&+m.|.] F `.$.`.%.n H.-+            , t.:.~+* } 2  +l a                                                     ",
"                                                                /+u /.V.@.4.).(+c.w.D.++S.J.u.D._+:+K.:+J.S.<+|.z Q :.q C 8.9.0.q.I.f.U.v [+R.Y.Z.}+Y.S.]+|+1.Z H.%.8.s.*.p.%           ; |.{ ~+G } 2 {+l |.                                                    ",
"                                                                  f /.1+2+4.3+[._+4+D.R.u.u.D.l.F.E.L.Y.Z.K.J.5.6 & Q +.c C 8.0.$+p.5+1+6+s. .u.Y.'+'+L.m.9.e Y 0.H.*.^.s.f.]+d       & % x - E J 9 2 {+Y {.y                                                   ",
"                                                                  W 7.v L X.7+(+8+c.E.@+#+T.5.F.9+C.^+Y.'+=+Y.:+E.N.& & & ! 6 s./.0.6.K (.(.5+9+E.&+*+Y.++@+D.[.L 7.0./.q.6.W.;.0.R y.>+~ ~.* X < Y 9 l 9 Y *                                                   ",
"                                                                    y.#.W.[+;.[.(+4+++Q.8+P.9+0+U.e.Y.L.J.K.'+=+Y.K.9+% a++.; m #.@.k.Q.m.E.D.4+4+E.:+&+J.J.^+J.:+;+v 6.B I.>+<.R.m.4.5.1+7.w I / x l {+2 2 >.                                                  ",
"                                                                    1.3.b+<+9+3+c.v.n.5.P.@.]+I.N.C.=+}+K.@+:+Z.Z.Z.L.l.!+< n 9+n.#+S.R.@+J.J.&+&+L.:+K.:+J.&+:+&+:+#+4.r.I.` [.u.D.).v.7+s.O ) l [ 2 2 2 9 V                                                   ",
"                                                                      U >+A.4.;+_+e.3+!.c+B p.6+-._+D.^+=+Y.Y.J.u.'+Z.@+_+7+w..+.+D.v.v.@+^+&+&+^+:+&+K.L.&+:+K.:+&+:+K.B.v W.).S.#+F.@+(+y.O * 2 } x f x } c                                                   ",
"                                                                      d+6+A.[._+k.!.<+0+>+3.e+ .'.P.j.;+c.J.:+@+w.n.v.D.w._+T.Q.Q.E.R.S.u.@+^+&+&+&+:+L.L.L.K.)+)+L.K.&+^+c.O.;.++.+k.:+[.t.2.o 9 x f x Y [ g                                                   ",
"                                                                        {+P.<.P.o.]+6+v f+]+h.h.2+A.A. .!.[.l.m..+F.'.k.5.C.l.Q.Q.E.v.@+@+u.&+&+K.:+K.K.K.L.L.L.L.L.K.:+u.J.w.7+#+4+l.J.k.V $ { {+[ f x 2 Y  +                                                  ",
"                                                                        w 9.(.r.f.6.6.6.r.6+V.f+b+b+>+W.c+ .i.j.j.i.'.3+(+5.8+l.T.#+E.@+u.^+L.Y.Z.)+L.L.K.L.K.L.L.)+)+:+K.&+^+D.m.d.n.S.S.m 2.a {+D [ f } [ 9                                                   ",
"                                                                    d+J / H.N.r.(.p.5+N.N.#.f+#.1+1+#.f+]+` 0+%+[+ .!.j.c._+4+v.S.@+^+K.L.L.)+Y.Z.Z.Y.)+)+L.K.L.K.K.L.K.K.:+J.^+@+8+Q.K.:+_++ d 8 p 8 8 D D D O                                                 ",
"                                                              ,.>.=.|.8 ^.r.f.5+5+6.f.#.f+B v N.v f.I.1+v f+U.A.5.C.4+D.u.:+L.)+)+Y.'+=+=+=+Z.Z.Y.Z.Z.L.Y.Y.L.)+L.K.u.:+:+K.^+K.:+J.&+:+&+u.9+x.D Z D } D y.~ )                                                 ",
"                                                        0 F ; e % f y.*.9.6.(.f.r.v B N.B I.v #.I.6.f.B I.v %+E.:+Y.Z.=+g+g+}+g+g+g+}+}+}+g+*+*+'+'+=+L.Y.Y.Y.L.Y.Y.&+:+:+)+K.K.L.:+:+:+:+J.&+A.x.y.f y.D f y.=                                                 ",
"                                                  3 z |.{+{. +{.f T ^.(.5+p.q.(.K $+I.f.K N.r.f.p.(.r.v 6+B B.c.B.}.'.'.F.m.u.)+Y.g+h+h+g+h+i+g+g+g+}+*+'+Z.=+Y.Z.Z.)+L.&+K.L.)+)+L.:+L.)+K.:+J.C p x.Z p x.Z I                                                 ",
"                                            3 :.|.2 l 2 l 9 x [ ~.~.9.5+H.$./.(.s.6 s.-+0.f.B 5+(.r.r.#.#.f.I.b+X.7+(+[.(+Q._+m.T.w.#+L.}+h+g+i+i+h+h+g+}+'+'+Z.=+Z.Y.'+L.L.)+Y.)+)+L.)+Y.)+Y.K.h.x.U U Z Z A 2.                            | |+                ",
"                                      , a. +x } D x 9 } 8 D ~.].9 8.n U T Z !+n u T A } 9.B 6+v 6+v U.6+f+ .F.o.I.5+^.S y.n V.O.n.:+L.u.@+)+*+h+h+h+}+h+i+h+g+'+'+=+=+Z.Z.Z.)+Y.Y.Z.Y.Y.Z.Y.)+L.D.G.Z S ~.A T                             3 / r                 ",
"                                # i x f } 2 q / / / > /  +2 e j & V + Q & Q a.j =.; b < % > {.2 Y [ Z -+S e { ^ o 4 V W ..' 4 a.d %.` 5.L.&+S.K.}+g+g+i+i+i+i+h+'+=+*+Z.=+=+Z.Y.Z.=+=+Z.Z.Z.Y.L.K.b+x.A -+$.!+                          ] |.g                   ",
"                    :./ {+9 Y 2 Y l  +{+{.g % / d b ; j ; ! ' { J :.+.z a+P Q +.+.& +.J >.s @ 7 M 7 ' ..J 4 F & @ ..s 4 s _.F + |.p N &.z.B.J.=+Z.h+g+i+i+i+i+h+h+}+h+*+'+'+'+=+Y.=+'+Z.Z.Z.Z.Y.)+d.m A C H.$+.                       h |./ !                   ",
"                  =./.0.!+m T D } {+ +q {.> l 5 b ; j t e a._.s s P :.V V 1 1 1 j 1 4 ' >.F 4 ' @ 7 ..{ & M # 1._ 3 ,.,.( 0 h :.j q } /.B v V.8+)+}+*+h+i+i+h+i+i+h+i+h+}+*+'+'+'+=+Z.Z.=+=+Z.Z.Y.K.r.$.s.f.]+|                     ' 5 e 5 {                   ",
"                ) 7+4+4+D.4+w.C.<.}.-.A.%+c+3.6+f.^.`.y.} 1 z & :.P R : t.R :.V F z a++.:.& P Q a+& P { # ] M s a++ 1 : d k 5 / e k =.{.!+3.,+A.;.@+g+g+h+h+h+h+h+h+h+h+}+}+g+*+*+'+Z.'+'+=+=+=+Z.Z.7+*.p.]+i.e                   G > |.% 5 -                   ",
"                  ^ W.Y.=+*+'+=+)+Y.Z.=+'+}+g+}+*+*+Y.J.R.F.B.F.P.4.-.9+4.%+]+3.]+L %+A.@.%+X.A.%+]+x.:.F a.t j t.j =.d 2 8 !+s.N.U.(.y.5 {.(.P.j.F.R.}+i+i+h+h+h+h+g+h+h+g+*+*+'+*+'+*+*+=+'+*+Z.=+@+$+f+[+[.h.            * r a+q {+g /  +w                   ",
"                      k l.*+h+g+*+'+*+}+*+}+h+h+g+h+g+g+g+}+*+}+*+=+=+=+)+@+T.#+w.P.!.4.P.J.m.A.'.^.{ + 1 P z :.V j b  +N m 0.r.1+]+2+%+3.7.[ `.o.E..+u.}+g+h+h+h+h+h+g+i+i+h+g+}+}+}+}+*+'+'+}+=+=+'+[+<+k.Q.m.0._         = ; {+q g g / 5                     ",
"                        d+f.K.g+}+}+g+}+*+}+h+i+h+i+h+h+g+*+g+h+*+g+=+*+Z.:+e.B.X.6+#.3.<+Q.4+z.z.c a & J Q a+a t > } Z G.*.(.6+V.b+z.z.O.@.z.H.%.<+u.:+)+*+h+i+i+i+i+h+i+h+h+g+g+g+g+g+}+}+*+*+'+=+=+d.3+D.++l.'.$.) .   O c }  +{.e % / ;                     ",
"                            + (+g+'+g+g+g+h+i+i+i+h+h+h+}+Z.=+}+*+*+Y.L.:+u.E._+S.l.T.@+&+:+&+w.]+=.Q z a+1 t e l D `.H.q.5+B 6+U.>+0+3.f+z.@.c+v s.!.Y.Z.Z.h+i+i+i+i+i+i+h+h+h+h+g+g+g+}+*+}+}+'+'+=+J.Q.u..+[.W.1.    d+k y. +{+ +2 > / F                     ",
"                                T m.}+g+h+i+i+i+h+h+i+h+}+*+Z.)+:+&+S.E.Q.4+8+C.E.@+)+&+^+D.E.Q.[+R a j d {.f U m %.s.p.K v b.]+z.U.>+` ]+f+V.` h.b.I.<.)+'+*+h+i+i+i+i+i+h+h+h+h+i+g+}+g+*+'+}+*+*+*+=+R.#+w.E.c     |+{.~ D 9  +l  +g > *                     ",
"                                  # X.=+h+i+h+h+*+)+}+}+Z.L.&+^+R.#+D.4+d.C.e.5.n.Q.n.T.w.c.8+<.A. + +x 8 Z m ].H.$+f.1+#.6+f+V.V.U.f+b.]+` >+f+` O.2+W.C.=+}+g+i+i+i+i+i+i+h+h+h+i+i+i+g+*+*+g+}+}+g+*+v.w.K.L.z   _ x [ N x {+l l  +{.>                       ",
"                                    ] n.h+h+h+h+g+*+*+*+)+&+^+S.#+.+4+w..+D.4+.+u.d.[.B.F.'.!.[+c+).l.).s.8.q.p.5+K N.B 1+1+U.6+B 1+6+b.b.]+W.W.z.h.A.[+X.m.g+g+g+i+h+h+i+i+i+i+i+i+i+i+h+g+g+h+g+g+h+g+'+Y.'+'+T | 9 D 2 p {.{.2 x {.g =.                      ",
"                                      $.g+h+h+h+h+h+'+Z.L.&+^+J.J.S.@+&+)+)+Y.)+L.;.4.%+2+3.O.]+1+d.Q.` 5+N.v #.v I.v #.1+1+U.U.6+I.U.3.z.V.]+h.L h.,+4.!.).^+h+h+h+}+g+i+i+i+i+i+i+i+i+i+h+h+i+h+h+i+g+g+*+Z.Z.;+y.[ N p [ l 2 {+9  +{+-                       ",
"                                      c }+h+h+h+i+h+*+'+=+Z.'+'+'+'+*+'+g+}+}+}+_+c+O.z.U.v #.B N.B ^.r.b.>+b.]+b.1+#.v 6+1+f+>+]+b.f+3.3.>+V.3.e+e+c+4.).7+8+'+i+h+h+h+i+i+i+i+i+i+i+i+i+h+h+i+h+g+h+h+g+*+}+'+&+q.~ p 8 2 f 2 Y  +{+x .                       ",
"                                      [ g+i+i+i+i+i+i+h+h+i+i+i+h+i+h+h+g+g+}+d.b+b.f+#.6.5+r.r.K {+  w ; s.V.b.U.U.B B f+b.b.z.b+]+z.0+>+b+L h.2+A.[+o.P.).j.v.g+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+h+h+h+h+i+g+*+*+:+n y.8 2 Y } x x [ l <                         ",
"                                    E 7+h+i+i+i+i+i+i+i+i+i+h+g+g+g+g+*+'+*+T.]+B N.K K (.q.9.v r.$.        , U N.V.U.f+b+O.>+V.z.2+2+e+b+>+h.2+2+%+4. .i.'.).C.Z.i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+h+h+h+i+h+g+}+}+++y.[ f p 8 f f 9 Y l /+                        ",
"                                  g.W.Z.g+h+h+h+i+h+h+h+g+}+*+'+Z.Z.Z.Y.L.@+3.B p.f.5+$+0.s.p.q.9.0.1.          M ].>+>+>+3.` h.%+%+e+@.O.` L %+%+<+,+'.-.6+F.;+@+h+i+i+i+i+i+i+i+i+i+i+i+i+i+i+h+h+h+h+h+}+*+*+E.S N [ 8 } D 8 8 {.e                           ",
"                            s C ,+@+=+=+*+}+'+}+*+Z.Z.Z.K.&+:+@+S.S.S.R.R.'.r.r.N.1+I.5+q.5+f.p.$+p.|.              k f+W.O.h.A.X.@.h.e+@.%+h.@.[+X.4.!.-.,+P.(+w.*+i+i+i+i+i+i+i+i+i+i+i+i+i+i+h+h+h+g+i+h+g+}+_+N y.p p x.8 Y } 2 G                           ",
"                        4 -.*+*+*+Z.Y.L.L.K.&+J.@+++S.E..+#+E.4+Q.n.l.e.(+b+f+>+V.1+N.(.6.6.(.q.(.6.!+                @ r.e+9+X.@.<+@.%+[+A.o.<+[+ .4.}.7+7+'.[.8+J.h+h+i+i+i+i+i+i+i+i+i+i+i+i+h+h+h+}+h+h+g+}+l.S x.N 8 D N ~ 8 Y                             ",
"                      x.S.*+=+Z.L.:+^+R.E.Q..+w.n.l.8+_+5.k.8+8+(+j.<.j.7+f+v 3.` >+I.(.9.5+5+B B K I.o                 | v A.o.o.X.X.,+X.,+X.[+X. .4.P.;.<.3+<.8+4+'+h+i+i+i+i+i+i+i+i+i+i+i+i+i+i+i+h+h+g+g+}+F.m Z D N p N p p s                             ",
"                    K Z.*+Y.L.&+S.v.E.w._+C.8+5.e.;+B.[.F.B.B.).).'.-.,+<+6+6+v I.r.r.(.9.N.v 6.5+q. +d+                  w f.c+A.<+X.,+ .i.X.,+X.4.}.}.;.j.(+3+e.l.&+g+h+i+i+i+i+i+i+i+i+i+i+i+i+i+i+h+h+g+g+*+%+~.x.x.-+x.U U  +                              ",
"                E O.'+Z.L.&+^+@+v.Q.l.l.5.;+j.[.j.F.).3+;.'.'.}.9+ .%+o.O.#.B N.(.I.6.(.N.N.5+(.$+a ( X                     1.#.A.[+[+,+'.9+4.}.}.-.}.;.).[.j.3+<.l.R.'+i+i+i+i+i+i+i+i+i+i+i+i+h+h+h+h+h+g+}+*+V.m -+x.-+Z S D r                               ",
"                >+)+Y.K.u.S.@+#+T.T.d.k.[.F.).).).;.P.7+9+ . . .[+@.A.i.V.1+I.6.q.5+5+B N.p.9.*.R X I I                       ..2+o.[+!.;.7+9+'.!.i.9+7+3+(+j.3+j.T..+L.h+i+i+i+i+i+i+i+i+i+i+i+h+h+h+h+h+g+Z.)+f.C u -+x.Z N '                                 ",
"              r.)+)+&+J.++v.E.w.n.C.e.<.B.).3+;.3+P.9+4.4.-.i.A.%+X.,+ .b.v p.9.6.B v I.5+5+/.+ | ) ) ~+$                       {.o.%+'.7+7+'.}.9+4.!.P.7+).<.j.j.n.m.&+}+i+i+i+i+i+i+i+i+i+i+i+h+h+h+h+h+g+'+@+*.].!+m A S i                                   ",
"            6 Y.)+^+u.S.#+.+T.n.l.5.(+<.B.3+).7+}.9+!.-.!.i.<+%+[+4. .A.B I.K K 6.K N.K (.G.4 r , 0 ) $ I                         q.A. .'.;.P.P.P.}.!.'.).3+<.;+F.c..+J.'+i+h+h+i+i+i+i+i+i+i+i+i+i+i+h+i+h+g+n.8.^.C m C x                                     ",
"          a.^+Y.:+@+S..+w.n._+8+5.8+(+F.B.F.j.;.}.'.'.9+P.}.<+i. .4.7+A.K f.K #.f.N.B #.].M I r ( ( X ~+                          G e+ .-.}.B.3+;.P.'.}.B.).(+5.;+5.m.S.Z.h+h+h+h+i+i+i+i+i+i+i+h+h+h+h+h+g+}+(+r.(./.0.^.J                                     ",
"        ] C.)+:+^+++#+4+n.d.C.(+[.<.F.;.7+;.).7+'.}.'.9+}.;.9+7+X.X.}.[+N.1+6+6+U.6+B -+h ( X ) ) 0 $                               A i.9+}.F.F.3+7+;.3+F.j.e.C.8+e.Q.D.J.g+h+h+h+i+i+i+i+i+i+i+h+h+h+h+h+g+'+P.[+h.z.I.K X                                     ",
"        b.Y.&+@+S.E.w._+n.l.5.(+j.B.P.P.;.7+}.-.'.4.!.!.'.!.4.-.i. .-.X.U.V.f+f+V.U.p | X I ~+$ r >                                 ] e+4.7+F.<.B.3+).P.3+F.;+8+C.8+m.T.D.}+h+h+h+i+i+i+i+i+i+i+i+i+i+i+i+h+)+_+v.F.!+D g X                                     ",
"      c &+K.&+S.++Q.n.l.l.8+k.<.F.;.}.!.B.;.}.7+4.-.-.P.3+9+9+-.,+4.X.%+V.f+#.V.1+p | I I O ~+( p W.:.W                               ^.9+7+B.<.B.).).).j.<.;+c.C.c.Q.n.k.=+}+h+h+i+i+i+i+i+i+i+i+i+i+i+i+h+@+5.m.&.0 _ $ ) d+( O 2.E I O H                     ",
"    g l.:+:+++R.D.T.l.c.8+e.e.[.j.F.).7+(+P.9+-.X.,+i.4.!.}.;.4.,+A.i.[+z.U.]+V.x w ( ( = $ w %. .!.<+` 8                             J 4.P.F.F.F.B.j.<.F.<.;+c.d.d.n._+P.:+=+g+i+i+i+i+i+i+i+i+i+i+h+i+i+h+)+^+Y.F ( d+0 ,.h h g.^ |+_.>.& + R i a.R < b % g.  ",
"  7.<.;+w.R..+#+E.#+w.d.c.e.8+e.[.j.j.).B.;.9+4.X.X.'.9+'.9+}.A.X.i.). .>+b.V.2 0 ( d+) $ | q.7+P.i.<+` #.i                           . 3.7+3+<.j.F.j.<.<.;+k.C.l.8+C.c.A.v.L.}+i+i+i+i+i+i+i+i+i+i+}+i+i+h+h+*+.+1 : q q 8 S Z n m S `.$.H.G.!+G.].~ ~ 2 g     ",
"  r.<+W.z.` 2+!.l.n._+T.n._+l.C.8+5.(+[.F.).;.'.4.,+i.[+!. .'.,+X.'.7+4.0+B : ] $ d+1.* W 6.F.7+}.A.2+O.b.I.7                           !+P.B.(+[.j.(+e.[.k.5.5._+8+;+8+[+C.J.'+h+i+i+i+i+i+i+i+i+i+h+i+i+h+g+'+#.Z 7.0.$.&.].!+&.C ].&.7.8.].`.A U {.~ D d+    ",
"  ^.e+O.b.#.r.f.N.6.#.>+o.'.).e.5.k.k.k.k.k.8+[.).j.;.P.F.P.}.i.'.B.<.).U.z w o ( = 3 ' V.<.j.).[+h.>+>+b+]+I.,                         ; }.j.(+;+[.[.(+(+e.e.8+_+5._+;.O.3+u.=+h+i+i+i+i+i+i+i+i+i+i+i+i+h+h+S.*.n s.n 8.!+u $.H.8.^.$+*.`.6 T Z D {.D ,       ",
"  X F / ].I.N.I.p./.^.!+u A `.%.0.(.z.0+9+P.B.j.j.[.j.(+<.[.8+c.C.c.w.c.N r @ Q 1.d+& z.}.).F.;.%+L ]+V.>+2+V.f.h                       |+,+3+(+(+[.(+(+;+;+5.k.k.e.C.o.v '.T.)+h+i+i+i+i+i+i+i+i+i+i+i+i+h+}+@.C S ].6 S ~.~.u `.A m T x.x.y.x.} f U #         ",
"            ] P Y G.0.&.`.A -+T y.N 8 D y.Z m $.p.6+c+ .!.).(+e.Q.m.c.,+Q w @ { ,.:.U.X.9+;.j.9+e+3.>+z.3.e+h.h.z.@                     E o.).[.[.[.<.[.(+[.;+;+(+j.c.f.s.e+'.)+g+i+i+i+i+i+i+i+i+i+i+h+h+}+m.n `.y.T Z N 8 x.-+x.[ y.x.~ [ 8 9 Y y./+          ",
"                    H M.t.{+y.~.y.N 8 D p [ [ 2 2 8 ~ D N N S m 8.$+f.2 X | w r 1 o.).3+j.C.l.P.<+3.b.` ]+` 0+c+W.6+Q                     3.B.(+(+[.<.[.[.<.F.j.F.7+).y.(.%+,+*+g+h+h+h+h+h+h+h+h+h+h+g+}+m.7.6 %.S Z f x.y.D D U ~ f ~ x x f l 8 g.            ",
"                              6.-.W.p.8.-+[ Y {+l x [ p y.x l {./ q g k w w d+ +7+d.d.4+Q.S.@+C.@.2+e+L b+V.]+L ]+U.]+8                   #.).<.(+(+[.(+j.).;.P.}.j.O./ 1+2+-.}+}+h+h+h+h+h+h+h+h+h+h+h+^+/.6 T Z x.U x.Z Z N D N } } x } f } 8 ^               ",
"                              A.*+*+=+)+++d.7+e+6+*.-+y.f l  +{+l l {./ G * x.w.^+L.)+Y.Z.*+'+E.%+o.c+2+W.]+>+>+V.W.0+O.!+                f.).[.[.j.F.B.;.'.4. .X.<.`.> #.>+[.g+g+h+h+h+h+h+h+h+h+h+h+'+L `.6 S U Z U y.Z y.N D 8 p 9 f l f m |+                ",
"                            V Z.g+i+i+i+h+g+h+i+h+i+=+K.#+n.;.@.z.(.*.T % C L.}+g+g+h+h+h+g+'+T.%+@.%+0+c+W.` ]+O.,+>+3.].=               I.).B.).;.7+9+X. .e+L 2+,+c [ #.(.#+*+h+i+h+h+i+i+i+h+g+}+*+h.C `.u u ~.x.f N ~.~.U p [ f } f 9 f ^                   ",
"                            4.g+g+i+i+i+h+*+h+h+i+g+g+}+g+}+i+h+g+g+'+K.D.&+}+g+g+i+h+g+}+=+Y.T.%+@.e+%+e+o.0+z.c+X.W.>+x O ~+            1+P.;.'.-.4.@.2+O.b.B A.q.t.(.#.1+Z.Y.h+i+h+h+i+i+h+h+g+'+}.7.n -+-+C A U } y.~.N N y.~ } } 9 p M                     ",
"                          t Z.g+g+i+i+i+i+h+i+h+h+i+i+h+g+h+}+h+h+g+}+g+}+g+g+g+*+*+'+*+=+:+L.m.o.c+@.A.c+2+L 3.o.` b.3.c ~+E ~+          z.9+9+X.%+h.z.b.6.q.N.e+|.m 0+I.j.K.)+h+i+h+h+i+h+h+h+*+}.^.H.s.*.A T 6 U U p S p p p Y [ g } ^                       ",
"                          ,+h+g+h+i+i+i+h+h+i+i+i+i+i+g+g+h+h+h+g+g+}+Z.Z.Z.=+L.L.^+L.:+J.R.++w.A.2+O.e+e+h.h.c+;+c+V.3.a.~+E I         I O.[+o.h.V.B f.8.].$.A.A D [+L K L.Z.h+i+i+i+h+h+}+}+=+).0.^.$.(.!+!+%.C `.T m S p } x > R 2 g.                        ",
"                        s :+i+i+i+h+h+h+i+i+i+i+h+i+g+g+}+*+*+=+K.L.K.K.^+&+S.++S.++++.+n.4+w.n.A.%+A.<+e+@.2+@.8+7+h.]+J X I I         G h.O.]+B p.&.`.Z Z q.B U 0+%+/.;+Z.Y.h+h+h+g+h+*+*+K. .{++.Z /.n $.8.C m -+m ~.x.~ ~ =.a+2 *                           ",
"                        s.g+h+g+g+g+}+}+g+g+g+g+*+}+=+K.Y.Y.:+J.v.#+m..+.+m.4+n.Q.Q.D._+_+8+C.d.X.<+<+c+O.c+0+<+n.8+9+6+M X X $ d ]     c b+1+p.^.C N 2 {+^.z.$+h.;.U.O.'+@+}+g+h+g+g+}+*+=+@.J # , o k $.^.7.&.%.].C `.N {.+ V > w                             ",
"                        ;+g+g+'+=+Y.Y.Y.Y.Z.=+Z.Y.=+K.&+&+^+@+D.4+E.D.Q..+n.c.d._+_+d.C.c.(+B.5.P.` %+2+h.L W. .<.l.%+r.| X ~+X f.]+s.: /.6+s.C Z {+5 d m s.%.I.i.W.O.&+)+Z.*+}+}+}+*+'+Q.b+7.{+G | * /+' 9 /.*.$+n U 5 P 7 R ~ d+                              ",
"                      # Y.}+'+Z.Z.Z.)+:+:+:+&+^+^+^+@+u.D.S.v.Q.T.T..+c.d.C.C.c.d.c.;+;+5.k.[.k.(+<+2+h.2+O.L o.!.c+3.^.d+X $ | ]+L o.<+[+%+6+^.D < ; D 8 t -+#.f+b+D.'+Y.h+}+}+*+L.;+0+$+*.9.^.n V ,.w | , b ].%.2 a.z @ 1 8 r                                 ",
"                      ! *+'+Z.Y.Y.:+&+u.J.J.++v.E.m.D..+D.++D.D.m.T.T.8+5.5.8+C.k.e.k.<.k.k.(+F.[.X.@.b+O.` W.` P.%+W.%.) X = 7 W.[+X.<+,+X.@.A.o.b+V.` &.&.f ~ N '.Z.@+*+}+Z.R.j.1+&.H.H.9.$+9.I.s.~ |+| * # @ j i >.@ d Y $                                   ",
"                      7.*+=+Y.K.&+J.&+@+S.++#+D.m.m.T.T.n.w.T.d.n.d.l.8+5.;+k.e.<.[.;+<.j.;.F.;.j.L ,+` ]+3.b+3.A. .` 6 = ( _ Q W.@.c+e+%+%+o.@.c+@.2+<+A.[+a+| w i k.#+;+4.O.v B 5+0.s./.q.8.$+f.I.5+$.i w ,.] 1.- @  +2 .                                     ",
"                      W.Y.Y.)+J.J.S.v.v.R.v.Q.n.n.T.d.d.C.d.C.5.C.[.c.;+[.<.(+(+<.j.F.[.<.F.<.j.3+^.%+2+` ` 3.L 2+9+h.Z ,.3 r t 0+W.e+c+@.@.<+ .c+@.c+@.<+[+x.] * /+D b.1+#.V.6+6+I.$+p.9.5+/./.$+6.N.q.8.{.1.w # ,.g.;                                         ",
"                      -.)+)+K.^+R.++m.m.Q.k.w.T.l.8+c.C.k.e.C.e.k.[.e.;+<.F.'.F.F.B.F.B.B.P.B.).P.&.p.e+` W.O.c+@.<+!.x 3 , d+l 0+L <+o.X.,+,+o.e+c+e+2+2+A.6+- g.h { 5+#.N.B 6+K B $+p.q.^.0.n p.$+(.5+/.&.`.z _ w w d+                                        ",
"                      e.)+)+&+^+v.E.m.Q._+Q.#+w.n.5.(+5.5.(+(+(+;+;+;+[.).3+3+;.).3+F.P.;.9+7+'.'.L &.V.3.W.O.0+[+<+4.|.3 ] = Z ` 2+%+i.3.%+-.,+X.o.%+0+h.c+O.{.w ] ,.x 5+6.v I.5+N.9.9.^.s.7./.q.$+*.5+K $+7.%.> h ,.r w $                                     ",
"                      _+L.^+^+&+v.D.T.w.T.#+4+c.C.8+j.(+;+;+F.[.[.(+[.j.3+j.3+}.3+7+P.).}.9+}.}.!.!.1+n 2+b+h.e+X.A.X.+ * _ r &.<+o.@.4.b.i.(+!.9+A.A.@.2+h.o.0.^ ] ,.7 ^.p.f.K I.r.6+(.7.$+q.(.^.s.s.s.0.q.9./.(.!+R 3 r 0 *                                   ",
"                      l.&+J.J.++E.E.n._+#+R.w.8+;+;+e.(+;+(+j.;+j.F.j.j.B.;.3+7+j.j.).B.}.9+}.}.7+B.}.W.i.o.0+X.X.%+e+{ 3 r w s.<+3+7+ .W.i.).-.<+@.c+L L W.@.3.q # | * g 9.f.I.6.9.K /.(.p.6.s.s.*.q.s.s.8.8.H.*.8.0.8 W d+| ( O                               ",
"                      l.u.@+^+++D.4+n.l.w.Q.8+E._+5.e.(+B.;+j.e.;+F.B.k.j.F.;.;.B.9+B.<.7+'.-.'.9+P.).;.}.4.2+c+i.%+h.- * w # O.3+C.n. .A. .o.i.o.,+%+h.W.` L W.(.- g., s p.(.p.K 9.p.(.p.0.q.0.*.0.*.$+/.!+7.8.n &.H.^.H./ /+) X X                             ",
"                      k.++++++m.4+m.T.l.d.c.5.8+8+(+[.(+[.<.B.F.[.B.3+;.j.P.P.7+}.3+B.).-.!.i.i.9+!.P.P.!.). .O.X.e+1+, ] _ W j.R.J.u.i. .4.[+-.,+O.[+e+@.L W.e+0+d ] 3 _.[ 6.p.r.6.6.6+p.$+s.p.q.p.0.H./.s.8.&.^.s.7.7.8./.].P ) E d+O                         ",
"                      ;.R.v.v.Q.l.n.c.C.;+c.n.k.;+).B.).B.(+P.7+'.;.P.3+}.'.!.9+'.<.).}.9+!.i.i.X.,+i.!.9+3+7+A.[+@.^.0 0 d+Q <.d..+T.<.9+[+e+!. .L 2+o.2+W.` W.2+5+h 3 1.' r.0+V.5+(.B (.I.p.f.p.s.p.q.q.f.q.5+6././.9.n q.8.&.{+] $ X 2.                      ",
"                      c+#+Q.D.4+C.c.C.k.j.;+d.;+).;.F.<.;.B.P.}.3+3+7+P.9+-.i.9+-.;.9+3+7+4.i.i.[+-.!.9+[+'.P.;.X.%+C = X = 1 B.<.B.j.B.F.).,+i.9+%+o.%+@.h.h.L o.3.e # , | ~.).'.W.6.5+q.I.I.f.K 5+f.B 9.K 5+f.B q.^.0.9.^.%.H.*.C < d+                        ",
"                      v m..+E._+C.d.5.e.[.j.[.[.j.j.).P.j.<.7+ .).j.3+}.}.;.9+ .9+;.4.-. .-.4.4.A. .!.,+A. .j.B. .A.8 I I O c -.!.!.X.4.F.).B.'.-.[+4.@.%+2+c+O.2+e+(.a+# w 4 ` >+z.U.I.N.5+5+v 9.B N.#.9.6.K (.f.^.H.s.H.6 7.#.b.1+e                           ",
"                      I.++E.#+l.8+c.k.C.5.(+F.;+(+P.).P.'.3+}.9+3+B.7+F.3+P.!.4.!.P.4.-.-.,+9+-.X.i.X.A.<+9+F.4.4.-.e I O I Y o.X. .%+[+ .j.<.i.F.i.4.%+c+0+` W.` 3.c+{+] r _ 2 5+s.^.8.8./.q.p./.9.p.$+$+/.^.!+6 Z D } ~.9.W.z.%.g.                            ",
"                      d.Z.Y.=+L.&+S.v.Q.d.T.8+8+e.j.[.B.;.P.i.;.'.7+;.3+'.9+'.i.9+!.i.i.i.i. .i.X.4.i.4.!.;+(+<.[.e.! = ( d+u e+A.<+c+c+X.4.j.'.}.[+,+[+<+2+h.` b+z.h.6+' 3 d+7 n &.n G.!+u m u A ].].S y.D D [ [ N T &.5+#.f.a.                                ",
"                    F 8+R.u.)+Y.=+Z.L.:+^+^+S.@+R..+R.E.E.4+m.m.m.4+n.4+4+m.T._+d.T.l.c.c.l.d.m.n.w.8+c.C.S..+w.T.5.j $ ( * /.2+O.h.O.W.[+o.i.7+'.'.i.-.,+%+c+o.3.b+W.b+l w 3 w {.&.!+G.m ~.Z N y.8 ~ p y.p ~ D S $.9.f+b.T 0                                   ",
"                      m G.H./.f.U.0+ .).k.n.w.T.D..+v.@+J.#+@+u.u.++Q.u.@+^+++++m.R.m.w.S.^+@+J.J.S.++_+(+w.m.d.(+B.q X ) 3 q.b+3.>+W.0+0+[+[+X.<+F.;.-.<+,+h.X.e+2+2+` 1+- * 1.' A `.A 6 Z x.U D 8 ~ } N [ U `.$+U.]+7.'                                       ",
"                      W !+A Z U p ~ f x } [ N x.T A ].s.$+p.I.b.U.z.f+3.>+W.O.O.>+b+U.f+1+b.U.z.z.#.K 9.0.H.].~.Z x.g @ _ g.K z.O.]+>+L W.O.0+2+o.0+@. .!.e+%+,+[+<+9+e+2+x 3 3 ,.d -+Z S U 8 N [ D 8 8 p A 7.6+>+I.k                                           ",
"                        3 h G :.j k g {.2 {. +q g 5 |.e e |.; |.; t t.; =.j t j j j j ; j t.; ! d b |.d |.|.% e |.U ].{+; +.#.V.V.>+>+3.3.]+b+]+O.W.>+L [+i.<+[+A.X. .9+9+W.G _ r /+~ N ~ x.D N f ~ N T &.f.1+#.8 X                                             ",
"                                            E ) 3 ^  +G.6 N [ } l {+q 5 e % / e e % / / / q 2 } f Y [ ~ y.T m !+G.0.K K r.N.6+f+z.b.>+` >+` V.U.f+1+f+]+f+V.%+;.i.-.F.;. .,+S _ 0 = b D y.x.x.D N ~.!+(.>+` C o                                                 ",
"                                                    V ;+<.F.).;.!.i.,+e+h.e+2+O.W.h.h.h.O.O.O.2+h.O.3.b+3.O.O.O.O.` 1+V.f+6+f+1+B f+>+]+V.z.z.>+V.#.B b.V.V.f+L o.9+B.[.j.P.@.s ,.d+o 8 p y.N S m s.#.]+q.:.                                                    ",
"                                                    H 4.[.<.<.B.P.).7+}.}.i.,+,+,+<+[+%+%+%+e+2+W.W.3.W.]+V.z.z.z.V.V.6+#.U.U.b.b.b.b.U.U.z.>+z.O.>+f+v U.U.B f+1+z.` ,+7+<.j.0.w 0 r =.p x.m n N.z.#.|..                                                       ",
"                                                      C ).P.;.}.4.!.,+ .X.X.A.o.e+2+e+c+0+h.e+0+O.3.3.O.b+U.z.U.v f+b.b.B N.U.V.>+b+z.f+f+>+v >+]+b.f+v 6+N.v v v 6+6+` [+4.9+<+P X ) |+y.*.N.z.6.g I                                                           ",
"                                                      M.'.).;.9+,+,+-.,+A.[+%+%+c+c+h.L ]+3.0+O.>+b+z.>+>+1+U.1+I.I.f+b.]+1+V.U.W.3.b+f+b.b+U.f+1+#.f+V.1+6+K v v v z.0+P.;.}.;.r.w I w 9 #.f+~ d+                                                              ",
"                                                        0.i.4.i.o.o.o.o.%+e+@.c+L O.3.o.>+>+z.]+z.>+b+z.z.#.#.1+U.B 1+` O.L b+f+1+1+V.6+b+f+1+6+N.U.1+v f+v N.K z.>+@.).5.w.d.8+P.b | , z Z ,                                                                   ",
"                                                        o o.<+[+e+@.0+0+2+2+O.]+3.W.>+c+b+V.b+>+z.]+z.U.b+b.V.#.]+b+I.r.U.1+1+f+v v #.r.f+b.B f+B #.U.B V.U.]+i. .'.B.e.c.[.9+V.N k l b |                                                                       ",
"                                                          %.o.o.@.h.0+h.W.W.z.>+>+>+>+` 3.z.%+W.3.f+]+f+b+f+f+1+1+b+N.r.N.V.N.N.f.v I.B f+V.V.f+3.b.3.2+ .,+;.;+B.j.P.o.$+9 ; q U } ^                                                                           ",
"                                                          | L >+o.c+L O.` 0+]+z.` L >+>+b+z.V.V.I.6+1+B #.v I.b.1+z.N.f.K f+]+1+N.#.f+v f+b.z.L %+!.F.j.;.B.;+}.3.].k 1 % 6 /.x.o                                                                               ",
"                                                            g 0+L O.O.O.b+>+0+]+]+3.b.]+]+U.1+]+U.6+1+f+6+6+v 6+f+N.U.#.I.6+v N.B 1+3.2+o.'.).B.F.P.3+P.L /.f t 1  +%.r.I.x.M.                                                                                  ",
"                                                              I.W.O.O.b+` b.V.b+]+>+U.b.f+U.f+#.6+v f+1+1+#.v 6+#.f.B v U.b+>+O.[+!.7+[.;.F.F.7+@.q.D ! a.; [ `.5+v r.U /+                                                                                      ",
"                                                              h L >+W.]+V.>+6+]+U.V.1+6+#.U.6+#.#.v #.#.f+1+V.f+>+>+` <+9+B.;.7+3+!.}.4.h.f.N c a t.% D C 0.p.v r.} *                                                                                           ",
"                                                                > >+b.b.]+V.V.f+V.6+6+#.B 6+B #.1+f+V.V.L <+-.,+-.).'.'.7+3+'.e+#.$.l t a : d x T G.7.6.6+V.q./ d+                                                                                              ",
"                                                                  ~.f+#.f+1+>+z.b.U.b+z.>+b+c+e+e+i.X.X.}.!.,+4.i.,+<+z.^.p |.a ' ] /+1 q 8 y.].^.#.b.#.^.! ~+                                                                                                  ",
"                                                                  2.r.@.c+0+2+o.A.X. .}.9+B.}.P.4.;.P. .o.0+r.%.[ b +.7 ] X               0 p 9.f.I.!+{                                                                                                         ",
"                                                                    N '.[+[+,+[+[+,+7+P.-.[+o.V.(.H.Z {.=.+..., $                           $ Z ~ M.                                                                                                            ",
"                                                                    7 [+@.e+2+>+f.n `.x.9 k ; P ' h 0 H                                                                                                                                                         ",
"                                                                      a+c c R a+z s - /+r y                                                                                                                                                                     ",
"                                                                          )                                                                                                                                                                                     ",
"                                                                                                                                                                                                                                                                ",
"                                                                                                                                                                                                                                                                ",
"                                                                                                                                                                                                                                                                ",
"                                                                                                                                                                                                                                                                "};

/* *INDENT-ON* */

#endif