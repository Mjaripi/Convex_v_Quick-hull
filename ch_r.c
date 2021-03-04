#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 50

struct punto 
{
   double x;
   double y;
 };
//Funtions
void busca(struct punto *,int num);
int ordenax(const void *,const void *);
double dist(struct punto,struct punto);
void busca2(struct punto *p,int num);

struct punto c1,c2,c3,c4; // c1 and c2 are a farest point, and c3 , c4 are a closer point.
double mindist=1e10; // min. distance
double maxdist=-1e10; //max. distance
int main()
{
   int a,num;  // num is a mount the points
   double x,y; //parameters (x,y)
   struct punto p[MAX];

   for(scanf(" %d",&num),a=0;a<num;a++) // 
   {
      scanf(" %lf %lf",&x,&y);
      p[a].x=x;
      p[a].y=y;
    }

   busca(p,num); // is the first found
   busca2(p,num);

   printf("Distancia minima: %.3lf\n",mindist);
   printf("Distancia maxima   %3lf\n",maxdist); 
   printf("Puntos: (%.3lf,%.3lf) y (%.3lf,%.3lf)\n",c1.x,c1.y,c2.x,c2.y);

   return(0);
 }

void busca(struct punto *p,int num)
{
   double d;
   int desde,hasta,a,b;

   if(num<=1) // 
      return; // exit

   qsort(p,num,sizeof(struct punto),ordenax); // sort the points

   busca(p,num/2); //find for left
 
   busca(p+num/2,(num+1)/2); // find for right

   
   for(desde=num/2; desde>0 && p[num/2].x-p[desde].x<mindist; desde--); //find the center points
   for(hasta=num/2; hasta<num-1 && p[hasta].x-p[num/2].x<mindist; hasta++);
   
  
   for(a=desde;a<=hasta;a++)  //find the center point
      for(b=a+1;b<=hasta;b++)
         if((d=dist(p[a],p[b]))<mindist) // save the min. distance
         {
            mindist=d;
            c1.x=p[0].x;
            c1.y=p[0].y;
            c2.x=p[1].x;
            c2.y=p[1].y;
          }

 }

void busca2(struct punto *p,int num)
{
   double d;
   int desde,hasta,a,b;

   if(num<=1) 
      return; 
 
   qsort(p,num,sizeof(struct punto),ordenax); 

   busca2(p,num/2); 
 
   busca2(p+num/2,(num+1)/2); 

   for(desde=num/2; desde>0 && p[num/2].x-p[desde].x>maxdist; desde--);
   for(hasta=num/2; hasta<num-1 && p[hasta].x-p[num/2].x>maxdist; hasta++);
   
  
   for(a=desde;a<=hasta;a++)  
      for(b=a+1;b<=hasta;b++)
         if((d=dist(p[a],p[b]))>maxdist)
         {
            maxdist=d;
            c3.x=p[0].x;
            c3.y=p[0].y;
            c4.x=p[1].x;
            c4.y=p[1].y;
          }
 }

int ordenax(const void *a,const void *b)
{
   return(((*(struct punto *)a).x<(*(struct punto *)b).x)?-1:1);   // auxiliary the quicksort
 }


double dist(struct punto a,struct punto b)
{
   return(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))); //calculate the distance between the points
 }
