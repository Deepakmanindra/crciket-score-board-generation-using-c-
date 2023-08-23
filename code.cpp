#include <iostream>
#include <fstream>
#include <regex>
#include<iomanip>
#include<string.h>
using namespace std;
int main()
{
    string bat[]={"Short","Finch","Smith","Maxwell","Henriques","Wade","Abbott","Starc","Swepson"};
    string bowl[]={"Chahar","Sundar","Shami","Natarajan","Chahal"};
    string team1,team2;
    string f,str,T="";
    int i,j,num=0;
    float strike_rate[9]={0},runs[9]={0},d[9]={0},fours[9]={0},sixes[9]={0},balls[9]={0};
    float b[5]={0},w[5]={0},r[5]={0},nb[5]={0},wd[5]={0},lb[5]={0},eco[5]={0};
    string st2,st1;    ifstream out("C:\\Users\\DEVI GIRI\\OneDrive\\Desktop\\cricketcommentary.txt");
    std::string  paragraph;
while(out)
{
    std::getline(out, paragraph);
    st1=st1+" "+paragraph;
    if((paragraph.find(" to ")==-1)||(paragraph.find(", ")==-1))
    {
        continue;
    }
    for(i=0;i<9;i++)
    {
        if(paragraph.find(bat[i])==-1)
        {
            continue;
        }
        for(int j=0;j<5;j++)
        {
            if(paragraph.find(bowl[j])==-1)
            {
                continue;
            }
            else
            {
                str="";
                str=str.append(bowl[j]);
                str=str.append(" to ");
                str=str.append(bat[i]);
                str=str.append(", ");
                if(paragraph.find(str)==0)
                {
                    T = paragraph;
                    //cout<<paragraph<<endl;
                    /*if(paragraph.find(", FOUR runs")!=-1)
                    {
                        fours[i]++;
                        runs[i]+=4;
                        RUNS[j]+=4;
                    }
                    if(paragraph.find(", 1 runs")!=-1)
                    {
                        runs[i]++;
                        RUNS[j]++;
                    }
                    if(paragraph.find(", SIX runs")!=-1)
                    {
                        sixes[i]++;
                        runs[i]+=6;
                        RUNS[j]+=6;
                    }
                    if(paragraph.find(", 2 runs")!=-1)
                    {
                        runs[i]+=2;
                        RUNS[j]+=2;
                    }
                    if(paragraph.find(", 3 runs")!=-1)
                    {
                        runs[i]+=3;
                        RUNS[j]+=3;
                    }*/

                    //cout << T << "\n";

                    if(T.find(", 1 run") != -1)
                        num=1;
                    else if(T.find(", 2 runs") != -1)
                        num =2;
                    else if(T.find(", 2 runs") != -1)
                        num =5;
                    else if(T.find(", 3 runs") != -1)
                        num=3;
                    else if(T.find(", FOUR runs") != -1)
                    {
                        num=4;
                        fours[i]++;
                    }
                    else if(T.find(", SIX runs") != -1)
                    {
                        num=6;
                        sixes[i]++;
                    }
                    else if(T.find(", no run") != -1)
                    {
                        num = 0;
                        d[i]++;
                    }
                    else if(T.find(", OUT") != -1)
                    {
                        num=0;
                        w[j]++;
                    }
                    else if(T.find(", 1 wide") != -1)
                    {

                        num=1;
                        wd[j]++;
                        --runs[i];
                        --b[j];
                        --balls[i];
                    }
                    else if(T.find(", 1 leg bye")!=-1)
                    {
                        num = 1;
                        lb[j]++;
                        runs[i]--;
                        --r[j];
                    }
                    else if(T.find(", 1 bye")!=-1)
                    {
                        num = 1;
                        lb[j]++;
                        runs[i]--;
                        --r[j];
                    }
                    else if(T.find(", (no ball)")!=-1)
                    {
                        if(T.find(", (no ball) 1 run")!=-1)
                        {
                             num = 2;
                             nb[j]++;
                             --runs[i];
                             --b[j];

                        }
                        else
                        {
                             num = 1;
                             nb[j]++;
                             --runs[i];
                             --b[j];
                        }

                    }


                    runs[i]+=num;
                    balls[i]++;
                    r[j]+=num;
                    b[j]++;


                }
            }
        }
    }


}
for(i=0;i<9;i++)
{
    cout<<bat[i]<<left<<"  "<<setw(8)<<runs[i]<<left<<" "<<fours[i]<<setw(8)<<" "<<sixes[i]<<setw(8)<<" "<<((100*runs[i])/balls[i])<<endl;
}
cout<<endl<<endl;
for(j=0;j<5;j++)
{
    cout<<bowl[j]<<" "<<setw(8)<<r[j]<<setw(8)<<b[j]/6<<setw(8)<<nb[j]<<setw(8)<<wd[j]<<endl;
}
out.close();
    return 0;
}