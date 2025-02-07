#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double max(double num1 , double num2)
{
    if (num1 >= num2) return num1;
    else return num2;
}

double min(double num1 , double num2)
{
    if (num1 <= num2) return num1;
    else return num2;
}

bool check_range_Y(double num , Rect *r1 , Rect *r2)
{
    if (num <= r1->y and num >= r1->y-r1->h and num <= r2->y and num >= r2->y-r2->h)
    return true;
    else
    return false;
}

bool check_range_X(double num , Rect *r1 , Rect *r2)
{
    if (num <= r1->x+r1->w and num >= r1->x and num <= r2->x+r2->w and num >= r2->x)
    return true;
    else
    return false;
}

double overlap(Rect *r1 , Rect *r2)
{
    double y_top_over = min(r1->y , r2->y);
    double y_low_over = max(r1->y-r1->h , r2->y-r2->h);
    
    double x_left_over = max(r1->x , r2->x);
    double x_right_over = min(r1->x+r1->w , r2->x+r2->w);
    
    if (not(check_range_Y(y_top_over , r1 , r2))) return 0;
    if (not(check_range_Y(y_low_over , r1 , r2))) return 0;
    
    if (not(check_range_X(x_left_over , r1 , r2))) return 0;
    if (not(check_range_X(x_right_over , r1 , r2))) return 0;
    
    double h = y_top_over - y_low_over;
    double w = x_right_over - x_left_over;
    
    return h*w;

}