#include <stdio.h>

int lines(double[], double[], double[]);

int main(){
    double u[3], v[3], s[2];
    printf("Enter vector 1 (a,b,c): ");
    for(int i = 0; i < 3; i++)
        scanf("%lf", &u[i]);

    printf("Enter vector 2 (d,e,f): ");
    for(int i = 0; i < 3; i++)
        scanf("%lf", &v[i]);

    switch(lines(u, v, s)){
        case 1:
            printf("The lines are parallel.");
            break;
        case 0:
            printf("The lines are coincident.");
            break;
        case -1:
            printf("The lines are intersecting.");
    }
}

int lines(double u[], double v[], double s[]){
    double slope1 = -1*u[0]/u[1];
    double slope2 = -1*v[0]/v[1];
    double yIntercept1 = u[2]/u[1];
    double yIntercept2 = v[2]/v[1];

    if(slope1 == slope2 && yIntercept1 == yIntercept2)
        return (0);
    else if(slope1 == slope2 && yIntercept1 != yIntercept2)
        return 1;
    else{
        s[0] = (yIntercept2 - yIntercept1) / (slope1 - slope2);
        s[1] = s[0]*slope1 + yIntercept1;
        return -1;
    }
}
