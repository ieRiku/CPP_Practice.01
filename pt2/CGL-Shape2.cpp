#include<iostream>
#include<graphics.h>
#include<math.h>
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
    int x1, y1, x2, y2, x3, y3, x4, y4, x5,y5, x6, y6, x7, y7, x8, y8;
    int r, D, d;
    cout<<"Enter x1: ";
    cin>>x1;    
    cout<<"Enter y1: ";
    cin>>y1;    
    cout<<"Enter x3: ";
    cin>>x3;    
    cout<<"Enter y3: ";
    cin>>y3;
    x2=x3;
    y2=y1;
    x4=x1;
    y4=y3;
    x5=(x1+x2)/2;
    y5=y1;
    x6=x2;
    y6=(y2+y3)/2;
    x7=(x3+x4)/2;
    y7=y3;
    x8=x1;
    y8=(y1+y4)/2;
    D=x2-x1;
    d=y4-y1;
    r=sqrt((D*D)/4 + (d*d)/4) / 2;
    dda(x1,y1,x2,y2);
	dda(x2,y2,x3,y3);
	dda(x3,y3,x4,y4);
	dda(x4,y4,x1,y1);
	dda(x5,y5,x6,y6);
	dda(x6,y6,x7,y7);
	dda(x7,y7,x8,y8);
	dda(x8,y8,x5,y5);
    bresc(x5,y6,r);
    delay(10000);
    closegraph();
}