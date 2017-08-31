#ifndef __CPP_SVG_HELPER_H__
#define __CPP_SVG_HELPER_H__

#include <utility>
#include <vector>
#include <cmath>

#include <stdexcept>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>

namespace SVG {
  class Colour {
    public:
      int red, green, blue, alpha;
      Colour(int r, int g, int b, int a = 255);
      Colour(int r, int g, int b, float a);
      std::string toHex();
      std::string opacity(int decimalPlaces=3);
      std::string toRGBA(int decimalPlaces=3);
  };
  
  class SVGWriter {
    public:
      SVGWriter(std::string filename, int w, int h);
      void writeHeader();
      void inject(std::string xml);
      void startDefs();
      void endDefs();
      void drawRect(int x1, int y1, int x2, int y2,
                    std::string style);
      void drawRect(int x1, int y1, int x2, int y2,
                    Colour fillColour,
                    Colour strokeColour = Colour(0,0,0,0),
                    int strokeWidth = 0,
                    std::string extraStyle = "");
      void drawRoundedRect(int x1, int y1, int x2, int y2,
                           int rx, int ry,
                           std::string style);
      void drawRoundedRect(int x1, int y1, int x2, int y2,
                           int rx, int ry,
                           Colour fillColour,
                           Colour strokeColour = Colour(0,0,0,0),
                           int strokeWidth = 0,
                           std::string extraStyle = "");
      void drawCircle(int cx, int cy, int r,
                      std::string style);
      void drawCircle(int cx, int cy, int r,
                      Colour fillColour,
                      Colour strokeColour = Colour(0,0,0,0),
                      int strokeWidth = 0,
                      std::string extraStyle = "");
      void drawEllipse(int cx, int cy, int rx, int ry,
                       std::string style);
      void drawEllipse(int cx, int cy, int rx, int ry,
                       Colour fillColour,
                       Colour strokeColour = Colour(0,0,0,0),
                       int strokeWidth = 0,
                       std::string extraStyle = "");
      void drawLine(int x1, int y1, int x2, int y2,
                    std::string style);
      void drawLine(int x1, int y1, int x2, int y2,
                    Colour strokeColour = Colour(0,0,0,255),
                    int strokeWidth = 1,
                    std::string strokeLinecap = "butt",
                    std::string extraStyle = "");
      void drawPolyline(std::vector<int> x, std::vector<int> y,
                        std::string style);
      void drawPolyline(std::vector< std::pair<int,int> > points,
                        std::string style);
      void drawPolyline(std::vector<int> x, std::vector<int> y,
                        Colour fillColour,
                        Colour strokeColour = Colour(0,0,0,255),
                        int strokeWidth = 1,
                        std::string strokeLinejoin = "miter",
                        std::string extraStyle = "");
      void drawPolyline(std::vector< std::pair<int,int> > points,
                        Colour fillColour,
                        Colour strokeColour = Colour(0,0,0,255),
                        int strokeWidth = 1,
                        std::string strokeLinejoin = "miter",
                        std::string extraStyle = "");
      void drawPolygon(std::vector<int> x, std::vector<int> y,
                       std::string style);
      void drawPolygon(std::vector< std::pair<int,int> > points,
                       std::string style);
      void drawPolygon(std::vector<int> x, std::vector<int> y,
                       Colour fillColour,
                       Colour strokeColour = Colour(0,0,0,255),
                       int strokeWidth = 1,
                       std::string strokeLinejoin = "miter",
                       std::string extraStyle = "");
      void drawPolygon(std::vector< std::pair<int,int> > points,
                       Colour fillColour,
                       Colour strokeColour = Colour(0,0,0,255),
                       int strokeWidth = 1,
                       std::string strokeLinejoin = "miter",
                       std::string extraStyle = "");
      void drawText(int x, int y, std::string text,
                    std::string style);
      void drawText(int x, int y, std::string text,
                    Colour fillColour,
                    Colour strokeColour = Colour(0,0,0,0),
                    int strokeWidth = 0,
                    std::string fontFamily = "Arial",
                    int fontSize = 12,
                    std::string extraStyle = "");
      void writeFooter();
    private:
      int width, height;
      std::ofstream outfile;
  };
}

#endif
