#include "SVG.h"

namespace SVG {  
  Colour::Colour(int r, int g, int b, int a) {
    red   = r;
    green = g;
    blue  = b;
    alpha = a;
  }
  
  Colour::Colour(int r, int g, int b, float a) {
    red   = r;
    green = g;
    blue  = b;
    alpha = static_cast<int>(lround(a * 255));
  }
  
  std::string Colour::toHex(void) {
    std::stringstream stream;
    stream << "#"
           << std::setfill('0') << std::hex
           << std::setw(2) << red
           << std::setw(2) << green
           << std::setw(2) << blue;
    return stream.str();
  }
  
  std::string Colour::opacity(int decimalPlaces) {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(decimalPlaces)
           << static_cast<float>(alpha) / 255.0f;
    return stream.str();
  }
  
  std::string Colour::toRGBA(int decimalPlaces) {
    std::stringstream stream;
    stream << "rgba("
           << red << ", "
           << green << ", "
           << blue << ", "
           << opacity(decimalPlaces)
           << ")";
    return stream.str();
  }
  
  SVGWriter::SVGWriter(std::string filename, int w, int h) {
    outfile.open(filename);
    width   = w;
    height  = h;
  }
  
  void SVGWriter::writeHeader(void) {
    outfile << "<?xml version=\"1.0\"?>\n"
            << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
            <<      "width=\""
                  << width <<
                "\" height=\""
                 << height <<
                "\">\n";
  }
  
  void SVGWriter::inject(std::string xml) {
    outfile << xml;
  }
  
  void SVGWriter::startDefs(void) {
    outfile << "\t<defs>\n";
  }
  
  void SVGWriter::endDefs(void) {
    outfile << "\t</defs>\n";
  }
  
  void SVGWriter::drawRect(int x1, int y1, int x2, int y2,
                           std::string style) {
    int w = x2-x1, h = y2-y1;
    outfile << "\t<rect x=\""
                     << x1 <<
                    "\" y=\""
                     << y1 <<
                    "\" width=\""
                     << width <<
                    "\" height=\""
                     << height <<
                    "\" style=\""
                     << style <<
                    "\"/>\n";
  }
  
  void SVGWriter::drawRect(int x1, int y1, int x2, int y2,
                           Colour fillColour, Colour strokeColour,
                           int strokeWidth, std::string extraStyle) {
    std::stringstream style;
    
    // Calculate styling
    style << "fill: " << fillColour.toHex() << ";"
          << "fill-opacity: " << fillColour.opacity() << ";"
          << "stroke: " << strokeColour.toHex() << ";"
          << "stroke-opacity: " << strokeColour.opacity() << ";"
          << "stroke-width: " << strokeWidth << ";"
          << extraStyle;
    
    drawRect(x1, y1, x2, y2, style.str());
  }
  
  void SVGWriter::drawRoundedRect(int x1, int y1, int x2, int y2,
                                  int rx, int ry,
                                  std::string style) {
    int w = x2-x1, h = y2-y1;
    outfile << "\t<rect x=\""
                     << x1 <<
                    "\" y=\""
                     << y1 <<
                    "\" rx=\""
                     << rx <<
                    "\" ry=\""
                     << ry <<
                    "\" width=\""
                     << width <<
                    "\" height=\""
                     << height <<
                    "\" style=\""
                     << style <<
                    "\"/>\n";
  }
  
  void SVGWriter::drawRoundedRect(int x1, int y1, int x2, int y2,
                                  int rx, int ry,
                                  Colour fillColour, Colour strokeColour,
                                  int strokeWidth, std::string extraStyle) {
    std::stringstream style;
    
    // Calculate styling
    style << "fill: " << fillColour.toHex() << ";"
          << "fill-opacity: " << fillColour.opacity() << ";"
          << "stroke: " << strokeColour.toHex() << ";"
          << "stroke-opacity: " << strokeColour.opacity() << ";"
          << "stroke-width: " << strokeWidth << ";"
          << extraStyle;
    
    drawRoundedRect(x1, y1, x2, y2, rx, ry, style.str());
  }
  
  void SVGWriter::drawCircle(int cx, int cy, int r,
                             std::string style) {
    outfile << "\t<circle cx=\""
                       << cx <<
                      "\" cy=\""
                       << cy <<
                      "\" r=\""
                       << r <<
                      "\" style=\""
                       << style <<
                      "\"/>\n";
  }
  
