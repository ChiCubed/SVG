#include "SVG.h"

// note: C++11 required

int main(int argc, char* argv[]) {
  SVG::SVGWriter a("file.svg", 800, 600);
  a.writeHeader();
  
  a.drawRect(50,50,300,400,SVG::Colour(255,0,0));
  a.drawText(100, 100, "hello world", SVG::Colour(0,255,255), SVG::Colour(255,255,0), 3, "Verdana", 50);
  a.drawPolyline({50,400,8,103},{400,50,100,30},"stroke: #000000; stroke-width: 10; fill: none;");
  a.drawPolygon({{0,40},{40,40},{40,80},{80,80},{80,120},{120,120},{120,160}}, "fill: #f9f38c; stroke: #d07735; stroke-width: 6;");
  for (int i = 10; i < 300; i += 5) {
    a.inject("<text x=\"100\" y=\"100\" transform=\"rotate("+std::to_string(i)+")\">HELLO WORLD</text>");
  }
  
  a.writeFooter();
}
