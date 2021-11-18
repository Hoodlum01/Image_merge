#include <iostream>
#include <string>
#include <opencv2\opencv.hpp>

using namespace cv;

class addImage
{
private:
    Mat3b img1;
    Mat3b img2;
    Mat3b f_img;

public:
    addImage(const String& file_name1, const String& file_name2);

    void horizontal_add();
    void vertical_add();
    void export_img(const String& file);
};

addImage::addImage(const String& file_name1, const String& file_name2)
{
    img1 = imread(file_name1);
    img2 = imread(file_name2);
}

void addImage::horizontal_add()
{
    int rows = max(img1.rows, img2.rows);
    int cols = img1.cols + img2.cols;
    f_img=Mat3b(rows, cols, Vec3b(0, 0, 0));
    
    img1.copyTo(f_img(Rect(0, 0, img1.cols, img1.rows)));
    img2.copyTo(f_img(Rect(img1.cols, 0, img2.cols, img2.rows)));
}

void addImage::vertical_add()
{
 
    int rows = img1.rows + img2.rows;
    int cols = max(img1.cols, img2.cols);
    f_img=Mat3b(rows, cols, Vec3b(0, 0, 0));

    img1.copyTo(f_img(Rect(0, 0, img1.cols, img1.rows)));
    img2.copyTo(f_img(Rect(0, img1.rows, img2.cols, img2.rows)));

}

void addImage::export_img(const String& file)
{
    imwrite(file, f_img);
}

int main()
{    
    String poza1;
    String poza2;
    String img_final;

    std::cout << "------// Program de concatenare a imaginilor ///------\n\n";

    std::cout << "//Introduceti prima poza(nume1.extensie):\n";
    std::getline(std::cin, poza1);
    std::cout << "//Introduceti a 2-a poza(nume2.extensie):\n";
    std::getline(std::cin, poza2);
    std::cout << "\n";

    std::cout << "Alegeti optiunea:\n";
    std::cout << "O - Concatenare orizontala\n";
    std::cout << "V - Concatenare Verticala\n";

    addImage image(poza1, poza2);

    char op;
    std::cin >> op;
    std::cin.ignore(1, '\n');

    switch (toupper(op))
    {
    case'O':
        image.horizontal_add();
        std::cout << "Alegeti numele imaginii rezultate:";
        std::getline(std::cin, img_final);
        image.export_img(img_final);
        break;

    case'V':
        image.vertical_add();
        std::cout << "Alegeti numele imaginii rezultate:";
        std::getline(std::cin, img_final);
        image.export_img(img_final);
        break;

    default:"Optiune gresita!";
    }

    return 0;
}
