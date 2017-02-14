
class coding {
public:

static unsigned char encode (unsigned char c) {
for(int i = 0; i < 5; ++i)  {
  if(c == 127) {
   c==0;
 }else{
   ++c;
 }
}
return c;
}

static unsigned char decode (unsigned char c) {
  for(int i = 0; i < 5; ++i)  {


    if(c == 0) {
     c==127;
   }else{
     --c;
   }
  }
  return c;
  }
};
