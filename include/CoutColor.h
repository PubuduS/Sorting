#ifndef COUTCOLOR_H
#define COUTCOLOR_H

namespace Color
{

   enum Code
   {

      FG_RED      = 31,
      FG_GREEN    = 32,
      FG_YELLOW   = 33,
      FG_BLUE     = 34,
      FG_MAGENTA  = 35,
      FG_CYAN     = 36,
      FG_DEFAULT  = 39,
      BG_RED      = 41,
      BG_GREEN    = 42,
      BG_BLUE     = 44,
      BG_DEFAULT  = 49

   };

   //Here, \033 is the ESC character, ASCII 27. It is followed by [,
   //then zero or more numbers separated by ;, and finally the letter m.
   //The numbers describe the colour and format to switch to from that point onwards.

   std::ostream& operator<<(std::ostream& os, Code code)
   {
      return os << "\033[" << static_cast<int>(code) << "m";
   }

}

#endif