  void SVGWriter::drawCircle(int cx, int cy, int r,
                             Colour fillColour, Colour strokeColour,
                             int strokeWidth, std::string extraStyle) {
    std::stringstream style;
                               
    // Calculate styling
    style << "fill: " << fillColour.toHex() << ";"
          << "fill-opacity: " << fillColour.opacity() << ";"
          << "stroke: " << strokeColour.toHex() << ";"
          << "stroke-opacity: " << strokeColour.opacity() << ";"
          << "stroke-width: " << strokeWidth << ";"
          << extraStyle;
    
    drawCircle(cx, cy, r, style.str());
  }
  
  void SVGWriter::drawEllipse(int cx, int cy, int rx, int ry,
                               std::string style) {
    outfile << "\t<ellipse cx=\""
                        << cx <<
                       "\" cy=\""
                        << cy <<
                       "\" rx=\""
                        << rx <<
                       "\" ry=\""
                        << ry <<
                       "\" style=\""
                        << style <<
                       "\"/>\n";
  }
  
  void SVGWriter::drawEllipse(int cx, int cy, int rx, int ry,
                             Colour fillColour, Colour strokeColour,
                             int strokeWidth, std::string extraStyle) {
    std::stringstream style;
                               
    // Calculate styling
    style << "fill: " << fillColour.toHex() << ";"
          << "fill-opacity: " << fillColour.opacity() << ";"
          << "stroke: " << strokeColour.toHex() << ";"
          << "stroke-opacity: " << strokeColour.opacity() << ";"
          << "stroke-width: " << strokeWidth << ";"
          << extraStyle;
    
    drawEllipse(cx, cy, rx, ry, style.str());
  }
  
  void SVGWriter::drawLine(int x1, int y1, int x2, int y2,
                           std::string style) {
    outfile << "\t<line x1=\""
                     << x1 <<
                    "\" y1=\""
                     << y1 <<
                    "\" x2=\""
                     << x2 <<
                    "\" y2=\""
                     << y2 <<
                    "\" style=\""
                     << style <<
                    "\"/>\n";
  }
  
  void SVGWriter::drawLine(int x1, int y1, int x2, int y2,
                           Colour strokeColour, int strokeWidth,
                           std::string strokeLinecap, std::string extraStyle) {
    std::stringstream style;
    
    // Calculate styling
    style << "stroke: " << strokeColour.toHex() << ";"
          << "stroke-opacity: " << strokeColour.opacity() << ";"
          << "stroke-width: " << strokeWidth << ";"
          << "stroke-linecap: " << strokeLinecap << ";"
          << extraStyle;
    
    drawLine(x1, y1, x2, y2, style.str());
  }
  
  void SVGWriter::drawPolyline(std::vector<int> x, std::vector<int> y,
                               std::string style) {
    if (x.size() != y.size()) {
      throw std::invalid_argument(
        "polyline x and y components must have the same length"
      );
    }
    outfile << "\t<polyline points=\"";
    for (int i = 0; i < x.size(); ++i) {
      outfile << x[i] << "," << y[i];
      if (i < x.size()-1) {
        // we add a space
        outfile << " ";
      }
    }
    outfile << "\" style=\""
                << style <<
               "\"/>\n";
  }
  
  void SVGWriter::drawPolyline(std::vector< std::pair<int,int> > points,
                               std::string style) {
    outfile << "\t<polyline points=\"";
    for (int i = 0; i < points.size(); ++i) {
      outfile << points[i].first << "," << points[i].second;
      if (i < points.size()-1) {
        outfile << " ";
      }
    }
    outfile << "\" style=\""
                << style <<
               "\"/>\n";
  }
  
  void SVGWriter::drawPolyline(std::vector<int> x, std::vector<int> y,
                               Colour fillColour, Colour strokeColour,
                               int strokeWidth, std::string strokeLinejoin,
                               std::string extraStyle) {
    std::stringstream style;
    
    style << "fill: " << fillColour.toHex() << ";"
          << "fill-opacity: " << fillColour.opacity() << ";"
          << "stroke: " << strokeColour.toHex() << ";"
          << "stroke-opacity: " << strokeColour.opacity() << ";"
          << "stroke-width: " << strokeWidth << ";"
          << "stroke-linejoin: " << strokeLinejoin << ";"
          << extraStyle;
          
    drawPolyline(x, y, style.str());
  }
  
