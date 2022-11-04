#include "Image.h"
#include "StickerSheet.h"

#include <iostream>

int main() {
  // Image alma;



  // std::cout << "Using Image::lighten to create `lighten.png`..." << std::endl;
  // alma.readFromFile("../alma.png");
  // alma.lighten(0.2);
  // alma.writeToFile("../lighten.png");

  // std::cout << "Using Image::saturate to create `saturate.png`..." << std::endl;
  // alma.readFromFile("../alma.png");
  // alma.saturate(0.2);
  // alma.writeToFile("../saturate.png");

  // std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  // alma.readFromFile("../alma.png");
  // alma.scale(2);
  // alma.writeToFile("../scale2x.png");


  Image alma;     alma.readFromFile("../tests/alma.png");
  Image i;        i.readFromFile("../tests/i.png");
  Image expected; expected.readFromFile("../tests/expected.png");

  StickerSheet sheet(alma, 5);
  sheet.addSticker(i, 20, 200);
  sheet.addSticker(i, 50, 200);
  sheet.removeSticker(1);

  sheet.render().writeToFile("../ritul.png");

  return 0;
}
