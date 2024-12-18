#include<iostream>
#include<graphics.h>
using namespace std;
void dda(int x1, int y1, int x2, int y2){
    float dx, dy, len, x, y;
    float xin, yin;
    int i=1;
    x=x1;
    y=y1;
    putpixel(x,y,RED);
    dx=abs(x2-x1);
    dy=abs(y2-y1);
    if(dx>dy)
    len=dx;
    else
    len=dy;
    xin=(x2-x1)/len;
    yin=(y2-y1)/len;
    while(i<=len){
        putpixel(x, y, RED);
        x+=xin;
        y+=yin;
        i++;
    }
    delay(2000);
}
void bresc(int centx, int centy, int r){
    int p,x,y;
    x=0;
    y=r;
    p=3-(2*r);
    do{
        putpixel(centx+x,centy-y,RED);
        putpixel(centx-x,centy-y,RED);
        putpixel(centx-x,centy+y,RED);
        putpixel(centx+x,centy+y,RED);
        putpixel(centx+y,centy+x,RED);
        putpixel(centx+y,centy-x,RED);
        putpixel(centx-y,centy+x,RED);
        putpixel(centx-y,centy-x,RED);
        if(p<0)
        p=p+(4*x) + 6;
        else{
            p=p+(4*(x-y)+10);
            y=y-1;
        }
        x=x+1;
    }while(x<y);
}
int main(){
    int gd=DETECT, gm;
    initgraph(&gd, &gm, NULL);
    int r, centx, centy;
    cout<<"Enter x-coordinate of center: ";
    cin>>centx;
    cout<<"Enter y-coordinate of center: ";
    cin>>centy;
    cout<<"Enter radius of circle: ";
    cin>>r;
    bresc(centx, centy, r);
    bresc(centx, centy, r/2);
    dda(centx, centy - r, centx - 0.865*r, centy + r/2);
    dda(centx - 0.865*r, centy + r/2, centx + 0.865*r, centy + r/2);
    dda(centx + 0.865*r, centy + r/2, centx, centy - r);
    closegraph();
}