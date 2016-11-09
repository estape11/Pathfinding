#include <QCoreApplication>
#include "pathfinding.h"

int main()
{
    srand(time(NULL));

    // create empty Map
    for(int y=0;y<m;y++)
    {
        for(int x=0;x<n;x++) Map[x][y]=0;
    }
    int mat[11][20] ={{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}
                     ,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0}
                     ,{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                     ,{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                     ,{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                     ,{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
                     ,{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0}
                     ,{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}
                     ,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}
                     ,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}
                     ,{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    for(int i=0; i<11; i++) {
        for (int j = 0; j < 20; j++) {
            Map[i][j] = 0;//mat[i][j];
        }
    }
    for(int y=0;y<m;y++) {
        for (int x = 0; x < n; x++)
            if (Map[x][y] == 0) {
                cout << ".";
            } else if (Map[x][y] == 1) {
                cout << "O"; //obstacle
            } else if (Map[x][y] == 2) {
                cout << "S"; //start
            } else if (Map[x][y] == 3) {
                cout << "R"; //route
            } else if (Map[x][y] == 4) {
                cout << "F"; //finish
        }
        cout<<endl;
    }cout<<endl;
    cout << "" << Map[0][7]<< endl ;
    cout << "" << Map[0][8]<< endl ;
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

    for(int y=0;y<m;y++)
    {
        for(int x=0;x<n;x++)
            if(Map[x][y]==0) {
                cout << ".";
                cout << "l";
            }else if(Map[x][y]=1)
                cout<<"O"; //obstacle
            else if(Map[x][y]==2)
                cout<<"S"; //start
            else if(Map[x][y]==3)
                cout<<"R"; //route
            else if(Map[x][y]==4)
                cout<<"F"; //finish
        cout<<endl;
    }cout<<endl;
    for(int i = 0; i< 11; i++){
        for (int j=0; j<20; j++){
            cout << Map[i][j];
        }cout<<endl;
    }cout<<endl;

    //ACÁ LE DIGO DONDE INIACIAR Y TERMINAR
    // randomly select start and finish locations
    int xA=0, yA=0, xB=n-1, yB=m-1;

    cout<<"Map Size (X,Y): "<<n<<","<<m<<endl;
    cout<<"Start: "<<xA<<","<<yA<<endl;
    cout<<"Finish: "<<xB<<","<<yB<<endl;

    // get the route
    clock_t start = clock();
    string route=pathFind(xA, yA, xB, yB);
    if(route=="") cout<<"An empty route generated!"<<endl;
    clock_t end = clock();
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
            Map[x][y]=3;
        }
        Map[x][y]=4;

        // display the map with the route
        for(int y=0;y<m;y++)
        {
            for(int x=0;x<n;x++)
                if(Map[x][y]==0)
                    cout<<".";
                else if(Map[x][y]==1)
                    cout<<"O"; //obstacle
                else if(Map[x][y]==2)
                    cout<<"S"; //start
                else if(Map[x][y]==3)
                    cout<<"R"; //route
                else if(Map[x][y]==4)
                    cout<<"F"; //finish
            cout<<endl;
        }
    }
    cout << "je " << Map[0][7]<< endl ;
    cout << "" << Map[0][8]<< endl ;
    //printMap(Map);
    for(int i=0; i<11; i++){
        for(int j=0; j<20; j++){
            cout << mat[i][j];
        }
        cout<< " "<< endl;
    }
    getchar(); // wait for a (Enter) keypress
    cout << "je " << Map[0][7]<< endl ;
    cout << "" << Map[0][8]<< endl ;
    return(0);

}
