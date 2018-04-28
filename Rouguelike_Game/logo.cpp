#include "logo.h"

using namespace std;

void DrawImage(string img_name)
{
	fstream image;
	string nameGraphic = "../graphics/";
	nameGraphic.append(img_name);
	image.open(nameGraphic);
	string line;

	do
	{
		getline(image, line);
		cout << line << "\n";
	} while (line != "");

	image.close();
}
