#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <stdlib.h>
using namespace std;

struct coursetime{
    int courseID;
    char day;
    int time;
    int roomID;
    int uniq = 0;
};
struct studenttime{
    int studentID;
    char day;
    int time;
    int roomID;
    int uniq = 0;
};
struct profftime{
    int proffID;
    char day;
    int time;
    int roomID;
    int uniq = 0;
};

int main()
{
    char day[6] = "MTWhF";
    int time[100] = {9,10,11,14,15,16};
    int courses[500][500],rooms[500],numberofrooms,numberofcourses,numberofstudents,numberofproffs;
    string tempus,courseinfo[500],roomsinfo[500],proffs[500],students[500];
    int i=0,j,cID,pID,sID,dID,random,counter,duration,sizer,k,t,temptime,tempday;
    ifstream fin("courses.in");
    ifstream fines("students.in");
    ifstream fine("proffs.in");
    ifstream finese("rooms.in");
    ifstream tenta("coursesinfo.in");
    //courses proffs students duration
    while(!fin.eof()){
        fin>>cID>>pID>>sID>>sizer;
        courses[i][0]=cID;
        courses[i][1]=pID;
        courses[i][2]=sID;
        courses[i][3]=sizer;
        i++;

    }
    numberofcourses = i;

    i=0;

    while(!fine.eof()){
        fine>>tempus;
        proffs[i]=tempus;
        i++;
    }
    numberofproffs=i;
    i=0;
    while(!fines.eof()){
        fines>>tempus;
        students[i]=tempus;
        i++;
    }
    numberofstudents=i;
    i=0;
    while(!tenta.eof()){
        tenta>>tempus;
        courseinfo[i]=tempus;
        i++;
    }
    //rooms
    i=0;
    while(!finese.eof()){
        finese>>dID>>tempus;
        rooms[i]=dID;
        roomsinfo[i]=tempus;
        i++;
    }
    numberofrooms = i;
    coursetime vec[500];
    profftime vep[500];
    studenttime ves[500];

    do{

    for(i=0;i<numberofcourses;i++){
        if(vec[i].uniq != 1){
                vec[i].courseID = courses[i][0];
                vep[i].proffID = courses[i][1];
                ves[i].studentID = courses[i][2];

                if(vec[i].uniq == 0){
                    random = rand()%5;
                    vec[i].day = day[random];
                    vep[i].day = day[random];
                    ves[i].day = day[random];
                    random = rand()%6;
                    vec[i].time = time[random];
                    vep[i].time = time[random];
                    ves[i].time = time[random];
                    k=0;
                    do{
                    random = rand()%numberofrooms;
                    if(rooms[random]>=courses[i][3]){
                            vec[i].roomID = random;
                            vep[i].roomID = random;
                            ves[i].roomID = random;
                            k=1;
                        }

                    } while(k==0);
                } else {

                    for(t=0;t<5;t++){
                        tempday = day[t];
                        for(k=0;k<6;k++){
                            temptime=time[k];
                            for(j=0;j<numberofcourses;j++){
                                    if(vep[i].proffID == vep[j].proffID){
                                        if(vep[j].day==tempday){
                                            if(vep[j].time-temptime == 1 || vep[j].time-temptime == -1 || vep[j].time-temptime == 0){
                                                continue;
                                            }
                                        }
                                    } else if(ves[i].studentID == ves[j].studentID){
                                        if(ves[j].day == tempday){
                                            if(ves[j].time-temptime == 1 || ves[j].time-temptime == -1 || ves[j].time-temptime == 0){
                                                continue;
                                            }else{
                                                ves[i].time = temptime;
                                                vec[i].time = temptime;
                                                vep[i].time = temptime;
                                                ves[i].day = tempday;
                                                vec[i].day = tempday;
                                                vep[i].day = tempday;
                                                temptime = 0;
                                                break;
                                            }
                                        }
                                    }

                                }
                                if(temptime==0){
                                    break;
                                }
                            }
                                if(temptime==0){
                                    break;
                                }
                        }
                    }
                }
            }


    for(j=0;j<numberofcourses;j++){
        for(i=0;i<numberofcourses;i++){
                        if(i!=j){
                            if(vec[i].courseID == vec[j].courseID && vec[i].day == vec[j].day && vec[i].time == vec[j].time){
                                if(vec[i].uniq==1){
                                    vec[j].uniq = 0;
                                    break;
                                }

                            }else if(vec[i].roomID == vec[j].roomID && vec[i].day == vec[j].day && vec[i].time == vec[j].time){
                                if(vec[i].uniq==1){
                                    vec[j].uniq = 0;
                                    break;
                                }
                            } else if(vep[i].proffID == vep[j].proffID && vep[i].day == vep[j].day && vep[i].time == vep[j].time){
                                if(vec[i].uniq==1){
                                    vec[j].uniq = 0;
                                    break;
                                }
                            }else if(vep[i].roomID == vep[j].roomID && vep[i].day == vep[j].day && vep[i].time == vep[j].time){
                                if(vec[i].uniq==1){
                                    vec[j].uniq = 0;
                                    break;
                                }
                            } else if(ves[i].studentID == ves[j].studentID && ves[i].day == vec[j].day && ves[i].time == ves[j].time){
                                if(vec[i].uniq==1){
                                    vec[j].uniq = 0;
                                    break;
                                }
                            }else if(ves[i].roomID == ves[j].roomID && ves[i].day == ves[j].day && ves[i].time == ves[j].time){
                                if(vec[i].uniq==1){
                                    vec[j].uniq = 0;
                                    break;
                                }
                            }else{
                                vec[j].uniq = 1;
                            }
                    }
                }
            }

    for(i=0;i<numberofcourses;i++){
       duration = vec[i].time + 1;
            for(j=0;j<numberofcourses;j++){
                if(i!=j){
                    if(vep[i].proffID == vep[j].proffID){
                        if(vep[i].day==vep[j].day){
                            if(vep[j].time == duration){
                                  vec[i].uniq = 2;
                            }
                        }
                    }else if(ves[i].studentID == ves[j].studentID){
                        if(ves[i].day==ves[j].day){
                            if(ves[j].time == duration){
                                  vec[i].uniq = 2;
                            }
                        }
                    }
                }

            }
    }
    counter=0;
    for(j=0;j<numberofcourses;j++){
        if(vec[j].uniq==0){
            counter++;
        }
    }


    cout<<counter<<"\n";
    }while(counter!=0);

    for(j=0;j<numberofstudents;j++){
        for(i=0;i<numberofcourses;i++){
            if(ves[i].studentID==j){
                cout<<"name: "<<j<<" course: "<<courseinfo[vec[i].courseID]<<" day: "<<ves[i].day<<" time: "<<ves[i].time<<" room: "<<vec[i].roomID<<" proff: "<<vep[i].proffID<<"\n";
            }
        }
        cout<<"\n";
    }
    fin.close();
    fine.close();
    fines.close();
    finese.close();





    ofstream myfile;
    string name1 = "report_stud_",name2 = "report_prof_",formal = ".html",full;
    //student groups
    for (i=0; i < numberofstudents; i++) {
        stringstream ss;
        ss << i;
        string str = ss.str();
        full = name1 + str + formal;
        myfile.open (full.c_str());
        myfile << "<!DOCTYPE HTML><html><head><meta charset=\"utf-8\"><title>Timetable_"<<students[i]<<"</title></head><body><table border=\"1\"><caption>Timetable_"<<students[i]<<"</ñaption>";
        myfile << "<tr><th></th><th>Monday</th><th>Tuesday</th><th>Wednesday</th><th>Thursday</th><th>Friday</th></tr>";
        for(temptime = 9; temptime < 18; temptime++){
            myfile << "<tr><th>"<<temptime<<":00</th>";
            for(tempday = 0; tempday < 5; tempday++){
                sID = 1;
                if(temptime == 13){
                    myfile <<"<th>Lunch</th>";
                    continue;
                }
                for(k=0; k<numberofcourses; k++){
                    if(ves[k].studentID == i){
                        if(day[tempday]==ves[k].day){

                            if(ves[k].time == temptime || ves[k].time == temptime-1){
                                myfile << "<th> Course:"<<courseinfo[k]<<"<br />Professor: "<<proffs[vep[k].proffID]<<"<br />room: "<<roomsinfo[vec[k].roomID]<<"</th>";
                                sID = 0;
                                break;
                            }
                        }
                    }
                }
                if(sID==1){
                    myfile << "<th></th>";
                }

            }
            myfile << "</tr>";
        }
        myfile << "</body></html>";
        myfile.close();
    }
    //proffs
for (i=0; i < numberofproffs; i++) {
        stringstream ss;
        ss << i;
        string str = ss.str();
        full = name2 + str + formal;
        myfile.open (full.c_str());
        myfile << "<!DOCTYPE HTML><html><head><meta charset=\"utf-8\"><title>Timetable_"<<proffs[i]<<"</title></head><body><table border=\"1\"><caption>Timetable_"<<proffs[i]<<"</caption>";
        myfile << "<tr><th></th><th>Monday</th><th>Tuesday</th><th>Wednesday</th><th>Thursday</th><th>Friday</th></tr>";
        for(temptime = 9; temptime < 18; temptime++){
            myfile << "<tr><th>"<<temptime<<":00</th>";
            for(tempday = 0; tempday < 5; tempday++){
                sID = 1;
                if(temptime == 13){
                    myfile <<"<th>Lunch</th>";
                    continue;
                }
                for(k=0; k<numberofcourses; k++){
                    if(vep[k].proffID == i){
                        if(day[tempday]==vep[k].day){

                            if(vep[k].time == temptime || vep[k].time == temptime-1){
                                myfile << "<th> Course:"<<courseinfo[k]<<"<br />Students: "<<students[ves[k].studentID]<<"<br />room: "<<roomsinfo[vec[k].roomID]<<"</th>";
                                sID = 0;
                                break;
                            }
                        }
                    }
                }
                if(sID==1){
                    myfile << "<th></th>";
                }

            }
            myfile << "</tr>";
        }
        myfile << "</body></html>";
        myfile.close();
    }

    return 0;
}