  void SVGWriter::drawPolyline(std::vector< std::pair<int,int> > points,
                               Colour fillColour, Colour strokeColour,
                               int strokeWidth, std::string strokeLinejoin,
                               std::string extraStyle) {
     std::stringstream style;
     
     style << "fill: " << fillColour.toHex() << ";"
           << "fill-opacity: " << fillColour.opacity() << ";"
           << "stroke: " << strokeColour.toHex() << ";"
           << "stroke-opacity: " << strokeColour.opacity() << ";"
           << "stroke-width: " << strokeWidth << ";"
           << "stroke-linejoin: " << strokeLinejoin << ";"
           << extraStyle;
           
     drawPolyline(points, style.str());
  }
  
  void SVGWriter::drawPolygon(std::vector<int> x, std::vector<int> y,
                              std::string style) {
    if (x.size() != y.size()) {
      throw std::invalid_argument(
        "polygon x and y components must have the same length"
      );
    }
    outfile << "\t<polygon points=\"";
    for (int i = 0; i < x.size(); ++i) {
      outfile << x[i] << "," << y[i];
      if (i < x.size()-1) {
        outfile << " ";
      }
    }
    outfile << "\" style=\""
                << style <<
               "\"/>\n";
  }
  
  void SVGWriter::drawPolygon(std::vector< std::pair<int,int> > points,
                              std::string style) {
    outfile << "\t<polygon points=\"";
    for (int i = 0; i < points.size(); ++i) {
      outfile << points[i].first << "," << points[i].second;
      if (i < points.size()-1) {
        outfile << " ";
      }
    }
    outfile << "\" style=\""
                << style <<
               "\"/>\n";
  }
  
  void SVGWriter::drawPolygon(std::vector<int> x, std::vector<int> y,
                              Colour fillColour, Colour strokeColour,
                              int strokeWidth, std::string strokeLinejoin,
                              std::string extraStyle) {
    std::stringstream style;
    
    style << "fill: " << fillColour.toHex() << ";"
          << "fill-opacity: " << fillColour.opacity() << ";"
          << "stroke: " << strokeColour.toHex() << ";"
          << "stroke-opacity: " << strokeColour.opacity() << ";"
          << "stroke-width: " << strokeWidth << ";"
          << "stroke-linejoin: " << strokeLinejoin << ";"
          << extraStyle;
          
    drawPolygon(x, y, style.str());
  }
  
  void SVGWriter::drawPolygon(std::vector< std::pair<int,int> > points,
                              Colour fillColour, Colour strokeColour,
                              int strokeWidth, std::string strokeLinejoin,
                              std::string extraStyle) {
     std::stringstream style;
     
     style << "fill: " << fillColour.toHex() << ";"
           << "fill-opacity: " << fillColour.opacity() << ";"
           << "stroke: " << strokeColour.toHex() << ";"
           << "stroke-opacity: " << strokeColour.opacity() << ";"
           << "stroke-width: " << strokeWidth << ";"
           << "stroke-linejoin: " << strokeLinejoin << ";"
           << extraStyle;
           
     drawPolygon(points, style.str());
  }
  
  void SVGWriter::drawText(int x, int y, std::string text,
                           std::string style) {
    outfile << "\t<text x=\""
                     << x <<
                    "\" y=\""
                     << y <<
                    "\" style=\""
                     << style <<
                    "\">"
                     << text <<
                    "</text>\n";
  }
  
  void SVGWriter::drawText(int x, int y, std::string text,
                           Colour fillColour, Colour strokeColour,
                           int strokeWidth, std::string fontFamily,
                           int fontSize, std::string extraStyle) {
    std::stringstream style;
    
    style << "fill: " << fillColour.toHex() << ";"
          << "fill-opacity: " << fillColour.opacity() << ";"
          << "stroke: " << strokeColour.toHex() << ";"
          << "stroke-opacity: " << strokeColour.opacity() << ";"
          << "stroke-width: " << strokeWidth << ";"
          << "font-family: " << fontFamily << ";"
          << "font-size: " << fontSize << ";"
          << extraStyle;
          
    drawText(x, y, text, style.str());
  }

  void SVGWriter::writeFooter(void) {
    outfile << "</svg>";
    outfile.close();
  }
}
