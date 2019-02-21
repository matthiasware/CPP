/*
see Pixmap:
https://de.wikipedia.org/wiki/Portable_Anymap#Pixmap
*/
void toFile(int w, int h, int maxiter,
	        int *map, std::string fileName,
	        bool transpose=false) {
  if(transpose)
  {
  	int tmp = w;
  	w = h;
  	h = tmp;
  }
  std::ofstream img(fileName + ".ppm");
  if (!img.is_open()) {
    std::cout << "Could not open the file";
    return;
  }
  img << "P3\n" << h << " " << w << " 255\n";
  for (int x = 0; x < w; x++) {
    for (int y = 0; y < h; y++) {
      int val = (map[x * h + y] % 255);
      img << val << ' ' << val << ' ' << val << "\n";
    }
  }
  img.close();
}

int main()
{
  
}