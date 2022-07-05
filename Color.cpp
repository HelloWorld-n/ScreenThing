#include <string>

class Color {
	public:
		short int red;
		short int green;
		short int blue;

		Color(short int red, short int green, short int blue){
			this->red = red % 256;
			this->green = green % 256;
			this->blue = blue % 256;
		}

		Color(short int values[3], bool autoModuo = false){
			for (int i = 0; i < 3; i++){
				if ((values[i] > 255 or values[i] < 0) and (not autoModuo)){
					throw "Please set `autoModuo` to `true` to allow values outside [0...255]"
				}
			}
			this->red = values[0] % 256;
			this->green = values[1] % 256;
			this->blue = values[2] % 256;
		}	

		void setAll(short int values[3], bool autoModuo = false){
			for (int i = 0; i < 3; i++){
				if ((values[i] > 255 or values[i] < 0) and (not autoModuo)){
					throw "Please set `autoModuo` to `true` to allow values outside [0...255]"
				}
			}
			this->red = values[0] % 256;
			this->green = values[1] % 256;
			this->blue = values[2] % 256;
		}	

		int getRed(){
			return this->red;
		}

		int getGreen(){
			return this->green;
		}

		int getBlue(){
			return this->blue;
		}
}
