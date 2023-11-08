#include <iostream>
#include <Windows.h>

using namespace std;
class linearInterpolationL {
private:
    float x0, x1, y0, y1, x;
public:
    float calc() {
        float L = ((x - x1) / (x0 - x1)) * y0 + ((x - x0) / (x1 - x0)) * y1;
        return L;
    }
    linearInterpolationL(float x, float x0, float x1, float y0, float y1) {
        this->x = x;
        this->x0 = x0;
        this->x1 = x1;
        this->y0 = y0;
        this->y1 = y1;
    }
};
class quadInterpolationL {
private://x1 и x2 целевые координаты, которые используются в линейной интерполяции
    float x0, x1, x2, x3;
    float y0, y1, y2, y3;
    float x;
    void find3_coordinates() {
        if (x0 - x > x3 - x)
        {
            x0 = x1;
            x1 = x2;
            x2 = x3;
            y0 = y1;
            y1 = y2;
            y2 = y3;
        }
    }
public:
    float calc() {
        find3_coordinates();
        float L = ((((x - x1) * (x - x2)) / ((x0 - x1) * (x0 - x2))) * y0)
            + ((((x - x0) * (x - x2)) / ((x1 - x0) * (x1 - x2))) * y1)
            + ((((x - x0) * (x - x1)) / ((x2 - x0) * (x2 - x1))) * y2);
        return L;
    }
    quadInterpolationL(float x, float x0, float x1, float x2, float x3, float y0, float y1, float y2, float y3)
    {
        this->x = x;
        this->x0 = x0;
        this->x1 = x1;
        this->x2 = x2;
        this->x3 = x3;
        this->y0 = y0;
        this->y1 = y1;
        this->y2 = y2;
        this->y3 = y3;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    float xc[4];
    float yc[4];
    float x;
    float result1, result2;
    cout << "Ввод х = "; cin >> x; cout << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "Ввод х" << i << " = "; cin >> xc[i]; cout << endl;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << "Ввод y" << i << " = "; cin >> yc[i]; cout << endl;
    }

    linearInterpolationL obj1(x, xc[1], xc[2], yc[1], yc[2]);
    quadInterpolationL obj2(x, xc[0], xc[1], xc[2], xc[3], yc[0], yc[1], yc[2], yc[3]);

    result1 = obj1.calc();
    result2 = obj2.calc();
    cout << "линейная интерполяция Лагранжа = " << result1 << endl;
    cout << "квадратичная интерполяция Лагранжа = " << result2 << endl;

    
    return 0;
}