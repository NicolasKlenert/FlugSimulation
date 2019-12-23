#include "../Graphics/gl_headers.h"
#define EIS1

GLubyte bigStrip[] = {
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

GLubyte smallStrip[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

// Outer frame vertices
// Drawn oversize
GLdouble rect[4][3] = {-1000,-1000, 0,
                        1000,-1000, 0,
                        1000, 1000, 0,
                       -1000, 1000, 0};

#ifdef EIS2
GLdouble speedRect[4][3] = {-372,-203, 0,
                            -372, 203, 0,
                            -290, 203, 0,
                            -290,-203, 0};
GLdouble headingRect[4][3] = {-192,-357, 0,
                              -192,-302, 0,
                               137,-302, 0,
                               137,-357, 0};
#elif defined EIS1
GLdouble speedRect[4][3] = {0,-200, 0,
                            0, 200, 0,
                            82, 200, 0,
                            82,-200, 0};
GLdouble speedFrame[4][3] = {0,-200, 0,
							0, 200, 0,
                            100, 200, 0,
                            100,-200, 0};
GLdouble speedMask[4][3] = {0,-200, 0,
                            0, 200, 0,
                            111, 200, 0,
                            111,-200, 0};
GLdouble headingRect[4][3] = {-173.2, 0, 0,
                              -173.2,55, 0,
                               173.2,55, 0,
                               173.2, 0, 0};
GLdouble vsiMask[4][3] = {297,-200, 0,
                          297, 200, 0,
                          329, 120, 0,
                          329,-120, 0};
//GLdouble altMask[4][3] = {192,-200, 0,
//                          192, 200, 0,
//GLdouble altMask[4][3] = {187,-200, 0,
//                          187, 200, 0,
//                          254, 200, 0,
//                          254,-200, 0};
GLdouble altMask[8][3] = {187,-200, 0,
                          187, 200, 0,
                          254, 200, 0,
                          254,  35, 0,
                          292,  35, 0,
                          292, -35, 0,
                          254, -35, 0,
                          254,-200, 0};
//GLdouble altBoundary[4][3] = {altMask[0][0], altMask[0][1], altMask[0][2],
//                              altMask[1][0], altMask[1][1], altMask[1][2],
GLdouble altBoundary[4][3] = {192,-200, 0,
                              192, 200, 0,
                              285, 200, 0,
                              285,-200, 0};

GLdouble innerMask[6][3] = {-198.2, 180.0, 0.0,
							 -95.0, 220.0, 0.0,
							  45.0, 220.0, 0.0,
                             148.8, 180.0, 0.0,
                             148.8,-200.0, 0.0,
                            -198.2,-200.0, 0.0};
#endif
