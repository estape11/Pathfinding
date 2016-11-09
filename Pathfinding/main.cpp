#include <QCoreApplication>
#include "pathfinding.h"

int main()
{
    /*
    // create empty Map
    for(int y=0;y<m;y++){
        for(int x=0;x<n;x++){
            Map[x][y]=0;
        }
    }

    //Obstaculos
    Map[2][4]=1;
    Map[3][4]=1;
    Map[4][4]=1;
    Map[4][7]=1;
    Map[5][7]=1;
    Map[6][7]=1;
    Map[7][7]=1;
    Map[6][10]=2;
    Map[6][11]=1;
    Map[6][12]=1;
    Map[6][13]=1;
    */
    //ACÁ LE DIGO DONDE INICIAR Y TERMINAR
    // randomly select start and finish locations
    int xA=0, yA=0, xB=n-1, yB=m-1;

    cout<<"Map Size (X,Y): "<<n<<","<<m<<endl;
    cout<<"Start: "<<xA<<","<<yA<<endl;
    cout<<"Finish: "<<xB<<","<<yB<<endl;

    // get the route
    string route=pathFind(xA, yA, xB, yB);
    double time_elapsed = double(end - start);
    cout<<"Time to calculate the route (ms): "<<time_elapsed<<endl;
    cout<<"Route:"<<endl;
    cout<<route<<endl<<endl;

    // follow the route on the map and display it
    if(route.length()>0)
    {
        int j;
        char c;
        int x=xA;
        int y=yA;
        Map[x][y]=2;
        for(int i=0;i<route.length();i++)
        {
            c =route.at(i);
            j=atoi(&c);
            x=x+dx[j];
            y=y+dy[j];
            cout<<"X "<<x<<" Y "<<y<<endl;
        }
    }
    return(0);

}
