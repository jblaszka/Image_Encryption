#include "MethodB.h"


MethodB::MethodB()
{
}

wxVector <wxImage> MethodB::codeWithMethodB(wxImage img1)
{
	srand(time(NULL));
	wxImage Img_A(1600, 1066);
	wxImage Img_B(1600, 1066);
	wxImage Img_C(1600, 1066);
	unsigned char* Coded;
	unsigned char* Image_a;
	unsigned char* Image_b;
	unsigned char* Image_c;
	Image_b = Img_B.GetData();
	Image_a = Img_A.GetData();
	Image_c = Img_C.GetData();

	wxImage Img_Coded = img1;

	Coded = Img_Coded.GetData();
	for (int i = 0; i < Img_A.GetHeight() * Img_A.GetWidth() * 3; i++) {
		Image_a[i] = 255;
		Image_b[i] = 255;
	}
	for (int i = 0; i < Img_C.GetHeight() * Img_C.GetWidth() * 3; i++) {
		Image_c[i] = 255;
	}

	int a, b;
	for (int i = 0; i < Img_Coded.GetHeight() * Img_Coded.GetWidth() * 3; i = i + 3) {
		int random = rand() % 2;
		if (Coded[i] == 255) {
			if (random == 1) {
				a = 0;
			}
			else {
				a = 255;
			}
			for (int q = 0; q < 3; q++) {
				Image_a[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3] = a;
				Image_b[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3] = a;
				Image_a[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3 + 3] = 255 - a;
				Image_b[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3 + 3] = 255 - a;
				Image_a[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3] = 255 - a;
				Image_b[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3] = 255 - a;
				Image_a[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3 + 3] = a;
				Image_b[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3 + 3] = a;
			}
		}
		else {
			if (random == 1) {
				a = 0;
				b = 255;
			}
			else {
				a = 255;
				b = 0;
			}
			for (int q = 0; q < 3; q++) {
				Image_a[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3] = a;
				Image_b[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3] = 255 - a;
				Image_a[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3 + 3] = 255 - a;
				Image_b[2 * i + q + (i / (Img_Coded.GetWidth() * 3)) * Img_A.GetWidth() * 3 + 3] = a;
				Image_a[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3] = 255 - a;
				Image_b[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3] = a;
				Image_a[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3 + 3] = a;
				Image_b[2 * i + q + (1 + (i / (Img_Coded.GetWidth() * 3))) * Img_A.GetWidth() * 3 + 3] = 255 - a;

			}
		}
	}
	vector_img.push_back(Img_A);
	vector_img.push_back(Img_B);
	return vector_img;
}

wxImage MethodB::decode(wxImage img1, wxImage img2) {

	srand(time(NULL));
	wxImage Img_A(1600, 1066);
	wxImage Img_B(1600, 1066);
	wxImage Img_C(1600, 1066);
	unsigned char* Coded;
	unsigned char* Image_a;
	unsigned char* Image_b;
	unsigned char* Image_c;
	Image_b = Img_B.GetData();
	Image_a = Img_A.GetData();
	Image_c = Img_C.GetData();

	Img_A = img1;
	Img_B = img2;

	for (int j = 0; j < Img_C.GetHeight() * Img_C.GetWidth() * 3; j += 3)
	{
		if (Image_a[j] != Image_b[j])
		{
			Image_c[j] = 0;
			Image_c[j + 1] = 0;
			Image_c[j + 2] = 0;
		}
	}
	return Img_C;

}
