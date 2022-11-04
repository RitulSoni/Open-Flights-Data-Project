#include "Image.h"
#include "StickerSheet.h"

int main() {
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

  Image alma;
  alma.readFromFile("../tests/alma.png");
  Image i;
  i.readFromFile("../tests/i.png");

  StickerSheet sheet(alma, 3);
  sheet.addSticker(i, 500, 500);
  sheet.addSticker(i, 200, 500);
  sheet.addSticker(i, 500, 300);

  sheet.render().writeToFile("../myImage.png");

  return 0;
}
